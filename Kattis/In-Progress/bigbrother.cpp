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

typedef bool                       bi;
typedef char                       ci;
typedef unsigned char              uci;
typedef frac<ci>                   fci;
typedef frac<uci>                  fuci;
typedef short                      si;
typedef unsigned short             usi;
typedef frac<si>                   fsi;
typedef frac<usi>                  fusi;
typedef int                        li;
typedef unsigned                   uli;
typedef frac<li>                   fli;
typedef frac<uli>                  fuli;
typedef long long                  lli;
typedef unsigned long long         ulli;
typedef frac<lli>                  flli;
typedef frac<ulli>                 fulli;
typedef float                      sf;
typedef double                     df;
typedef long double                ldf;

typedef pair<bi, bi>               pbi;
typedef pair<ci, ci>               pci;
typedef pair<uci, uci>             puci;
typedef pair<fci, fci>             pfci;
typedef pair<fuci, fuci>           pfuci;
typedef pair<si, si>               psi;
typedef pair<usi, usi>             pusi;
typedef pair<fsi, fsi>             pfsi;
typedef pair<fusi, fusi>           pfusi;
typedef pair<li, li>               pli;
typedef pair<uli, uli>             puli;
typedef pair<fli, fli>             pfli;
typedef pair<fuli, fuli>           pfuli;
typedef pair<lli, lli>             plli;
typedef pair<ulli, ulli>           pulli;
typedef pair<flli, flli>           pflli;
typedef pair<fulli, fulli>         pfulli;
typedef pair<sf, sf>               psf;
typedef pair<df, df>               pdf;
typedef pair<ldf, ldf>             pldf;

typedef vector<bi>                 vbi;
typedef vector<ci>                 vci;
typedef vector<uci>                vuci;
typedef vector<fci>                vfci;
typedef vector<fuci>               vfuci;
typedef vector<si>                 vsi;
typedef vector<usi>                vusi;
typedef vector<fsi>                vfsi;
typedef vector<fusi>               vfusi;
typedef vector<li>                 vli;
typedef vector<uli>                vuli;
typedef vector<fli>                vfli;
typedef vector<fuli>               vfuli;
typedef vector<lli>                vlli;
typedef vector<ulli>               vulli;
typedef vector<flli>               vflli;
typedef vector<fulli>              vfulli;
typedef vector<sf>                 vsf;
typedef vector<df>                 vdf;
typedef vector<ldf>                vldf;

typedef vector<pbi>                vpbi;
typedef vector<pci>                vpci;
typedef vector<puci>               vpuci;
typedef vector<pfci>               vpfci;
typedef vector<pfuci>              vpfuci;
typedef vector<psi>                vpsi;
typedef vector<pusi>               vpusi;
typedef vector<pfsi>               vpfsi;
typedef vector<pfusi>              vpfusi;
typedef vector<pli>                vpli;
typedef vector<puli>               vpuli;
typedef vector<pfli>               vpfli;
typedef vector<pfuli>              vpfuli;
typedef vector<plli>               vplli;
typedef vector<pulli>              vpulli;
typedef vector<pflli>              vpflli;
typedef vector<pfulli>             vpfulli;
typedef vector<psf>                vpsf;
typedef vector<pdf>                vpdf;
typedef vector<pldf>               vpldf;

typedef vector<vbi>                 vvbi;
typedef vector<vci>                 vvci;
typedef vector<vuci>                vvuci;
typedef vector<vfci>                vvfci;
typedef vector<vfuci>               vvfuci;
typedef vector<vsi>                 vvsi;
typedef vector<vusi>                vvusi;
typedef vector<vfsi>                vvfsi;
typedef vector<vfusi>               vvfusi;
typedef vector<vli>                 vvli;
typedef vector<vuli>                vvuli;
typedef vector<vfli>                vvfli;
typedef vector<vfuli>               vvfuli;
typedef vector<vlli>                vvlli;
typedef vector<vulli>               vvulli;
typedef vector<vflli>               vvflli;
typedef vector<vfulli>              vvfulli;
typedef vector<vsf>                 vvsf;
typedef vector<vdf>                 vvdf;
typedef vector<vldf>                vvldf;

