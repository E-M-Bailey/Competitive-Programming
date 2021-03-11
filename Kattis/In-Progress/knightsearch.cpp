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
constexpr const ui I_MAX = numeric_limits<int>::max();

int main()
{
	ui N; cin >> N;
	vector<vector<char>> grid(N, vector<char>(N));
	set<pi> curIndices, newIndices;
	{
		string str; cin >> str;
		loop(0, N, i) loop(0, N, j)
		{
			char c = grid[i][j] = str[i * N + j];
			if (c == 'I') curIndices.insert({ i, j });
		}
	}

	char favStr[] = { 'C', 'P', 'C', 'A', 'S', 'I', 'A', 'S', 'G' };

	for (ui idx = 0; idx < 9; idx++)
	{
		newIndices.clear();
		char ch = favStr[idx];
		for (pi curIdx : curIndices)
		{
			ui i = curIdx.first, j = curIdx.second;
			pi newIdx;
			newIdx = { i + 2, j + 1 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i + 1, j + 2 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i + 2, j - 1 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i + 1, j - 2 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i - 2, j + 1 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i - 1, j + 2 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i - 2, j - 1 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
			newIdx = { i - 1, j - 2 }; if (newIdx.first >= 0 && newIdx.first < N && newIdx.second >= 0 && newIdx.second < N && grid[newIdx.first][newIdx.second] == ch) newIndices.insert(newIdx);
		}
		swap(newIndices, curIndices);
	}

	cout << (curIndices.empty() ? "NO" : "YES");

	return 0;
}