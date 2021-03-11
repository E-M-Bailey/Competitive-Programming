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

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef unsigned           ui;
typedef pair<int, int>     pi;
typedef pair<ui, ui>       pui;
typedef vector<int>        vi;
typedef vector<ui>         vui;
typedef vector<pi>         vpi;
typedef vector<pui>        vpui;
typedef vector<bool>       vb;

int main()
{
	// O(1)
	ui n; cin >> n;
	vui f(n);
	loop(n, i)
	{
		ui fi; cin >> fi;
		f[i] = fi - 1;
	}
	loop(n, i)
	{
		if (f[f[f[i]]] == i)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}