// 예시에서 a,b - c,d 까지 구하는것
// 일단 1,1 - c,d 까지의 합을 구함
// 1,1 - a,d 까지 빼고
// 1,1 - c,b 까지 뺵고
// 중복으로 뺀 1,1을 더해주면 됨됨 

// 3,3 4,4 -> 1,1 - 2,4 / 1,1 - 4,2 / 1,1 - 2,2

// 시간을 많이 잡아먹음
// (x1, y1) , (x2, y2) 이걸 (x1, x2), (y1, y2) 이렇게 풀어서 문제가 생김

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    // 입력값 받기
    int n, m;
    cin >> n >> m;
    // 일단 전체 구간 합

    vector<vector<int>> sums(n + 1, vector<int>(n + 1, 0));

    for(int ix = 1; ix <= n; ix++)
    {
        for(int jx = 1; jx <= n; jx++)
        {
            // 중복된 값을 빼줘야함
            cin >> sums[ix][jx];
            sums[ix][jx] += (sums[ix-1][jx] + sums[ix][jx-1] - sums[ix - 1][jx - 1]);
        }
    }

    for(int ix = 0; ix < m; ++ix)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;

        cout << sums[y1][y2] - sums[x1-1][y2] - sums[y1][x2-1] + sums[x1-1][x2-1] << "\n";
    }
}


// 다른 방식은 한줄씩 더하는 방식 대신 느림

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    // 입력값 받기
    int n, m;
    cin >> n >> m;
    // 일단 전체 구간 합

    vector<vector<int>> sums(n + 1, vector<int>(n + 1, 0));

    for(int ix = 1; ix <= n; ix++)
    {
        for(int jx = 1; jx <= n; jx++)
        {
            // 중복된 값을 빼줘야함
            cin >> sums[ix][jx];
            sums[ix][jx] += sums[ix][jx-1];
        }
    }

    for(int ix = 0; ix < m; ++ix)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = 0;
        for(int jx = x1; jx <= x2; jx++)
        {
            result += sums[jx][y2] - sums[jx][y1-1];
        }
        cout << result << "\n";
    }
}
