#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
//문제:   https://www.acmicpc.net/problem/9020

/**
 
1. 우선 에라토스테네스 체를 활용하여 소수를 미리 판별한다
2. 입력받은수의 절반부터 1씩 더해가며 두 수 모두 소수인 경우를 탐색하면 된다


 */

// MARK: 에라토스테네스 체
#define MAX_NUM 1000001   //  최댓값 상수 설정
bool primeNum[MAX_NUM];

void eraPrimeFunc() {
    
    for (bool num : primeNum) {
        num = false;
    }
    
    for (int i = 2; i <= sqrt(MAX_NUM); i++) {
        if(primeNum[i]) {
            continue;
        }
        
        for (int j = i*i ; j <= MAX_NUM; j+=i) {
            primeNum[j] = true;
        }
    }
    //  false 인 인덱스들이 소수
}

// MARK: 골드바흐 함수

void goldBach(int caseNum) {
    int upIndex = 0;
    
    for (int i = 0; i < caseNum / 2; i++) {
        if(primeNum[caseNum/2 + i]){  // 탐색숫자가 짝수면 패스
            continue;
        }
        else {    // 탐색숫자가 홀수인경우
            int bigNum = caseNum/2+i;
            int smallNum = caseNum - (bigNum);
            if (primeNum[smallNum]) {   // 테스트케이스에서 탐색숫자를 뺀 숫자가 짝수면 패스
                continue;
            } else {                    // 홀수면 정답 = 두 수 모두 홀수
                cout << smallNum << " " << bigNum << endl;
                break;
            }
        }
    }
     
}


// MARK: Main 함수
int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    eraPrimeFunc();
    
// MARK: 테스트 코드
//    for (int i = 700; i < 800; i++) {
//        if(!primeNum[i]) {
//            cout << i << endl;
//        }
//    }

    // MARK: 본 코드
    int t;
    cin >> t;
    vector<int>v;
    for (int i = 0; i < t; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    
    for (int i = 0; i < t; i++) {
        clock_t start, finish;  //  시작 종료 시간 변수
        double duration;         //  측정시간 변수

        start = clock(); //  측정 시작
        
        goldBach(v[i]);
        
        finish = clock();

        duration = (double)(finish - start) / CLOCKS_PER_SEC;   //  실행시간
        cout << duration << "초" << endl;
    }
        

    return 0;
}



// 참고 링크:
// https://donggoolosori.github.io/2020/10/16/eratos/
