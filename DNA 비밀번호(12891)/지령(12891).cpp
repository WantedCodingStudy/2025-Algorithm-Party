#include <iostream>
#include <vector>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	// 입력값.
	int S, P;

	std::cin >> S >> P;


	// DNA 문자열값.
	std::string tmp;
	std::cin >> tmp;
	std::vector<char> DNA(S);


	for (int i = 0; i < S; ++i)
	{
		DNA[i] = tmp[i];
	}

	// ACGT 횟수값 저장.
	std::vector<int> ACGT(4);
	for (int i = 0; i < 4; ++i)
	{
		std::cin >> ACGT[i];
	}


	// 슬라이딩 윈도우 포인터
	int start = 0;	// 첫번째 인덱스부터
	int end = P-1;	// 비밀번호 길이까지
	
	int A = 0, C = 0, G = 0, T = 0;
	int cnt = 0;

	for (int i = start; i <= end; i++)
	{
		if (DNA[i] == 'A')
		{
			++A;
		}
		else if (DNA[i] == 'C')
		{
			++C;
		}
		else if (DNA[i] == 'G')
		{
			++G;
		}
		else if (DNA[i] == 'T')
		{
			++T;
		}
	}

	if (A >= ACGT[0] && C >= ACGT[1]
		&& G >= ACGT[2] && T >= ACGT[3])
	{
		++cnt;
	}

	++end;


	while (end < S)
	{

		if (DNA[start] == 'A')
		{
			--A;
		}
		else if (DNA[start] == 'C')
		{
			--C;
		}
		else if (DNA[start] == 'G')
		{
			--G;
		}
		else if (DNA[start] == 'T')
		{
			--T;
		}	
		
		if (DNA[end] == 'A')
		{
			++A;
		}
		else if (DNA[end] == 'C')
		{
			++C;
		}
		else if (DNA[end] == 'G')
		{
			++G;
		}
		else if (DNA[end] == 'T')
		{
			++T;
		}


		if (A >= ACGT[0] && C >= ACGT[1]
			&& G >= ACGT[2] && T >= ACGT[3])
		{
			++cnt;
		}


		++start;
		++end;
	}
	std::cout << cnt;
}
