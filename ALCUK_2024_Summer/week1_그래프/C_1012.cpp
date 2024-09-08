#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int graph[60][60];
int visited[60][60];
int dx[4] = {0 ,0, 1, -1};
int dy[4] = {1 ,-1, 0, 0};
//vector<pair<int, int>>delta ={{0,1},{0,-1},{-1,0},{1,0}}; //상-하-좌-우 의 (x,y)


bool dfs(int nodeY, int nodeX, int sero, int garo) {
    int y = nodeY;
    int x = nodeX;
    
    if (visited[y][x]) {    // 이미 방문한 좌표라면 연결되어있는 구역
        return false;
    }
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        
        if (nextY >= 0 && nextY < sero && nextX >= 0 && nextX < garo) {
            // 배추가 심어져 있는데 방문한적이 없는 경우
            if (graph[nextY][nextX]) {
                dfs(nextY, nextX, sero, garo);

            }
        }
    }
    return true;
}
    

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t > 0) {
        int m, n, k;
        cin >> m >> n >> k; // 가로-세로-배추개수
        
        memset(graph, 0, sizeof(graph));
        memset(visited , 0, sizeof(visited));
        
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
        }
        
        int bugCnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] && !visited[i][j]) {
                    if(dfs(i, j, n, m)) bugCnt++;   // 깊이 우선으로 탐색해서 모두 새로운 좌표면 별개의 구역이므로 벌레수를 추가한다

                }
            }
        }
        
        cout << bugCnt << endl;
        t--;
    }
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1012

/**
 
 - 2차원 배열을 놓고보았을 때 기준점에서 인접한 상하좌우 한칸씩 연결되어 있는지 확인해야함
 - DFS 필요할 듯


 */


// MARK: - 트러블 슈팅

/*
 
 - 여러 테스트 케이스를 받으므로 각 테스트 케이스마다 배열들을 초기화 해야함
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 https://phil-baek.tistory.com/entry/%EB%B0%B1%EC%A4%80-1012-%EC%9C%A0%EA%B8%B0%EB%86%8D-%EB%B0%B0%EC%B6%94-%ED%92%80%EC%9D%B4-C
 
 
 
 
 */
