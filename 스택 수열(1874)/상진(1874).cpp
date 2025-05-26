#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<char> Result;
    stack<int> Stack;

    // 1부터 N까지 차례대로 push할 오름차순 수
    int Count = 1;
    // 결과 출력 여부 플래그
    bool bFlag = true;

    for (int i = 0; i < A.size(); ++i)
    {
        // 현재 수열의 수
        const int Num = A[i];

        // 현재 수열값 >= 오름차순 자연수: 값이 같아질 때까지 push
        if (Num >= Count)
        {
            while (Num >= Count)
            {
                Stack.push(Count++);
                Result.push_back('+');
            }

            Stack.pop();
            Result.push_back('-');
        }
        // 현재 수열값 < 오름차순 자연수: 수열의 원소를 pop
        else
        {
            const int Top = Stack.top();
            Stack.pop();

            // 스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크다면 수열 출력 불가능
            if (Top > Num)
            {
                cout << "NO";
                bFlag = false;
                break;
            }
            else
                Result.push_back('-');
        }
    }

    if (bFlag)
    {
        for (int i = 0; i < Result.size(); ++i)
            cout << Result[i] << "\n";
    }

    return 0;
}
