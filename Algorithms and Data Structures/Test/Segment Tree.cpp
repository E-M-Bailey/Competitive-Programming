#include <assert.h>

#include <Template.h>

#include <segment_tree.h>

// Simple example (range gcd)
void go1()
{
	const auto op = [](uli l, uli r, auto lo, auto mid, auto hi)
	{
		return gcd(l, r);
	};

	uli N;
	cin >> N;
	segment_tree<uli, decltype(op)> st(N, 0, op);
	loop(0, N, i) cin >> st[i];

	//segment_tree<uli, decltype(op)> st(ALL(A), 0, op);

	loop(0, N, i) loop(0, N + 1, j)
	{
		cout << i << ' ' << j << ' ' << st[range(i, j)] << endl;
	}
}

// More complex example (merge sort tree)
void go2()
{
	uli N;
	cin >> N;
	vvuli A(N, vuli(1));
	loop(0, N, i) cin >> A[i].front();

	const auto op = [](const vuli& l, const vuli& r, auto lo, auto mid, auto hi)
	{
		if (r.empty()) return l;
		else if (l.empty()) return r;
		vuli res(l.size() + r.size());
		std::merge(l.begin(), l.end(), r.begin(), r.end(), res.begin());
		return res;
	};

	segment_tree<vuli, decltype(op)> st(ALL(A), vuli(), op);

	loop(0, N, i) loop(0, N + 1, j)
	{
		cout << i << ' ' << j << " [ ";
		vuli V = st[range(i, j)];
		for (uli x : V) cout << x << ' ';
		cout << ']' << endl;
	}

	//const auto op = [](uli l, uli r, auto, auto, auto) { return l + r; };
	//segment_tree<uli, decltype(op)> st(ALL(A), 0u, op);
	//st.point_query(st.begin() + 3);
	//st.range_query(st.begin() + 2, st.begin() + 4);
}

void go()
{
	go1();
}