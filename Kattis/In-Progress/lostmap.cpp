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

#define _CRT_SECURE_NO_DEPRECATE

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

typedef array<ui, 3> ui3;

bool compare(const ui3& n1, const ui3& n2)
{
	return n1[0] < n2[0];
}

int main()
{
	ui n;
	cin >> n;
	vector<ui3> graph;
	for (ui i = 0; i < n; i++)
		for (ui j = 0; j < n; j++)
		{
			ui weight;
			cin >> weight;
			if (i < j)
			{
				graph.push_back({ weight, i, j });
			}
		}
	sort(graph.begin(), graph.end(), compare);

	vui forest;

	for (ui i = 0; i < n; i++)
	{
		forest.push_back(i);
	}

	vector<ui3> mst;

	ui edgesLeft = n - 1;

	for (ui idx = 0; idx < graph.size() && edgesLeft > 0; idx++)
	{
		ui3 edge = graph[idx];
		if (forest[edge[1]] != forest[edge[2]])
		{
			mst.push_back(edge);
			ui original = forest[edge[1]];
			for (ui i = 0; i < n; i++)
			{
				if (forest[i] == original)
				{
					forest[i] = forest[edge[2]];
				}
			}
			edgesLeft--;
		}
	}

	for (const ui3& edge : mst)
	{
		cout << edge[1] + 1 << " " << edge[2] + 1 << endl;
	}

	return 0;
}