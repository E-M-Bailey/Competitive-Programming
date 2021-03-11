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

int main()
{
	ui n; cin >> n;
	vui denom(n); loop(0, n, i) cin >> denom[i];
	ui numVals = denom[n - 1] + denom[n - 2];
	vui greedy(numVals); greedy[0] = 0;
	vui optimal(numVals, UI_MAX); optimal[0] = 0;

	loop(1, numVals, i)
	{
		ui val = i;
		ui coins = 0;
		rloop(0, n, j)
		{
			ui cVal = denom[j];
			ui ct = val / cVal;
			coins += ct;
			val -= ct * cVal;
		}
		greedy[i] = coins;
	}

	loop(0, numVals, i)
	{
		ui ct = optimal[i] + 1;
		for (ui cVal : denom)
		{
			ui nextVal = i + cVal;
			if (nextVal < numVals && optimal[nextVal] > ct) optimal[nextVal] = ct;
		}
	}

	cout << (optimal == greedy ? "canonical" : "non-canonical");

	return 0;
}