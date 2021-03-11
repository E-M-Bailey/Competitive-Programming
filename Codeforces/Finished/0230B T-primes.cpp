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
constexpr const int I_MAX = numeric_limits<int>::max();
constexpr const int I_MIN = numeric_limits<int>::min();
constexpr const ull ULL_MAX = numeric_limits<ull>::max();
constexpr const ll LL_MAX = numeric_limits<ll>::max();
constexpr const ll LL_MIN = numeric_limits<ll>::min();

bool C[1000001]{ false };
vui P;

int main()
{
	C[0] = C[1] = true;
	P.reserve(78498);
	for (ui i = 2; i <= 1000000; i++)
	{
		if (!C[i])
		{
			P.push_back(i);
		}
		ui p, x;
		for (ui j = 0; j < P.size() && (p = P[j], x = i * p, x <= 1000000); j++)
		{
			C[x] = true;
			if (i % p == 0)
			{
				break;
			}
		}
	}

	tCases()
	{
		ull p2;
		cin >> p2;
		ull p = sqrtl(p2);
		cout << (p * p == p2 && !C[p] ? "YES" : "NO") << endl;
	}
	return 0;
}