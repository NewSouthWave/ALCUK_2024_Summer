#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/10989
//#define MAX_NUM 10000000

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int count[10001] = {0,};
    cin >> n;
    
    for (int i = 0; i < n; i++) {   // 입력 받은 인덱스에 숫자가 나온 횟수를 저장
        int tmp;
        cin >> tmp;
        count[tmp] = count[tmp] + 1;
    }
    
    for (int i = 1; i < 10001; i++) {   // 1 이상인 경우만 출력
        if(count[i] > 0){               // 한번 이상 나온 숫자의 경우
            for (int j = 0; j < count[i]; j++) {    // 인덱스의 숫자만큼이 출력 반복 횟수
                cout << i << "\n";
            }
        }
        
    }
    
    return 0;
}



// 참고 링크:
