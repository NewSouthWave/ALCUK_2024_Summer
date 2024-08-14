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
        cin >> n >> m;
        
        vector<int>a;
        vector<int>b;
        
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }for (int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = m;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (a[i] > b[mid]) left = mid;
                else right = mid;
            }
            sum += left;
            if (a[i] > b[left]){
                sum++;
            }
            
            
        }
        cout << sum << endl;

    }
    
    
    
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/7795

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 https://breakcoding.tistory.com/188
 https://2jinishappy.tistory.com/249
 
 */
