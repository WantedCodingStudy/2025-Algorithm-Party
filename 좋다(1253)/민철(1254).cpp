#include <iostream>
#include <algorithm>

int array[2001];

int main() {
    int index;
    std::cin >> index;
    for (int i = 0; i < index; ++i)
    {
        std::cin >> array[i];
    }
    std::sort(array, array + index);

    int goodNum = 0;

    //좋은수는 3번째부터 있을수 밖에 없다.
    int targetIndex = 2;

    for (int i = 0; i < index; i++) 
    {
        int left = 0;
        int right = index - 1;

        while (left < right) 
        {
            if (left == i) 
            {
                left++;
                continue;
            }
            if (right == i) 
            {
                right--;
                continue;
            }

            int sum = array[left] + array[right];

            if (sum == array[i]) 
            {
                goodNum++;
                break;
            }
            else if (sum < array[i]) 
            {
                left++;
            }
            else {
                right--;
            }
        }
    }
    std::cout << goodNum << "\n";
    return 0;
}
