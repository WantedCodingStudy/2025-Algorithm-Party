#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int stringLen, partStringLen;
    cin >> stringLen >> partStringLen;

    string str;
    cin >> str;
   
    // 결과값(++)
    int result = 0;

    // A, C, G, T 문자가 얼마나 포함되어야 하는지 입력.
    int ACGT[4];
    for (int a = 0; a < 4; a++)
    {
        cin >>ACGT[a];
    }
    
    // 문자 카운트를 위한 변수.
    int a = 0, c = 0, g = 0, t = 0; 
    
    // 초기 윈도우 설정.
    
    //윈도우 시작 지점
    int start = 0;
    //윈도우 끝 지점.
    int end = partStringLen - 1;
    for (int i = 0; i < partStringLen; i++)
    {
        // 부분 배열의 사이즈 만큼 검사.
        switch (str[i])
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }


    }
    
    // 
    if (a >= ACGT[0] && c >= ACGT[1] && g >= ACGT[2] && t >= ACGT[3])
    {
        result++;
    }

    //다음 윈도우 설정: 인덱스start, end를 + 1로 1칸씩 옮기고 마지막 인덱스만 확인
    // 그떄 맨앞의 값에 대한 카운트는 지워야함.
    
    while (end != stringLen - 1)
    {
        // 앞 인덱스의 카운트 지우고
        switch (str[start])
        {
        case 'A':
            a--;
            break;
        case 'C':
            c--;
            break;
        case 'G':
            g--;
            break;
        case 'T':
            t--;
            break;
        }
        // 인덱스 옮기고
        start++;
        end++;
        
        // 맨 뒷부분만 검사..
        switch (str[end])
        {
        case 'A':
           a++;
           break;
        case 'C':
           c++;
           break;
        case 'G':
           g++;
           break;
        case 'T':
           t++;
           break;
        }
        

        if (a >= ACGT[0] && c >= ACGT[1] && g >= ACGT[2] && t >= ACGT[3])
        {
            result++;
        }
    }


    cout << result << "\n";
    return 0;
}
