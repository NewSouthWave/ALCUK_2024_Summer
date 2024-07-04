#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제: https://www.acmicpc.net/problem/24262

//MenOfPassion(A[], n) {
//    i = ⌊n / 2⌋;
//    return A[i]; # 코드1
//}

// 위의 함수의 시간 복잡도에 관한 문제

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    cout << 1 << endl << 0 << endl; // 항상 코드 1의 실행 횟수는 1회이고 시간복잡도는 O(1) 이다

    return 0;
}



// 참고 링크:
