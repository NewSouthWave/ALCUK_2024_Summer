#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int length;
int currentY, currentX;
int targetY, targetX;

int chess[310][310];
int checked[310][310];

// 2칸씩 움직이는 변수 (동-남-서-북)
int dx[4] = {2, 0 , -2, 0};
int dy[4] = {0, -2 , -0, 2};
// 1칸씩 움직이는 변수 (상-좌-하-우)
int dx2[4] = {0, -1 , 0, 1};
int dy2[4] = {1, 0 , -1, 0};


void bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({y,x});
    checked[y][x] = true;
    chess[y][x] = 0;
    // * 이번 문제에선 8방향으로 움직여야한다
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            pair<int, int>coord = q.front();
            int newY = coord.first + dy[i];
            int newX = coord.second + dx[i];
            for (int j = i % 2; j < i % 2 + 3; j += 2) {
                int nextY = newY + dy2[j];
                int nextX = newX + dx2[j];
                if (nextY >= 0 && nextY < length && nextX >= 0 && nextX < length) {
                    // 방문하지 않은 경우
                    if (!checked[nextY][nextX]) {
                        q.push({nextY,nextX});
                        checked[nextY][nextX] = true;
                        chess[nextY][nextX] = chess[coord.first][coord.second] + 1;
                    }
                    // 이미 방문한 경우
                    else {
                        chess[nextY][nextX] = min(chess[coord.first][coord.second] + 1, chess[nextY][nextX]);
                    }
                }
            }
            
            
        }
        q.pop();
    }
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    while (t > 0) {
        
        // 0으로 배열들 초기화
        memset(chess, 0, sizeof(chess));
        memset(checked , 0, sizeof(checked));
        
        // 체스판의 크기 입력
        cin >> length;
        // 나이트가 현재 있는 칸
        cin >> currentY >> currentX;
        // 이동하려는 칸
        cin >> targetY >> targetX;
        
        bfs(currentY, currentX);
        
        cout << chess[targetY][targetX] << endl;
        t--;
    }

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/7562

/**
 
- 대각선 이동을 구현해야 하므로 상하좌우 2칸 이동 후 각각 상하 혹은 좌우로 한칸씩 이동하는 BFS를 수행하게 한다

 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
