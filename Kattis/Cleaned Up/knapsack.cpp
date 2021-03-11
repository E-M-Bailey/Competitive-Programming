#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr const unsigned MAXIMUM_U32 = numeric_limits<unsigned>::max();

unsigned C, n;
vector<unsigned> weight, value;
vector<vector<pair<unsigned, bool>>> dp;

unsigned knap(unsigned i, unsigned s)
{
	if (s > C)
		return MAXIMUM_U32;
	if (i >= n)
		return 0;

	pair<unsigned, bool>& thisDP = dp[i][s];

	if (thisDP.first != MAXIMUM_U32) return thisDP.first;

	unsigned excCur = knap(i + 1, s);
	unsigned incCur = knap(i + 1, s + weight[i]);
	incCur = incCur == MAXIMUM_U32 ? MAXIMUM_U32 : incCur + value[i];

	if (excCur == MAXIMUM_U32)
	{
		thisDP = {0, false};
		return 0;
	}
	else if (excCur > incCur || incCur == MAXIMUM_U32)
	{
		thisDP = { excCur, false };
		return excCur;
	}
	else
	{
		thisDP = { incCur, true };
		return incCur;
	}
}

int main()
{
	while (cin >> C >> n)
	{
		dp = vector<vector<pair<unsigned, bool>>>(n, vector<pair<unsigned, bool>>(C + 1, { MAXIMUM_U32, false }));
		weight = vector<unsigned>(n);
		value = vector<unsigned>(n);
		for (unsigned i = 0; i < n; i++)
			cin >> value[i] >> weight[i];
		knap(0, 0);
		vector<unsigned> indices;
		unsigned i = 0, s = 0;
		while (i < n && s <= C)
		{
			if (dp[i][s].second)
			{
				indices.push_back(i);
				s += weight[i];
			}
			i++;
		}

		cout << indices.size() << endl;
		for (unsigned i = 0; i < indices.size(); i++)
		{
			if (i > 0)
				cout << " ";
			cout << indices[i];
		}
		cout << endl;
	}
	return 0;
}