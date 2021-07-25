#ifndef EMBAILEY_SEGMENT_TREE
#define EMBAILEY_SEGMENT_TREE

#ifndef EMBAILEY_TEMPLATE
#include <initializer_list>
#include <istream>
#include <memory>
#include <vector>
#endif

#ifndef EMBAILEY_RANGE
#include <range.h>
#endif

template<typename T>
inline constexpr T nextPow2(T x)
{
	x--;
	for (T s = 1; s; s *= 2)
		x |= x >> s;
	return x + 1;
}

template<typename T>
inline constexpr T log2p1(T x)
{
	if (!x) return 0;
	T y = 1;
	while (x /= 2) y++;
	return y;
}

template<typename T, typename Op>
class segment_tree
{
public:
	using value_type = T;
	using size_type = size_t;

	// Number of elements
	const size_type n;
	// n rounded up to the next power of 2
	const size_type np2;
	// number of levels; equals log2(np2)+1
	const size_type m;

	// front ([0]) contains the root, back ([m-1]) contains the leaves
	std::vector<std::vector<T>> data;

	const T id;

	// Must support op(left, right, lo, mid, hi)
	// left is the value in the left segment
	// right is the value in the right segment
	// lo is the first index of the left segment
	// mid is the one-past-the-end index of the left segment and the first index of the right segment
	// hi is the one-past-the-end index of the right segment
	// op must be associative
	const Op op;

	template<typename Iter>
	inline segment_tree(Iter first, Iter last, T id, const Op& op = Op());
	inline segment_tree(const std::vector<T>& vec, T id, const Op& op = Op());
	inline segment_tree(size_type n, T id, const Op& op = Op());
	inline segment_tree(size_type n, T value, T id, const Op& op = Op());
	inline segment_tree(const std::initializer_list<T>& iList, T id, const Op& op = Op());

	inline size_type size() const { return n; }

	inline const std::vector<T>& level(size_type i) const { return data[i]; }

	// 0 calls to op (O(1) overall)
	inline T point_query(size_type idx) const;
	// O(log(n)) calls to op
	inline T range_query(size_type first, size_type last) const;
	// O(log(n)) calls to op
	inline T range_query(range r) const { return range_query(r.first, r.last); }

	// O(log(n)) calls to op
	inline void point_update(size_type idx, T value);

private:
	class PointProxy
	{
		friend class segment_tree<T, Op>;

	private:
		segment_tree& st;
		const size_type idx;

		inline PointProxy(segment_tree& st, size_type idx) :
			st(st),
			idx(idx)
		{}

	public:
		inline operator T() const
		{
			return st.point_query(idx);
		}

		inline PointProxy& operator=(T value)
		{
			st.point_update(idx, value);
			return *this;
		}

		friend std::istream& operator>>(std::istream& strm, PointProxy proxy)
		{
			T t;
			strm >> t;
			proxy = t;
			return strm;
		}
	};

	class ConstPointProxy
	{
		friend class segment_tree<T, Op>;

	private:
		const segment_tree& st;
		const size_type idx;

		inline ConstPointProxy(const segment_tree& st, size_type idx) :
			st(st),
			idx(idx)
		{}

	public:
		inline operator T() const
		{
			return st.point_query(idx);
		}
	};

	class ConstRangeProxy
	{
		friend class segment_tree<T, Op>;

	private:
		const segment_tree& st;
		const range r;

		inline ConstRangeProxy(const segment_tree& st, range r) :
			st(st),
			r(r)
		{}

	public:
		inline operator T() const
		{
			return st.range_query(r);
		}
	};

public:
	using reference = PointProxy;
	using const_reference = ConstPointProxy;

	inline PointProxy operator[](size_type i) { return PointProxy(*this, i); }
	inline ConstPointProxy operator[](size_type i) const { return ConstPointProxy(*this, i); }
	inline ConstRangeProxy operator[](range r) const { return ConstRangeProxy(*this, r); }
};

template<typename T, typename Op>
template<typename Iter>
inline segment_tree<T, Op>::segment_tree(Iter first, Iter last, T id, const Op& op) :
	n(std::distance(first, last)),
	np2(nextPow2(n)),
	m(log2p1(np2)),
	data(m),
	id(id),
	op(op)
{
	data.back().resize(np2);
	{
		typename std::vector<T>::iterator iter = std::copy(first, last, data.back().begin());
		std::fill(iter, data.back().end(), id);
	}

	for (size_type i = m - 1; i-- > 0;)
	{
		data[i].resize(1ull << i);
		size_type size = 1ull << (m - 1 - i);
		size_type lo = 0;
		std::vector<T>& upper = data[i];
		std::vector<T>& lower = data[i + 1];
		for (size_type j = 0; j < 1ull << i; j++)
		{
			upper[j] = op(lower[2 * j], lower[2 * j + 1], lo, lo + size / 2, lo + size);
			lo += size;
		}
	}
}

template<typename T, typename Op>
inline segment_tree<T, Op>::segment_tree(const std::vector<T>& vec, T id, const Op& op) :
	segment_tree(vec.begin(), vec.end(), id, op)
{}

template<typename T, typename Op>
inline segment_tree<T, Op>::segment_tree(size_type n, T id, const Op & op) :
	segment_tree(std::vector<T>(n), id, op)
{}

template<typename T, typename Op>
inline segment_tree<T, Op>::segment_tree(size_type n, T val, T id, const Op& op) :
	segment_tree(std::vector<T>(n, val), id, op)
{}

template<typename T, typename Op>
inline segment_tree<T, Op>::segment_tree(const std::initializer_list<T>& iList, T id, const Op& op) :
	segment_tree(iList.begin(), iList.end(), id, op)
{}

template<typename T, typename Op>
inline T segment_tree<T, Op>::point_query(size_type idx) const
{
	return data.back()[idx];
}

template<typename T, typename Op>
inline T segment_tree<T, Op>::range_query(size_type first, size_type last) const
{
	if (last <= first) return id;
	size_type mid = first;
	size_type level = m - 1, lSize = 1;
	T res = id;
	while (true)
	{
		if (mid + lSize > last)
		{
			do
			{
				lSize /= 2;
				level++;
			}
			while (mid + lSize > last);
			if (lSize == 0) break;
		}
		else
		{
			size_type nextLSize;
			while (nextLSize = lSize * 2, mid + nextLSize <= last && (mid & nextLSize - 1) == 0)
			{
				lSize = nextLSize;
				level--;
			}
		}
		size_type hi = mid + lSize;
		res = op(res, data[level][mid >> (m - 1 - level)], first, mid, hi);
		mid = hi;
	}
	return res;
}

template<typename T, typename Op>
inline void segment_tree<T, Op>::point_update(size_type idx, T value)
{
	data.back()[idx] = value;
	for (size_t layer = m - 1, lSize = 2; layer-- > 0; lSize *= 2)
	{
		size_t i = idx >> (m - 1 - layer);
		size_t lo = idx << (m - 1 - layer);
		data[layer][i] = op(data[layer + 1][2 * i], data[layer + 1][2 * i + 1], lo, lo + lSize / 2, lo + lSize);
	}
}

#endif