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
		int x1, y1, x2, y2;
		ui m;
		cin >> x1 >> y1 >> x2 >> y2 >> m;
		vector<string> names(m);
		vector<pi> XY0(m);
		loop(0, m, i)
			cin >> names[i] >> XY0[i].first >> XY0[i].second;

		int dx = x1 - x2, dy = y2 - y1, cr = x2 * y1 - y2 * x1;
		vector<ui> indices(0);
		int minD = I_MAX;
		loop(0, m, i)
		{
			pi xy = XY0[i];
			int d = abs(dy * xy.first + dx * xy.second + cr);
			if (d <= minD)
			{
				if (d < minD)
				{
					minD = d;
					indices.clear();
				}
				indices.push_back(i);
			}
		}
		cout << names[indices[0]];
		loop(1, indices.size(), i)
			cout << " " << names[indices[i]];
		cout << endl;
	}
	return 0;
}