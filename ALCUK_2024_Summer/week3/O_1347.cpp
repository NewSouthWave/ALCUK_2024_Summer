#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/1347
    
/**
 
 게임을 하는 것처럼 각 커맨드들에 대한 함수를 작성하낟
 크게 Left, Right, Forward 에대한 움직임에 대한 함수를 만들고
 플레이어에 방향에 따라 다른 동작을 하게 한다
 
 bool형 차원 배열의 (0,0) 인덱스를 시작점으로 간주하며 각 커맨드에 따라 배열을 따라 움직이고
 한번 거쳐간 인덱스는 true 처리한다
 
 이때 주의할 점은
 1. 만약 행이나 열에서 0 이하의 인덱스로 향해야 하는 경우는 기존에 체크된 배열을 그대로 우측이나 아래로 밀어야한다
 -> 이때 원래 위치는 false 처리한다
 2. 배열(미로)의 출력을 위해 행과 열의 크기를 알아야한다
 

 */

bool mazeArr[100][100] = {0,};  //  미로 (2차원 배열)
char playerDirection = 'S';     //  플레이어 방향
pair<int, int>coordinates(0,0);      //  플레이어좌표
int rowLength = 1, colLength = 1;

void leftFunc () {
    switch (playerDirection) {
        case 'E':
            playerDirection = 'N';
            break;
        case 'W':
            playerDirection = 'S';
            break;
        case 'S':
            playerDirection = 'E';
            break;
        case 'N':
            playerDirection = 'W';
            break;
            
        default:
            break;
    }
}

void rightFunc() {
    switch (playerDirection) {
        case 'E':
            playerDirection = 'S';
            break;
        case 'W':
            playerDirection = 'N';
            break;
        case 'S':
            playerDirection = 'W';
            break;
        case 'N':
            playerDirection = 'E';
            break;
            
        default:
            break;
    }
}

void forwardFunc() {
    if (playerDirection == 'N') {
        if (coordinates.second -1 >= 0 ) {  //  플레이어의 Y좌표가 1이상일 때
            coordinates.second -= 1;    //  Y좌표 변경
            mazeArr[coordinates.second][coordinates.first] = true;
//            colLength++;
        } else {    // 그렇지 않은 경우
            for (int i = colLength - 1; i >= 0; i--) { // 세로기준 가장 밑줄부터 한칸씩 밑으로 민다
                for (int j = 0; j < rowLength; j++) {
                    if (mazeArr[i][j]) {
                        mazeArr[i+1][j] = true;
                        mazeArr[i][j] = false;
                    }
                }
            }
            mazeArr[coordinates.second][coordinates.first] = true;  //  플레이어 현재 좌표는 변하지 않고 한칸씩 밑으로 밀었음
            colLength++;
        }
    }
    
    else if (playerDirection == 'W') {
        if (coordinates.first - 1 >= 0 ) {  //  플레이어의 X좌표가 1이상일 때
            coordinates.first -= 1;    //  Y좌표 변경
            mazeArr[coordinates.second][coordinates.first] = true;
//            rowLength++;
        } else {    // 그렇지 않은 경우
            for (int i = rowLength - 1; i >= 0; i--) { // 가장 오른쪽부터 한칸씩 오른쪽 민다
                for (int j = 0; j < colLength; j++) {
                    if (mazeArr[j][i]) {
                        mazeArr[j][i+1] = true;
                        mazeArr[j][i] = false;
                    }
                }
            }
            mazeArr[coordinates.second][coordinates.first] = true;  //  플레이어 현좌표는 변하지 않고 한칸씩 오른쪽으로 밀었음
            rowLength++;
        }
    }
    
    else if (playerDirection == 'S') {
        coordinates.second += 1;
        mazeArr[coordinates.second][coordinates.first] = true;
        if (coordinates.second > colLength - 1) {   //  기존 행의 길이를 넘어서는 경우만 길이 증가
            colLength++;
        }
    }
    
    else if (playerDirection == 'E') {
        coordinates.first += 1;
        mazeArr[coordinates.second][coordinates.first] = true;
        if (coordinates.first > rowLength - 1) {    // 기존 열 길이를 넘어서는 경우만
            rowLength++;
        }
    }
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int strLength;
    cin >> strLength;
    
    string mazeOrder;
    
    cin >> mazeOrder;

    
    mazeArr[0][0] = true;
    
    for (int i = 0; i < strLength; i++) {
        switch (mazeOrder[i]) {
            case 'L':
                leftFunc();
                break;
                
            case 'R':
                rightFunc();
                break;
                
            case 'F':
                forwardFunc();
                break;
                
            default:
                break;
        }
        
    }
    
    for (int i = 0; i < colLength; i++) {
        for (int j = 0; j < rowLength; j++) {
            if (mazeArr[i][j]) {
                cout << '.';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }

    return 0;
}



// 참고 링크:
