#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int netGraph[101][101] = {0,};
int visited[101] = {0,};

void bfs(int target, int qty) {

    queue<int>bfsQueue;
    bfsQueue.push(target);
    
    // 큐가 비기전까지 실행
    while (!bfsQueue.empty()) {
        int now = bfsQueue.front();
        bfsQueue.pop();
        
        if (visited[now] == 0) {
            visited[now] = 1;
        }
        
        for (int where = 1; where < qty+1; where++) {
            if (netGraph[now][where] == 1 && visited[where] == 0) {
                bfsQueue.push(where);
            }
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    // 컴퓨터의 수
    int n;
    cin >> n;
    
    // 연결된 컴퓨터 쌍의 수
    int connected;
    cin >> connected;
    
    // 연결된 컴퓨터 쌍
    for (int i = 0; i < connected; i++) {
        int a, b;
        cin >> a >> b;
        netGraph[a][b] = 1;
        netGraph[b][a] = 1;
    }
    
    bfs(1, n);
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            continue;
        }
        if (visited[i]) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/2606

/**
 
- 방문배열 형태로 그래프를 입력받는다
 - BFS 로 정점에서 방문하면서 방문할 수 없는 노드를 체크한다
 - 방문할 수 없는 노드는 정점(1번)에서 독립된 그래프이므로 바이러스에 걸리지 않는다

 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
