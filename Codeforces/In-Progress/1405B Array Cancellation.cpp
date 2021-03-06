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

int main()
{
	ui tCases; cin >> tCases; loop(0, tCases, tCase)
	{
		ui n; cin >> n;
		vi a(n); loop(0, n, i) cin >> a[i];
		loop(0, n, i)
		{
			int& ai = a[i];
			if (ai > 0)
			{
				loop(i + 1, n, j)
				{
					int& aj = a[j];
					if (aj < 0)
					{
						int amt = min(ai, -aj);
						ai -= amt;
						aj += amt;
					}
				}
			}
		}
		ui val = 0;
		for (int i : a)
		{
			if (i > 0) val += i;
		}
		cout << val << endl;
	}
	return 0;
}