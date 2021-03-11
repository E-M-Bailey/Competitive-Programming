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

constexpr const ui MOD = 1000000007u;
constexpr const ui INV2 = (MOD + 1) / 2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//for (ui n = 0; n < 11; n++)
	//{
	//	ui sum = 0;
	//	for (ui i = 0; i < 1u << n; i++)
	//	{
	//		ui a = i, b = 0, c = 0;
	//		while (a > 0)
	//		{
	//			if (a & 1)
	//				c += b;
	//			else
	//				b++;
	//			a >>= 1;
	//		}
	//		//if (n == 5)
	//		//	cout << c << endl;
	//		sum += c;
	//	}

	//	cout << endl << sum << endl;
	//}

	ull ct1 = 0;
	ull ctQ = 0;
	ull ct10 = 0;
	ull ctQ0_1Q = 0;


	char ch;
	while (!cin.eof() && cin >> ch)
	{
		switch (ch)
		{
		case '0':
			ct10 = (ct10 + ct1) % MOD;
			ctQ0_1Q = (ctQ0_1Q + ctQ) % MOD;
			break;
		case '1':
			ct1++;
			break;
		case '?':
			ctQ0_1Q = (ctQ0_1Q + ct1) % MOD;
			ctQ++;
			break;
		}
	}

	ct10 %= MOD;
	ctQ0_1Q %= MOD;

	if (ctQ)
	{
		ull qm1 = ctQ - 1;
		ull pow2qm1 = 1;
		ull mul = 2;
		while (qm1)
		{
			if (qm1 & 1)
			{
				pow2qm1 = (pow2qm1 * mul) % MOD;
			}
			mul = (mul * mul) % MOD;
			qm1 >>= 1;
		}
		ull sum10 = ct10 * pow2qm1 % MOD * 2 % MOD;
		ull sum1Q = ctQ0_1Q * pow2qm1 % MOD;
		ull sumQQ = ctQ * (ctQ - 1) / 2 % MOD * pow2qm1 % MOD * INV2 % MOD;

		cout << (sum10 + sum1Q + sumQQ) % MOD;
	}
	else
	{
		cout << ct10;
	}

	return 0;
}