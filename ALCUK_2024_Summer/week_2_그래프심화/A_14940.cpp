// *** FAILED ***
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_NUM 1001

int map[MAX_NUM][MAX_NUM] = {0,};
bool visited[MAX_NUM][MAX_NUM];
int result[MAX_NUM][MAX_NUM];
int dx[4] = {1,-1,0,0}; //  동서남북의 x,y 이동 저장
int dy[4] = {0,0,-1,1};
int y, x;
int n, m;


void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[y][x] = true;
    result[y][x] = 0;
    
    while (!q.empty()) {
        pair<int, int> coord = q.front();
        for (int i = 0; i < 4; i++) {
            int x_next = coord.first + dx[i];
            int y_next = coord.second + dy[i];
            
            if (x_next >= 0 && x_next < n && y_next >= 0 && y_next < n ) {
                if (map[y_next][x_next] == 1 && !visited[y_next][x_next]) {
                    q.push({x_next, y_next});
                    visited[y_next][x_next] = true;
                    result[y_next][x_next] = result[coord.second][coord.first] + 1;
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

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                y = i;
                x = j;
            }
        }
    }
    bfs(x,y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (result[i][j] == 0 && map[i][j] == 1) {
                cout << -1 << ' ';
            }
            else {
                cout << result[i][j] << ' ';
            }
        }
        cout << endl;
    }
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/14940

/**
 - 최단거리 탐색이므로 BFS 사용
 -

 */


// MARK: - 트러블 슈팅

/*
 1. 길이 있는데 가지못하는 곳을 반영 못하는 듯 하다
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 https://www.acmicpc.net/board/view/134219
 https://velog.io/@ooo1324/%EB%B0%B1%EC%A4%80-14940%EB%B2%88-%EC%89%AC%EC%9A%B4-%EC%B5%9C%EB%8B%A8%EA%B1%B0%EB%A6%AC-C
 
 */
