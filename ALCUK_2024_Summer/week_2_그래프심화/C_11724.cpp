#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, compNum = 1;
vector<int>graph[1001];
int checked[1001];


void bfs(int num) {
    queue<int>q;
    q.push(num);
    checked[num] = 1;

    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        
        
        for (int where = 0; where < graph[now].size(); where++) {
            if (!checked[graph[now][where]]) {
                q.push(graph[now][where]);
                checked[graph[now][where]] = 1;
            }
        }
    }
   
    return;
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 무방향 그래프 구현(인접리스트)
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bool notDone = true;
    int tmp = 1;
    
    while (notDone) {
        if (notDone) {
            bfs(tmp);
        }
        notDone = false;
        for (int i = 1; i <= n ; i++ ) {
            if (!checked[i]) {
                tmp = i;
                notDone = true;
                compNum++;
                break;
            }
        }
        
    }
    
    cout << compNum << endl;
    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/11724

/**
 


 */


// MARK: - 트러블 슈팅

/*
 1. 메모리 초과 발생
 - 방문하지 않는 노드가 있는 경우, bfs 내부애서 재귀로 처리하던 것을 main함수에서 while문을 활용하여 bfs를 실행하도록 함
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
