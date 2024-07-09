#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
//문제:   https://www.acmicpc.net/problem/11497


void TongFunc (vector<int>v){
    sort(v.begin(), v.end());
    
    // 정렬된 통나무를 큰 수 부터 back과 front를 번갈아 가며 덱에 삽입하면 가장 높은 통나무가 가운데에,
    // 양옆으로 가장 차이가 적은 통나무들이 피라미드 형태로 들어서게 된다
    
    deque<int>dqTong;
    bool isBack = true;
    
    while (!v.empty()) {
        if(isBack) {
            dqTong.push_back(v.back());
            v.pop_back();
            isBack = false;
        } else {
            dqTong.push_front(v.back());
            v.pop_back();
            isBack = true;
        }
    }
    
    int minLevel = 0;
    
    minLevel = max(minLevel,abs(dqTong.back()-dqTong.front())); // 문제상에 조건은 통나무 배치가 원형이므로 덱의 첫번째 front와 back 의 차도 반영해야 한다
    for (int i = 1; i < dqTong.size(); i++) {
        int gap = abs(dqTong[i]-dqTong[i-1]);
        minLevel = max(minLevel,gap);   // 각 통나무들의 간격의 최댓값을 구한다
    }
    
    cout << minLevel << endl;
    
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        vector<int>v;
        int n;
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            
        }
        TongFunc(v);

    }

    return 0;
}



// 참고 링크:
