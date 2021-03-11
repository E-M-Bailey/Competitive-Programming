#include <iostream>

const unsigned MOD = 1000000007;
int main()
{
	unsigned n;
	std::cin >> n;
	char d;
	unsigned a = 0;
	unsigned b = 0;
	unsigned c = 0;
	for(unsigned i = 0; i < n; i++)
	{
		std::cin >> d;
		switch (d)
		{
		case '1':
			a = (a + 1) % MOD;
			b++;
			break;
		case '2':
			a = (a * 2) % MOD;
			break;
		case '3':
			c = (c + a + MOD - b) % MOD;
			break;
		}
	}
	std::cout << c;

	return 0;
}