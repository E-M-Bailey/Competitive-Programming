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


int main()
{
	ui n; cin >> n;
	__assume(n > 0);
	vll a(n);
	loop(n, i) cin >> a[i];

	stringstream stream;
	if (n == 1)
	{
		stream << "1 1" << endl << -a[0] << endl << "1 1" << endl << "0" << endl << "1 1" << endl << "0";
	}
	else if (n == 2)
	{
		stream << "1 1" << endl << -a[0] << endl << "2 2" << endl << -a[1] << endl << "1 1" << endl << "0";
	}
	else if (n == 3)
	{
		stream << "1 1" << endl << -a[0] << endl << "2 2" << endl << -a[1] << endl << "3 3" << endl << -a[2];
	}
	else
	{
		stream << "1 " << n << endl;
		loop(n, i)
		{
			if (i) stream << " ";
			ll diff = n * (a[i] % (n - 1));
			a[i] -= diff;
			stream << -diff;
		}
		stream << endl;
		stream << "1 " << n - 1 << endl;
		loop(n - 1, i)
		{
			if (i) stream << " ";
			stream << -a[i];
		}
		stream << endl;
		stream << n << " " << n << endl;
		stream << -a[n - 1];
	}
	cout << stream.str();

	return 0;
}