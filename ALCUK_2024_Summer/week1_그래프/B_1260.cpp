#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int graph[1001][1001] = {0,};
int dfsVisited[1001] = {0,};
int bfsVisited[1001] = {0,};

void dfs(int node, int qty) {
    cout << node << " ";
    dfsVisited[node] = 1;
    
    for (int search = 1; search < qty+1; search++) {
        // 정점이 존재하고 방문하지 않은 경우
        if (graph[node][search] == 1 && dfsVisited[search] == 0) {
            dfs(search, qty);
        }
    }
    
}

void bfs(int node, int qty) {
    queue<int>bfsQueue;
    bfsQueue.push(node);
    
    while (!bfsQueue.empty()) { //  큐가 빌때까지 수행
        int now = bfsQueue.front();
        bfsQueue.pop();
        
        // 탐색하고자 하는 노드를 방문하지 않은 경우
        if (!bfsVisited[now]) {
            cout << now << " ";
            bfsVisited[now] = 1;
        }
        
        // 정점이 존재하고 방문하지 않은 경우
        for (int search = 1; search < qty+1; search++) {
            if (graph[now][search] == 1 && bfsVisited[search] == 0) {
                bfsQueue.push(search);
            }
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;
    
    for (int i = 0; i < m; i++) {
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
        graph[tmp2][tmp1] = 1;
    }
    
    dfs(v, n);
    cout << endl;
    bfs(v, n);
    cout << endl;

    
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1260

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
