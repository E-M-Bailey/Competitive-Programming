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


int r, c, V;

struct point
{
	int i, j;

	operator ui() const
	{
		return i * c + j;
	}
};

const point dirs[8]{ {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

typedef pair<ui, point> entry;

point operator+(const point& a, const point& b)
{
	return { a.i + b.i, a.j + b.j };
}

bool operator==(const point& a, const point& b)
{
	return a.i == b.i && a.j == b.j;
}

bool operator>(const point& e1, const point& e2)
{
	return static_cast<ui>(e1) > static_cast<ui>(e2);
}

int main()
{
	cin >> r >> c; V = r * c;
	char ch;
	vui grid(V);
	for (point pt{ 0, 0 }; pt.i < r; pt.i++)
		for (pt.j = 0; pt.j < c; pt.j++)
		{
			cin >> ch;
			grid[pt] = ch - '0';
		}

	tCases()
	{
		point src, dest; cin >> src.i >> src.j >> dest.i >> dest.j; src.i--; src.j--; dest.i--; dest.j--;
		priority_queue<entry, vector<entry>, greater<entry>> Q;
		vui dist(V, UI_MAX);

		Q.push({ 0, src });
		dist[src] = 0;

		while (!Q.empty())
		{
			point u = Q.top().second;
			Q.pop();
			loop(0, 8, d)
			{
				point v = u + dirs[d];
				ui weight = grid[u] != d;
				if (v.i >= 0 && v.i < r && v.j >= 0 && v.j < c && dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					Q.push({ dist[v], v });
				}
			}
		}
		cout << dist[dest] << endl;
	}
	return 0;
}