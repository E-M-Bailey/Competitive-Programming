#include <array>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()

#define CONTAINS(c, x) ((c).find(x) != (c).end())

template<size_t I>
struct TupleReadHelper
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c);
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c);
};

template<>
struct TupleReadHelper<0>
{
	template<typename... Ts>
	static inline void read(tuple<Ts...>& c) {}
	template<typename... Ts>
	static inline void read(tuple<Ts&...>&& c) {}
};

template<typename Iter>
inline void read_rng(Iter first, Iter last);

template<typename T>
inline void read(T& t)
{
	cin >> t;
}

template<typename T, typename U>
inline void read(pair<T, U>& c)
{
	read(c.first);
	read(c.second);
}

template<typename... Ts>
inline void read(tuple<Ts...>& c)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c);
}

template<typename... Ts>
inline void read(tuple<Ts&...>&& c)
{
	TupleReadHelper<tuple_size<tuple<Ts...>>::value>::read(c);
}

template<typename T, size_t Size>
inline void read(array<T, Size>& c)
{
	read_rng(ALL(c));
}

template<typename T, typename Alloc>
inline void read(vector<T, Alloc>& c)
{
	read_rng(ALL(c));
}

template<typename T, typename Alloc>
inline void read(deque<T, Alloc>& c)
{
	read_rng(ALL(c));
}

template<typename T, typename Alloc>
inline void read(list<T, Alloc>& c)
{
	read_rng(ALL(c));
}

template<typename T, typename Alloc>
inline void read(forward_list<T, Alloc>& c)
{
	read_rng(ALL(c));
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts...>& c)
{
	TupleReadHelper<I - 1>::read(c);
	::read(get<I - 1>(c));
}

template<size_t I>
template<typename... Ts>
inline void TupleReadHelper<I>::read(tuple<Ts&...>&& c)
{
	TupleReadHelper<I - 1>::read(c);
	::read(get<I - 1>(c));
}

template<typename T>
inline T read()
{
	T t;
	::read(t);
	return t;
}

template<typename Iter>
inline void read_rng(Iter first, Iter last)
{
	while (first != last)
		read(*(first++));
}

template<size_t Depth, size_t I>
struct TupleWriteHelper
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c);
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(tuple<Ts&...>&& c, const tuple<Delim0, Delims...>& delims);
	template<typename... Ts>
	static inline void write(tuple<Ts&...>&& c);
};

template<size_t Depth>
struct TupleWriteHelper<Depth, 0>
{
	template<typename... Ts, typename Delim0, typename... Delims>
	static inline void write(const tuple<Ts...>& c, const tuple<Delim0, Delims...>& delims) {}
	template<typename... Ts>
	static inline void write(const tuple<Ts...>& c) {}
};

template<size_t Depth = 0, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, const tuple<Delim0, Delims...>& delims);

template<typename Iter>
inline void write_rng(Iter first, Iter last);

template<typename T>
inline void write(const T& t)
{
	cout << t;
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void writeD(const T& t, const tuple<Delim0, Delims...>&)
{
	write(t);
}

template<typename T, typename U>
inline void write(const pair<T, U>& c)
{
	write(c.first);
	write(c.second);
}

template<size_t Depth, typename T, typename U, typename Delim0, typename... Delims>
inline void writeD(const pair<T, U>& c, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		writeD<Depth + 1>(c.first, delims);
		write(get<safeDepth>(delims));
		writeD<Depth + 1>(c.second, delims);
	}
	else
	{
		write(c.first);
		write(c.second);
	}
}

template<typename... Ts>
inline void write(const tuple<Ts...>& c)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void writeD(const tuple<Ts...>& c, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, delims);
}

template<typename... Ts>
inline void write(tuple<Ts&...>&& c)
{
	TupleWriteHelper<0, tuple_size<tuple<Ts...>>::value>::write(c);
}

template<size_t Depth, typename... Ts, typename Delim0, typename... Delims>
inline void writeD(tuple<Ts&...>&& c, const tuple<Delim0, Delims...>& delims)
{
	TupleWriteHelper<Depth, tuple_size<tuple<Ts...>>::value>::write(c, delims);
}

