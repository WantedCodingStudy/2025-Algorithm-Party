#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, P;
    cin >> S >> P;
    
    string DNA;
    cin >> DNA;
    
    array<int, 4> ACGT;
    
    for (int i = 0; i < ACGT.size(); ++i)
        cin >> ACGT[i];
    
    array<int, 4> Current = {};
    int Count = 0;

    for (int i = 0; i < P; ++i)
    {
        if (DNA[i] == 'A')
            ++Current[0];
        else if (DNA[i] == 'C')
            ++Current[1];
        else if (DNA[i] == 'G')
            ++Current[2];
        else if (DNA[i] == 'T')
            ++Current[3];
    }

    for (int i = 0; i <= S - P; ++i)
    {
        if (Current[0] >= ACGT[0] &&
            Current[1] >= ACGT[1] &&
            Current[2] >= ACGT[2] &&
            Current[3] >= ACGT[3])
        {        
            ++Count;
        }

        if (i + P < S)
        {
            if (DNA[i] == 'A')
                --Current[0];
            else if (DNA[i] == 'C')
                --Current[1];
            else if (DNA[i] == 'G')
                --Current[2];
            else if (DNA[i] == 'T')
                --Current[3];

            if (DNA[i + P] == 'A')
                ++Current[0];
            else if (DNA[i + P] == 'C')
                ++Current[1];
            else if (DNA[i + P] == 'G')
                ++Current[2];
            else if (DNA[i + P] == 'T')
                ++Current[3];
        }
    }

    cout << Count;
    return 0;
}
