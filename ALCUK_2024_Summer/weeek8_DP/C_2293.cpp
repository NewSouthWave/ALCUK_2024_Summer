#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll>coin;
ll dp[10001] = {0,};

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        coin.push_back(tmp);
    }
    
    sort(coin.begin(), coin.end());
    
    dp[0] = 1;  //  동전을 쓰지 않는 것도 하나의 방법
    for (int i = 0; i < n; i++) {
        for (ll j = coin[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    
    cout << dp[k] << endl;

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/2293

/**
    - 동전의 가치는 10만 이하이고 동전의 최대 개수는 100개이므로 long long 형 선언
    - 가장 작은 단위의 동전단위로 시작하여 1원부터  k원까지 만들 수 있는 동전 개수를 dp에 더한다
    - 점화식은 dp[ j ] = dp [ j ] + dp[ j - coin[ i ] ]

 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 https://hellooworld.tistory.com/24
 
 
 */
