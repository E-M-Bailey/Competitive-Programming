#include <cstring>
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define loop(m, n, i) for (uli i = (m); i < (n); i++)
#define rloop(m, n, i) for (uli i = (n); i-- > (m);)

#define tCases() uli testCaseCount; cin >> testCaseCount; for (uli testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++)

#define endl '\n'

using namespace std;

typedef bool                       bi;
typedef char                       ci;
typedef unsigned char              uci;
typedef short                      si;
typedef unsigned short             usi;
typedef int                        li;
typedef unsigned                   uli;
typedef long long                  lli;
typedef unsigned long long         ulli;
typedef float                      sf;
typedef double                     df;
typedef long double                ldf;

typedef pair<bi, bi>               pbi;
typedef pair<ci, ci>               pci;
typedef pair<uci, uci>             puci;
typedef pair<si, si>               psi;
typedef pair<usi, usi>             pusi;
typedef pair<li, li>               pli;
typedef pair<uli, uli>             puli;
typedef pair<lli, lli>             plli;
typedef pair<ulli, ulli>           pulli;
typedef pair<sf, sf>               psf;
typedef pair<df, df>               pdf;
typedef pair<ldf, ldf>             pldf;

typedef vector<bi>                 vbi;
typedef vector<ci>                 vci;
typedef vector<uci>                vuci;
typedef vector<si>                 vsi;
typedef vector<usi>                vusi;
typedef vector<li>                 vli;
typedef vector<uli>                vuli;
typedef vector<lli>                vlli;
typedef vector<ulli>               vulli;
typedef vector<sf>                 vsf;
typedef vector<df>                 vdf;
typedef vector<ldf>                vldf;

typedef vector<pbi>                vpbi;
typedef vector<pci>                vpci;
typedef vector<puci>               vpuci;
typedef vector<psi>                vpsi;
typedef vector<pusi>               vpusi;
typedef vector<pli>                vpli;
typedef vector<puli>               vpuli;
typedef vector<plli>               vplli;
typedef vector<pulli>              vpulli;
typedef vector<psf>                vpsf;
typedef vector<pdf>                vpdf;
typedef vector<pldf>               vpldf;

typedef vector<vbi>                vvbi;
typedef vector<vci>                vvci;
typedef vector<vuci>               vvuci;
typedef vector<vsi>                vvsi;
typedef vector<vusi>               vvusi;
typedef vector<vli>                vvli;
typedef vector<vuli>               vvuli;
typedef vector<vlli>               vvlli;
typedef vector<vulli>              vvulli;
typedef vector<vsf>                vvsf;
typedef vector<vdf>                vvdf;
typedef vector<vldf>               vvldf;

typedef vector<vpbi>               vvpbi;
typedef vector<vpci>               vvpci;
typedef vector<vpuci>              vvpuci;
typedef vector<vpsi>               vvpsi;
typedef vector<vpusi>              vvpusi;
typedef vector<vpli>               vvpli;
typedef vector<vpuli>              vvpuli;
typedef vector<vplli>              vvplli;
typedef vector<vpulli>             vvpulli;
typedef vector<vpsf>               vvpsf;
typedef vector<vpdf>               vvpdf;
typedef vector<vpldf>              vvpldf;

typedef forward_list<bi>           l1bi;
typedef forward_list<ci>           l1ci;
typedef forward_list<uci>          l1uci;
typedef forward_list<si>           l1si;
typedef forward_list<usi>          l1usi;
typedef forward_list<li>           l1li;
typedef forward_list<uli>          l1uli;
typedef forward_list<lli>          l1lli;
typedef forward_list<ulli>         l1ulli;
typedef forward_list<sf>           l1sf;
typedef forward_list<df>           l1df;
typedef forward_list<ldf>          l1ldf;

