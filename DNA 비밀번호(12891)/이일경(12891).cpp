#include <iostream>
#include <algorithm>
using namespace std;

int s, p;
string dnaString;
int ACGT[4];
int ACGT_Result[4];
int result;
int firstIndex, lastIndex;

void Result()
{
	int count = 0;
	for (int k = 0; k < 4; ++k)
	{
		if (ACGT_Result[k] >= ACGT[k])
		{
			++count;
		}
	}

	if (count == 4)
	{
		++result;
	}
}

int main() {
	// 문자열 길이 / 비밀번호 길이.
	cin >> s >> p;
	
	// DNA 문자열/
	cin >> dnaString;

	// ACGT의 최소 개수.
	for (int i = 0; i < 4; ++i)
	{
		cin >> ACGT[i];
	}

	for (int i = 0; i < p; ++i)
	{
		if (i == 0)
		{
			firstIndex = i;
		}

		if (i == p - 1)
		{
			lastIndex = i;
		}

		switch (dnaString[i])
		{
		case 'A':
			++ACGT_Result[0]; break;
		case 'C':
			++ACGT_Result[1]; break;
		case 'G':
			++ACGT_Result[2]; break;
		case 'T':
			++ACGT_Result[3]; break;
		}
	}

	Result();

	for (int i = 0; i < s - p; ++i)
	{
		switch (dnaString[firstIndex])
		{
		case 'A':
			--ACGT_Result[0]; break;
		case 'C':
			--ACGT_Result[1]; break;
		case 'G':
			--ACGT_Result[2]; break;
		case 'T':
			--ACGT_Result[3]; break;
		}

		++firstIndex;

		switch (dnaString[++lastIndex])
		{
		case 'A':
			++ACGT_Result[0]; break;
		case 'C':
			++ACGT_Result[1]; break;
		case 'G':
			++ACGT_Result[2]; break;
		case 'T':
			++ACGT_Result[3]; break;
		}

		Result();
	}

	cout << result;

	return 0;
}
