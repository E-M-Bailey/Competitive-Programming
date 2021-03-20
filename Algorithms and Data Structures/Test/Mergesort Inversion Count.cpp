#include "../Implementations/Mergesort Inversion Count.h"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	uli n;
	cin >> n;
	vuli vec(n);
	loop(0, n, i)
		cin >> vec[i];
	cout << mergeSortInversionCount(vec) << endl;
	loop(0, n, i)
		cout << vec[i] << ' ';

	return 0;
}