typedef forward_list<pbi>          l1pbi;
typedef forward_list<pci>          l1pci;
typedef forward_list<puci>         l1puci;
typedef forward_list<psi>          l1psi;
typedef forward_list<pusi>         l1pusi;
typedef forward_list<pli>          l1pli;
typedef forward_list<puli>         l1puli;
typedef forward_list<plli>         l1plli;
typedef forward_list<pulli>        l1pulli;
typedef forward_list<psf>          l1psf;
typedef forward_list<pdf>          l1pdf;
typedef forward_list<pldf>         l1pldf;

typedef list<bi>                   l2bi;
typedef list<ci>                   l2ci;
typedef list<uci>                  l2uci;
typedef list<si>                   l2si;
typedef list<usi>                  l2usi;
typedef list<li>                   l2li;
typedef list<uli>                  l2uli;
typedef list<lli>                  l2lli;
typedef list<ulli>                 l2ulli;
typedef list<sf>                   l2sf;
typedef list<df>                   l2df;
typedef list<ldf>                  l2ldf;

typedef list<pbi>                  l2pbi;
typedef list<pci>                  l2pci;
typedef list<puci>                 l2puci;
typedef list<psi>                  l2psi;
typedef list<pusi>                 l2pusi;
typedef list<pli>                  l2pli;
typedef list<puli>                 l2puli;
typedef list<plli>                 l2plli;
typedef list<pulli>                l2pulli;
typedef list<psf>                  l2psf;
typedef list<pdf>                  l2pdf;
typedef list<pldf>                 l2pldf;

typedef set<bi>                    sbi;
typedef set<ci>                    sci;
typedef set<uci>                   suci;
typedef set<si>                    ssi;
typedef set<usi>                   susi;
typedef set<li>                    sli;
typedef set<uli>                   suli;
typedef set<lli>                   slli;
typedef set<ulli>                  sulli;
typedef set<sf>                    ssf;
typedef set<df>                    sdf;
typedef set<ldf>                   sldf;

typedef set<pbi>                   spbi;
typedef set<pci>                   spci;
typedef set<puci>                  spuci;
typedef set<psi>                   spsi;
typedef set<pusi>                  spusi;
typedef set<pli>                   spli;
typedef set<puli>                  spuli;
typedef set<plli>                  splli;
typedef set<pulli>                 spulli;
typedef set<psf>                   spsf;
typedef set<pdf>                   spdf;
typedef set<pldf>                  spldf;

typedef multiset<bi>               msbi;
typedef multiset<ci>               msci;
typedef multiset<uci>              msuci;
typedef multiset<si>               mssi;
typedef multiset<usi>              msusi;
typedef multiset<li>               msli;
typedef multiset<uli>              msuli;
typedef multiset<lli>              mslli;
typedef multiset<ulli>             msulli;
typedef multiset<sf>               mssf;
typedef multiset<df>               msdf;
typedef multiset<ldf>              msldf;

typedef multiset<pbi>              mspbi;
typedef multiset<pci>              mspci;
typedef multiset<puci>             mspuci;
typedef multiset<psi>              mspsi;
typedef multiset<pusi>             mspusi;
typedef multiset<pli>              mspli;
typedef multiset<puli>             mspuli;
typedef multiset<plli>             msplli;
typedef multiset<pulli>            mspulli;
typedef multiset<psf>              mspsf;
typedef multiset<pdf>              mspdf;
typedef multiset<pldf>             mspldf;

typedef unordered_multiset<bi>     umsbi;
typedef unordered_multiset<ci>     umsci;
typedef unordered_multiset<uci>    umsuci;
typedef unordered_multiset<si>     umssi;
typedef unordered_multiset<usi>    umsusi;
typedef unordered_multiset<li>     umsli;
typedef unordered_multiset<uli>    umsuli;
typedef unordered_multiset<lli>    umslli;
typedef unordered_multiset<ulli>   umsulli;
typedef unordered_multiset<sf>     umssf;
typedef unordered_multiset<df>     umsdf;
typedef unordered_multiset<ldf>    umsldf;

