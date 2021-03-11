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
#include <type_traits>
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

struct DisjointSetForest
{
	struct Node
	{
		ui parent;
		ui rank;
	};

	const ui n;
	ui k;
	Node* const nodes;

	inline DisjointSetForest(ui n) :
		n(n),
		k(n),
		nodes(new Node[n])
	{
		loop(0, n, i)
		{
			nodes[i] = { i, 0 };
		}
	}

	inline ~DisjointSetForest()
	{
		delete[] nodes;
	}

	inline constexpr ui& Parent(ui x)
	{
		return nodes[x].parent;
	}

	inline constexpr ui& Rank(ui x)
	{
		return nodes[x].rank;
	}

	inline ui Find(ui x)
	{
		while (x != Parent(x))
		{
			Parent(x) = Parent(Parent(x));
			x = Parent(x);
		}
		return x;
	}

	inline void Union(ui x, ui y)
	{
		x = Find(x);
		y = Find(y);

		if (x == y)
		{
			return;
		}

		if (Rank(x) < Rank(y))
		{
			swap(x, y);
		}

		Parent(y) = x;
		if (Rank(x) == Rank(y))
		{
			Rank(x)++;
		}

		k--;
	}
};

template<class T>
struct Point
{
	T x, y;

	inline constexpr Point<T> operator+(const Point<T>& p) const
	{
		return { x + p.x, y + p.y };
	}

	inline constexpr Point<T> operator-(const Point<T>& p) const
	{
		return { x - p.x, y - p.y };
	}

	inline constexpr T operator*(const Point<T>& p) const
	{
		return x * p.x + y * p.y;
	}

	inline constexpr T operator^(const Point<T>& p) const
	{
		return x * p.y - y * p.x;
	}

	inline constexpr bool operator<(const Point<T>& p) const
	{
		return x < p.x || x == p.x && y < p.y;
	}
};

template<class T>
struct Segment
{
	Point<T> a, b;

	inline constexpr bool merge(Segment<T>& o)
	{
		Point<T> r = (b - a);
		Point<T> s = (o.b - o.a);
		Point<T> d = (o.a - a);
		T rs = (r ^ s);
		T dr = (d ^ r);
		T ds = (d ^ s);
		if (!(rs || dr))
		{
			T mag2 = r * r;
			T t0n = d * r;
			T t1n = (d + s) * r;
			if (t0n <= mag2 && t1n >= 0)
			{
				if (t0n >= 0)
				{
					o.a = a;
				}
				if (t1n <= mag2)
				{
					o.b = b;
				}
				return true;
			}
		}
		return false;
	}

	inline constexpr bool operator&(const Segment<T>& o)
	{
		Point<T> r = (b - a);
		Point<T> s = (o.b - o.a);
		Point<T> d = (o.a - a);
		T rs = (r ^ s);
		T dr = (d ^ r);
		T ds = (d ^ s);
		if (rs)
		{
			if (rs < 0)
			{
				rs = -rs;
				ds = -ds;
				dr = -dr;
			}
			if (ds >= 0 && ds <= rs && dr >= 0 && dr <= rs)
			{
				return true;
			}
		}
		return false;
	}
};

Segment<ll>* S;
ui* I;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ui n;
	cin >> n;

	S = new Segment<ll>[n];
	I = new ui[n]{ 0 };

	ll dCt = 0;
	loop(0, n, i)
	{
		Segment<ll>& s = S[dCt];
		cin >> s.a.x >> s.a.y >> s.b.x >> s.b.y;
		if (s.b < s.a)
		{
			swap(s.a, s.b);
		}
		bool m = false;
		loop(0, dCt, j)
		{
			if (s.merge(S[j]))
			{
				m = true;
				break;
			}
		}
		if (!m)
		{
			dCt++;
		}
	}

	DisjointSetForest dsf(dCt);

	// e - v
	ll r = -dCt;

	loop(1, dCt, i)
	{
		loop(0, i, j)
		{
			if (S[i] & S[j])
			{
				r++;
				dsf.Union(i, j);
			}
		}
	}

	cout << dsf.k + r;

	return 0;
}