@@ -0,0 +1,77 @@
// 문자열 자르는 문제
// 윈도우?라고 해야하나 하나씩 옆으로 밀면 된다
// 창안에 들어오는건 map으로 관리를 하자 해봤자 4개만 있음 
// 조건을 만족하는거 확인하고 결과에 +1 하기

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // 문자열 크기 및 비밀번호 길이
    int n, m; 
    cin >> n >> m;

    // 문자열 받기
    map<char, int> ACGT;
    string DNA;
    cin >> DNA;

    // 필수 내역 받기
    int A, C, G, T;
    cin >> A >> C >> G >> T;

    ACGT.insert({'A', A});
    ACGT.insert({'C', C});
    ACGT.insert({'G', G});
    ACGT.insert({'T', T});

    // 현재 창 내에 있는거 확인용
    map<char, int> current;

    current.insert({'A', 0});
    current.insert({'C', 0});
    current.insert({'G', 0});
    current.insert({'T', 0});

    // 창구 양끝 만들기
    int left = 0;
    int right = left + m - 1;

    // 결과값 저장용
    int result = 0;

    // 초기 창구 확인
    for(int ix = 0; ix < m; ++ix)
    {
        current[DNA[ix]] += 1;
    }

    while(true)
    {
        //cout << current['A'] << " " << current['C'] << " " << current['G'] << " " << current['T'] << "\n";
        // 현재 비번이 조건에 맞는지 확인
        if(current['A'] >= ACGT['A'] && current['C'] >= ACGT['C'] && current['G'] >= ACGT['G'] && current['T'] >= ACGT['T'])
        {
            result += 1;
        }

        if(right + 1 < n)
        {
            right += 1;
            current[DNA[left]] -= 1;
            current[DNA[right]] += 1;
            left += 1;
            
        }
        else
        {
            cout << result;
            return 0;
        }
    }
}
