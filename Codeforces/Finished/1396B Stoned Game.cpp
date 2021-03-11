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

#define loop(n, i) for (ui i = 0; i < (n); i++)
#define rloop(n, i) for (ui i = (n); i-- > 0;)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

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

//inline bool p1Wins(vui& a)
//{
//	bool ret = false;
//	while (true)
//	{
//		ui diff = a.size();
//		vui::iterator newEnd = remove_if(a.begin(), a.end(), [](ui a) { return a == 1; });
//		a.resize(newEnd - a.begin());
//		diff -= a.size();
//		if (diff % 2)
//		{
//			ret = !ret;
//		}
//		if (a.size() == 0)
//		{
//			return ret;
//		}
//		else if (a.size() == 1)
//		{
//			return !ret;
//		}
//		ui m = std::numeric_limits<ui>::max();
//		for (ui ai : a)
//		{
//			if (m > ai) m = ai;
//		}
//		for (ui& ai : a)
//		{
//			ai -= m - 1;
//		}
//		if (a.size() % 2 && m % 2)
//		{
//			ret = !ret;
//		}
//	}
//}

inline bool p1Wins(vui& a)
{
	sort(a.begin(), a.end());
	ui n = a.size();
	ui sum = 0; loop(n - 1, i) sum += a[i];
	if (a[n - 1] > sum)
	{
		return true;
	}
	else
	{
		return (sum + a[n - 1]) % 2;
	}
}

int main()
{
	ui testCases; cin >> testCases;
	__assume (testCases >= 1);
	__assume (testCases <= 100);
	loop(testCases, testCase)
	{
		ui n; cin >> n;
		__assume (n >= 1);
		__assume (n <= 100);
		vui a(n);
		loop(n, i)
		{
			cin >> a[i];
			__assume(a[i] >= 1);
			__assume(a[i] <= 100);
		}
		cout << (p1Wins(a) ? "T" : "HL") << endl;
	}
	return 0;
}