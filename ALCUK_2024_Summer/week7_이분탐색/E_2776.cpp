#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        
        cin >> n;
        vector<int>noteOne;
        
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            noteOne.push_back(tmp);
        }
        
        cin >> m;
        vector<int>noteTwo;
        
        for (int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            noteTwo.push_back(tmp);
        }
        
        sort(noteOne.begin(), noteOne.end());
        
        for (int i = 0; i < m; i++) {
            cout << binary_search(noteOne.begin(), noteOne.end(), noteTwo[i]) << "\n";
        }

    }
    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제: https://www.acmicpc.net/problem/2776

/**
 첫번째 수첩 벡터 정렬 후 이진탐색 라이브러리 사용


 */


// MARK: - 트러블 슈팅

/*
 1. 시간초과 발생
 Solution: endl 대신 "\n" 을 쓰자...ㅋㅋ
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
