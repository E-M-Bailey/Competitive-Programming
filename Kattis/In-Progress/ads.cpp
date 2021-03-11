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
constexpr const streamsize SS_MAX = numeric_limits<streamsize>::max();

struct Img
{
	ui i, j, h, w;

	inline constexpr ui pxCt() const
	{
		return w * h;
	}
};

inline constexpr bool operator<(const Img& img1, const Img& img2)
{
	return img1.pxCt() < img2.pxCt();
}

int main()
{

}

int mainn()
{
	ui H, W; cin >> H >> W; cin.ignore(SS_MAX, '\n');
	vector<vector<char>> webpage(H, vector<char>(W));
	string line;
	loop(0, H, i)
	{
		getline(cin, line);
		loop(0, W, j) webpage[i][j] = line[j];
	}

	vector<vb> borderMask(H, vb(W, false));

	vector<Img> images;
	loop(0, H, i) loop(0, W, j)
	{
		if (webpage[i][j] == '+' && !borderMask[i][j])
		{
			ui h, w;
			for (ui k = i + 1;; k++)
			{
				if (k == H || webpage[k][j] != '+' || k > i + 1 && webpage[k - 1][j + 1] == '+')
				{
					h = k - i;
					break;
				}
			}
			for (ui k = j + 1;; k++)
			{
				if (k == W || webpage[i][k] != '+' || k > j + 1 && webpage[i + 1][k - 1] == '+')
				{
					w = k - j;
					break;
				}
			}
			images.push_back({ i, j, h, w });
			loop(i, i + h, k) borderMask[k][j] = borderMask[k][j + w - 1] = true;
			loop(j + 1, j + w - 1, k) borderMask[i][k] = borderMask[i + h - 1][k] = true;
		}
	}
	ui I = images.size();
	sort(images.begin(), images.end());
	loop(0, I, idx)
	{
		Img img = images[idx];
		bool isAd = false;
		loop(img.i + 1, img.i + img.h - 1, i)
		{
			loop(img.j + 1, img.j + img.w - 1, j)
			{
				char c = webpage[i][j];
				if (
					(c < 'A' || c > 'Z') &&
					(c < 'a' || c > 'z') &&
					(c < '0' || c > '9') &&
					c != '?' &&
					c != '!' &&
					c != ',' &&
					c != '.' &&
					c != ' '
					)
				{
					isAd = true;
					break;
				}
			}
			if (isAd) break;
		}
		if (isAd)
			loop(img.i, img.i + img.h, i) loop(img.j, img.j + img.w, j)
				webpage[i][j] = ' ';
	}
	loop(0, W, j) cout << webpage[0][j];
	loop(1, H, i)
	{
		cout << endl;
		loop(0, W, j) cout << webpage[i][j];
	}
	return 0;
}