#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for (int& x : A)
        cin >> x;

    int Count = 0;

    for (int i = N - 1; i > 0; --i)
    {
        bool bSwapped = false;

        for (int j = 0; j < i; ++j)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                ++Count;
                bSwapped = true;

                if (Count == K)
                {
                    cout << A[j] << " " << A[j + 1];
                    return 0;
                }
            }
        }

        // 더 이상 교환이 일어나지 않으면 정렬 완료
        if (!bSwapped)
            break;
    }

    cout << -1;
    return 0;
}
