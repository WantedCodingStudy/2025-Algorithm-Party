// 스택 문제
// 스택의 가장 위의 값 확인하고 실제 출력해야하는 값이 다르면 문제가 됨

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    stack<int> s;
    vector<int> inputs(n);
    vector<char> result;
    vector<int> data;

    for(int ix = 0; ix < n; ++ix)
    {
        cin >> inputs[ix];
        data.emplace_back(ix + 1);
    }

    int cnt = 0;

    for(int ix = 0; ix < n; ++ix)
    {
        // 원하는 값이 나올때 까지 스택에 push
        while(data[cnt] <= inputs[ix] && cnt < n)
        {
            result.emplace_back('+');
            s.push(data[cnt]);
            ++cnt;
        }

        //최상위 값이 출력 값이랑 다르면 만들지 못한다고 판단
        if(s.top() == inputs[ix])
        {
            result.emplace_back('-');
            s.pop();
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    for(const auto& c : result)
    {
        cout << c << "\n";
    }
}

