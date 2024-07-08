#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/17262

/*
 풀이: 가장 빨리 하교하는 사람의 하교시간과 가장 늦게 등교하는 사람의 등교시간을 빼주면 된다
  두개의 값을 뺀 값이 양수라면 그 시간만큼 학교에 머문 것이고 음수라면 모두 겹치기 때문에 한번에 인사가 가능하므로
 
 */

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int minNum = 100001, maxNum = 0;
    
    for (int i = 0 ; i < n; i++) {
        int a,b;
        cin >> a >> b;
        minNum = min(minNum, b);
        maxNum = max(maxNum, a);
    }
    
    if(maxNum - minNum > 0){
        cout << maxNum - minNum << endl;
    } else {
        cout << 0 << endl;
    }
    

    return 0;
}



/*  참고 링크:
 https://jaynamm.tistory.com/entry/%EB%B0%B1%EC%A4%80-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-17262%EB%B2%88-%ED%8C%AC%EB%8D%A4%EC%9D%B4-%EB%84%98%EC%B3%90%ED%9D%98%EB%9F%AC
 
 
 
 */
