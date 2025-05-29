#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);

    for (int& a : A)
        cin >> a;
    
    int Count = 0;
    
    // 뒤에서부터 i번째 위치에 최대값을 찾아 교환하는 선택 정렬
    for (int i = N - 1; i > 0; --i)
    {
        // 현재 최대값 위치 초기화
        int Max = 0;
        
        // 0부터 i까지 탐색하며 최대값 위치 찾기
        for (int j = 0; j <= i; ++j)
        {
            if (A[Max] < A[j])
                Max = j;
        }
        
        // 최대값이 i 위치에 없다면 교환
        if (Max != i)
        {
            swap(A[Max], A[i]);
            
            // 교환 횟수 증가
            ++Count;
        }
        
        // K번째 교환 후 배열 출력하고 종료
        if (Count == K)
        {
            for (int a : A)
                cout << a << " ";
            return 0;
        }
    }
    
    // K번째 교환이 발생하지 않았다면 -1 출력
    cout << -1;
    return 0;
}
