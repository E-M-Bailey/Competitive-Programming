/*
BEGIN ANNOTATION
PROBLEM URL: open.kattis.com/problems/ovalwatch
EXPLANATION:
Runs in O(N + K)
Sorts the legs in reverse (non-ascending) order by B.
Starts with V=[0, 1, 2, 3, ...] and for every leg going up the page, swaps V[A] with V[A + 1].
By the end, the values (character ids) have been permuted to their correct indices (player ids).
END ANNOTATION
*/

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
	unsigned int N, K;
	cin >> N >> K;

	vector<unsigned int> V(N);
	for (unsigned int i = 0; i < N; i++)
		V[i] = i;

	vector<pair<unsigned int, unsigned int>> BA(K);
	for (unsigned int i = 0; i < K; i++)
		cin >> BA[i].second >> BA[i].first;

	// Sorts B in non-ascending order.
	sort(BA.begin(), BA.end(), greater<pair<unsigned int, unsigned int>>());

	for (pair<unsigned int, unsigned int> ba : BA)
		swap(V[ba.second], V[ba.second + 1]);

	cout << V[0];
	for (unsigned int i = 1; i < N; i++)
		cout << ' ' << V[i];

	return 0;
}