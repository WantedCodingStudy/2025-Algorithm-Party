#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> Vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> Vec[i];
    }

    std::sort(Vec.begin(), Vec.end());

    int count = 0;

    for (int i = 0; i < N; ++i) {
        int goal = Vec[i];
        int start = 0;
        int end = N - 1;

        while (start < end) {
            int sum = Vec[start] + Vec[end];

            if (sum == goal) {
                if (start != i && end != i) {
                    count++;
                    break;
                } else if (start == i) {
                    start++;
                } else {
                    end--;
                }
            } else if (sum < goal) {
                start++;
            } else {
                end--;
            }
        }
    }

    std::cout << count << '\n';
    return 0;
}
