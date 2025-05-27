#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> Queue;
    int N;
    cin >> N;

    // 카드를 큐에 저장
    for (int i = 1; i <= N; ++i)
        Queue.push(i);

    // 카드가 1장이 남을 때까지
    while (Queue.size() > 1)
    {
        // 맨 위 카드를 버림
        Queue.pop();

        // 맨 위 카드를 가장 아래 카드 밑으로 이동
        Queue.push(Queue.front());
        Queue.pop();
    }

    cout << Queue.front();
    return 0;
}
