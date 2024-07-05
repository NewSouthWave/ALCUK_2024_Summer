#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/5597


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    int submitDone[31] = {0,};
    
    for (int i = 0; i < 28; i++) {
        int student;
        cin >> student;
        submitDone[student] = 1;
    }
    for (int i = 1; i <= 30; i++) {
        if(!submitDone[i]){
            cout << i << endl;
        }
    }
    

    return 0;
}



// 참고 링크:
