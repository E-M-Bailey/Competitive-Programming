#include <iostream>

using namespace std;

int main()
{
	unsigned n;
	cin >> n;
	if (n % 2 == 0)
		cout << "Bob";
	else
		cout << "Alice";
	return 0;
}