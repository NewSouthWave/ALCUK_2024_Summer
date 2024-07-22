#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/15970

/**
 


 */

#define MAX_NUM 100001

pair<bool, int>arr[MAX_NUM];   //  위치 표시 pair 형 배열 / first: 점 존재여부 , second: 색깔
vector<int>dotLoca;            // 점들의 위치를 미리 저장함
int maxLoca;                    // 가장 숫자가 큰 점의 위치
int totalLength = 0;

void calcLength(int loca) {
    int downLength = 0, upLength = 0;
    
    for (int i = loca - 1; i >= 0 ; i--) {  //  인덱스 하행 탐색
        if(!arr[i].first) { //  점이 없는 인덱스인 경우
            continue;
        } else {    //  점이 있는 인덱스인 경우
            if (arr[loca].second == arr[i].second) {
                downLength = loca - i;
                break;      //  가장 짧은 거리를 찾았으므로 반복문 종료
            }
        }
    }
    
    for (int i = loca + 1; i <=  maxLoca; i++) {  //  인덱스 상행 탐색
        if(!arr[i].first) { //  점이 없는 인덱스인 경우
            continue;
        } else {    //  점이 있는 인덱스인 경우
            if (arr[loca].second == arr[i].second) {
                upLength = i - loca;
                break;      //  가장 짧은 거리를 찾았으므로 반복문 종료
            }
        }
    }
    
    if (downLength == 0 && upLength == 0) { //  둘다 0인 경우는 스킵
        return;
    }
    if (downLength == 0) {
        totalLength += upLength;
    } else if (upLength == 0) {
        totalLength += downLength;
    } else {
        totalLength += min(downLength, upLength);
    }
    
    return;
        
}


void arrowFunc() {
    for (int loca : dotLoca) {
        calcLength(loca);
    }
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int loca, color;
        cin >> loca >> color;
        
        arr[loca] = make_pair(true, color); //  pair를 만들어서 배열에 저장
        dotLoca.push_back(loca);
    }
    
    sort(dotLoca.begin(), dotLoca.end());
    maxLoca = dotLoca[dotLoca.size()-1];
    
    arrowFunc();
    
    cout << totalLength << endl;
    
    return 0;
}



// 참고 링크:
