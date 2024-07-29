#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

char arr[128][128];
int blueCnt = 0;
int whiteCnt = 0;

void squareCut(int sero, int garo, int length) {
    bool check = true;  //  특정 범위의 칸의 색깔이 모두 같다는 가정
    
    for (int i = sero; i < sero + length; i++) {
        for (int j = garo; j < garo + length; j++) {
            if (arr[sero][garo] != arr[i][j]) { //  첫번째 칸과 다른 칸의 색깔이 다른 경우
                check = false;
                break;
            }
        }
    }
    
    if (check) {    //  범위 안의 칸의 색깔이 모두 같음
        if (arr[sero][garo] == '1') {
            blueCnt++;
        } else {
            whiteCnt++;
        }
        return; //  함수 종료
    }
    
    // 4등분 하여 분할정복
    squareCut(sero, garo, length / 2);
    squareCut(sero, garo + length / 2, length / 2);
    squareCut(sero + length / 2, garo, length / 2);
    squareCut(sero + length / 2, garo + length / 2, length / 2);
    
    return;
    
}




int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    squareCut(0, 0, n);
    cout << whiteCnt << endl << blueCnt << endl;
    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/2630

/**
 
2차원 배열로 입력받아 4등분해가며 4등분한 범위에 같은 색깔로 이루어져 있는지 판별

 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