typedef vector<vpbi>                vvpbi;
typedef vector<vpci>                vvpci;
typedef vector<vpuci>               vvpuci;
typedef vector<vpfci>               vvpfci;
typedef vector<vpfuci>              vvpfuci;
typedef vector<vpsi>                vvpsi;
typedef vector<vpusi>               vvpusi;
typedef vector<vpfsi>               vvpfsi;
typedef vector<vpfusi>              vvpfusi;
typedef vector<vpli>                vvpli;
typedef vector<vpuli>               vvpuli;
typedef vector<vpfli>               vvpfli;
typedef vector<vpfuli>              vvpfuli;
typedef vector<vplli>               vvplli;
typedef vector<vpulli>              vvpulli;
typedef vector<vpflli>              vvpflli;
typedef vector<vpfulli>             vvpfulli;
typedef vector<vpsf>                vvpsf;
typedef vector<vpdf>                vvpdf;
typedef vector<vpldf>               vvpldf;

typedef set<bi>                    sbi;
typedef set<ci>                    sci;
typedef set<uci>                   suci;
typedef set<fci>                   sfci;
typedef set<fuci>                  sfuci;
typedef set<si>                    ssi;
typedef set<usi>                   susi;
typedef set<fsi>                   sfsi;
typedef set<fusi>                  sfusi;
typedef set<li>                    sli;
typedef set<uli>                   suli;
typedef set<fli>                   sfli;
typedef set<fuli>                  sfuli;
typedef set<lli>                   slli;
typedef set<ulli>                  sulli;
typedef set<flli>                  sflli;
typedef set<fulli>                 sfulli;
typedef set<sf>                    ssf;
typedef set<df>                    sdf;
typedef set<ldf>                   sldf;

typedef set<pbi>                   spbi;
typedef set<pci>                   spci;
typedef set<puci>                  spuci;
typedef set<pfci>                  spfci;
typedef set<pfuci>                 spfuci;
typedef set<psi>                   spsi;
typedef set<pusi>                  spusi;
typedef set<pfsi>                  spfsi;
typedef set<pfusi>                 spfusi;
typedef set<pli>                   spli;
typedef set<puli>                  spuli;
typedef set<pfli>                  spfli;
typedef set<pfuli>                 spfuli;
typedef set<plli>                  splli;
typedef set<pulli>                 spulli;
typedef set<pflli>                 spflli;
typedef set<pfulli>                spfulli;
typedef set<psf>                   spsf;
typedef set<pdf>                   spdf;
typedef set<pldf>                  spldf;

typedef multiset<bi>               msbi;
typedef multiset<ci>               msci;
typedef multiset<uci>              msuci;
typedef multiset<fci>              msfci;
typedef multiset<fuci>             msfuci;
typedef multiset<si>               mssi;
typedef multiset<usi>              msusi;
typedef multiset<fsi>              msfsi;
typedef multiset<fusi>             msfusi;
typedef multiset<li>               msli;
typedef multiset<uli>              msuli;
typedef multiset<fli>              msfli;
typedef multiset<fuli>             msfuli;
typedef multiset<lli>              mslli;
typedef multiset<ulli>             msulli;
typedef multiset<flli>             msflli;
typedef multiset<fulli>            msfulli;
typedef multiset<sf>               mssf;
typedef multiset<df>               msdf;
typedef multiset<ldf>              msldf;

typedef multiset<pbi>              mspbi;
typedef multiset<pci>              mspci;
typedef multiset<puci>             mspuci;
typedef multiset<pfci>             mspfci;
typedef multiset<pfuci>            mspfuci;
typedef multiset<psi>              mspsi;
typedef multiset<pusi>             mspusi;
typedef multiset<pfsi>             mspfsi;
typedef multiset<pfusi>            mspfusi;
typedef multiset<pli>              mspli;
typedef multiset<puli>             mspuli;
typedef multiset<pfli>             mspfli;
typedef multiset<pfuli>            mspfuli;
typedef multiset<plli>             msplli;
typedef multiset<pulli>            mspulli;
typedef multiset<pflli>            mspflli;
typedef multiset<pfulli>           mspfulli;
typedef multiset<psf>              mspsf;
typedef multiset<pdf>              mspdf;
typedef multiset<pldf>             mspldf;

