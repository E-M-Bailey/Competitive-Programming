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

const long double logE = 1 / logl(10);
const long double a = log10l(2 * sqrtl(2 * atanl(1)));

inline ui stirlingDigits(ui n)
{
	return static_cast<ui>(a - logE * n + (n + 0.5) * log10l(n)) + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	ui dTgt = str.size();
	if (dTgt <= 3)
	{
		switch (dTgt)
		{
		case 1:
			switch (str[0])
			{
			case '1':
				cout << '1';
				break;
			case '2':
				cout << '2';
				break;
			default:
				cout << '3';
				break;
			}
			break;
		case 2:
			cout << '4';
			break;
		default:
			switch (str[0])
			{
			case '1':
				cout << '5';
				break;
			default:
				cout << '6';
				break;
			}
			break;
		}
		return 0;
	}
	ui min = 7, max = 205022, ipl, dMin = 4, dMax = 999999, dIpl;
	while (max >= min)
	{
		//ipl = (dTgt - dMin) * (max - min) / (dMax - dMin) + min;
		ipl = (min + max) / 2;
		dIpl = stirlingDigits(ipl);
		if (dIpl == dTgt)
		{
			cout << ipl;
			return 0;
		}
		else if (dIpl < dTgt)
		{
			min = ipl + 1;
			//dMin = stirlingDigits(min);
		}
		else
		{
			max = ipl - 1;
			//dMax = stirlingDigits(max);
		}
	}

	// should never occur
	throw 0;
}