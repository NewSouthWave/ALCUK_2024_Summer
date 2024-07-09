#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;

//문제: https://www.acmicpc.net/problem/15761

/*
 
 소 n은 앞에 n마리에 소가 있어도 기다릴 수 있는 것을 뜻한다
 즉 소3이 줄을 섰는데 앞에 10마리의 소가 있다면 줄을 서지 않고 돌아가므로
 레몬에이드를 준비할 필요가 없음을 뜻한다
 
 */

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>v;
    deque<int>dq;
    
    int n;
    cin >> n;
    
    for (int i = 0 ; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(),greater<>());   // 입력 값을 벡터로 받아 내림차순 정렬
    
    for (int i = 0 ; i < n; i++) {  // 덱에 원소 삽입
        dq.push_back(v[i]);
    }
    
    vector<int>cowLine;
    bool isFront = true;
    
    while (!dq.empty()) {   // 덱이 빌 때까지 실행
        if(isFront){    // 큰 수들 먼저 줄을 세우려고 함
            if(dq.front() >= cowLine.size()){   // front 값이 줄선 소들보다 작다면
                cowLine.push_back(dq.front());  // 줄에 삽입
                dq.pop_front();
                isFront = false;
            } else {    // front 값이 줄선 소들보다 크다면
                dq.pop_front(); // 그냥 덱에서 제거
                isFront = false;
                
            }
            
        } else {    // 숫자가 작은 소들
            if(cowLine.size() <= dq.back()) {   // 줄선 소들보다 숫자가 크면 덱에서 대기
                isFront = true;
            } else {    //   작으면 얄짤없이 덱에서 제거
                dq.pop_back();
                isFront = true;
            }
        }
    }
    
    cout << cowLine.size() << endl;

    return 0;
}



// 참고 링크:
