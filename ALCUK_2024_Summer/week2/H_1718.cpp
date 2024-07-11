#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
//문제:   https://www.acmicpc.net/problem/1718

/**
 


 */

void decodeFunc(string plainTxt, string passKey) {
    
    vector<char>encryptedTxt;   // 암호문 저장 벡터
    
    // 암호화 키의 길이가 평문 이상 경우
    if(passKey.length() >= plainTxt.length()) {
        for (int i = 0; i < passKey.length(); i++) {
            if(plainTxt[i] == ' ') {
                encryptedTxt.push_back(32);
                continue;
            }
            int keyNum = passKey[i] - 96;   // 알파벳에서의 순서
            if(plainTxt[i] - keyNum < 97) { // a 이전의 알파벳인 경우
                encryptedTxt.push_back(plainTxt[i]-keyNum + 26);
            } else {
                encryptedTxt.push_back(plainTxt[i]-keyNum);

            }
            
        }} else {    // 평문의 길이가 암호화 키 이상인 경우
            for (int i = 0; i < plainTxt.length(); i++) {
                if(plainTxt[i] == ' ') {
                    encryptedTxt.push_back(32);
                    continue;
                }
                int keyNum = passKey[i % passKey.length()] - 96;
                if(plainTxt[i] - keyNum < 97) {
                    encryptedTxt.push_back(plainTxt[i]-keyNum + 26);
                } else {
                    encryptedTxt.push_back(plainTxt[i]-keyNum);
                }
                
            }
        }
    
    for (int i = 0; i < encryptedTxt.size(); i++) {
        cout << encryptedTxt[i];
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    string plainTxt, passKey;
    
    getline(cin, plainTxt); // 공백을 포함하여 한 줄 전체 입력 가능
    getline(cin, passKey);
    
    
    decodeFunc(plainTxt,passKey);
    

    return 0;
}



// 참고 링크:
