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


int main()
{
	ull k = 1;
	ull val;
	while (true)
	{
		val = (1ull << (k - 1)) * ((1ull << k) - 1);
		if (val <= 1000000000000000000) cout << "0x" << hex << val << ", ";
		else break;
		k++;
	}
	return 0;
}