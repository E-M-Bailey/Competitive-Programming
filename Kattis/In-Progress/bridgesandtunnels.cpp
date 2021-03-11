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

#define endl '\n'

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
constexpr const int I_MAX = numeric_limits<int>::max();
constexpr const int I_MIN = numeric_limits<int>::min();
constexpr const ull ULL_MAX = numeric_limits<ull>::max();
constexpr const ll LL_MAX = numeric_limits<ll>::max();
constexpr const ll LL_MIN = numeric_limits<ll>::min();

struct DisjointSetForest
{
	struct Node
	{
		ui parent;
		ui rank;
	};

	const ui n;
	ui k;
	Node* const nodes;

	inline DisjointSetForest(ui n) :
		n(n),
		k(n),
		nodes(new Node[n])
	{
		loop(0, n, i)
		{
			nodes[i] = { i, 0 };
		}
	}

	inline ~DisjointSetForest()
	{
		delete[] nodes;
	}

	inline constexpr ui& Parent(ui x)
	{
		return nodes[x].parent;
	}

	inline constexpr ui& Rank(ui x)
	{
		return nodes[x].rank;
	}

	inline ui Find(ui x)
	{
		while (x != Parent(x))
		{
			Parent(x) = Parent(Parent(x));
			x = Parent(x);
		}
		return x;
	}

	inline void Union(ui x, ui y)
	{
		x = Find(x);
		y = Find(y);

		if (x == y)
		{
			return;
		}

		if (Rank(x) < Rank(y))
		{
			swap(x, y);
		}

		Parent(y) = x;
		if (Rank(x) == Rank(y))
		{
			Rank(x)++;
		}

		k--;
	}

	inline vector<vui> Partitions()
	{
		vui mapping(n);
		for (ui x = 0, i = 0; i < k; x++)
		{
			if (x == Parent(x))
			{
				mapping[x] = i;
				i++;
			}
		}
		vector<vui> partitions(k, vui());
		loop(0, n, x)
		{
			partitions[mapping[Find(x)]].push_back(x);
		}
		return partitions;
	}
};

// (x-1)th triangular number
inline constexpr ui Tri(ui x)
{
	return (x > 0) * x * (x - 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ui n, m, p;
	cin >> n >> m >> p;

	vui I(Tri(n), 0), O(Tri(n), 0);
	DisjointSetForest dsf(n);

	ui x, y, t;
	char c;
	loop(0, m, i)
	{
		cin >> x >> y >> t >> c;
		if (x == y)
		{
			continue;
		}
		if (x < y)
		{
			swap(x, y);
		}

		if (c == 'I')
		{
			dsf.Union(x, y);
			I[Tri(y) + x] = t;
		}
		else
		{
			O[Tri(y) + x] = t;
		}
	}

	vector<vui> parts = dsf.Partitions();

	vector<pair<ui, pui>> redO(Tri(dsf.k), { 0, { 0, 0 } });

	loop(1, dsf.k, i)
	{
		vui& partI = parts[i];
		ui lI = partI.size();
		loop(0, i, j)
		{
			vui& partJ = parts[j];
			ui lJ = partJ.size();
			for (ui x : partI)
			{
				for (ui y : partJ)
				{
					if (x < y)
					{
						swap(x, y);
					}
					pair<ui, pui>& entry = redO[Tri(i) + j];
					t = O[Tri(x) + y];
					if (t && (t < entry.first || !entry.first))
					{
						entry = { t, {x, y} };
					}
				}
			}
		}
	}

	return 0;
}