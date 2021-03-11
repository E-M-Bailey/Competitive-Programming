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

int main()
{
	tCases()
	{
		ull R, B, M;
		{
			long double Rf, Bf, Mf;
			cin >> Rf >> Bf >> Mf;
			R = (ull)(Rf * 100 + 0.5l);
			B = (ull)(Bf * 100 + 0.5l);
			M = (ull)(Mf * 100 + 0.5l);
		}
		ui i = 1;
		while (true)
		{
			if (i > 1200)
			{
				cout << "impossible" << endl;
				break;
			}
			ull I = (R * B + 5000) / 10000;
			if (I >= M)
			{
				cout << "impossible" << endl;
				break;
			}
			B += I;
			if (B <= M)
			{
				cout << i << endl;
				break;
			}
			B -= M;
			i++;
		}
	}
	return 0;
}