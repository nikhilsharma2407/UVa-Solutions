//10299 - Relatives
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

long long p;
bool isNotPrime[MAX];
long long factor[MAX];
vector<long long> prime(1, 2);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (p = 3; p < MAX; p += 2)
	{
		if (not isNotPrime[p])
		{	
			factor[p] = p;
			prime.push_back(p);
		}

		for (int j = 0; j < prime.size() and p * prime[j] < MAX and prime[j] <= factor[p]; ++j)
		{
			factor[p * prime[j]] = prime[j];
			isNotPrime[p * prime[j]] = true;
		}
	}

	long long n;
	long long result;

	while (cin >> n and n)
	{	
		result = (n == 1?0:n);

		for (int i = 0; prime[i] * prime[i] <= n; ++i)
		{
			if (n % prime[i] == 0)
			{
				result -= result / prime[i];

				while (n % prime[i] == 0)
					n /= prime[i];
			}
		}

		if (n > 1)
			result -= result / n;

		cout << result << "\n";
	}

	return 0;
}