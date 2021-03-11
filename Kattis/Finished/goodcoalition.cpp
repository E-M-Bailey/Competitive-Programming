#include <cstring>
#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <iomanip>
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
constexpr const ui I_MAX = numeric_limits<int>::max();

int main()
{
	tCases()
	{
		ui n; cin >> n;
		vui S(n), P(n);
		loop(0, n, i)
			cin >> S[i] >> P[i];

		long double DP[151]{ 0.0L };
		DP[0] = 100.0L;
		long double maxProb = 0.0L;
		loop(0, n, i)
		{
			ui s = S[i], p = P[i];
			rloop(0, 151, j)
			{
				long double jp = DP[j];
				if (jp == 0.0L) continue;
				jp = (jp * p) / 100;
				ui sp = j + s;
				DP[sp] = max(DP[sp], jp);
				if (sp >= 76)
					maxProb = max(maxProb, jp);
			}
		}
		
		cout << fixed << setprecision(numeric_limits<long double>::max_digits10) << maxProb << endl;
	}
	return 0;
}