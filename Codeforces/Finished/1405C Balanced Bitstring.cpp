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
		ui n, k; cin >> n >> k;
		string str; cin >> str;
		if (k % 2 == 1)
		{
			cout << "NO" << endl;
			continue;
		}
		bool balanced = true;
		ui ct0 = 0, ct1 = 0;
		for (ui i = 0; i < k && balanced; i++)
		{
			for (ui j = i + k; j < n; j += k)
			{
				if (str[i] == '?')
				{
					str[i] = str[j];
				}
				else if (str[i] != str[j] && str[j] != '?')
				{
					balanced = false;
					break;
				}
			}
			if (str[i] == '0') ct0++;
			else if (str[i] == '1') ct1++;

		}
		balanced &= max(ct0, ct1) <= k / 2;
		cout << (balanced ? "YES" : "NO") << endl;
	}
	return 0;
}