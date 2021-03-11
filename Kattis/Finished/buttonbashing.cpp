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
	ui tCases; cin >> tCases;
	loop(0, tCases, tCase)
	{
		ui n, t; cin >> n >> t;
		vi b;
		loop(0, n, i)
		{
			ui bi; cin >> bi;
			if (bi != 0)
			{
				b.push_back(bi);
			}
		}

		if (t == 0)
		{
			cout << "0 0" << endl;
			continue;
		}

		n = b.size();
		vi dp(3601, -1);
		dp[0] = 0;
		bool stop;
		ui presses = 0;
		do
		{
			stop = true;
			presses++;
			for (int bi : b)
			{
				loop(0, 3601, j)
				{
					if (dp[j] == presses - 1)
					{
						ui k = max(0, min(3600, (int)j + bi));
						if (dp[k] == -1)
						{
							dp[k] = presses;
							stop = false;
						}
					}
				}
			}
		}
		while (!stop);

		loop(t, 3601, i)
		{
			if (dp[i] >= 0)
			{
				cout << dp[i] << " " << i - t << endl;
				break;
			}
		}
	}
	return 0;
}