typedef unordered_multiset<pbi>    umspbi;
typedef unordered_multiset<pci>    umspci;
typedef unordered_multiset<puci>   umspuci;
typedef unordered_multiset<psi>    umspsi;
typedef unordered_multiset<pusi>   umspusi;
typedef unordered_multiset<pli>    umspli;
typedef unordered_multiset<puli>   umspuli;
typedef unordered_multiset<plli>   umsplli;
typedef unordered_multiset<pulli>  umspulli;
typedef unordered_multiset<psf>    umspsf;
typedef unordered_multiset<pdf>    umspdf;
typedef unordered_multiset<pldf>   umspldf;

typedef unordered_set<bi>          usbi;
typedef unordered_set<ci>          usci;
typedef unordered_set<uci>         usuci;
typedef unordered_set<si>          ussi;
typedef unordered_set<usi>         ususi;
typedef unordered_set<li>          usli;
typedef unordered_set<uli>         usuli;
typedef unordered_set<lli>         uslli;
typedef unordered_set<ulli>        usulli;
typedef unordered_set<sf>          ussf;
typedef unordered_set<df>          usdf;
typedef unordered_set<ldf>         usldf;

typedef unordered_set<pbi>         uspbi;
typedef unordered_set<pci>         uspci;
typedef unordered_set<puci>        uspuci;
typedef unordered_set<psi>         uspsi;
typedef unordered_set<pusi>        uspusi;
typedef unordered_set<pli>         uspli;
typedef unordered_set<puli>        uspuli;
typedef unordered_set<plli>        usplli;
typedef unordered_set<pulli>       uspulli;
typedef unordered_set<psf>         uspsf;
typedef unordered_set<pdf>         uspdf;
typedef unordered_set<pldf>        uspldf;

typedef stack<bi>                  stbi;
typedef stack<ci>                  stci;
typedef stack<uci>                 stuci;
typedef stack<si>                  stsi;
typedef stack<usi>                 stusi;
typedef stack<li>                  stli;
typedef stack<uli>                 stuli;
typedef stack<lli>                 stlli;
typedef stack<ulli>                stulli;
typedef stack<sf>                  stsf;
typedef stack<df>                  stdf;
typedef stack<ldf>                 stldf;

typedef stack<pbi>                 stpbi;
typedef stack<pci>                 stpci;
typedef stack<puci>                stpuci;
typedef stack<psi>                 stpsi;
typedef stack<pusi>                stpusi;
typedef stack<pli>                 stpli;
typedef stack<puli>                stpuli;
typedef stack<plli>                stplli;
typedef stack<pulli>               stpulli;
typedef stack<psf>                 stpsf;
typedef stack<pdf>                 stpdf;
typedef stack<pldf>                stpldf;

typedef queue<bi>                  qbi;
typedef queue<ci>                  qci;
typedef queue<uci>                 quci;
typedef queue<si>                  qsi;
typedef queue<usi>                 qusi;
typedef queue<li>                  qli;
typedef queue<uli>                 quli;
typedef queue<lli>                 qlli;
typedef queue<ulli>                qulli;
typedef queue<sf>                  qsf;
typedef queue<df>                  qdf;
typedef queue<ldf>                 qldf;

typedef queue<pbi>                 qpbi;
typedef queue<pci>                 qpci;
typedef queue<puci>                qpuci;
typedef queue<psi>                 qpsi;
typedef queue<pusi>                qpusi;
typedef queue<pli>                 qpli;
typedef queue<puli>                qpuli;
typedef queue<plli>                qplli;
typedef queue<pulli>               qpulli;
typedef queue<psf>                 qpsf;
typedef queue<pdf>                 qpdf;
typedef queue<pldf>                qpldf;

typedef deque<bi>                  dbi;
typedef deque<ci>                  dci;
typedef deque<uci>                 duci;
typedef deque<si>                  dsi;
typedef deque<usi>                 dusi;
typedef deque<li>                  dli;
typedef deque<uli>                 duli;
typedef deque<lli>                 dlli;
typedef deque<ulli>                dulli;
typedef deque<sf>                  dsf;
typedef deque<df>                  ddf;
typedef deque<ldf>                 dldf;

