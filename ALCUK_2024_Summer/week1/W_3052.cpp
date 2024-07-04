#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/3052


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    int checkArr[1001] = {0,};
    int countNum = 0;
    
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        num = num % 42;
        if(!checkArr[num]){ // 만약 나오지 않았던 나머지라면
            checkArr[num] += 1; // 배열에 체크
            countNum++; // 개수로 카운트
        }
    }
    
    cout << countNum << endl;

    return 0;
}



// 참고 링크:
