#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int fibo[50];

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 0) {
            cout << "1 0" << endl;
        }
        else if (n == 1) {
            cout << "0 1" << endl;
        }
        else {
            fibo[0] = 1;
            fibo[1] = 1;
            
            for (int i = 2; i < n; i++) {
                fibo[i] = fibo[i-1] + fibo[i-2];
            }
            
            cout << fibo[n-2] << " " << fibo[n-1] << endl;
        }
        
    }

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1003

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
