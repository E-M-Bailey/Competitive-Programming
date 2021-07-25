#include <Mergesort Inversion Count [O(nlogn)].h>

void go()
{
	/*uli a;
	puli b;
	tuple<uli, uli, uli> c;
	array<uli, 4> d;
	vuli e(5);
	duli f(6);
	l2uli g(7);
	l1uli h(8);

	read(tie(a, b, c, d, e, f, g, h));
	write_delim(tie(a, b, c, d, e, f, g, h), '\n', ' ');

	sci i{ 'a', 'a', 'b' };
	msci j{ 'c', 'c', 'd' };
	usci k{ 'e', 'e', 'f' };
	umsci l{ 'g', 'g', 'h' };
	
	map<ci, ci> m;
	m['i'] = 'k';
	m['i'] = 'l';
	m['j'] = 'l';
	multimap<ci, ci> n;
	n.emplace('m', 'o');
	n.emplace('m', 'p');
	n.emplace('n', 'p');
	unordered_map<ci, ci> o;
	o['q'] = 's';
	o['q'] = 't';
	o['r'] = 't';
	unordered_multimap<ci, ci> p;
	p.emplace('u', 'w');
	p.emplace('u', 'x');
	p.emplace('v', 'x');

	cout << endl << endl << endl;

	write_delim(tie(i, j, k, l, m, n, o, p), '\n', ' ', '-');

	typedef tuple<unsigned, pair<string, unsigned>, tuple<string, char, unsigned>, array<unsigned, 4>, vector<deque<forward_list<unsigned>>>, list<unsigned>, set<char>, multiset<char>, unordered_set<char>, unordered_multiset<char>, map<string, char>, multimap<string, char>, unordered_map<string, char>, unordered_multimap<string, char>> BigBoi;
	BigBoi bigBoi = read_n<BigBoi>(cin, 0, 2, 3, 4);
	write_delim(bigBoi, '\n', " ", "_", '-');
	write("\n\n");
	cout << std::endl;*/
	//write(std::endl);

	//vuli vec = ReadNHelper<vuli>::read(read<uli>());
	//write(tuple<size_t, vuli&>(mergeSortInversionCount(ALL(vec)), vec), '\n', ' ');
	uli T;
	cin >> T;
	while (T--)
	{
		uli n;
		cin >> n;
		vuli vec(n);
		loop(0, n, i) cin >> vec[i];
		cout << mergeSortInversionCount(ALL(vec)) << endl;
	}
}