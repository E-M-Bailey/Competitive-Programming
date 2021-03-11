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

#define loop(m, n, i) for (ui i = m; i < (n); i++)
#define rloop(m, n, i) for (ui i = (n); i-- > m;)
#define loop_each(vec, i, x) auto x = vec.front(); for (ui i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (ui i = (vec).size(); i-- > 0; x = vec[i - 1])

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

typedef pair<int, ui> entry;

//inline bool compare(Node a, Node b)
//{
//	return a.p > b.p;
//}

int main()
{
	ui n, m; cin >> n >> m;
	vui grid(n * m);
	string line;
	loop(0, n, i)
	{
		cin >> line;
		loop(0, m, j)
		{
			grid[i * m + j] = line[j] - '0';
		}
	}

	vui dist(n * m, numeric_limits<ui>::max()); // i * m + j -> d
	dist[0] = 0;

	priority_queue<entry, vector<entry>, greater<entry>> Q;
	Q.push({ 0, 0 });

	while (!Q.empty())
	{
		ui u = Q.top().second;
		Q.pop();

		ui iu = u / m, ju = u % m;
		ui valU = grid[u];

		if (iu >= valU)
		{
			ui v = (iu - valU) * m + ju;
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				Q.push({ dist[v], v });
			}
		}
		if (ju >= valU)
		{
			ui v = iu * m + ju - valU;
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				Q.push({ dist[v], v });
			}
		}
		if (iu + valU < n)
		{
			ui v = (iu + valU) * m + ju;
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				Q.push({ dist[v], v });
			}
		}
		if (ju + valU < m)
		{
			ui v = iu * m + ju + valU;
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				Q.push({ dist[v], v });
			}
		}
	}

	ui d = dist[n * m - 1];
	cout << (d == numeric_limits<ui>::max() ? "-1" : to_string(d)) << endl;

	return 0;
}