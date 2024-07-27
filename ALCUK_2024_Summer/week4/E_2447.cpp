#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void starFunc (int i, int j, int n) {
    
    if((i/n) % 3 == 1 && (j/n) % 3 == 1) {  // 모든 이 조건의 인덱스에서 공백이 출력된다
        cout << " ";
    }
    else {
        if (n / 3 == 0) {
            cout << '*';
        }
        else {
            starFunc(i, j, n / 3);  //  크기가 커도 어차피 같은 출력조건을 만족하므로 재귀 호출
        }
    }
    
    
    
    return;
}



int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;  // n은 3의 거듭제곱
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            starFunc(i, j, n);
        }
        cout << "\n";
    }
    
 
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/2447

/**
 
행과 열이 각각 n인 2차원의 구성이므로 이중 for문을 써서 가장 안쪽에 별을 출력하게 해야한다
 별이나 공백을 출력하는 함수의 조건을 세운다
 1. 가로와 세로 인덱스를 3으로 나눈 나머지가 모두 1이면 -> 공백 출력
 2. 1. 이 아닌 경우
 2-1. n이 3보다 작은 경우 -> 별 출력
 2-2. 2-1이 아닌 경우 -> n 을 3으로 나누어 재귀 호출

 */


// MARK: - 참고 링크

// 참고 링크:
/*
 https://cryptosalamander.tistory.com/38

 
 */
