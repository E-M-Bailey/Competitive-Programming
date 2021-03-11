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

inline void root(vector<set<ui>>& tree, vui& parents, ui x = 0)
{
	for (ui y : tree[x])
	{
		tree[y].erase(tree[y].find(x));
		parents[y] = x;
		root(tree, parents, y);
	}
}

inline ui compHeight(const vector<set<ui>>& tree, vui& height, ui x = 0)
{
	ui sum = 1;
	for (ui y : tree[x])
	{
		sum += compHeight(tree, height, y);
	}
	return height[x] = sum;
}

inline ui compDiam(const vector<set<ui>>& tree, const vui& height, ui x = 0)
{
	ui max1 = 0, max2 = 0;
	ui maxDiam = 0;
	for (ui y : tree[x])
	{
		if (height[y] > max2)
		{
			max2 = height[y];
			if (max2 > max1)
			{
				ui temp = max1;
				max1 = max2;
				max2 = temp;
			}
		}
		ui childDiam = compDiam(tree, height, y);
		if (childDiam > maxDiam) maxDiam = childDiam;
	}
	return max(max1 + max2, maxDiam);
}

inline ui dist(const vui& parents, ui a, ui b)
{
	ui da = 0, db = 0;
	ui a1 = a, b1 = b;
	while (a1 != 0)
	{
		a1 = parents[a1];
		da++;
	}
	while (b1 != 0)
	{
		b1 = parents[b1];
		db++;
	}
	a1 = a; b1 = b;
	ui d = 0;
	while (da > db)
	{
		a1 = parents[a1];
		da--;
		d++;
	}
	while (db > da)
	{
		b1 = parents[b1];
		db--;
		d++;
	}
	while (a1 != b1)
	{
		a1 = parents[a1];
		b1 = parents[b1];
		d++;
	}
	return d;
}

int main()
{
	tCases()
	{
		ui n, a, b, da, db; cin >> n >> a >> b >> da >> db;
		a--; b--;
		vector<set<ui>> tree(n);
		vui parents(n);
		loop(0, n - 1, i)
		{
			ui u, v; cin >> u >> v; u--; v--;
			tree[u].insert(v);
			tree[v].insert(u);
		}
		if (db <= 2 * da)
		{
			cout << "Alice" << endl;
			continue;
		}
		parents[0] = 0;
		root(tree, parents);
		vui height(n, 0u);
		compHeight(tree, height);
		//vui diam(n, 0u);
		ui treeDiam = compDiam(tree, height);
		cout << (dist(parents, a, b) <= da || treeDiam <= 2 * da ? "Alice" : "Bob") << endl;
	}
	return 0;
}