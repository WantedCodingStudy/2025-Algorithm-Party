// 단순하게 queue를 물어보는거 같음
// 50만 정도면 커버 가능할듯?

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;

    for(int ix = 1; ix <= n; ++ix)
    {
        q.push(ix);
    }

    // 무조건 하나씩 버리니까 짝수든 홀수든 상관이 없다
    while(q.size() > 1)
    {
        // 맨 위에꺼 버리기
        q.pop();
        // 그다음꺼 맨뒤로 옮기기
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}
