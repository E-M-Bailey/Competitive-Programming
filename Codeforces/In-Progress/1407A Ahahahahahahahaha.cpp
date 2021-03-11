#include <cstring>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
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

string DELIMITER = " ";

template<typename T>
inline ostream& operator<<(ostream& stream, const tuple<T>& container)
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

int main()
{
	tCases()
	{
		ui n; cin >> n;
		vui a(n); loop(0, n, i) cin >> a[i];
		vpi dp(n, { 0, 0 });
		dp[n - 1] = {}
		rloop(0, n, i)
		{
			
		}
	}
	return 0;
}