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

#define loop(i, n) for (ui i = 0; i < (n); i++)

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef unsigned           ui;
typedef pair<int, int>     pi;
typedef pair<ui, ui>       pui;
typedef vector<int>        vi;
typedef vector<ui>         vui;
typedef vector<pi>         vpi;
typedef vector<pui>        vpui;
typedef vector<bool>       vb;

inline void searchTree(ui& total, const vector<vui>& graph, ui x, ui y, vb& visited, ui depth = 2)
{
	visited[y - 1] = true;
	if (y % x == 0)
		total += depth;
	for (ui next : graph[y - 1])
		if (!visited[next])
			searchTree(total, graph, x, next + 1, visited, depth + 1);
}

int main()
{
	ui n; cin >> n;
	vector<vui> graph(n);
	loop(idx, n - 1)
	{
		ui i, j; cin >> i >> j;
		i--; j--;
		graph[i].push_back(j);
		graph[j].push_back(i);
	}

	vb visited;
	ui total = 0;

	loop(x, n / 2)
	{
		visited = vb(n, false);
		visited[x] = true;
		for (ui y : graph[x])
			searchTree(total, graph, x + 1, y + 1, visited);
	}
	cout << total;

	return 0;
}