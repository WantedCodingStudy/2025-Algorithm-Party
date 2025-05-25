#include <iostream>
#include <vector>

typedef long long int ll;

int main()
{
	// 입력값 받기.
	int N, M;
	std::cin >> N >> M;

	// 누적합 저장하는 벡터.
	std::vector<ll> prefix(N);

	// 누적합의 나머지 계산.
	std::vector<ll> remainder(N);

	// 나머지가 될 수 있는 수를 저장하는 배열.
	std::vector<ll> num(M, -1);
	num[0] = 0;


	std::cin >> prefix[0];
	remainder[0] = prefix[0] % M;

	for (int i = 1; i < N; ++i)
	{
		std::cin >> prefix[i];
		prefix[i] += prefix[i - 1];
		remainder[i] = prefix[i] % M;
	}

	//  나누어 떨어지는 구간의 개수 저장.
	ll count = 0;

	for (int i = 0; i < N; ++i)
	{
		count += ++num[remainder[i]];
	}

	std::cout << count;

}
