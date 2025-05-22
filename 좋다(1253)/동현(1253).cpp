// 4:40분에 시작함함
// 일단 한눈에 안들어옴
// 서로 다른 2개를 골라서 존재하는 수를 만들 수 있으면 된다

// 이중 for문으로 확인하면 되는거 아닐까
// 시간 초과 날거 같긴함
// 일단 입력 받아서 있는지 확인하는 것을 먼저 만들어야 겠는데
// 입력 범위가 -10억~10억이니까 unordermap으로 하면 편하겠네
// 숫자 압축이 필요한가 고민을 해봅시다, 걍 배열 크기 20얼짜리로 하고
// 다 패기하고 정렬을 하고 왼쪽, 오른쪽 하나씩 하고 오른쪽이든 왼쪽이드 넘어가면 없는걸로 하고
// 있으면 그거 저장해 놓음, 있는건 또할 필요 없으니까

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);

    for(int ix = 0; ix < n; ++ix)
    {
        cin >> nums[ix];
    }

    // 정렬렬
    sort(nums.begin(), nums.end());
    
    // 결과과
    int result = 0;

    // 중복 된거 빠르게 걸러내기용
    unordered_set<int> visited;

    for(int ix = 0; ix < n; ++ix)
    {
        // 이미 확인한거 거르기기
        if(visited.count(nums[ix]))
        {
            result += 1;
            continue;
        }

        // 투포인터
        int right = n-1;
        int left = 0;

        // 오른쪽이 왼쪽보다 작거나 같으면 중단단
        while(right > left)
        {
            // 본인은 피해야함함
            if(left == ix)
            {
                left++;
                continue;
            }
            if(right == ix)
            {
                right--;
                continue;
            }

            if(nums[right] + nums[left] == nums[ix])
            {
                result += 1;
                
                visited.insert(nums[ix]);
                break;
            }

            if(nums[ix] < nums[right] + nums[left])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    cout << result;
}