typedef unordered_multiset<bi>     umsbi;
typedef unordered_multiset<ci>     umsci;
typedef unordered_multiset<uci>    umsuci;
typedef unordered_multiset<fci>    umsfci;
typedef unordered_multiset<fuci>   umsfuci;
typedef unordered_multiset<si>     umssi;
typedef unordered_multiset<usi>    umsusi;
typedef unordered_multiset<fsi>    umsfsi;
typedef unordered_multiset<fusi>   umsfusi;
typedef unordered_multiset<li>     umsli;
typedef unordered_multiset<uli>    umsuli;
typedef unordered_multiset<fli>    umsfli;
typedef unordered_multiset<fuli>   umsfuli;
typedef unordered_multiset<lli>    umslli;
typedef unordered_multiset<ulli>   umsulli;
typedef unordered_multiset<flli>   umsflli;
typedef unordered_multiset<fulli>  umsfulli;
typedef unordered_multiset<sf>     umssf;
typedef unordered_multiset<df>     umsdf;
typedef unordered_multiset<ldf>    umsldf;

typedef unordered_multiset<pbi>    umspbi;
typedef unordered_multiset<pci>    umspci;
typedef unordered_multiset<puci>   umspuci;
typedef unordered_multiset<pfci>   umspfci;
typedef unordered_multiset<pfuci>  umspfuci;
typedef unordered_multiset<psi>    umspsi;
typedef unordered_multiset<pusi>   umspusi;
typedef unordered_multiset<pfsi>   umspfsi;
typedef unordered_multiset<pfusi>  umspfusi;
typedef unordered_multiset<pli>    umspli;
typedef unordered_multiset<puli>   umspuli;
typedef unordered_multiset<pfli>   umspfli;
typedef unordered_multiset<pfuli>  umspfuli;
typedef unordered_multiset<plli>   umsplli;
typedef unordered_multiset<pulli>  umspulli;
typedef unordered_multiset<pflli>  umspflli;
typedef unordered_multiset<pfulli> umspfulli;
typedef unordered_multiset<psf>    umspsf;
typedef unordered_multiset<pdf>    umspdf;
typedef unordered_multiset<pldf>   umspldf;

typedef unordered_set<bi>          usbi;
typedef unordered_set<ci>          usci;
typedef unordered_set<uci>         usuci;
typedef unordered_set<fci>         usfci;
typedef unordered_set<fuci>        usfuci;
typedef unordered_set<si>          ussi;
typedef unordered_set<usi>         ususi;
typedef unordered_set<fsi>         usfsi;
typedef unordered_set<fusi>        usfusi;
typedef unordered_set<li>          usli;
typedef unordered_set<uli>         usuli;
typedef unordered_set<fli>         usfli;
typedef unordered_set<fuli>        usfuli;
typedef unordered_set<lli>         uslli;
typedef unordered_set<ulli>        usulli;
typedef unordered_set<flli>        usflli;
typedef unordered_set<fulli>       usfulli;
typedef unordered_set<sf>          ussf;
typedef unordered_set<df>          usdf;
typedef unordered_set<ldf>         usldf;

typedef unordered_set<pbi>         uspbi;
typedef unordered_set<pci>         uspci;
typedef unordered_set<puci>        uspuci;
typedef unordered_set<pfci>        uspfci;
typedef unordered_set<pfuci>       uspfuci;
typedef unordered_set<psi>         uspsi;
typedef unordered_set<pusi>        uspusi;
typedef unordered_set<pfsi>        uspfsi;
typedef unordered_set<pfusi>       uspfusi;
typedef unordered_set<pli>         uspli;
typedef unordered_set<puli>        uspuli;
typedef unordered_set<pfli>        uspfli;
typedef unordered_set<pfuli>       uspfuli;
typedef unordered_set<plli>        usplli;
typedef unordered_set<pulli>       uspulli;
typedef unordered_set<pflli>       uspflli;
typedef unordered_set<pfulli>      uspfulli;
typedef unordered_set<psf>         uspsf;
typedef unordered_set<pdf>         uspdf;
typedef unordered_set<pldf>        uspldf;

typedef stack<bi>                  stbi;
typedef stack<ci>                  stci;
typedef stack<uci>                 stuci;
typedef stack<fci>                 stfci;
typedef stack<fuci>                stfuci;
typedef stack<si>                  stsi;
typedef stack<usi>                 stusi;
typedef stack<fsi>                 stfsi;
typedef stack<fusi>                stfusi;
typedef stack<li>                  stli;
typedef stack<uli>                 stuli;
typedef stack<fli>                 stfli;
typedef stack<fuli>                stfuli;
typedef stack<lli>                 stlli;
typedef stack<ulli>                stulli;
typedef stack<flli>                stflli;
typedef stack<fulli>               stfulli;
typedef stack<sf>                  stsf;
typedef stack<df>                  stdf;
typedef stack<ldf>                 stldf;

typedef stack<pbi>                 stpbi;
typedef stack<pci>                 stpci;
typedef stack<puci>                stpuci;
typedef stack<pfci>                stpfci;
typedef stack<pfuci>               stpfuci;
typedef stack<psi>                 stpsi;
typedef stack<pusi>                stpusi;
typedef stack<pfsi>                stpfsi;
typedef stack<pfusi>               stpfusi;
typedef stack<pli>                 stpli;
typedef stack<puli>                stpuli;
typedef stack<pfli>                stpfli;
typedef stack<pfuli>               stpfuli;
typedef stack<plli>                stplli;
typedef stack<pulli>               stpulli;
typedef stack<pflli>               stpflli;
typedef stack<pfulli>              stpfulli;
typedef stack<psf>                 stpsf;
typedef stack<pdf>                 stpdf;
typedef stack<pldf>                stpldf;

typedef queue<bi>                  qbi;
typedef queue<ci>                  qci;
typedef queue<uci>                 quci;
typedef queue<fci>                 qfci;
typedef queue<fuci>                qfuci;
typedef queue<si>                  qsi;
typedef queue<usi>                 qusi;
typedef queue<fsi>                 qfsi;
typedef queue<fusi>                qfusi;
typedef queue<li>                  qli;
typedef queue<uli>                 quli;
typedef queue<fli>                 qfli;
typedef queue<fuli>                qfuli;
typedef queue<lli>                 qlli;
typedef queue<ulli>                qulli;
typedef queue<flli>                qflli;
typedef queue<fulli>               qfulli;
typedef queue<sf>                  qsf;
typedef queue<df>                  qdf;
typedef queue<ldf>                 qldf;

typedef queue<pbi>                 qpbi;
typedef queue<pci>                 qpci;
typedef queue<puci>                qpuci;
typedef queue<pfci>                qpfci;
typedef queue<pfuci>               qpfuci;
typedef queue<psi>                 qpsi;
typedef queue<pusi>                qpusi;
typedef queue<pfsi>                qpfsi;
typedef queue<pfusi>               qpfusi;
typedef queue<pli>                 qpli;
typedef queue<puli>                qpuli;
typedef queue<pfli>                qpfli;
typedef queue<pfuli>               qpfuli;
typedef queue<plli>                qplli;
typedef queue<pulli>               qpulli;
typedef queue<pflli>               qpflli;
typedef queue<pfulli>              qpfulli;
typedef queue<psf>                 qpsf;
typedef queue<pdf>                 qpdf;
typedef queue<pldf>                qpldf;

typedef deque<bi>                  dbi;
typedef deque<ci>                  dci;
typedef deque<uci>                 duci;
typedef deque<fci>                 dfci;
typedef deque<fuci>                dfuci;
typedef deque<si>                  dsi;
typedef deque<usi>                 dusi;
typedef deque<fsi>                 dfsi;
typedef deque<fusi>                dfusi;
typedef deque<li>                  dli;
typedef deque<uli>                 duli;
typedef deque<fli>                 dfli;
typedef deque<fuli>                dfuli;
typedef deque<lli>                 dlli;
typedef deque<ulli>                dulli;
typedef deque<flli>                dflli;
typedef deque<fulli>               dfulli;
typedef deque<sf>                  dsf;
typedef deque<df>                  ddf;
typedef deque<ldf>                 dldf;

