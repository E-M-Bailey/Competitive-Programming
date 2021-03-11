#include <iostream>

using namespace std;

int main()
{
	unsigned N;
	cin >> N;

	unsigned res = (1u << N) + 1;
	cout << res * res;

	return 0;
}