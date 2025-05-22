#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> V(N, 0);
    
    for (int i = 0; i < N; ++i)
        cin >> V[i];
    
    sort(V.begin(), V.end());
    
    int Count = 0;
    
    for (int i = 0; i < N; ++i)
    {
        long Find = V[i];
        int Start = 0;
        int End = N - 1;
        
        while (Start < End)
        {
            if (V[Start] + V[End] == Find)
            {
                if (Start != i && End != i)
                {
                    ++Count;
                    break;
                }
                else if (Start == i)
                    ++Start;
                else if (End == i)
                    --End;
            }
            else if (V[Start] + V[End] < Find)
                ++Start;
            else
                --End;
        }
    }
    
    cout << Count;
    return 0;
}
