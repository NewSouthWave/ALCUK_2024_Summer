#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int grid[101][101] = {0,};
ll dp[1001][1001] = {0,};

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    // 게임판 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 만약 시작점의 점프가능한 칸이 0이면 도달 불가이므로 즉시 종료
    if (grid[0][0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    dp[0][0] = 1; //  첫번째 칸의 dp 값은 1로 설정
    
    // 게임판에 각 한칸씩을 기준판으로 설정하여 모두 순회
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //마지막 칸 도달시 반복문 종료
            if (i == n-1 && j == n-1) {
                break;
            }
            ll value = dp[i][j];
            int jump = grid[i][j];

            if (value == 0 || jump == 0) {   //  기준칸의 dp 값이 0이면 스킵(이미 기준칸까지 도달할 수 없으므로
                continue;
            }
            else {
                //도달 가능한 dp 배열에 좌표에 각 기준칸 경로까지의 경우의 수를 더해준다
                if (i+jump < n) {
                    dp[i+jump][j] += value;
                }
                if (j+jump < n) {
                    dp[i][j+jump] += value;
                }
            }
        }
    }
    
    
    cout << dp[n-1][n-1] << endl;

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/1890

/**
 
 - (0,0) 부터 (n-1,n-2)) 까지 도달 가능한 경로수를 계속 저장해가며
 도달할 수 있는 좌표의 dp 배열에 계속 경로수를 더해준다
 - 경로의 수는 2^63-1 이하이므로 dp배열은 long long 형으로 선언해주어야 한다


 */


// MARK: - 트러블 슈팅

/*
 
 void findRoute(int x, int y, int cnt, int size) {
     if (!grid[x][y]) {
         return;
     }
     
     cnt += grid[x][y];
     if (cnt == 2*(size-1)) {
         routeCnt++;
         return;
     }
     
     findRoute(x, y + grid[x][y], cnt, size);
     findRoute(x + grid[x][y], y, cnt, size);
     
 }
 
 *이런식으로 재귀를 활용한 브루투포스로 접근하면 시간초과 발생한다
 
 */

// dp 배열을 long long 으로 선언해주어야함

// MARK: - 참고 링크

// 참고 링크:

/*
 
 https://code-angie.tistory.com/12
 
 */
