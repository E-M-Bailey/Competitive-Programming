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
constexpr const ull ULL_MAX = numeric_limits<ull>::max();
constexpr const ull LL_MAX = numeric_limits<ll>::max();

struct Node
{
	ui val = 0;
	ui size = 1;
	ui sum = 0;
	Node* parent = nullptr;
	unordered_set<Node*> children = {};

	Node(ui v) :
		val(v),
		size(1),
		sum(v),
		parent(nullptr)
	{}

	Node() : Node(0) {}

	Node(const Node& n) = default;
};

struct DisjointSet
{
	ui n;
	vector<Node> nodes;

	DisjointSet(ui n) : n(n), nodes(n)
	{
		loop(0, n, i)
			nodes[i] = Node(i + 1);
	}

	inline Node* Get(ui x)
	{
		Node* n = &nodes[x - 1];
		return n;
	}

	inline Node* Find(Node* p)
	{
		if (p->parent)
		{
			p->parent->children.erase(p);
			p->parent = Find(p->parent);
			p->parent->children.insert(p);
			return p->parent;
		}
		else
			return p;
	}

	inline void Union(Node* p, Node* q)
	{
		p = Find(p);
		q = Find(q);
		if (p != q)
		{
			if (p->size < q->size)
				swap(p, q);
			q->parent = p;
			p->children.insert(q);
			p->size += q->size;
			p->sum += q->sum;
		}
	}

	inline void Separate(Node* p, Node* rep)
	{
		const bool hasChildren = !p->children.empty(), hasParent = p->parent != nullptr;
		if (!hasChildren && !hasParent)
			return;
		Node* child = nullptr;
		if (hasChildren)
		{
			auto beg = p->children.begin();
			child = *beg;
			beg++;
			child->parent = p->parent;
			child->children.insert(beg, p->children.end());
			for (; beg != p->children.end(); beg++)
			{
				(*beg)->parent = child;
			}
			if (hasParent)
				p->parent->children.insert(child);
		}
		if (hasParent)
		{
			p->parent->children.erase(p);
			rep->size--;
			rep->sum -= p->val;
		}
		else
		{
			child->size = p->size - 1;
			child->sum = p->sum - p->val;
		}
		p->children.clear();
		p->parent = nullptr;
		p->size = 1;
		p->sum = p->val;
	}

	inline void Move(Node* p, Node* q)
	{
		q = Find(q);
		Node* rep = Find(p);
		if (rep == q)
			return;
		Separate(p, rep);
		Union(p, q);
	}

	inline void Print(Node* p)
	{
		p = Find(p);
		cout << p->size << " " << p->sum << endl;
	}

};

int main()
{
	ui n, m;
	while (cin >> n >> m)
	{
		DisjointSet ds(n);
		for (ui i = 0; i < m; i++)
		{
			ui c, p, q;
			cin >> c;
			switch (c)
			{
			case 1:
				cin >> p >> q;
				ds.Union(ds.Get(p), ds.Get(q));
				break;
			case 2:
				cin >> p >> q;
				ds.Move(ds.Get(p), ds.Get(q));
				break;
			case 3:
				cin >> p;
				ds.Print(ds.Get(p));
				break;
			}
		}
	}
	return 0;
}