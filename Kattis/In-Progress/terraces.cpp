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

struct Node
{
	//ui i, j;
	ui h;
	bool wet;
	Node* parent;
	ui size;
};

struct UnionFind
{
	vector<vui> mat;
	vector<vector<Node>> vec;

	inline Node* Find(Node* x)
	{
		if (x->parent)
		{
			x->parent = Find(x->parent);
			return x->parent;
		}
		return x;
	}

	inline Node* Find(ui i, ui j)
	{
		return Find(&vec[i][j]);
	}

	inline void Union(Node* x, Node* y)
	{
		x = Find(x);
		y = Find(y);
		if (x == y) return;
		if (x->size < y->size)
		{
			Node* temp = x;
			x = y;
			y = temp;
		}
		y->parent = x;
		x->size += y->size;
	}

	inline void Union(ui xi, ui xj, ui yi, ui yj)
	{
		Union(&vec[xi][xj], &vec[yi][yj]);
	}

	inline UnionFind(ui x, ui y) :
		mat(x, vui(y)),
		vec(x, vector<Node>(y))
	{
		loop(0, x, i) loop(0, y, j) cin >> mat[i][j];

		loop(0, x, i) loop(0, y, j)
		{
			vec[i][j] = { mat[i][j], true, nullptr, 1 };
		}

		loop(1, x, i) if (mat[i][0] == mat[i - 1][0])
		{
			Union(i, 0, i - 1, 0);
		}

		loop(1, y, j) if (mat[0][j] == mat[0][j - 1])
		{
			Union(0, j, 0, j - 1);
		}

		loop(1, x, i) loop(1, y, j)
		{
			if (mat[i][j] == mat[i - 1][j])
			{
				Union(i, j, i - 1, j);
			}
			if (mat[i][j] == mat[i][j - 1])
			{
				Union(i, j, i, j - 1);
			}
		}

	}
};

void comp(Node* a, Node* b)
{
	if (a == b) return;
	if (a->h < b->h)
	{
		b->wet = false;
	}
	else
	{
		a->wet = false;
	}
}

int main()
{
	ui x, y; cin >> y >> x;

	UnionFind uf(x, y);

	unordered_set<Node*> roots;

	loop(0, x, i) loop(0, y, j)
	{
		Node* a = uf.Find(i, j);
		roots.insert(a);
		Node* b;
		if (i > 0)
		{
			b = uf.Find(i - 1, j);
			comp(a, b);
		}
		if (i < x - 1)
		{
			b = uf.Find(i + 1, j);
			comp(a, b);
		}
		if (j > 0)
		{
			b = uf.Find(i, j - 1);
			comp(a, b);
		}
		if (j < y - 1)
		{
			b = uf.Find(i, j + 1);
			comp(a, b);
		}
	}

	ui wetSize = 0;
	for (Node* root : roots)
	{
		if (root->wet)
		{
			wetSize += root->size;
		}
	}
	cout << wetSize;
	return 0;
}