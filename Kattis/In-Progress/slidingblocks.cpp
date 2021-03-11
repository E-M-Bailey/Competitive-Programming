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

#ifdef _MSC_VER
inline int __builtin_clz(unsigned int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzl(unsigned long int value)
{
	return __lzcnt(value);
}
inline int __builtin_clzll(unsigned long long int value)
{
	return value & 0xffffffff00000000ull ? __lzcnt(value >> 32) : 32 + __lzcnt(value);
}
inline constexpr int __builtin_ctzll(unsigned long long int value);
inline constexpr int __builtin_ctz(unsigned int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzl(unsigned long int value)
{
	return __builtin_ctzll(value);
}
inline constexpr int __builtin_ctzll(unsigned long long int value)
{
	if (value == 0)
	{
		return 437; // undefined
	}
	int ctr = 0;
#define CTZ_SEGMENT(n) do { if (!(value & ((1ull << (n)) - 1))) { ctr |= (n); value >>= (n); } } while (0)
	CTZ_SEGMENT(1 << 5);
	CTZ_SEGMENT(1 << 4);
	CTZ_SEGMENT(1 << 3);
	CTZ_SEGMENT(1 << 2);
	CTZ_SEGMENT(1 << 1);
	CTZ_SEGMENT(1 << 0);
#undef CTZ_SEGMENT
	return ctr;
}
#endif

#define loop(m, n, i) for (uli i = (m); i < (n); i++)
#define rloop(m, n, i) for (uli i = (n); i-- > (m);)
#define loop_each(vec, i, x) auto x = vec.front(); for (uli i = 0; i < (vec).size(); i++, x = vec[i])
#define rloop_each(vec, i, x) auto x = vec.back(); for (uli i = (vec).size(); i-- > 0; x = vec[i - 1])

#define tCases() uli testCaseCount; cin >> testCaseCount; for (uli testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

#define endl '\n'

using namespace std;

template<class T>
struct frac;

typedef bool                 bi;
typedef char                 ci;
typedef unsigned char        uci;
typedef frac<ci>             fci;
typedef frac<uci>            fuci;
typedef short                si;
typedef unsigned short       usi;
typedef frac<si>             fsi;
typedef frac<usi>            fusi;
typedef int                  li;
typedef unsigned             uli;
typedef frac<li>             fli;
typedef frac<uli>            fuli;
typedef long long            lli;
typedef unsigned long long   ulli;
typedef frac<lli>            flli;
typedef frac<ulli>           fulli;
typedef float                sf;
typedef double               df;
typedef long double          ldf;

typedef pair<bi, bi>         pbi;
typedef pair<ci, ci>         pci;
typedef pair<uci, uci>       puci;
typedef pair<fci, fci>       pfci;
typedef pair<fuci, fuci>     pfuci;
typedef pair<si, si>         psi;
typedef pair<usi, usi>       pusi;
typedef pair<fsi, fsi>       pfsi;
typedef pair<fusi, fusi>     pfusi;
typedef pair<li, li>         pli;
typedef pair<uli, uli>       puli;
typedef pair<fli, fli>       pfli;
typedef pair<fuli, fuli>     pfuli;
typedef pair<lli, lli>       plli;
typedef pair<ulli, ulli>     pulli;
typedef pair<flli, flli>     pflli;
typedef pair<fulli, fulli>   pfulli;
typedef pair<sf, sf>         psf;
typedef pair<df, df>         pdf;
typedef pair<ldf, ldf>       pldf;

typedef vector<bi>           vbi;
typedef vector<ci>           vci;
typedef vector<uci>          vuci;
typedef vector<fci>          vfci;
typedef vector<fuci>         vfuci;
typedef vector<si>           vsi;
typedef vector<usi>          vusi;
typedef vector<fsi>          vfsi;
typedef vector<fusi>         vfusi;
typedef vector<li>           vli;
typedef vector<uli>          vuli;
typedef vector<fli>          vfli;
typedef vector<fuli>         vfuli;
typedef vector<lli>          vlli;
typedef vector<ulli>         vulli;
typedef vector<flli>         vflli;
typedef vector<fulli>        vfulli;
typedef vector<sf>           vsf;
typedef vector<df>           vdf;
typedef vector<ldf>          vldf;

typedef vector<pbi>          vpbi;
typedef vector<pci>          vpci;
typedef vector<puci>         vpuci;
typedef vector<pfci>         vpfci;
typedef vector<pfuci>        vpfuci;
typedef vector<psi>          vpsi;
typedef vector<pusi>         vpusi;
typedef vector<pfsi>         vpfsi;
typedef vector<pfusi>        vpfusi;
typedef vector<pli>          vpli;
typedef vector<puli>         vpuli;
typedef vector<pfli>         vpfli;
typedef vector<pfuli>        vpfuli;
typedef vector<plli>         vplli;
typedef vector<pulli>        vpulli;
typedef vector<pflli>        vpflli;
typedef vector<pfulli>       vpfulli;
typedef vector<psf>          vpsf;
typedef vector<pdf>          vpdf;
typedef vector<pldf>         vpldf;

template<class T, class Container = vector<T>>
using max_heap = priority_queue<T, Container, less<T>>;

template<class T, class Container = vector<T>>
using min_heap = priority_queue<T, Container, greater<T>>;

#define MIN(T) (numeric_limits<T>::min())
#define MAX(T) (numeric_limits<T>::max())

inline constexpr uli gcd(uli l, uli r)
{
	if (!(l && r))
	{
		return l | r;
	}
	int s = __builtin_ctz(l | r);
	l >>= __builtin_ctz(l);
	do
	{
		r >>= __builtin_ctz(r);
		if (l > r)
		{
			swap(l, r);
		}
		r -= l;
	}
	while (r);
	return l << s;
}

inline constexpr ulli gcd(ulli l, ulli r)
{
	if (!(l && r))
	{
		return l | r;
	}
	int s = __builtin_ctzll(l | r);
	l >>= __builtin_ctzll(l);
	do
	{
		r >>= __builtin_ctzll(r);
		if (l > r)
		{
			swap(l, r);
		}
		r -= l;
	}
	while (r);
	return l << s;
}

template<class T>
struct frac
{
	using N = T;
	using D = make_unsigned_t<T>;

	N n;
	D d;

	inline constexpr frac r() const
	{
		D g = gcd(abs(n), d);
		return { n / g, d / g };
	}

	inline constexpr frac i() const
	{
		return n < 0 ? frac{ -(N)d, (D)-n } : frac{ (N)d, (D)n };
	}

	inline constexpr frac operator+() const
	{
		return { n, d };
	}

	inline constexpr frac operator-() const
	{
		return { -n, d };
	}

	inline constexpr frac operator+(const frac& f) const
	{
		return { n * (N)f.d + f.n * (N)d, d * f.d };
	}

	inline constexpr frac operator-(const frac& f) const
	{
		return { n * (N)f.d - f.n * (N)d, d * f.d };
	}

	inline constexpr frac operator*(const frac& f) const
	{
		return { n * f.n, d * f.d };
	}

	inline constexpr frac operator/(const frac& r) const
	{
		return n < 0 ? frac{ n * -(N)r.d, d * (D)-r.n } : frac{ n * (N)r.d, d * (D)r.n };
	}

	template<class S>
	inline constexpr frac operator<<(const S& s)
	{
		return { n << s, d };
	}

	template<class S>
	inline constexpr frac operator>>(const S& s)
	{
		return { n, d << s };
	}

	inline constexpr bool operator==(const frac& f)
	{
		return n * f.d == f.n * d;
	}

	inline constexpr bool operator!=(const frac& f)
	{
		return n * f.d != f.n * d;
	}

	inline constexpr bool operator<(const frac& f)
	{
		return n * f.d < f.n * d;
	}

	inline constexpr bool operator<=(const frac& f)
	{
		return n * f.d <= f.n * d;
	}

	inline constexpr bool operator>(const frac& f)
	{
		return n * f.d > f.n * d;
	}

	inline constexpr bool operator>=(const frac& f)
	{
		return n * f.d >= f.n * d;
	}

	inline constexpr operator bool() const
	{
		return d;
	}

	template<class S>
	inline constexpr explicit operator frac<S>() const
	{
		return frac<S>{ (typename frac<S>::N)n, (typename frac<S>::D)(d) };
	}
};

struct point
{
	uli x, y;

	inline constexpr bool operator==(const point& p) const
	{
		return x == p.x && y == p.y;
	}

	inline constexpr point operator+(const point& p) const
	{
		return { x + p.x, y + p.y };
	}
};

namespace std
{
	template<>
	struct hash<point>
	{
		inline constexpr size_t operator()(const point& p) const
		{
			return p.x ^ p.y;
		}

	};
}

enum NodeType
{
	DEF = 0,
	U = 1,
	D = 2,
	L = 3,
	R = 4,
	ROOT = 5
};

const pair<NodeType, point> dir[4]{ { U, { 0, MAX(uli) } }, { D, { 0, 1 } }, { L, { MAX(uli), 0 } }, { R, { 1, 0 } } };

static uli dummy = 0;

struct node
{
	point pos;
	NodeType type;
	uli p, u, d, l, r;
	uli children;

	inline constexpr uli& operator[](NodeType type)
	{
		switch (type)
		{
		case U:
			return u;
		case D:
			return d;
		case L:
			return l;
		case R:
			return r;
		default:
			return dummy;
		}
	}
};

struct bfsEntry
{
	uli index;
	uli parent;
	NodeType type;
};

struct action
{
	NodeType type;
	uli coord;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uli N, M, B;
	cin >> N >> M >> B;

	vector<deque<uli>> rows(N), cols(M);
	unordered_map<point, uli> target;
	vector<node> tree;
	tree.reserve(B);
	loop(0, B, i)
	{
		point p;
		cin >> p.y >> p.x;
		p.x--;
		p.y--;
		target[p] = i;
		rows[p.y].push_back(p.x);
		cols[p.x].push_back(p.y);
		tree.push_back({ p, DEF, 0, 0, 0, 0, 0 });
	}
	for (deque<uli>& row : rows)
	{
		sort(row.begin(), row.end());
	}
	for (deque<uli>& col : cols)
	{
		sort(col.begin(), col.end());
	}

	vector<action> actions;

	queue<uli> leaves, nextLeaves;
	queue<bfsEntry> q;
	q.push({ 0, 0, ROOT });
	while (!q.empty())
	{
		bfsEntry entry = q.front();
		q.pop();
		node& cur = tree[entry.index];
		if (cur.type != DEF)
		{
			continue;
		}
		node& par = tree[entry.parent];

		par[entry.type] = entry.index;
		if (entry.type != ROOT)
		{
			par.children++;
		}
		cur.p = entry.parent;
		cur.type = entry.type;

		for (const pair<NodeType, point>& d : dir)
		{
			point next = cur.pos + d.second;
			decltype(target)::iterator iter = target.find(next);
			if (iter != target.end())
			{
				q.push({ iter->second, entry.index, d.first });
			}
		}
	}

	loop(0, B, i)
	{
		if (tree[i].children == 0)
		{
			leaves.push(i);
		}
	}

	bool done = false;
	bool stuck = false;
	while (!(done || stuck))
	{
		stuck = true;
		while (!leaves.empty())
		{
			uli idx = leaves.front();
			leaves.pop();

			node& cur = tree[idx];
			node& par = tree[cur.p];

			point tr = cur.pos;
			deque<uli>* rowCol = nullptr;
			deque<uli>::iterator iter;

			switch (cur.type)
			{
			case U:
				rowCol = &cols[tr.x];
				iter = rowCol->begin();
				break;
			case D:
				rowCol = &cols[tr.x];
				iter = rowCol->end() - 1;
				break;
			case L:
				swap(tr.x, tr.y);
				rowCol = &rows[tr.x];
				iter = rowCol->begin();
				break;
			case R:
				swap(tr.x, tr.y);
				rowCol = &rows[tr.x];
				iter = rowCol->end() - 1;
				break;
			default:
				done = true;
				break;
			}

			if (done)
			{
				stuck = false;
				break;
			}
			if (tr.y == *iter)
			{
				stuck = false;
				rowCol->erase(iter);
				actions.push_back({ cur.type, tr.x });
				if (--par.children == 0)
				{
					leaves.push(cur.p);
				}
			}
			else
			{
				nextLeaves.push(idx);
			}
		}
		swap(leaves, nextLeaves);
	}
	if (stuck)
	{
		cout << "impossible";
	}
	else
	{
		cout << "possible";
		while (!actions.empty())
		{
			cout << endl;
			action a = actions.back();
			actions.pop_back();
			switch (a.type)
			{
			case U:
				cout << "v ";
				break;
			case D:
				cout << "^ ";
				break;
			case L:
				cout << "> ";
				break;
			case R:
				cout << "< ";
				break;
			default:
				break;
			}
			cout << a.coord + 1;
		}
	}

	return 0;
}