// 버블 정렬 다 해야하는건가..
// k 값을 하고 하나 스왑할때마다 횟수 카운트 해서 그 카운트 나오면 종료하는 식으로
// k 값이 교환 횟수보다 크면 -1 출력


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입력값이 10000 이여서 입력으로 시간 초가 날거 같지는 않음
    int n, k;
    cin >> n >> k;

    vector<int> nums(n, 0);

    for(int ix = 0; ix < n; ++ix)
    {
        cin >> nums[ix];
    }

    // 횟수
    int count = 0;

    for(int ix= 1; ix < n; ++ix)
    {
        for(int jx = 0; jx < n - ix; ++jx)
        {
            if(nums[jx] > nums[jx+1])
            {
                swap(nums[jx], nums[jx+1]);
                count++;
                if(count == k)
                {
                    cout << nums[jx] << " " << nums[jx+1];
                    return 0;
                }
            }
        }
    }
    cout << -1;
}

// 이야 이것도 틀려? 정신 안차리지
// jx+1인데 이걸 ix를 넣고 난리르 치니까 문제가 되지 하... 