template<typename T>
inline void write(const initializer_list<T>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Delim0, typename... Delims>
inline void writeD(const initializer_list<T>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, size_t Size>
inline void write(const array<T, Size>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, size_t Size, typename Delim0, typename... Delims>
inline void writeD(const array<T, Size>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Alloc>
inline void write(const vector<T, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const vector<T, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Alloc>
inline void write(const deque<T, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const deque<T, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Alloc>
inline void write(const list<T, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const list<T, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Alloc>
inline void write(const forward_list<T, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const forward_list<T, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const set<T, Pr, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const set<T, Pr, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Pr, typename Alloc>
inline void write(const multiset<T, Pr, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const multiset<T, Pr, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_set<T, Hash, Eq, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const unordered_set<T, Hash, Eq, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename T, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multiset<T, Hash, Eq, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename T, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const unordered_multiset<T, Hash, Eq, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const map<K, V, Pr, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const map<K, V, Pr, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename K, typename V, typename Pr, typename Alloc>
inline void write(const multimap<K, V, Pr, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename K, typename V, typename Pr, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const multimap<K, V, Pr, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_map<K, V, Hash, Eq, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const unordered_map<K, V, Hash, Eq, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
inline void write(const unordered_multimap<K, V, Hash, Eq, Alloc>& c)
{
	write_rng(ALL(c));
}

template<size_t Depth, typename K, typename V, typename Hash, typename Eq, typename Alloc, typename Delim0, typename... Delims>
inline void writeD(const unordered_multimap<K, V, Hash, Eq, Alloc>& c, const tuple<Delim0, Delims...>& delims)
{
	write_rng<Depth>(ALL(c), delims);
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, delims);
	writeD<Depth + 1>(get<I - 1>(c), delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims));
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(const tuple<Ts...>& c)
{
	TupleWriteHelper<Depth, I - 1>::write(c);
	::write(get<I - 1>(c));
}

template<size_t Depth, size_t I>
template<typename... Ts, typename Delim0, typename... Delims>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c, const tuple<Delim0, Delims...>& delims)
{
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	TupleWriteHelper<Depth, I - 1>::write(c, delims);
	writeD<Depth + 1>(get<I - 1>(c), delims);
	if (hasDelim && I < tuple_size<tuple<Ts...>>::value) ::write(get<safeDepth>(delims));
}

template<size_t Depth, size_t I>
template<typename... Ts>
inline void TupleWriteHelper<Depth, I>::write(tuple<Ts&...>&& c)
{
	TupleWriteHelper<Depth, I - 1>::write(c);
	::write(get<I - 1>(c));
}

template<size_t Depth, typename Iter, typename Delim0, typename... Delims>
inline void write_rng(Iter first, Iter last, const tuple<Delim0, Delims...>& delims)
{
	if (first == last) return;
	constexpr bool hasDelim = Depth < tuple_size<tuple<Delim0, Delims...>>::value;
	constexpr size_t safeDepth = hasDelim ? Depth : 0;
	if (hasDelim)
	{
		for (;;)
		{
			writeD<Depth + 1>(*(first++), delims);
			if (first == last) break;
			write(get<safeDepth>(delims));
		}
	}
	else
	{
		do
			write(*(first++));
		while (first != last);
	}
}

template<typename Iter>
inline void write_rng(Iter first, Iter last)
{
	while (first != last) write(*(first++));
}

template<typename T, typename Delim0, typename... Delims>
inline void write(const T& t, const Delim0& delim0, const Delims&... delims)
{
	writeD<0>(t, tie(delim0, delims...));
}

inline unsigned long long func(vector<unsigned>::iterator first, vector<unsigned>::iterator last)
{
	unsigned long long x = 0;
	for (vector<unsigned>::iterator itr = first; itr != last; itr++)
	{
		*itr++;
		x += (unsigned long long)sqrt(*itr);
		x %= 29;
	}
	return x;
}

int main()
{
	unsigned a;
	pair<unsigned, unsigned> b;
	tuple<unsigned, unsigned, unsigned> c;
	array<unsigned, 4> d;
	vector<unsigned> e(5);
	deque<unsigned> f(6);
	list<unsigned> g(7);
	forward_list<unsigned> h(8);

	read(tie(a, b, c, d, e, f, g, h));
	write(tie(a, b, c, d, e, f, g, h), '\n', ' ');

	set<char> i{ 'a', 'a', 'b' };
	multiset<char> j{ 'c', 'c', 'd' };
	unordered_set<char> k{ 'e', 'e', 'f' };
	unordered_multiset<char> l{ 'g', 'g', 'h' };

	map<char, char> m;
	m['i'] = 'k';
	m['i'] = 'l';
	m['j'] = 'l';
	multimap<char, char> n;
	n.emplace('m', 'o');
	n.emplace('m', 'p');
	n.emplace('n', 'p');
	unordered_map<char, char> o;
	o['q'] = 's';
	o['q'] = 't';
	o['r'] = 't';
	unordered_multimap<char, char> p;
	p.emplace('u', 'w');
	p.emplace('u', 'x');
	p.emplace('v', 'x');

	cout << endl << endl << endl;

	write(tie(i, j, k, l, m, n, o, p), '\n', ' ', '-');

	vector<unsigned> vec(read<unsigned>());
	read(vec);
	write(tuple<unsigned long long, vector<unsigned>&>(func(ALL(vec)), vec), '\n', " ");
}
