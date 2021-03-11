#include <cstring>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define loop(m, n, i) for (ui i = (m); i < (n); i++)
#define rloop(m, n, i) for (ui i = (n); i-- > (m);)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

#define tCases() ui testCaseCount; cin >> testCaseCount; for (ui testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

using namespace std;

typedef unsigned           ui;
typedef long long          ll;
typedef unsigned long long ull;
typedef pair<int, int>     pi;
typedef pair<ui, ui>       pui;
typedef pair<ll, ll>       pll;
typedef pair<ull, ull>     pull;
typedef vector<int>        vi;
typedef vector<ui>         vui;
typedef vector<ll>         vll;
typedef vector<ull>        vull;
typedef vector<pi>         vpi;
typedef vector<pui>        vpui;
typedef vector<pll>        vpll;
typedef vector<pull>       vpull;
typedef vector<bool>       vb;

constexpr const ui UI_MAX = numeric_limits<ui>::max();

string DELIMITER = " ";

namespace
{
	//template<typename Type>
	//struct arg_type {};
	//
	//template<typename Type>
	//struct arg_type<function<Type>>
	//{
	//	using type = Type;
	//};
	//
	//#define REM_PAREN(Type) arg_type<void(Type)>::type
	//
	//#define PT_CONT(Cont, Elem)\
	//inline ostream& operator<<(ostream& stream, const REM_PAREN(Cont)& container)\
	//{\
	//bool first = true;\
	//for (const REM_PAREN(Elem)& x : container)\
	//{\
	//if (!first) stream << DELIMITER;\
	//first = false;\
	//stream << x;\
	//}\
	//}


	//template<typename T> PT_CONT(tuple<T>, T)
	//template<typename T, size_t size> PT_CONT((array<T, size>), T)
	template<typename T>
	inline ostream& operator<<(ostream & stream, const tuple<T> & container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T, size_t size>
	inline ostream& operator<<(ostream& stream, const array<T, size>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const vector<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const deque<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const forward_list<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const list<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const stack<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const queue<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const priority_queue<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const set<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename T>
	inline ostream& operator<<(ostream& stream, const multiset<T>& container)
	{
		bool first = true;
		for (const T& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
	template<typename K, typename V>
	inline ostream& operator<<(ostream& stream, const multiset<K, V>& container)
	{
		bool first = true;
		for (const pair<K, V>& x : container)
		{
			if (!first) stream << DELIMITER;
			first = false;
			stream << x;
		}
		return stream;
	}
}

template<class T, class PredType = decltype(less_equal<T>())>
inline size_t mergeAndCountInv(vector<T>& vec, size_t l, size_t m, size_t r, PredType pred = less_equal<T>())
{
	auto beg = vec.begin();
	vector<T> left(beg + l, beg + m + 1);
	vector<T> right(beg + m + 1, beg + r + 1);

	size_t i = 0, j = 0, k = l, count = 0;

	while (i < left.size() && j < right.size())
	{
		if (pred(left[i], right[j]))
			vec[k++] = left[i++];
		else
		{
			vec[k++] = right[j++];
			count += (m + 1) - (l + i);
		}
	}

	while (i < left.size())
		vec[k++] = left[i++];
	while (j < right.size())
		vec[k++] = right[j++];

	return count;
}

template<class T, class PredType = decltype(less_equal<T>())>
inline size_t mergeSortAndCountInv(vector<T>& vec, size_t l, size_t r, PredType pred = less_equal<T>())
{
	if (l >= r) return 0;
	size_t m = (l + r) / 2;
	return mergeSortAndCountInv(vec, l, m, pred)
		+ mergeSortAndCountInv(vec, m + 1, r, pred)
		+ mergeAndCountInv(vec, l, m, r, pred);
}

// O(n*log(n))
template<class T, class PredType = decltype(less_equal<T>())>
inline size_t mergeSortInvCount(vector<T>& vec, PredType pred = less_equal<T>())
{
	return mergeSortAndCountInv(vec, 0, vec.size() - 1, pred);
}

int main()
{
	tCases()
	{
		ull n; cin >> n;
		vui a(n); loop(0, n, i) cin >> a[i];
		size_t count = mergeSortInvCount(a);
		cout << (count <= n * (n - 1) / 2 - 1 ? "YES" : "NO") << endl;
	}
	return 0;
}