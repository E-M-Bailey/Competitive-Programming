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

struct Node
{
	//ui x, y;
	Node* parent;
	ui rank;
};

struct DisjointSet
{
	vector<vb> mat;
	vector<vector<Node>> nodes;

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
		return Find(&nodes[i][j]);
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

	inline void Union(ui xi, ui xj, ui yi, ui yj)
	{
		Union(&nodes[xi][xj], &nodes[yi][yj]);
	}

	inline DisjointSet(ui r, ui c) :
		mat(r, vb(c)),
		nodes(r, vector<Node>(c))
	{
		char ch;
		string str;
		loop(0, r, i)
		{
			cin >> str;
			loop(0, c, j)
			{
				mat[i][j] = str[j] == '1';
			}
		}

		loop(0, r, i) loop(0, c, j)
		{
			nodes[i][j] = { nullptr, 0 };
		}

		loop(1, r, i) if (mat[i][0] == mat[i - 1][0])
		{
			Union(i, 0, i - 1, 0);
		}

		loop(1, c, j) if (mat[0][j] == mat[0][j - 1])
		{
			Union(0, j, 0, j - 1);
		}

		loop(1, r, i) loop(1, c, j)
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

int main()
{
	ui r, c; cin >> r >> c;
	DisjointSet ds(r, c);

	ui n; cin >> n;
	ui r1, c1, r2, c2;
	loop(0, n, i)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		if (ds.Find(r1, c1) == ds.Find(r2, c2))
		{
			cout << (ds.mat[r1][c1] ? "decimal" : "binary");
		}
		else
		{
			cout << "neither";
		}
		cout << endl;
	}

	return 0;
}