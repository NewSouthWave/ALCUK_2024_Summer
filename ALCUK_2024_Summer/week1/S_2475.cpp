#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/2475


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int serial = 0;
    
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        serial += num * num;
    }
    
    cout << serial % 10 << endl;

    return 0;
}



// 참고 링크:
