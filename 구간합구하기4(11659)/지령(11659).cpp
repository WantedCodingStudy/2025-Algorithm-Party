#include <iostream>
#include <vector>

int N, M;
int main()
{

	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::cin >> N>> M;

	std::vector<int> InputData;  
	std::vector<int> Prefix(N,0); 

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> tmp;
		InputData.push_back(tmp);
		if (i == 0)
		{

			Prefix[i] =InputData[i];
		}
		else
		{
			Prefix[i] = Prefix[i-1] + InputData[i];
		}
	}


	int i, j;
	int result;

	while (M != 0)
	{ 
		result = 0;

		std::cin >> i>> j;
	    
		result = i == 1 ? Prefix[j - 1]  : Prefix[j-1] - Prefix[i - 2];

		std::cout << result << '\n';
		--M;
	}
	
}
