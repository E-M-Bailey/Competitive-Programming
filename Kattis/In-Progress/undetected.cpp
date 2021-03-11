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
constexpr const ui I_MAX = numeric_limits<int>::max();

struct Node
{
	Node* parent;
	ui rank;
};

struct DisjointSet
{
	vector<Node> nodes;

	inline Node* Find(Node* x)
	{
		if (x->parent)
		{
			x->parent = Find(x->parent);
			return x->parent;
		}
		return x;
	}

	inline Node* Find(ui i)
	{
		return Find(&nodes[i]);
	}

	inline void Union(Node* x, Node* y)
	{
		x = Find(x);
		y = Find(y);
		if (x == y) return;
		if (x->rank < y->rank)
		{
			Node* temp = x;
			x = y;
			y = temp;
		}
		y->parent = x;
		if (x->rank == y->rank) x->rank++;
	}

	inline void Union(ui i, ui j)
	{
		Union(&nodes[i], &nodes[j]);
	}

	inline DisjointSet(ui n) :
		nodes(n, { nullptr, 0 })
	{}
};
int main()
{
	ui N; cin >> N;
	vector<long double> X(N);
	vector<long double> Y(N);
	vector<long double> R(N);
	loop(0, N, i)
	{
		cin >> X[i] >> Y[i] >> R[i];
	}

	DisjointSet ds(N + 2);

	ui i = 0;
	while (ds.Find(N) != ds.Find(N + 1))
	{
		long double x = X[i], y = Y[i], r = R[i];
		loop(0, N, j)
		{
			if (j == i) continue;
			long double dist = hypotl(x - X[j], y - Y[j]);
			if (dist < r + R[i])
				ds.Union(i, j);
		}
		if (x < r)
			ds.Union(i, N);
		if (x > 200 - r)
			ds.Union(i, N + 1);

		i++;
	}

	cout << i;

	return 0;
}