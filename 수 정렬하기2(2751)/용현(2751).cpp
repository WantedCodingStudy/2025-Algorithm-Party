#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    
    vector<int> vec(n);
    
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    
    for(int i : vec)
        cout << i << "\n";
    
    return 0;
}