typedef deque<pbi>                 dpbi;
typedef deque<pci>                 dpci;
typedef deque<puci>                dpuci;
typedef deque<pfci>                dpfci;
typedef deque<pfuci>               dpfuci;
typedef deque<psi>                 dpsi;
typedef deque<pusi>                dpusi;
typedef deque<pfsi>                dpfsi;
typedef deque<pfusi>               dpfusi;
typedef deque<pli>                 dpli;
typedef deque<puli>                dpuli;
typedef deque<pfli>                dpfli;
typedef deque<pfuli>               dpfuli;
typedef deque<plli>                dplli;
typedef deque<pulli>               dpulli;
typedef deque<pflli>               dpflli;
typedef deque<pfulli>              dpfulli;
typedef deque<psf>                 dpsf;
typedef deque<pdf>                 dpdf;
typedef deque<pldf>                dpldf;

typedef priority_queue<bi>         pqbi;
typedef priority_queue<ci>         pqci;
typedef priority_queue<uci>        pquci;
typedef priority_queue<fci>        pqfci;
typedef priority_queue<fuci>       pqfuci;
typedef priority_queue<si>         pqsi;
typedef priority_queue<usi>        pqusi;
typedef priority_queue<fsi>        pqfsi;
typedef priority_queue<fusi>       pqfusi;
typedef priority_queue<li>         pqli;
typedef priority_queue<uli>        pquli;
typedef priority_queue<fli>        pqfli;
typedef priority_queue<fuli>       pqfuli;
typedef priority_queue<lli>        pqlli;
typedef priority_queue<ulli>       pqulli;
typedef priority_queue<flli>       pqflli;
typedef priority_queue<fulli>      pqfulli;
typedef priority_queue<sf>         pqsf;
typedef priority_queue<df>         pqdf;
typedef priority_queue<ldf>        pqldf;

typedef priority_queue<pbi>        pqpbi;
typedef priority_queue<pci>        pqpci;
typedef priority_queue<puci>       pqpuci;
typedef priority_queue<pfci>       pqpfci;
typedef priority_queue<pfuci>      pqpfuci;
typedef priority_queue<psi>        pqpsi;
typedef priority_queue<pusi>       pqpusi;
typedef priority_queue<pfsi>       pqpfsi;
typedef priority_queue<pfusi>      pqpfusi;
typedef priority_queue<pli>        pqpli;
typedef priority_queue<puli>       pqpuli;
typedef priority_queue<pfli>       pqpfli;
typedef priority_queue<pfuli>      pqpfuli;
typedef priority_queue<plli>       pqplli;
typedef priority_queue<pulli>      pqpulli;
typedef priority_queue<pflli>      pqpflli;
typedef priority_queue<pfulli>     pqpfulli;
typedef priority_queue<psf>        pqpsf;
typedef priority_queue<pdf>        pqpdf;
typedef priority_queue<pldf>       pqpldf;

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

//	vpldf points(n);
//	// Avoid vertical lines:
//	{
//		vpldf ogPoints(n);
//		loop(0, n, i)
//		{
//			cin >> ogPoints[i].x >> ogPoints[i].y;
//		}
//		sldf angles;
//		ldf angle = atanl((ogPoints[0].y - ogPoints[n - 1].y) / (ogPoints[0].x - ogPoints[n - 1].x));
//		if (angle < 0)
//		{
//			angle += PI;
//		}
//		angles.insert(angle);
//		angles.insert(angle + PI);
//
//		loop(1, n, i)
//		{
//			angle = atanl((ogPoints[i].y - ogPoints[i - 1].y) / (ogPoints[i].x - ogPoints[i - 1].x));
//			if (angle < 0)
//			{
//				angle += PI;
//			}
//			angles.insert(angle);
//			angles.insert(angle + PI);
//		}
//
//		ldf maxGap = 0;
//		sldf::const_iterator maxGapIter = angles.cbegin();
//		ldf prev = *angles.cend() - 2 * PI;
//		for (sldf::const_iterator iter = angles.cbegin(); iter != angles.cend(); iter++)
//		{
//			ldf cur = *iter;
//			ldf gap = cur - prev;
//			if (gap > maxGap)
//			{
//				maxGap = gap;
//				maxGapIter = iter;
//			}
//			prev = cur;
//		}
//
//		ldf rot = 0.5 * (PI + maxGap) - *maxGapIter;
//		ldf s = sin(rot), c = cos(rot);
//		loop(0, n, i)
//		{
//			pldf og = ogPoints[i];
//			points[i] = { og.x * c - og.y * s, og.y * c + og.x * s };
//		}
//	}

