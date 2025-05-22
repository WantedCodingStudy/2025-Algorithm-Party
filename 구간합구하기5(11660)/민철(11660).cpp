#include<iostream>
#include<vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 2차원 배열 초기화.
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    // 입력 및 누적 합 계산
    for (int i = 1; i <= N; ++i) 
    {
        for (int j = 1; j <= N; ++j) 
        {
            cin >> arr[i][j];
            // 점화식.
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    
    int x1 =0, y1=0, x2=0, y2=0;
    while (M--) 
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}