typedef deque<pbi>                 dpbi;
typedef deque<pci>                 dpci;
typedef deque<puci>                dpuci;
typedef deque<psi>                 dpsi;
typedef deque<pusi>                dpusi;
typedef deque<pli>                 dpli;
typedef deque<puli>                dpuli;
typedef deque<plli>                dplli;
typedef deque<pulli>               dpulli;
typedef deque<psf>                 dpsf;
typedef deque<pdf>                 dpdf;
typedef deque<pldf>                dpldf;

typedef priority_queue<bi>         pqbi;
typedef priority_queue<ci>         pqci;
typedef priority_queue<uci>        pquci;
typedef priority_queue<si>         pqsi;
typedef priority_queue<usi>        pqusi;
typedef priority_queue<li>         pqli;
typedef priority_queue<uli>        pquli;
typedef priority_queue<lli>        pqlli;
typedef priority_queue<ulli>       pqulli;
typedef priority_queue<sf>         pqsf;
typedef priority_queue<df>         pqdf;
typedef priority_queue<ldf>        pqldf;

typedef priority_queue<pbi>        pqpbi;
typedef priority_queue<pci>        pqpci;
typedef priority_queue<puci>       pqpuci;
typedef priority_queue<psi>        pqpsi;
typedef priority_queue<pusi>       pqpusi;
typedef priority_queue<pli>        pqpli;
typedef priority_queue<puli>       pqpuli;
typedef priority_queue<plli>       pqplli;
typedef priority_queue<pulli>      pqpulli;
typedef priority_queue<psf>        pqpsf;
typedef priority_queue<pdf>        pqpdf;
typedef priority_queue<pldf>       pqpldf;

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

enum Direction
{
	NONE, NEG_X, POS_X, NEG_Y, POS_Y
};

struct node
{
	point pos;
	vuli children;
	uli idxInRow = 0;
	uli idxInCol = 0;
	Direction dir;
};

struct dfs1Node
{
	uli c;
	uli p;
	Direction d;

	inline constexpr dfs1Node(uli c, uli p, Direction d) :
		c(c),
		p(p),
		d(d)
	{}
};

struct rowColEntry
{
	uli coord;
	uli idx;

	inline constexpr rowColEntry(uli coord, uli idx) :
		coord(coord),
		idx(idx)
	{}
};

inline constexpr bool operator<(rowColEntry e1, rowColEntry e2)
{
	return e1.coord < e2.coord;
}

