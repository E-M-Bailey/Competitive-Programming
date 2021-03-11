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

ull IS_PRIME_TABLE[625]{ 0 };
ull POS_TABLE[10000]{ 0 };
ull VAL_TABLE[10000]{ 0 };

inline void genSieve()
{
	vb isPrime(40000, true);
	isPrime[0] = false;
	loop(2, 40001, i)
	{
		if (isPrime[i - 1])
		{
			for (ui j = i * 2; j < 40001; j += i)
			{
				isPrime[j - 1] = false;
			}
		}
	}
	loop(0, 625, i)
	{
		loop(0, 64, j)
		{
			if (isPrime[i * 64 + j])
			{
				IS_PRIME_TABLE[i] |= 1ull << j;
			}
		}
	}
}

inline void genPos()
{
	vector<pair<ui, ui>> pos(40000);
	vector<vector<uint16_t>> vals(200, vector<uint16_t>(200));
	ui dir = 0;
	ui len = 1;
	ui cur = 0;
	int x = 0, y = 0;
	loop(0, 40000, i)
	{
		pos[i] = { x + 99, y + 99 };
		vals[x + 99][y + 99] = i + 1;
		if (cur < len)
		{
			cur++;
		}
		else
		{
			dir++;
			if (dir == 4) dir = 0;
			if (dir % 2 == 0) len++;
			cur = 1;
		}
		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		}
	}
	loop(0, 10000, i)
	{
		loop(0, 4, j)
		{
			POS_TABLE[i] |= ((ull)pos[i * 4 + j].first) << (j * 16ull);
			POS_TABLE[i] |= ((ull)pos[i * 4 + j].second) << (j * 16ull + 8ull);
		}
	}

	loop(0, 10000, i)
	{
		loop(0, 4, j)
		{
			ui idx = i * 4 + j;
			VAL_TABLE[i] |= ((ull)vals[idx / 200][idx % 200]) << (j * 16ull);
		}
	}
}

inline constexpr bool isPrime(ui i)
{
	ull entry = IS_PRIME_TABLE[(i - 1) / 64];
	return entry & (1ull << (i - 1) % 64);
}

inline constexpr pui getPos(ui i)
{
	ull entry = POS_TABLE[(i - 1) / 4];
	entry >>= ((i - 1) % 4) * 16ull;
	ui x = entry & 0xff, y = (entry >> 8) & 0xff;
	return { x, y };
}

inline constexpr pui getPosSgn(ui i)
{
	ull entry = POS_TABLE[(i - 1) / 4];
	entry >>= ((i - 1) % 4) * 16ull;
	int x = entry & 0xff, y = (entry >> 8) & 0xff;
	return { x - 99, y - 99 };
}

inline constexpr ui getVal(ui x, ui y)
{
	ui idx = x * 200 + y;
	ull entry = VAL_TABLE[idx / 4];
	return 0xffff & (entry >> (idx % 4) * 16);
}

inline constexpr ui getValSgn(int x, int y)
{
	ui idx = (x + 99) * 200 + (y + 99);
	ull entry = VAL_TABLE[idx / 4];
	return 0xffff & (entry >> (idx % 4) * 16);
}

ui proc(ui x, ui y)
{
	vb xHit(40000, false), yHit(40000, false);
	set<ui> cx, cy;
	xHit[x - 1] = true;
	yHit[y - 1] = true;
	cx.insert(x);
	cy.insert(y);
	ui dist = 0;
	do
	{
		set<ui> nextX, nextY;
		dist++;
		for (ui xVal : cx)
		{
			pui xPos = getPos(xVal);
			if (xPos.first > 0)
			{
				ui val = getVal(xPos.first - 1, xPos.second);
				if (!xHit[val - 1] && !isPrime(val))
				{
					if (yHit[val - 1]) return dist;
					xHit[val - 1] = true;
					nextX.insert(val);
				}
			}
			if (xPos.first < 199)
			{
				ui val = getVal(xPos.first + 1, xPos.second);
				if (!xHit[val - 1] && !isPrime(val))
				{
					if (yHit[val - 1]) return dist;
					xHit[val - 1] = true;
					nextX.insert(val);
				}
			}
			if (xPos.second > 0)
			{
				ui val = getVal(xPos.first, xPos.second - 1);
				if (!xHit[val - 1] && !isPrime(val))
				{
					if (yHit[val - 1]) return dist;
					xHit[val - 1] = true;
					nextX.insert(val);
				}
			}
			if (xPos.second < 199)
			{
				ui val = getVal(xPos.first, xPos.second + 1);
				if (!xHit[val - 1] && !isPrime(val))
				{
					if (yHit[val - 1]) return dist;
					xHit[val - 1] = true;
					nextX.insert(val);
				}
			}
		}
		dist++;
		for (ui yVal : cy)
		{
			pui yPos = getPos(yVal);
			if (yPos.first > 0)
			{
				ui val = getVal(yPos.first - 1, yPos.second);
				if (!yHit[val - 1] && !isPrime(val))
				{
					if (xHit[val - 1]) return dist;
					yHit[val - 1] = true;
					nextY.insert(val);
				}
			}
			if (yPos.first < 199)
			{
				ui val = getVal(yPos.first + 1, yPos.second);
				if (!yHit[val - 1] && !isPrime(val))
				{
					if (xHit[val - 1]) return dist;
					yHit[val - 1] = true;
					nextY.insert(val);
				}
			}
			if (yPos.second > 0)
			{
				ui val = getVal(yPos.first, yPos.second - 1);
				if (!yHit[val - 1] && !isPrime(val))
				{
					if (xHit[val - 1]) return dist;
					yHit[val - 1] = true;
					nextY.insert(val);
				}
			}
			if (yPos.second < 199)
			{
				ui val = getVal(yPos.first, yPos.second + 1);
				if (!yHit[val - 1] && !isPrime(val))
				{
					if (xHit[val - 1]) return dist;
					yHit[val - 1] = true;
					nextY.insert(val);
				}
			}
		}
		cx = move(nextX);
		cy = move(nextY);
	}
	while (cx.size() > 0 && cy.size() > 0);
	return 0;
}

int main()
{
	genSieve();
	genPos();
	ui i = 0;
	while (true)
	{
		ui x, y; cin >> x >> y;
		if (x == y)
		{
			cout << "Case " << ++i << ": 0" << endl;
			continue;
		}
		ui res = proc(x, y);
		cout << "Case " << ++i << ": " << (res ? to_string(res) : "impossible") << endl;
	}
	return 0;
}