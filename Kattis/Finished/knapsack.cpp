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

constexpr const ui UI_MAX = numeric_limits<ui>::max();

ui C, n;
vui weight, value;
vector<vector<pair<ui, bool>>> dp;

ui knap(ui i, ui s)
{
	if (s > C) return UI_MAX;
	if (i >= n) return 0;

	pair<ui, bool>& thisDP = dp[i][s];

	if (thisDP.first != UI_MAX) return thisDP.first;

	ui excCur = knap(i + 1, s);
	ui incCur = knap(i + 1, s + weight[i]);
	incCur = incCur == UI_MAX ? UI_MAX : incCur + value[i];

	if (excCur == UI_MAX)
	{
		thisDP = {0, false};
		return 0;
	}
	else if (excCur > incCur || incCur == UI_MAX)
	{
		thisDP = { excCur, false };
		return excCur;
	}
	else
	{
		thisDP = { incCur, true };
		return incCur;
	}
}

int main()
{
	while (cin >> C >> n)
	{
		dp = vector<vector<pair<ui, bool>>>(n, vector<pair<ui, bool>>(C + 1, { UI_MAX, false }));
		weight = vui(n); value = vui(n); loop(0, n, i) cin >> value[i] >> weight[i];
		knap(0, 0);
		vui indices;
		ui i = 0, s = 0;
		while (i < n && s <= C)
		{
			if (dp[i][s].second)
			{
				indices.push_back(i);
				s += weight[i];
			}
			i++;
		}

		cout << indices.size() << endl;
		loop(0, indices.size(), i)
		{
			if (i) cout << " ";
			cout << indices[i];
		}
		cout << endl;
	}
	return 0;
}