typedef vector<rowColEntry> rowCol;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uli N, M, B;
	cin >> N >> M >> B;
	vector<rowCol> rows(N), cols(M);
	//suli usedRows, usedCols;
	vector<node> graph(B);
	loop(0, B, i)
	{
		point p;
		cin >> p.y >> p.x;
		p.x--;
		p.y--;
		rows[p.y].emplace_back(p.x, i);
		cols[p.x].emplace_back(p.y, i);
		//usedRows.insert(p.y);
		//usedCols.insert(p.x);
		graph[i].pos = p;
	}
	//for (uli x : usedRows)
	loop(0, N, y)
	{
		rowCol& row = rows[y];
		if (row.size() > 1)
		{
			sort(row.begin(), row.end());
			loop(0, row.size(), i)
				graph[row[i].idx].idxInRow = i;
		}
	}
	//for (uli y : usedCols)
	loop(0, M, x)
	{
		rowCol& col = cols[x];
		if (col.size() > 1)
		{
			sort(col.begin(), col.end());
			loop(0, col.size(), i)
				graph[col[i].idx].idxInCol = i;
		}
	}

	// DFS to construct graph
	{
		vector<dfs1Node> s;
		s.emplace_back(0, 0, NONE);
		while (!s.empty())
		{
			uli c = s.back().c, p = s.back().p;
			Direction d = s.back().d;
			s.pop_back();
			graph[c].dir = d;
			if (p != c)
				graph[p].children.push_back(c);
			point cPos = graph[c].pos;
			uli idxInRow = graph[c].idxInRow, idxInCol = graph[c].idxInCol;
			rowCol& row = rows[cPos.y], &col = cols[cPos.x];
			bool fNegX = false, fPosX = false, fNegY = false, fPosY = false;
			if (idxInRow > 0 && d != POS_X) // Check for a direct child to the left
			{
				rowColEntry e = row[idxInRow - 1];
				if (fNegX = e.coord == cPos.x - 1)
					s.emplace_back(e.idx, c, NEG_X);
			}
			if (idxInRow < row.size() - 1 && d != NEG_X) // Check for a direct child to the right
			{
				rowColEntry e = row[idxInRow + 1];
				if (fPosX = e.coord == cPos.x + 1)
					s.emplace_back(e.idx, c, POS_X);
			}
			if (idxInCol > 0 && d != POS_Y) // Check for a direct child up
			{
				rowColEntry e = col[idxInCol - 1];
				if (fNegY = e.coord == cPos.y - 1)
					s.emplace_back(e.idx, c, NEG_Y);
			}
			if (idxInCol < col.size() - 1 && d != NEG_Y) // Check for a direct child down
			{
				rowColEntry e = col[idxInCol + 1];
				if (fPosY = e.coord == cPos.y + 1)
					s.emplace_back(e.idx, c, POS_Y);
			}
			fNegX = fPosX = fNegY = fPosY = false;

			switch (d)
			{
			case NEG_X: // Check for obstructors to the left
				//if (!fNegX && idxInRow > 0)
					//graph[c].children.push_back(row[idxInRow - 1].idx);
				loop(0, idxInRow, i) graph[c].children.push_back(row[i].idx);
				break;
			case POS_X: // Check for obstructors to the right
				//if (!fPosX && idxInRow < row.size() - 1)
					//graph[c].children.push_back(row[idxInRow + 1].idx);
				loop(idxInRow + 1, row.size(), i) graph[c].children.push_back(row[i].idx);
				break;
			case NEG_Y: // Check for obstructors up
				//if (!fNegY && idxInCol > 0)
					//graph[c].children.push_back(col[idxInCol - 1].idx);
				loop(0, idxInCol, i) graph[c].children.push_back(col[i].idx);
				break;
			case POS_Y: // Check for obstructors down
				//if (!fPosY && idxInCol < col.size() - 1)
					//graph[c].children.push_back(col[idxInCol + 1].idx);
				loop(idxInCol + 1, col.size(), i) graph[c].children.push_back(col[i].idx);
				break;
			}
		}
	}

	vector<pair<Direction, point>> output;
	output.reserve(B);
	// DFS to detect cycles
	{
		vbi visited(B, false);
		vbi inStack(B, false);
		vuli s;
		bool cycle = false;
		s.push_back(0);
		while (!cycle && !s.empty())
		{
			uli p = s.back();
			if (inStack[p])
			{
				s.pop_back();
				inStack[p] = false;
			}
			else
			{
				visited[p] = true;
				inStack[p] = true;
				output.emplace_back(graph[p].dir, graph[p].pos);
				for (uli c : graph[p].children)
				{
					if (inStack[c])
					{
						cycle = true;
						break;
					}
					if (!visited[c])
						s.push_back(c);
				}
			}
		}

		if (cycle)
			cout << "impossible";
		else
		{
			cout << "possible";
			for (pair<Direction, point> res : output)
			{
				switch (res.first)
				{
				case NEG_X:
					cout << endl << "> " << res.second.y + 1;
					break;
				case POS_X:
					cout << endl << "< " << res.second.y + 1;
					break;
				case NEG_Y:
					cout << endl << "v " << res.second.x + 1;
					break;
				case POS_Y:
					cout << endl << "^ " << res.second.x + 1;
					break;
				}
			}
		}
	}

	return 0;
}