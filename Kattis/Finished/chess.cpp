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

constexpr const ui UI_MAX = numeric_limits<ui>::max();\

inline constexpr pi toUV(pi xy)
{
	return { xy.first - xy.second, xy.first + xy.second };
}

inline constexpr pi toXY(pi uv)
{
	return { (uv.second + uv.first) / 2, (uv.second - uv.first) / 2 };
}

int main()
{
	tCases()
	{
		char ch;
		int x1, y1, x2, y2;
		cin >> ch; x1 = ch - 'A';
		cin >> ch; y1 = ch - '1';
		cin >> ch; x2 = ch - 'A';
		cin >> ch; y2 = ch - '1';

		if ((x1 ^ y1 ^ x2 ^ y2) & 1)
		{
			cout << "Impossible" << endl;
			continue;
		}
		if (x1 == x2 && y1 == y2)
		{
			cout << "0 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << endl;
			continue;
		}

		bool white = (x1 ^ y1) & 1;

		pi xy1 = { x1, y1 }, xy2 = { x2, y2 };
		pi uv1 = toUV(xy1), uv2 = toUV(xy2);

		if (uv1.first == uv2.first || uv1.second == uv2.second)
		{
			cout << "1 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << " " << (char)(x2 + 'A') << " " << (char)(y2 + '1') << endl;
			continue;
		}

		pi uvImd = { uv1.first, uv2.second };
		pi xyImd = toXY(uvImd);
		if (xyImd.first < 0 || xyImd.first >= 8 || xyImd.second < 0 || xyImd.second >= 8)
		{
			uvImd = { uv2.first, uv1.second };
			xyImd = toXY(uvImd);
		}

		cout << "2 " << (char)(x1 + 'A') << " " << (char)(y1 + '1') << " " << (char)(xyImd.first + 'A') << " " << (char)(xyImd.second + '1') << " " << (char)(x2 + 'A') << " " << (char)(y2 + '1') << endl;
	}
	return 0;
}