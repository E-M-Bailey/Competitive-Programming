/*
BEGIN ANNOTATION
PROBLEM URL: open.kattis.com/problems/trainsorting
TAGS: longest increasing subsequence, longest decreasing subsequence, LIS, LDS, dynamic programming, DP, subsequence
EXPLANATION:
The number of elements that can be added to the front of a train starting with the car at index i is
the longest increasing (in weight) subsequence of trains after index i. The number of elements that
can be added to the back is the longest decreasing (in weight) subsequence of trains after index i.
The maximum length of a train starting with a given car is the number that can go in the front plus
the number that can go in the back plus 1 (for the car itself). The maximum of these lengths among
all trains is the answer to the problem.
END ANNOTATION
*/
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
using namespace std;

int main()
{
	// Reads input data and deals with the edge case n <= 2
	unsigned n;
	cin >> n;
	if (n <= 2)
	{
		cout << n;
		return 0;
	}
	vector<unsigned> weight(n);
	for(unsigned i = 0; i < n; i++)
		cin >> weight[i];

	// Iterates backwards through weight, computing the LIS and LDS of each car and finding the max LIS + LDS.
	vector<unsigned> LDS(n), LIS(n);
	unsigned bestSum = 0;
	// loops from n - 1 to 0. Written weirdly to avoid underflow.
	for (unsigned i = n; i-- > 0;)
	{
		unsigned iWeight = weight[i];
		unsigned maxLDS = 0, maxLIS = 0;
		// Iterates through the list after i, finding the max LDS/LIS that is lighter/heavier than iWeight
		for(unsigned j = i + 1; j < n; j++)
		{
			unsigned jWeight = weight[j];
			if (jWeight < iWeight)
				maxLDS = max(maxLDS, LDS[j] + 1);
			else
				maxLIS = max(maxLIS, LIS[j] + 1);
		}
		LDS[i] = maxLDS;
		LIS[i] = maxLIS;
		bestSum = max(bestSum, maxLDS + maxLIS);
	}

	// Outputs the sum plus 1 for the starting car itself
	cout << bestSum + 1;
	return 0;
}