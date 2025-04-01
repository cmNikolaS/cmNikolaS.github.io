#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int a)
{
	if(a < 2) return false;
	if(a < 4) return true;
	if(a % 2 == 0 || a % 3 == 0) return false; 
	for(int i = 5; i * i <= a; i+= 6)
		if(a % i == 0 || a % (i+2) == 0) return false;
	return true;
}

int main()
{
	int N;
	std::cin >> N;
	
	std::vector<int> A1, A2, prosti;
	std::vector<bool> p(4100, false);
	for(int i = 2; i < 4100; i++)
	{
		if(isPrime(i))
		{
			for(int j = i; j < 4100; j+=i)
			p.at(j) = true;
		}
	}
	for(int i = 2; i < 4100; i++)
		if(p.at(i))
			prosti.push_back(i);
	

	int t, a, b, s = prosti.size();
	for(int i = 0; i < N; i++)
	{
		a = -1;
		b = -1;
		std::cin >> t;
		if(t == 1)
		{
			A1.push_back(-1);
			A2.push_back(-1);
			continue;
		}
		
		for(int j = 0; j < s; j++)
		{
			if(t % prosti.at(j) == 0)
			{
				a = 1;
				while(t % prosti.at(j) == 0)
				{
					a*=prosti.at(j);
					t/=prosti.at(j);
				}
				if(t == 1)
				a = -1;
				else
				b = t;
				A1.push_back(a);
				A2.push_back(b);
				break;
			}
		}

	}


	for(int i = 0; i < A1.size();i++)
	{
		std::cout << A1[i] << " ";
	}
	std::cout << std::endl;
		for(int i = 0; i < A2.size();i++)
	{
		std::cout << A2[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
