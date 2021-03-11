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

constexpr const ui COST_MAX = 30000;

class test
{
private:
	void hi();
};

void test::hi()
{
	cout << "Hello";
}

int main()
{
	ui n;
	cin >> n;
	vui C(n);
	loop(0, n, i)
		cin >> C[i];
	ui m;
	cin >> m;
	vui S(m);
	ui maxS = 0;
	loop(0, m, i)
	{
		ui s;
		cin >> s;
		S[i] = s;
		if (s > maxS)
			maxS = s;
	}

	vpui DP(maxS + 1, { 0, 0 });
	DP[0] = { 1, 0 };

	loop(0, n, i)
	{
		ui c = C[i];
		rloop(0, maxS, j)
		{
			if (DP[j].first == 0 || DP[j].first == UI_MAX)
				continue;
			for (ui k = j + c, l = 1; k <= maxS; k += c, l++)
				DP[k] = DP[k].first ? pui{ UI_MAX, 0 } : pui{ i + 1, l };
		}
	}

	loop(0, m, i)
	{
		ui s = S[i];
		if (DP[s].first == 0)
		{
			cout << "Impossible" << endl;
			continue;
		}
		bool ambig = false;
		vpui res;
		while (s)
		{
			pui dp = DP[s];
			if (dp.first == UI_MAX)
			{
				cout << "Ambiguous" << endl;
				ambig = true;
				break;
			}
			res.push_back(dp);
			s -= C[dp.first - 1] * dp.second;
		}
		if (ambig)
			continue;
		rloop(0, res.size(), j)
		{
			pui dp = res[j];
			rloop(0, dp.second, k)
				cout << dp.first << " ";
		}
		cout << endl;
	}
	return 0;
}