#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/10870

/**
 


 */

int fiboResult = 0;

int fiboFunc(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    fiboResult = fiboFunc(n-1) + fiboFunc(n-2);
    return fiboResult;
    
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    else if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    else {
        cout << fiboFunc(n) << endl;
    }
    
    
    
    return 0;
}



// 참고 링크:
