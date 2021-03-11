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

#define endl '\n'

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
constexpr const int I_MAX = numeric_limits<int>::max();
constexpr const int I_MIN = numeric_limits<int>::min();
constexpr const ull ULL_MAX = numeric_limits<ull>::max();
constexpr const ll LL_MAX = numeric_limits<ll>::max();
constexpr const ll LL_MIN = numeric_limits<ll>::min();

inline constexpr pi operator-(const pi& p1, pi& p2)
{
	return { p1.first - p2.first, p1.second - p2.second };
}

inline constexpr int cross(const pi & p1, const pi & p2)
{
	return p1.first * p2.second - p2.first * p1.second;
}

inline constexpr int magSqr(const pi& p)
{
	return p.first * p.first + p.second * p.second;
}

inline constexpr int sortComp(const pi& p1, const pi& p2)
{
	return cross(p1, p2) > 0;
}

inline constexpr bool leftTurn(pi& p1, pi& p2, pi& p3)
{
	return cross(p2 - p1, p3 - p2) > 0;
}

inline constexpr bool revLexComp(const pi& p1, const pi& p2)
{
	return p1.second < p2.second || p1.second == p2.second && p1.first < p2.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ui N, M;
	cin >> N >> M;

	vpui trees(N);
	vpi poles(M);
	loop(0, N, i)
	{
		cin >> trees[i].first >> trees[i].second;
	}
	loop(0, M, i)
	{
		cin >> poles[i].first >> poles[i].second;
	}
	ui L;

	// Convex Hull
	{
		ui pivotIdx = 0;
		loop(1, M, i)
		{
			if (revLexComp(poles[i], poles[pivotIdx]))
			{
				pivotIdx = i;
			}
		}
		if (pivotIdx)
		{
			swap(poles[0], poles[pivotIdx]);
		}

		pi offset = poles[0];

		for (pi& pole : poles)
		{
			pole = pole - offset;
		}

		sort(poles.begin() + 1, poles.end(), sortComp);

		// Poles are already guaranteed to be non-collinear.

		vpi hull{ poles[0], poles[1], poles[2] };
		ui s = 3;

		loop(3, M, i)
		{
			while (!leftTurn(hull[s - 2], hull[s - 1], poles[i]))
			{
				hull.pop_back();
				s--;
			}

			hull.push_back(poles[i]);
			s++;
		}

		long double realFenceLength = sqrtl(magSqr(hull[s - 1]));
		loop(1, s, i)
		{
			realFenceLength += sqrtl(magSqr(hull[i] - hull[i - 1]));
		}
		L = ceill(realFenceLength);
	}

	// Knapsack
	{
		vui DP(L + 1, UI_MAX);
		DP[0] = 0;
		for (pui tree : trees)
		{
			rloop(0, L, i)
			{
				if (DP[i] == UI_MAX)
				{
					continue;
				}
				ui newI = i + tree.first, newT = DP[i] + tree.second;
				if (newI > L)
				{
					newI = L;
				}
				DP[newI] = min(DP[newI], newT);
			}
		}

		cout << DP[L];
	}

	return 0;
}