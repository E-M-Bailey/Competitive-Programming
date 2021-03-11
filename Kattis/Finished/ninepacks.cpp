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

void getSums(const vui& packSizes, vui& netCosts)
{
	netCosts[0] = 0u;
	ui max = 1;
	for (ui packSize : packSizes)
	{
		rloop(0, max, i)
		{
			ui j = i + packSize;
			if (netCosts[i] != UI_MAX && (netCosts[j] == UI_MAX || netCosts[j] > netCosts[i] + 1))
			{
				netCosts[j] = netCosts[i] + 1;
			}
		}
		max += packSize;
	}
}

int main()
{
	ui H; cin >> H;
	ui hSumAll = 0;
	vui h(H);
	loop(0, H, i)
	{
		cin >> h[i];
		hSumAll += h[i];
	}
	vui hSums(hSumAll + 1, UI_MAX);
	getSums(h, hSums);

	ui B; cin >> B;
	vui b(B);
	ui bSumAll = 0;
	loop(0, B, j)
	{
		cin >> b[j];
		bSumAll += b[j];
	}
	vui bSums(bSumAll + 1, UI_MAX);
	getSums(b, bSums);

	ui minSumAll = min(hSumAll, bSumAll);

	ui best = UI_MAX;

	loop(1, minSumAll + 1, sum)
	{
		ui hSum = hSums[sum], bSum = bSums[sum];
		if (hSum != UI_MAX && bSum != UI_MAX)
		{
			best = min(best, hSum + bSum);
		}
	}

	if (best == UI_MAX) cout << "impossible";
	else cout << best;

	return 0;
}