#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;



int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    
    stack<int>st;
    
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        
        if (num != 0) {
            st.push(num);
        } else {
            st.pop();
        }
    }
    
    int sum = 0;
    while (st.size() != 0) {
        sum += st.top();
        st.pop();
    }
    
    cout << sum << endl;

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/10773

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
