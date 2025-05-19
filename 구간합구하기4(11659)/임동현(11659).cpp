#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1, 0);
    vector<int> results(n + 1, 0);

    // 계산할 때 편하기 위해서 배열 범위를 n+1 로 설정
    for(int ix = 1; ix < n + 1; ++ix)
    {
        cin >> nums[ix];
        results[ix] = results[ix - 1] + nums[ix];
    }

    // 디버그용 누적합 출력 코드 
    // for(int ix = 0; ix < n + 1; ++ix)
    // {
    //     cout << results[ix] << " ";
    // }

    // 입력 받은 값에서 0에서 b까지의 누적합 - (a -1) 까지의 누적합 계산
    for(int ix = 0; ix < m; ++ix)
    {
        int a, b;
        cin >> a >> b;
        cout << results[b] - results[a-1] << "\n";
    }
}
