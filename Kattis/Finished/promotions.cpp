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

constexpr const ui UI_MAX = numeric_limits<ui>::max();

inline ui getSize(ui x, const vector<vui>& dag, vb& visited)
{
	ui res = 1;
	for (ui y : dag[x])
	{
		if (!visited[y])
		{
			visited[y] = true;
			res += getSize(y, dag, visited);
		}
	}
	return res;
}

int main()
{
	ui A, B, E, P; cin >> A >> B >> E >> P;
	vector<vui> down(E), up(E);
	//vb isRoot(E, true);
	loop(0, P, i)
	{
		ui x, y; cin >> x >> y;
		down[x].push_back(y);
		up[y].push_back(x);
		//isRoot[y] = false;
	}
	vui sizeUp(E, UI_MAX), sizeDown(E);

	//queue<pui> bfsQueue;
	//loop(0, E, x)
	//{
	//	if (isRoot[x])
	//	{
	//		bfsQueue.emplace(x, 0);
	//		mins[x] = 0;
	//	}
	//}
	//while (!bfsQueue.empty())
	//{
	//	pui cur = bfsQueue.front();
	//	bfsQueue.pop();
	//	ui x = cur.first, d = cur.second;
	//	mins[x] = d;
	//	d++;
	//	for (ui y : down[x])
	//	{
	//		if (mins[y] == UI_MAX)
	//		{
	//			bfsQueue.emplace(y, d);
	//		}
	//	}
	//}

	loop(0, E, x)
	{
		vb visited(E, false);
		sizeDown[x] = E - getSize(x, down, visited);
	}
	loop(0, E, x)
	{
		vb visited(E, false);
		sizeUp[x] = getSize(x, up, visited);
	}

	ui res1 = 0, res2 = 0, res3 = 0;

	loop(0, E, x)
	{
		if (sizeDown[x] < A)
			res1++;
		if (sizeDown[x] < B)
			res2++;
		if (sizeUp[x] > B)
			res3++;
	}

	cout << res1 << endl << res2 << endl << res3;

	return 0;
}