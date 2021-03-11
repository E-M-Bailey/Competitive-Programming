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
constexpr const ull ULL_MAX = numeric_limits<ull>::max();
constexpr const ull LL_MAX = numeric_limits<ll>::max();

typedef pair<ull, ui> entry;

ui N, M;

bool rec(ui x, ui q, const vector<vui> & prev)
{
	if (q == x) return true;
	if (prev[x].empty()) return false;
	for (ui y : prev[x])
	{
		if (!rec(y, q, prev))
			return false;
	}
	return true;
}

int main()
{
	cin >> N >> M;
	vull cost(N, ULL_MAX);
	priority_queue<entry, vector<entry>, greater<entry>> Q;
	vector<vector<pair<ull, ui>>> graph(N);
	vector<vui> prev(N);
	loop(0, M, i)
	{
		ui u, v; cin >> u >> v;
		ull w; cin >> w;
		graph[u].push_back({ w, v });
	}
	ui src, dest; cin >> src >> dest;
	Q.push({ 0, src });
	cost[src] = 0;

	while (!Q.empty())
	{
		ui u = Q.top().second;
		Q.pop();
		for (const pair<ull, ui> p : graph[u])
		{
			ull w = p.first;
			ui v = p.second;
			ull newW = cost[u] + w;
			if (newW < cost[v])
			{
				cost[v] = newW;
				prev[v] = vui(1, u);
				Q.push({ newW, v });
			}
			else if (newW == cost[v])
			{
				prev[v].push_back(u);
			}
		}
	}

	//vb res(N, true);
	loop(0, N, i)
		if (rec(dest, i, prev))
			cout << i << ' ';

	return 0;
}