#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/2480


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>dice;
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        dice.push_back(num);
    }
    sort(dice.begin(), dice.end());
    
    int sameDice = 1;
    int sameDiceNum = dice[2];
    
    for (int i = 1; i < 3; i++) {
        if(dice[i-1] == dice[i]){
            sameDiceNum = dice[i];
            sameDice++;
        }
    }
    
    int prize = 0;
    if(sameDice == 1){
        prize = 100 * dice[2];
    } else if (sameDice == 2){
        prize = 1000 + sameDiceNum * 100;
    } else {
        prize = 10000 + sameDiceNum * 1000;
    }
    
    cout << prize << endl;

    return 0;
}



// 참고 링크:
