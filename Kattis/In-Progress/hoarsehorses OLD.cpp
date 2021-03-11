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

inline constexpr ui gcd(ui l, ui r)
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

inline constexpr ull gcd(ull l, ull r)
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
struct Frac
{
	using N = T;
	using D = make_unsigned<S>;

	N n;
	D d;

	inline constexpr Frac r() const
	{
		D g = gcd(abs(n), d);
		return { n / g, d / g };
	}

	inline constexpr Frac i() const
	{
		return n < 0 ? Frac{ -(N)d, (D)-n } : Frac{ (N)d, (D)n };
	}

	inline constexpr Frac operator+() const
	{
		return { n, d }
	}

	inline constexpr Frac operator-() const
	{
		return { -n, d };
	}

	inline constexpr Frac operator-(const Frac& f) const
	{
		return { -f.n, f.d };
	}

	inline constexpr Frac operator+(const Frac& f) const
	{
		return { n * (N)f.d + f.n * (N)d, d * f.d };
	}

	inline constexpr Frac operator-(const Frac& f) const
	{
		return { n * (N)r.d - r.n * (N)d, d * r.d };
	}

	inline constexpr Frac operator*(const Frac& f) const
	{
		return { n * f.n, d * f.d };
	}

	inline constexpr Frac operator/(const Frac& r) const
	{
		return n < 0 ? { n * -(N)r.d, d * (D)-r.n } : { n * (N)r.d, d * (D)r.n };
	}

	template<class S>
	inline constexpr Frac operator<<(const S& s)
	{
		return { n << s, d };
	}

	template<class S>
	inline constexpr Frac operator>>(const S& s)
	{
		return { n, d << s };
	}

	inline constexpr bool operator==(const Frac& f)
	{
		return n * f.d == f.n * d;
	}

	inline constexpr bool operator!=(const Frac& f)
	{
		return n * f.d != f.n * d;
	}

	inline constexpr bool operator<(const Frac& f)
	{
		return n * f.d < f.n * d;
	}

	inline constexpr bool operator<=(const Frac& f)
	{
		return n * f.d <= f.n * d;
	}

	inline constexpr bool operator>(const Frac& f)
	{
		return n * f.d > f.n * d;
	}

	inline constexpr bool operator>=(const Frac& f)
	{
		return n * f.d >= f.n * d;
	}

	inline constexpr operator bool() const
	{
		return d;
	}

	template<class S>
	inline constexpr explicit operator Frac<S>() const
	{
		return Frac<S>{ (Frac<S>::N)n, (Frac<S>::D)d };
	}
};

struct Point
{
	Frac x, y;

	inline constexpr Point r() const
	{
		return { x.r(), y.r() };
	}
};

struct Segment
{
	Point a, b;

	inline constexpr Segment r()
	{
		return { a.r(), b.r() };
	}
};

enum class EventType
{
	START = 0,
	END = 1,
	INTERSECTION = 2
};

struct Event
{
	Point p;
	EventType t;
	ui a, b;
};

Point curPt;
inline constexpr Frac eval(const Segment& s)
{
	Frac m = ((s.b.y - s.a.y) / (s.b.x - s.a.x)).r();
	Frac b = s.a.y - m * s.a.x;
	return m * curPt.x + b;
}

Segment* S;

inline constexpr bool compSeg(ui l, ui r)
{
	// TODO allow vertical
	return eval(S[l]) < eval(S[r]);
}

struct Hash
{
	ull operator()(const Event* e) const
	{
		return (ull)e->t ^ e->p.x.n ^ e->p.x.d ^ e->p.y.n ^ e->p.y.d ^ (((ull)e->a << 32ull) | e->b);
	}
};

struct Equal
{
	inline constexpr bool operator()(const Event* l, const Event* r)
	{
		return *l == *r;
	}
};

priority_queue<Event*> Q;
unordered_set<Event*, Hash, Equal> U;
set<ui, decltype(compSeg)> SL(compSeg);
vector<Point> P;

inline constexpr bool operator==(const Point& l, const Point& r)
{
	return l.x == r.x && l.y == r.y;
}

inline constexpr bool operator==(const Segment& l, const Segment& r)
{
	return l.a == r.a && l.b == r.b;
}

inline constexpr bool operator==(const Event& l, const Event& r)
{
	return l.t == r.t && l.p == r.p;
}

inline constexpr bool operator<(const Point& l, const Point& r)
{
	return l.x < r.x || l.x == r.x && l.y < r.y;
}

inline constexpr bool operator<(const Segment& l, const Segment& r)
{
	return l.a < r.a || l.a == r.a && l.b < r.b;
}

inline constexpr bool operator<(const Event& l, const Event& r)
{
	return l.p < r.p || l.p == r.p && (l.t < r.t || l.t == r.t && (l.a < r.a || l.a == r.a && l.b < r.b));
}

inline constexpr Point operator+(const Point& l, const Point& r)
{
	return { l.x + r.x, l.y + r.y };
}

inline constexpr Point operator-(const Point& l, const Point& r)
{
	return { l.x - r.x, l.y - r.y };
}

inline constexpr Point operator*(Frac l, const Point& r)
{
	return { l * r.x, l * r.y };
}

inline constexpr Frac operator*(const Point& l, const Point& r)
{
	return l.x * r.x + l.y * r.y;
}

inline constexpr Frac operator^(const Point& l, const Point& r)
{
	return l.x * r.y - l.y * r.x;
}

inline constexpr Point intersect(const Segment& a, const Segment& b)
{
	Point r = (a.b - a.a);
	Point s = (b.b - b.a);
	Point d = (b.a - a.a);
	Frac rs = (r ^ s);
	Frac dr = (d ^ r);
	Frac ds = (d ^ s);
	if (rs.n)
	{
		Frac t = ds / rs;
		Frac u = dr / rs;
		if (t.n >= 0 && t.n <= t.d && u.n >= 0 && u.n <= u.d)
		{
			return a.a + t * r;
		}
	}
	else
	{
		if (!dr.n)
		{
			Frac mag2 = r * r;
			Frac t0 = d * r / mag2;
			Frac t1 = (d + s) * r / mag2;
			if (t0.n <= t0.d && t1.n >= 0)
			{
				return t0.n >= 0 ? b.a : b.b;
			}
		}
	}
	return { { 0, 0 }, { 0, 0 } };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ui n;
	cin >> n;

	S = new Segment[n];
	loop(0, n, i)
	{
		Segment& s = S[i];
		cin >> s.a.x.n >> s.a.y.n >> s.b.x.n >> s.b.y.n;
		s.a.x.d = s.a.y.d = s.b.x.d = s.b.y.d = 1;
		if (s.b < s.a)
		{
			swap(s.a, s.b);
		}
	}
	sort(S, S + n);

	loop(0, n, i)
	{
		Segment& seg = S[i];
		Q.push(new Event{ seg.a, EventType::START, i, UI_MAX });
		Q.push(new Event{ seg.b, EventType::END, i, UI_MAX });
	}

	curPt = S[0].a;

	unordered_set<Point> IL;

	while (!Q.empty())
	{
		Event& e = *Q.top();
		Q.pop();

		switch (e.t)
		{
		case EventType::START:
		{
			Segment se = S[e.a];
			decltype(SL)::iterator iter = SL.insert(e.a).first, prev = iter, post = iter;
			if (++post != SL.end())
			{
				Segment sa = S[*post];
				Point i = intersect(se, sa);
				if (i.x)
				{
					Event* ne = new Event{ i.r(), EventType::INTERSECTION, e.a, *post };
					Q.push(ne);
					U.insert(ne);
				}
			}
			if (prev-- != SL.begin())
			{
				Segment sb = S[*prev];
				Point i = intersect(sb, se);
				if (i.x)
				{
					Event* ne = new Event{ i.r(), EventType::INTERSECTION, *prev, e.a };
					Q.push(ne);
					U.insert(ne);
				}
			}
			break;
		}
		case EventType::END:
		{
			Segment se = S[e.a];
			decltype(SL)::iterator iter = SL.find(e.a), prev = iter, post = iter;
			if (++post != SL.end() && prev-- != SL.begin())
			{
				Segment sa = S[*post];
				Segment sb = S[*prev];
				Point i = intersect(sb, sa);
				if (i.x)
				{
					Event* ne = new Event{ i.r(), EventType::INTERSECTION, *prev, *post };
					if (U.insert(ne).second)
						Q.push(ne);
					else
						delete ne;
				}
			}

		}
		case EventType::INTERSECTION:
		{
			IL.insert(e.p);

		}
		}
		delete &e;
	}

	return 0;
}