//#define x first
//#define y second

//inline const ldf PI = atanl(1) * 4;

struct Point
{
	ldf x, y;

	inline Point() {}
	inline constexpr Point(ldf x, ldf y) : x(x), y(y) {}
};

inline constexpr Point& minx(Point& a, Point& b)
{
	return a.x <= b.x ? a : b;
}
inline constexpr const Point& minx(const Point& a, const Point& b)
{
	return a.x <= b.x ? a : b;
}
inline constexpr Point& miny(Point& a, Point& b)
{
	return a.y <= b.y ? a : b;
}
inline constexpr const Point& miny(const Point& a, const Point& b)
{
	return a.y <= b.y ? a : b;
}
inline constexpr Point& maxx(Point& a, Point& b)
{
	return a.x >= b.x ? a : b;
}
inline constexpr const Point& maxx(const Point& a, const Point& b)
{
	return a.x >= b.x ? a : b;
}
inline constexpr Point& maxy(Point& a, Point& b)
{
	return a.y >= b.y ? a : b;
}
inline constexpr const Point& maxy(const Point& a, const Point& b)
{
	return a.y >= b.y ? a : b;
}

typedef vector<Point> Envelope;
typedef pair<Envelope, Envelope> Polygon;
// {lower, upper}

uli n;
vector<Point> points;

#define S 10000000

#define SAME(dim) (b.dim == 0)
#define BOTH(dim, val) (r0.dim == (val) && r1.dim == (val))
#define BOUND(val) ((val) >= 0 && (val) < S)

inline Polygon emptyPgon()
{
	return { {}, {} };
}

inline Polygon fullPgon()
{
	return { { {0, 0}, {S, 0} }, { {0, S}, {S, S} } };
}

//inline void remDupes(Envelope* env)
//{
//
//}
//
//inline Polygon& remDupes(Polygon& pgon)
//{
//	remDupes(&pgon.first);
//	remDupes(&pgon.second);
//	return pgon;
//}

// last >= first
Polygon hPlaneIsect(uli first, uli last)
{
	if (last > first)
	{

	}
	else
	{
		Point r0 = points[(first > 0 ? first : n) - 1];
		Point r1 = points[first];

		if (BOTH(y, 0))
		{
			return r1.x > r0.x ? emptyPgon() : fullPgon();
		}
		else if (BOTH(x, S))
		{
			return r1.y > r0.y ? emptyPgon() : fullPgon();
		}
		else if (BOTH(y, S))
		{
			return r0.x > r1.x ? emptyPgon() : fullPgon();
		}
		else if (BOTH(x, 0))
		{
			return r0.y > r1.y ? emptyPgon() : fullPgon();
		}

		Point b = { r1.x - r0.x, r1.y - r0.y };

		bool d0 = false, d1 = false, d2 = false, d3 = false;

		uli f0, f1;
		ldf t0, t1;
		Point p0, p1;
		bool found = false;

		const ldf d = b.y * r0.x - b.x * r0.y;

		// vertices
		if (d == 0)
		{
			f0 = 0;
			t0 = 0;
			p0 = { 0, 0 };
			d0 = true;
			found = true;
		}
		if (d == b.y * S)
		{
			(found ? f1 : f0) = 2;
			(found ? t1 : t0) = S * b.x;
			(found ? p1 : p0) = { S, 0 };
			d1 = true;
			found = true;
		}
		if (d == (b.y - b.x) * S)
		{
			(found ? f1 : f0) = 4;
			(found ? t1 : t0) = S * (b.x + b.y);
			(found ? p1 : p0) = { S, S };
			d2 = true;
			found = true;
		}
		if (d == -b.x * S)
		{
			(found ? f1 : f0) = 6;
			(found ? t1 : t0) = S * b.y;
			(found ? p1 : p0) = { 0, S };
			d3 = true;
			found = true;
		}

		// edges
		if (!d0 && !d1 && !SAME(y))
		{
			ldf x = r0.x - b.x * r0.y / b.y;
			if (BOUND(x))
			{
				(found ? f1 : f0) = 1;
				(found ? t1 : t0) = x * b.x;
				(found ? p1 : p0) = { x, 0 };
				found = true;
			}
		}
		if (!d1 && !d2 && !SAME(x))
		{
			ldf y = r0.y + b.y * (S - r0.x) / b.x;
			if (BOUND(y))
			{
				(found ? f1 : f0) = 3;
				(found ? t1 : t0) = S * b.x + y * b.y;
				(found ? p1 : p0) = { S, y };
				found = true;
			}
		}
		if (!d2 && !d3 && !SAME(y))
		{
			ldf x = r0.x + b.x * (S - r0.y) / b.y;
			if (BOUND(x))
			{
				(found ? f1 : f0) = 5;
				(found ? t1 : t0) = x * b.x + S * b.y;
				(found ? p1 : p0) = { x, S };
			}
		}
		if (!d3 && !d0 && !SAME(x))
		{
			ldf y = r0.y - b.y * r0.x / b.x;
			if (BOUND(y))
			{
				f1 = 7;
				t1 = y * b.y;
				p1 = { 0, y };
			}
		}

		if (t1 < t0)
		{
			swap(f1, f0);
			swap(t1, t0);
			swap(p1.x, p0.x);
			swap(p1.y, p0.y);
		}

		switch (f0)
		{
		case 0:
			switch (f1)
			{
			case 3:
			case 4:
				return { {p0, {S, 0}}, {p0, p1} };
			case 5:
				return { {p0, {S, 0}}, {p0, p1, {S, S}} };
			}
		case 1:
			switch (f1)
			{
			case 3:
			case 4:
				return { {p0, {S, 0}}, {p0, p1} };
			case 5:
				if (p1.x > p0.x)
					return { {p0, {S, 0}}, {p0, p1, {S, S}} };
				else if (p1.x == p0.x)
					return { {p0, {S, 0}}, {p1, {S, S}} };
				else
					return { {p1, p0, {S, 0}}, {p1, {S, S}} };
			case 6:
			case 7:
				return { {p1, p0, {S, 0}}, {{0, S}, {S, S}} };
			}
		case 2:
			switch (f1)
			{
			case 5:
			case 6:
				return { {p1, p0}, {p1, {S, S}} };
			case 7:
				return { {p1, p0}, {{0, S}, {S, S}} };
			}
		case 3:
			switch (f1)
			{
			case 5:
			case 6:
				return { {p1, p0}, {p1, {S, S}} };
			case 7:
			case 0:
				return { {p1, p0}, {{0, S}, {S, S}} };
			case 1:
				return { {{0, 0}, p1, p0}, {{0, S}, {S, S}} };
			}
		case 4:
			switch (f1)
			{
			case 7:
			case 0:
				return { {p1, p0}, {{0, S}, {S, S}} };
			case 1:
				return { {{0, 0}, p1, p0}, {{0, S}, {S, S}} };
			}
		case 5:
			switch (f1)
			{
			case 7:
			case 0:
				return 
			case 1:
				if (p1.x > p0.x)
					;
				else if (p1.x == p0.x)
					;
				else
					;
			case 2:
			case 3:
			}
		case 6:
			switch (f1)
			{
			case 1:
			case 2:
			case 3:
			}
		case 7:
			switch (f1)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	points.reserve(n);

	loop(0, n, i)
	{
		uli x, y;
		cin >> x >> y;
		points.emplace_back(x, y);
	}

	Polygon pgon = hPlaneIsect(0, n - 1);


	return 0;
}