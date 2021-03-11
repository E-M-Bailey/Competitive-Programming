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

namespace
{
	template<class T>
	struct Point
	{
		T x, y;
		inline constexpr Point() : x(), y() {}
		inline constexpr Point(const T& x, const T& y) : x(x), y(y) {}

		inline constexpr void swap(Point& other)
		{
			swap(x, other.x);
			swap(y, other.y);
		}

		template<class U>
		inline constexpr explicit operator Point<U>() const
		{
			return Point<U>(static_cast<U>(x), static_cast<U>(y));
		}

		template<class U>
		inline constexpr Point& operator=(const Point<U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);
			return *this;
		}

		template<class U>
		inline constexpr Point& operator+=(const Point<U>& other)
		{
			x = x + static_cast<T>(other.x);
			y = y + static_cast<T>(other.y);
			return *this;
		}

		template<class U>
		inline constexpr Point& operator-=(const Point<U>& other)
		{
			x = x - static_cast<T>(other.x);
			y = y - static_cast<T>(other.y);
			return *this;
		}

		template<class U>
		inline constexpr Point& operator*=(const U& factor)
		{
			x = x * static_cast<T>(factor);
			y = y * static_cast<T>(factor);
			return *this;
		}

		template<class U>
		inline constexpr Point& operator/=(const U& factor)
		{
			x = x / static_cast<T>(factor);
			y = y / static_cast<T>(factor);
			return *this;
		}

		inline constexpr operator bool() const
		{
			return x && y;
		}

	};

	template<class T>
	inline istream& operator>>(istream& stream, Point<T>& point)
	{
		return stream >> point.x >> point.y;
	}

	template<class T>
	inline ostream& operator<<(ostream& stream, const Point<T>& point)
	{
		return stream << point.x << ' ' << point.y;
	}

	template<class T>
	inline constexpr void swap(Point<T>& lhs, Point<T>& rhs)
	{
		lhs.swap(rhs);
	}

	template<class T>
	inline constexpr auto operator-(const Point<T>& point)
	{
		return { -point.x, -point.y };
	}

	template<class T, class U>
	inline constexpr auto operator+(const Point<T>& lhs, const Point<U>& rhs)
	{
		return { lhs.x + rhs.x, lhs.y + rhs.y };
	}

	template<class T, class U>
	inline constexpr auto operator-(const Point<T>& lhs, const Point<U>& rhs) -> Point<decltype(lhs.x - rhs.x)>
	{
		return { lhs.x - rhs.x, lhs.y - rhs.y };
	}

	template<class T, class U>
	inline constexpr auto operator*(const T& lhs, const Point<U>& rhs)
	{
		return { lhs * rhs.x, lhs * rhs.y };
	}

	template<class T, class U>
	inline constexpr auto operator*(const Point<T>& lhs, const U& rhs)
	{
		return { lhs.x * rhs, lhs.y * rhs };
	}

	template<class T, class U>
	inline constexpr auto operator/(const Point<T>& lhs, const U& rhs)
	{
		return { lhs.x / rhs, lhs.y / rhs };
	}

	// Dot Product
	template<class T, class U>
	inline constexpr auto operator*(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	// Cross Product
	// Positive iff rhs is ccw of lhs around the origin, negative iff cw, 0 if same or opposite orientation
	template<class T, class U>
	inline constexpr auto operator^(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	// Orientation
	// Positive iff a->b->c turns ccw, negative iff turns cw, 0 if maintains or reverses direction
	template<class T, class U, class V>
	inline constexpr auto orient(const Point<T>& a, const Point<U>& b, const Point<V>& c)
	{
		return (b - a) ^ (c - b);
	}

	// Comparison is lexicographical
	template<class T, class U>
	inline constexpr bool operator==(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	template<class T, class U>
	inline constexpr bool operator!=(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x != rhs.x || lhs.y != rhs.y;
	}

	template<class T, class U>
	inline constexpr bool operator<(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x < rhs.x || lhs.x == rhs.x && lhs.y < rhs.y;
	}

	template<class T, class U>
	inline constexpr bool operator<=(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x < rhs.x || lhs.x == rhs.x && lhs.y <= rhs.y;
	}

	template<class T, class U>
	inline constexpr bool operator>(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x > rhs.x || lhs.x == rhs.x && lhs.y > rhs.y;
	}

	template<class T, class U>
	inline constexpr bool operator>=(const Point<T>& lhs, const Point<U>& rhs)
	{
		return lhs.x > rhs.x || lhs.x == rhs.x && lhs.y >= rhs.y;
	}

	template<class T>
	inline constexpr float anglef(const Point<T>& point)
	{
		return atan2f(point.y, point.x);
	}

	template<class T>
	inline constexpr double angle(const Point<T>& point)
	{
		return atan2(point.y, point.x);
	}

	template<class T>
	inline constexpr long double anglel(const Point<T>& point)
	{
		return atan2l(point.y, point.x);
	}

	template<class T, class U>
	inline constexpr float anglef(const Point<T>& lhs, const Point<U>& rhs)
	{
		return atan2f(lhs ^ rhs, lhs * rhs);
	}

	template<class T, class U>
	inline constexpr double angle(const Point<T>& lhs, const Point<U>& rhs)
	{
		return atan2(lhs ^ rhs, lhs * rhs);
	}

	template<class T, class U>
	inline constexpr long double anglel(const Point<T>& lhs, const Point<U>& rhs)
	{
		return atan2l(lhs ^ rhs, lhs * rhs);
	}

	template<class T, class U>
	inline constexpr auto rotf(const Point<T>& point, const U& angle)
	{
		float c = cosf(angle), s = sinf(angle);
		return { c * point.x - s * point.y, s * point.x + c * point.y };
	}

	template<class T, class U>
	inline constexpr auto rot(const Point<T>& point, const U& angle)
	{
		double c = cos(angle), s = sin(angle);
		return { c * point.x - s * point.y, s * point.x + c * point.y };
	}

	template<class T, class U>
	inline constexpr auto rotl(const Point<T>& point, const U& angle)
	{
		long double c = cosl(angle), s = sinl(angle);
		return { c * point.x - s * point.y, s * point.x + c * point.y };
	}

	template<class T>
	inline constexpr auto rot0(const Point<T>& point)
	{
		return { point.x, point.y };
	}

	template<class T>
	inline constexpr auto rot90(const Point<T>& point)
	{
		return { -point.y, point.x };
	}

	template<class T>
	inline constexpr auto rot180(const Point<T>& point)
	{
		return { -point.x, -point.y };
	}

	template<class T>
	inline constexpr auto rot270(const Point<T>& point)
	{
		return { point.y, -point.x };
	}

	template<class T>
	inline constexpr auto mag2(const Point<T>& point)
	{
		return point * point;
	}

	template<class T>
	inline constexpr float magf(const Point<T>& point)
	{
		return sqrtf(mag2(point));
	}

	template<class T>
	inline constexpr double mag(const Point<T>& point)
	{
		return sqrt(mag2(point));
	}

	template<class T>
	inline constexpr long double magl(const Point<T>& point)
	{
		return sqrtl(mag2(point));
	}

	template<class T, class U>
	inline constexpr auto dist2(const Point<T>& lhs, const Point<U>& rhs)
	{
		return mag2(lhs - rhs);
	}

	template<class T, class U>
	inline constexpr float distf(const Point<T>& lhs, const Point<U>& rhs)
	{
		return magf(lhs - rhs);
	}

	template<class T, class U>
	inline constexpr double dist(const Point<T>& lhs, const Point<U>& rhs)
	{
		return mag(lhs - rhs);
	}

	template<class T, class U>
	inline constexpr long double distl(const Point<T>& lhs, const Point<U>& rhs)
	{
		return magl(lhs - rhs);
	}

	template<class T, class U>
	inline constexpr auto bisectf(const Point<T>& lhs, const Point<T>& rhs)
	{
		return lhs * magf(rhs) + rhs * magf(lhs);
	}


	template<class T, class U>
	inline constexpr auto bisect(const Point<T>& lhs, const Point<T>& rhs)
	{
		return lhs * mag(rhs) + rhs * mag(lhs);
	}

	template<class T, class U>
	inline constexpr auto bisectl(const Point<T>& lhs, const Point<T>& rhs)
	{
		return lhs * magl(rhs) + rhs * magl(lhs);
	}

	template<class T>
	inline constexpr auto normalf(const Point<T>& point)
	{
		return point / magf(point);
	}

	template<class T>
	inline constexpr auto normal(const Point<T>& point)
	{
		return point / mag(point);
	}

	template<class T>
	inline constexpr auto normall(const Point<T>& point)
	{
		return point / magl(point);
	}

}

typedef Point<int> pt;

int main()
{
	tCases()
	{
		ui C; cin >> C;
		vector<pt> XY(C);
		vui R(C), A(C);
		loop(0, C, i)
		{
			cin >> XY[i] >> R[i];
			A[i] = R[i] * R[i];
		}
		vector<vb> isect(C, vb(C));
		loop(0, C, i)
		{
			pt xy1 = XY[i];
			ui r1 = R[i];
			loop(i + 1, C, j)
			{
				pt xy2 = XY[j];
				ui r2 = R[j];
				ui r = r1 + r2;
				isect[i][j] = dist2(xy1, xy2) <= r * r;
			}
		}
		ui maxBits = 1u << C;
		ui bestArea = 0;
		for (ui bits = 1; bits < maxBits; bits++)
		{
			bool is = false;
			ui area = 0;
			loop(0, C, i)
			{
				if ((~bits >> i) & 1) continue;
				loop(i + 1, C, j)
				{
					if ((~bits >> j) & 1) continue;
					if (isect[i][j])
					{
						is = true;
						break;
					}
				}
				if (is) break;
				area += A[i];
			}
			if (is) continue;
			if (area > bestArea) bestArea = area;
		}
		cout << bestArea << endl;
	}
	return 0;
}