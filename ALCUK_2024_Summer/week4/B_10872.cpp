#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/10872

/**
 


 */

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2 ) {
        return 2;
    }
    return n * factorial(n-1);
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin >> n;
    
    cout <<  factorial(n) << endl;
    
    
    return 0;
}



// 참고 링크:
