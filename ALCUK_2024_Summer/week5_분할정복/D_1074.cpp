#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r, c, answer;

void zuluSearch(int length, int row, int col, int indexNum) {
    if (length == 2) {
        if (row < length / 2) {
            if (col < length / 2) {  //  0사분면
                answer = indexNum;
            } else {    //  1사분면
                answer = indexNum + 1;
            }
        }
        else {
            if (col < length / 2) {  //  2사분면
                answer = indexNum + 2;
            } else {    //  3사분면
                answer = indexNum + 3;
            }
        }
        return;
    }
    
    else {
        int startIdx;
        if (row < length / 2) {
            if (col < length / 2) {  //  0사분면
                startIdx = indexNum;
                zuluSearch(length / 2, row, col, startIdx);
            } else {    //  1사분면
                startIdx = indexNum + pow(length / 2, 2);
                zuluSearch(length / 2, row, col - length / 2, startIdx);
            }
        }
        else {
            if (col < length / 2) {  //  2사분면
                startIdx = indexNum + pow(length / 2, 2) * 2;
                zuluSearch(length / 2, row - length / 2, col, startIdx);

            } else {    //  3사분면
                startIdx = indexNum + pow(length / 2, 2) * 3;
                zuluSearch(length / 2, row - length / 2, col - length / 2, startIdx);

            }
        }

    }
    return;
}



int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> c;
    
    zuluSearch(pow(2, n), r, c, 0);
    
    cout << answer << endl;
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1074

/**
 
 4분면 분할 방식을 사용한다


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
