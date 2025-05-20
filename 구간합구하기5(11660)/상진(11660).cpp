#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Arr(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> Sum(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> Arr[i][j];
            Sum[i][j] = Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1] + Arr[i][j];
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << Sum[X2][Y2] - Sum[X1 - 1][Y2] - Sum[X2][Y1 - 1] + Sum[X1 - 1][Y1 - 1] << "\n";        
    }

    return 0;
}
