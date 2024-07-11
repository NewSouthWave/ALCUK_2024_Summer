#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/1543

/**
 


 */

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    string docu, word;
    
    getline(cin, docu);
    getline(cin, word);
    
    int i = 0;
    int cnt = 0;
    while (i < docu.length()) {
        bool isExist = true;
        if(docu[i] != word[0]) {
            i++;
            isExist = false;
            continue;
        } else {
            for (int j = 0; j < word.length(); j++) {
                if(word[j] != docu[i+j]){
                    i++;
                    isExist = false;
                    break;
                }
            }
        }
        
        if(isExist){
            i += word.length();
            cnt += 1;
        }
    }
    
    cout << cnt << endl;

    return 0;
}



// 참고 링크:
