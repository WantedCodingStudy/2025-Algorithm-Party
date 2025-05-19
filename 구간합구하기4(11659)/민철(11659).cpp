#include<vector>
#include <iostream>



int main()
{
	// 입출력 속도 개선
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	// N개의 수, M개만큼 반복함
	int N =0, M =0;

	// 인덱스 수 구하기.
	int startIndex=0, endIndex = 0;
	std::cin >> N >> M;

	std::vector<int> Index(N);

	// 벡터에 넣기.
	for (int j = 0; j < N; j++)
	{
		int inputInt;
		std::cin >> inputInt;
		Index[j] = inputInt;
	}

	//for (int i = 0; i < M; i++)
	//{
	//	resultSum = 0;
	//	std::cin >> startIndex >> endIndex;
	//	// 벡터 인덱스 접근해서 범위만큼 출력.

	//	for (int k = startIndex; k <= endIndex; k++)
	//	{
	//		resultSum += result[k-1];
	//	}
	//	std::cout << resultSum <<"\n";
	//}


	// 누적 합 알고리즘 -> 0번 인덱스부터 누적된 합을 저장시킨다음 답을 구하는 알고리즘
	// 누적합을 저장하기 위한 벡터.
	// *** 크기지정을 통해 속도 증가 ***
	std::vector<int> SumSum(N+1);
	
	// 누적합 벡터에 값을 넣기 위한 변수.
	int resultSum =0;
	SumSum[0] = 0;
	for (int u = 0; u < N; u++)
	{
		resultSum += Index[u];
		SumSum[u + 1] = resultSum;
	}

	// 누적합을 가지고 구간 합 구하기.
	for (int i = 0; i < M; i++)
	{
		std::cin >> startIndex >> endIndex;
		std::cout <<SumSum[endIndex] - SumSum[startIndex-1] <<"\n";
		
	}

	return 0;
}
