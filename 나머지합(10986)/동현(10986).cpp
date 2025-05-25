#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> nums(n+1, 0);
    vector<ll> remainders(m, 0);

    for(int ix = 1; ix <= n; ++ix)
    {
        int num;
        cin >> num;
        nums[ix] = (nums[ix-1] + num);
        ++remainders[nums[ix] % m];
    }

    
    // 일단 바로 나누어 떨어지는것
    ll count = remainders[0];
    // 나머지가 같은 것끼리 조합해서 푸는 방식
    for(int ix = 0; ix < m; ++ix)
    {
        // 없는 갯수에 대한 것은 기본으로 0 * -1 이 되기 때문에 고민할 필요가 없음
        // 최소한 2개는 골라야 하기 때문에 1개인 것도 1 * 0 이 되어서 걸러짐
        count += remainders[ix] * (remainders[ix] - 1) / 2;
    }

    cout << count;

}
