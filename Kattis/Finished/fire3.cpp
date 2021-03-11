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

#define loop(m, n, i) for (ui i = m; i < (n); i++)
#define rloop(m, n, i) for (ui i = (n); i-- > m;)
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
	ui R, C; cin >> R >> C;

	set<pui> joes, fires;

	vector<vb> wall(R, vb(C));

	string line;
	loop(0, R, i)
	{
		cin >> line;
		loop(0, C, j)
		{
			char ch = line[j];
			wall[i][j] = ch == '#';
			if (ch == 'J') joes.emplace(i, j);
			if (ch == 'F') fires.emplace(i, j);
		}
	}

	for (ui turn = 0; !joes.empty(); turn++)
	{
		for (pui joe : joes)
		{
			wall[joe.first][joe.second] = true;
		}
		for (pui fire : fires)
		{
			wall[fire.first][fire.second] = true;
		}
		set<pui> newJoes, newFires;
		for (pui joe : joes)
		{
			ui i = joe.first, j = joe.second;
			if (i == 0 || i == R - 1 || j == 0 || j == C - 1)
			{
				cout << turn + 1;
				return 0;
			}
			if (!wall[i - 1][j]) newJoes.emplace(i - 1, j);
			if (!wall[i + 1][j]) newJoes.emplace(i + 1, j);
			if (!wall[i][j - 1]) newJoes.emplace(i, j - 1);
			if (!wall[i][j + 1]) newJoes.emplace(i, j + 1);
		}
		for (pui fire : fires)
		{
			ui i = fire.first, j = fire.second;
			if (i != 0 && !wall[i - 1][j]) newFires.emplace(i - 1, j);
			if (i != R - 1 && !wall[i + 1][j]) newFires.emplace(i + 1, j);
			if (j != 0 && !wall[i][j - 1]) newFires.emplace(i, j - 1);
			if (j != C - 1 && !wall[i][j + 1]) newFires.emplace(i, j + 1);
		}
		for (pui fire : newFires)
		{
			auto jIter = newJoes.find(fire);
			if (jIter != newJoes.end())
				newJoes.erase(jIter);
		}
		joes = move(newJoes);
		fires = move(newFires);
	}

	cout << "IMPOSSIBLE";
	return 0;
}