#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long  ll;
vector<ll>box;
ll dp[10001] = {0,};

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        box.push_back(tmp);
    }
    
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (box[i] > box[j]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
    }
    ll answer = *max_element(begin(dp), end(dp));
    cout << answer << endl;
    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1965

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
