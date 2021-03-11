#include <iostream>
#include <vector>

int main()
{
	unsigned int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	
	unsigned int M = std::min(b, d);
	std::vector<bool> C(M + 1, false);
	std::vector<unsigned int> P;
	std::vector<int> U(M + 1);
	U[1] = 1;
	for (unsigned int i = 2; i <= M; i++)
	{
		if (!C[i])
		{
			P.push_back(i);
			U[i] = -1;
		}
		unsigned int p, x;
		for (unsigned int j = 0; j < P.size() && (p = P[j], x = i * p, x <= M); j++)
		{
			C[x] = true;
			if (i % p == 0)
			{
				U[x] = 0;
				break;
			}
			else
			{
				U[x] = U[i] * U[p];
			}
		}
	}
	unsigned long long int B = 0;
	for (unsigned int h = 1; h <= M; h++)
	{
		unsigned long long int longU = U[h];
		B += longU * (b / h - (a - 1) / h) * (d / h - (c - 1) / h);
	}

	std::cout << B;
	return 0;
}