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

#define loop(n, i) for (ui i = 0; i < (n); i++)
#define rloop(n, i) for (ui i = (n); i-- > 0;)
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

inline constexpr const ull& min(const ull& a, const ull& b, const ull& c)
{
	return min(a, min(b, c));
}

inline ull cost(vull& table, const vui& a, ull r1, ull r2, ull r3, ull d, ull i)
{
	if (table[i])
	{
		return table[i];
	}

	const ui n = a.size();

	ui ai = a[i];

	if (i == n - 1)
	{
		table[i] = min
		(
			ai * r1 + r3,
			min((ai + 1ull) * r1, r2) + r1 + 2 * d
		);
		return table[i];
	}

	ui ai1 = a[i + 1];

	ull cost1 = cost(table, a, r1, r2, r3, d, i + 1);

	if (i == n - 2)
	{
		table[i] = min
		(
			ai * r1 + r3 + d + cost1,
			min((ai + 1ull) * r1, r2) + (ai1 + 1ull) * r1 + r3 + 2 * d,
			min((ai + 1ull) * r1, r2) + min((ai1 + 1ull) * r1, r2) + 2 * r1 + 3 * d
		);
		return table[i];
	}
	ull cost2 = cost(table, a, r1, r2, r3, d, i + 2);

	table[i] = min
	(
		ai * r1 + r3 + d + cost1,
		min((ai + 1ull) * r1, r2) + (ai1 + 1ull) * r1 + r3 + 4 * d + cost2,
		min((ai + 1ull) * r1, r2) + min((ai1 + 1ull) * r1, r2) + 2 * r1 + 4 * d + cost2
	);
	return table[i];
}

int main()
{
	ui n; cin >> n;
	ull r1, r2, r3, d; cin >> r1 >> r2 >> r3 >> d;
	vui a(n); loop(n, i) cin >> a[i];
	vull table(n, 0);

	cout << cost(table, a, r1, r2, r3, d, 0);

	return 0;
}