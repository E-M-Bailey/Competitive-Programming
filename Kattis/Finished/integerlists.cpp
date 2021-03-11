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

int main()
{
	tCases()
	{
		string cmd; cin >> cmd;
		ui n; cin >> n;
		vui X(n);
		string arrStr; cin >> arrStr;
		stringstream arrStream(arrStr.substr(1, arrStr.size() - 2));
		loop(0, n, i)
		{
			getline(arrStream, arrStr, ',');
			X[i] = stoi(arrStr);
		}
		bool rev = false;
		ui dLeft = 0, dRight = 0;
		for (char ch : cmd)
		{
			if (ch == 'R') rev = !rev;
			else if (rev) dRight++;
			else dLeft++;
		}

		if (dLeft + dRight > n) cout << "error" << endl;
		else
		{
			cout << '[';
			bool first = true;
			if (rev)
			{
				rloop(dLeft, n - dRight, i)
				{
					cout << X[i];
					if (i > dLeft) cout << ',';
				}
			}
			else
			{
				loop(dLeft, n - dRight, i)
				{
					if (i > dLeft) cout << ',';
					cout << X[i];
				}
			}
			cout << ']' << endl;
		}
	}
	return 0;
}