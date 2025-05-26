
#include<iostream>
#include<vector>
#include<stack>

int main()
{
	// 입출력 최적화.
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 연산 횟수.
	int calCount = 0;

	// 스택에 들어갈수.
	int count = 1;

	// 스택.
	std::stack<int> stack;
	// 결과 벡터.
	std::vector<char> result;


	std::cin >> calCount;

	for (int i = 0; i < calCount; i++)
	{
		int input = 0;
		std::cin >> input;

		// 스택에 input인덱스만큼 push_back
		while (count <= input)
		{
			stack.push(count);
			result.push_back('+');
			count++;
		}
		// 스택의 값이 input이랑 같으면 pop하기.
		if (stack.top() == input)
		{
			stack.pop();
			result.push_back('-');

		}
		// 해당 조건이 충족이 안되면 "NO"출력
		else
		{
			std::cout << "NO" << "\n";
			return 0;
		}
	}

	for (int j = 0; j < result.size(); j++)
	{
		std::cout << result[j] << "\n";
	}

}
