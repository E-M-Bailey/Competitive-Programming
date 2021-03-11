#include <iostream>
#include <limits>

using namespace std;

int main()
{
	cout.precision(numeric_limits<long double>::max_digits10);
	
	unsigned N;
	cin >> N;

	long double sum = 0;
	for (unsigned i = 0; i < N; i++)
	{
		long double q, y;
		cin >> q >> y;
		sum += q * y;
	}

	cout << sum;
	return 0;
}