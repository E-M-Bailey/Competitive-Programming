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
constexpr const ui I_MAX = numeric_limits<int>::max();

inline constexpr int cross(pi a, pi b)
{
	return a.first * b.second - a.second * b.first;
}

inline constexpr int magSqr(pi a)
{
	return a.first * a.first + a.second * a.second;
}

constexpr bool comp0(pi l, pi r)
{
	int cp = cross(l, r);
	if (cp) return cp > 0;
	else return magSqr(l) < magSqr(r);
}

// 0 -> ccw, 1 -> colinear, 2 -> cw
inline constexpr ui orient(pi a, pi b, pi c)
{
	int val = cross({ b.second - a.second, b.first - a.first }, { c.second - b.second, c.first - b.first });
	return val < 0 ? 0 : val == 0 ? 1 : 2;
}

int main()
{
	while (true)
	{
		ui n; cin >> n;
		if (n == 0) break;

		ui offsetIdx = UI_MAX;
		pi offset = { I_MAX, I_MAX };
		vpi initPoints(n + 1);
		loop(0, n, i)
		{
			pi point; cin >> point.first >> point.second; initPoints[i + 1] = point;
			if (point.second < offset.second || point.second == offset.second && point.first < offset.first)
			{
				offsetIdx = i;
				offset = point;
			}
		}
		initPoints.erase(initPoints.begin() + offsetIdx + 1);
		initPoints[0] = offset;

		for (pi& point : initPoints) { point.first -= offset.first; point.second -= offset.second; }

		sort(initPoints.begin() + 1, initPoints.end(), comp0);

		vpi points; points.reserve(n); points.push_back({ 0, 0 });

		for (ui i = 1; i < n; i++)
		{
			if (i == n - 1 ? (initPoints[i].first || initPoints[i].second) : cross(initPoints[i], initPoints[i + 1]) != 0) points.push_back(initPoints[i]);
		}

		initPoints.resize(0);

		ui m = points.size();
		if (m < 3)
		{
			cout << m << endl;
			for (pi point : points)
			{
				cout << point.first + offset.first << " " << point.second + offset.second << endl;
			}
			continue;
		}

		vpi st{ points[0], points[1], points[2] };

		loop(3, m, i)
		{
			while (orient(st[st.size() - 2], st[st.size() - 1], points[i]) != 0)
				st.pop_back();
			st.push_back(points[i]);
		}

		cout << st.size() << endl;
		for (pi point : st)
		{
			cout << point.first + offset.first << " " << point.second + offset.second << endl;
		}
	}
	return 0;
}