#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	// 입력 받기
	int N, M;
	std::cin >> N >> M;

	// 누적합 벡터
	std::vector<std::vector<int>> prefixVec(N+1, std::vector<int>(N+1));

	// 행렬값
	int MatrixValue;

	// 누적합 구하기
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			// 매 행마다 누적합을 구해준다. 
			std::cin >> prefixVec[i][j];
			prefixVec[i][j] += prefixVec[i][j - 1];
		}
	}

	// (x1, y1)부터 (x2, y2)까지 합을 구하기 : M번 반복
	int x1, x2;
	int y1, y2;

	int result;
	while (M--)
	{
		result = 0;

		std::cin >> x1 >> x2 >> y1 >> y2;

		result = prefixVec[x1][y2] - prefixVec[x1][x2 - 1];
		// 행마다 구간합구하기
		while (x1 != y1)
		{
			++x1;
			result += prefixVec[x1][y2] - prefixVec[x1][x2 - 1];
		}
		std::cout << result << "\n";
	}


}
