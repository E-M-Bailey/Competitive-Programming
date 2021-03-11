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

ui N, H, L;

int main()
{
	cin >> N >> H >> L;
	vui hIdx(N, UI_MAX);
	priority_queue<pui, vpui, greater<pui>> Q;
	loop(0, H, i)
	{
		ui x; cin >> x;
		hIdx[x] = 0;
		Q.push({ 0, x });
	}
	vector<vui> sim(N);
	loop(0, L, i)
	{
		ui a, b; cin >> a >> b;
		sim[a].push_back(b);
		sim[b].push_back(a);
	}

	while (!Q.empty())
	{
		ui u = Q.top().second;
		Q.pop();
		for (ui v : sim[u])
		{
			if (hIdx[v] > hIdx[u] + 1)
			{
				hIdx[v] = hIdx[u] + 1;
				Q.push({ hIdx[v], v });
			}
		}
	}

	ui bestX = 0, bestHIdx = hIdx[0];
	loop(1, N, x)
	{
		if (hIdx[x] > bestHIdx)
		{
			bestHIdx = hIdx[x];
			bestX = x;
		}
	}

	cout << bestX;

	return 0;
}