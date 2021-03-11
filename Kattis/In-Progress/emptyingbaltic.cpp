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

struct Entry
{
	ui i, j, d;
};

vpui next(ui i, ui j, ui h, ui w)
{
	vpui ret;
	if (i > 0) ret.push_back({ i - 1, j });
	if (i < h - 1) ret.push_back({ i + 1, j });
	if (j > 0) ret.push_back({ i, j - 1});
	if (j < w - 1) ret.push_back({ i, j  + 1});
	if (i > 0 && j > 0) ret.push_back({ i - 1, j - 1 });
	if (i > 0 && j < w - 1) ret.push_back({ i - 1, j + 1 });
	if (i < h - 1 && j > 0) ret.push_back({ i + 1, j - 1 });
	if (i < h - 1 && j < w - 1) ret.push_back({ i + 1, j + 1 });
	return ret;
}

inline constexpr bool compare(Entry e1, Entry e2)
{
	return e1.d < e2.d;
}

int main()
{
	ui h, w; cin >> h >> w;
	vector<vui> depth(h, vui(w, 0));
	loop(0, h, i) loop(0, w, j)
	{
		int d; cin >> d;
		if (d < 0) depth[i][j] = -d;
	}
	ui i, j; cin >> i >> j;
	i--; j--;

	auto cmp = [](Entry l, Entry r) { return compare(l, r); };
	priority_queue < Entry, vector<Entry>, decltype(cmp)> queue(cmp);
	queue.push({ i, j, depth[i][j] });
	depth[i][j] = 0;

	ull volume = 0;
	while (!queue.empty())
	{
		Entry e = queue.top();
		queue.pop();

		volume += e.d;

		vpui nextPos = next(e.i, e.j, h, w);

		for (pui p : nextPos)
		{
			ui &ip = p.first, &jp = p.second;
			ui dp = min(depth[ip][jp], e.d);
			if (dp > 0) queue.push({ ip, jp, dp });
			depth[ip][jp] = 0;
		}
	}

	cout << volume;

	return 0;
}