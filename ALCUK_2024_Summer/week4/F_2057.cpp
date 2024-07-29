#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    ll fact[20];
    
    fact[0] = 1;
    
    for (int i = 1; i < 20; i++) {  //  팩토리얼 값 저장
        fact[i] = fact[i-1] * i;
    }
    
    ll n;
    cin >> n;
    
    if (n == 0) {
        cout << "NO" << endl;
    } else {
        for (int i = 19; i >= 0; i--) {
            if (n >= fact[i]) { //  팩토리얼 값이 n보다 작은 경우만
                n -= fact[i];
            }
        }
        if (n) {    //  n이 0이 아니면 ( = 팩토리얼로 나타낼 수 없으면
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        
    }
    
    
    //    출력 테스트 코드
//        for (ll elem : factVec) {
//            cout << elem << endl;
//        }

    
    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/2057

/**
 
 접근 1: n이하의 팩토리얼값들을 구한 후 조합을 통해 추출된 원소들의 합이 n이 되는지 판별
 -> 시간복잡도 및 메모리 문제 -> 기각
 
 접근 2 : n이 3 이상이면 n!의 값은 각 정 수의 팩토리얼의 합보다 항상 크다
 


 */


// MARK: - 트러블 슈팅

/*
 <메모리 초과>
 - long long형과 벡터 사용으로 그런가?
 - 6자리 이상부터 실행시간 많이 느려짐
 - 조합을 사용하므로 숫자가 증가할수록 급격하게 숫자가 늘어남 , 당연히 펙토리얼의 시간복잡도는 최악이므로
 - 뭔가 실행 횟수를 줄일 방법이 있을까
 - 조합 말고 다른 방법을 생각해봐야 할듯 -> 가능한 펙토리얼 개수가 많지는 않으므로
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 https://ansohxxn.github.io/algorithm/combination/#google_vignette
 https://measurezero.tistory.com/881
 
 */
