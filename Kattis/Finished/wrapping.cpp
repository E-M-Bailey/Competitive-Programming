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

typedef long double ld;
typedef pair<ld, ld> pld;
typedef vector<ld> vld;
typedef vector<pld> vpld;

constexpr const ui UI_MAX = numeric_limits<ui>::max();
constexpr const int I_MAX = numeric_limits<int>::max();

constexpr const ld LD_INFINITY = numeric_limits<ld>::infinity();

const ld TO_RAD_CCW = -atanl(1) / 45.0l;

inline constexpr ld cross(pld a, pld b)
{
	return a.first * b.second - a.second * b.first;
}

inline constexpr ld magSqr(pld a)
{
	return a.first * a.first + a.second * a.second;
}

constexpr bool comp0(pld l, pld r)
{
	ld cp = cross(l, r);
	if (cp) return cp > 0;
	else return magSqr(l) < magSqr(r);
}

// 0 -> ccw, 1 -> colinear, 2 -> cw
inline constexpr ui orient(const pld& a, const pld& b, const pld& c)
{
	ld val = cross({ b.second - a.second, b.first - a.first }, { c.second - b.second, c.first - b.first });
	return val < 0 ? 0 : val == 0 ? 1 : 2;
}

int main()
{
	tCases()
	{
		ui n; cin >> n;
		ld rectArea = 0;
		vpld initPoints(n * 4 + 1);
		auto iter = initPoints.begin() + 1;
		loop(0, n, i)
		{
			ld x, y, w, h, v; cin >> x >> y >> w >> h >> v;
			v *= TO_RAD_CCW;
			ld s = sinl(v), c = cosl(v);
			x = x - w * c / 2 + h * s / 2;
			y = y - w * s / 2 - h * c / 2;
			rectArea += w * h;
			*iter++ = { x, y };
			*iter++ = { x + w * c, y + w * s };
			*iter++ = { x + w * c - h * s, y + w * s + h * c };
			*iter++ = { x - h * s, y + h * c };
		}

		ui offsetIdx = UI_MAX;
		pld offset = { LD_INFINITY, LD_INFINITY };
		loop(1, 4 * n + 1, i)
		{
			pld point = initPoints[i];
			if (point.second < offset.second || point.second == offset.second && point.first < offset.first)
			{
				offsetIdx = i;
				offset = point;
			}
		}
		initPoints.erase(initPoints.begin() + offsetIdx);
		initPoints[0] = offset;

		for (pld& point : initPoints) { point.first -= offset.first; point.second -= offset.second; }
		sort(initPoints.begin() + 1, initPoints.end(), comp0);
		vpld points; points.reserve(4 * n); points.push_back({ 0, 0 });
		loop(1, 4 * n, i)
			if (i == 4 * n - 1 ? (initPoints[i].first || initPoints[i].second) : cross(initPoints[i], initPoints[i + 1]) != 0) points.push_back(initPoints[i]);
		initPoints.clear();

		ld hullArea = 0;
		ui m = points.size();
		if (m >= 3)
		{
			vpld st{ points[0], points[1], points[2] };
			loop(3, m, i)
			{
				ui o = orient(st[st.size() - 2], st[st.size() - 1], points[i]);
				while (o != 0)
				{
					st.pop_back();
					o = orient(st[st.size() - 2], st[st.size() - 1], points[i]);
				}
				st.push_back(points[i]);
			}

			ui s = st.size();
			st.push_back({ 0, 0 });
			loop(0, s, i)
				hullArea += st[i].first * st[i + 1].second - st[i + 1].first * st[i].second;
			hullArea /= 2;
		}

		if (hullArea)
			cout << fixed << setprecision(1) << (rectArea * 100 / hullArea) << " %" << endl;
		else
			cout << "100.0 %" << endl;
	}
	return 0;
}
