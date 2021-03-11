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

struct Node
{
	pi i;
	int m;
	Node* l, *r;

	Node(pi ivl) : i(ivl), m(ivl.second), l(nullptr), r(nullptr) {}

	static Node* ins(Node* r, pi ivl)
	{
		if (!r)
			return new Node(ivl);
		int l = r->i.first;
		if (ivl.first < l)
			r->l = ins(r->l, ivl);
		else
			r->r = ins(r->r, ivl);
		if (r->m > ivl.second)
			r->m = ivl.second;
		return r;
	}

	static bool overlap(pi ivl1, pi ivl2)
	{
		return ivl1.first >= ivl2.first && ivl1.first <= ivl2.second || ivl1.second >= ivl2.first && ivl1.second <= ivl2.second;
	}

	static pi* search(Node* r, pi ivl)
	{
		if (!r)
			return nullptr;
		if (overlap(r->i, ivl))
			return &(r->i);
		if (r->l && r->l->m >= i.first)
	}
};

int main()
{
	ui n; cin >> n;

	return 0;
}