#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> Sum(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> Sum[i];
        Sum[i] += Sum[i - 1];
    }

    while (M--)
    {
        int i, j;
        cin >> i >> j;
        cout << Sum[j] - Sum[i - 1] << "\n";
    }

    return 0;
}
