#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/8958


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        bool isContinue = false;
        int continueScore = 0;
        int score = 0;
        string str;
        
        cin >> str;
        
        for(int j = 0 ; j < str.length(); j++){
            if(str[j] == 'O'){
                if(isContinue){ // 연속되는 중일 때
                    continueScore += 1;
                    isContinue = true;
                } else {    // 연속되는 중이 아닐 때
                    continueScore += 1;
                    isContinue = true;
                }
                score += continueScore;
            }  else {
                continueScore = 0;
                isContinue = false;
            }
        }
        cout << score << endl;
    }
    
    return 0;
}



// 참고 링크:
