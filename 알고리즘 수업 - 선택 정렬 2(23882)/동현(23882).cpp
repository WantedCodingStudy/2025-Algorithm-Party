#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int count = 0;

    cin >> n >> k;

    vector<int> nums(n, 0);

    for(int ix = 0; ix < n; ++ix)
    {
        cin >> nums[ix];
    }

    // 변경 위치
    // for(int ix = n - 1 ; ix > 1; --ix)
    for(int ix = n - 1 ; ix >= 1; --ix)
    {
        int max_idx = ix;

        for(int jx = 0; jx < ix; ++jx)
        {
            if(nums[jx] > nums[max_idx])
            {
                max_idx = jx;
            }
        }

        if(max_idx != ix)
        {
            swap(nums[ix], nums[max_idx]);
            count++;

            if(count == k)
            {
                for(int kx = 0; kx < n; ++kx)
                {
                    cout << nums[kx] << " ";
                }
                return 0;
            }
        }
    }
    cout << -1;
}
