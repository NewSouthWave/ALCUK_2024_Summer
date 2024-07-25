#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
//문제:   https://www.acmicpc.net/problem/13458

/**
 
 각 시험장마다의 학생들의 수에서 감독관이 커버 가능한 인원을 0명이 될 때까지 뺀다
 - 총감독관은 시험장마다 한명이므로 최초 1회만 빼준다
 - 그후 남은 학생 수는 부감독관의 몫이다
 - 남은 학생 수에서 부감독관의 커버 가능한 학생수를 나누고 나누어 떨어지지 않으면 올림한다 (부족하면 안되므로)
 - 나누어 떨어지면 몫이, 나누어떨어지지 않으면 올림까지 한 값이 필요한 부감독관의 수이다
 - 총감독관의 수와 부감독관의 수를 더한다
 
 최대 입력크기가 100만이므로 시간복잡도도 고려해야 함
 %$%$%$#%#$ long long 써야함!!!!!!! #$%$#^$
 -> 총 감독관의 수에서 int의 범위를 넘어설 수 있음

 */

vector<int>testerNum;

ll supervisorCalc(int sup, int viceSup) {
    ll totalSup = 0;

    for (int tester : testerNum) {
        tester -= sup;  //  총감독관의 감시 인원을 뺀다
        totalSup += 1;
        
        if (tester <= 0) {  // 총감독관만 필요한 경우
            continue;
        }
        else {          //  부감독관도 필요한 경우
            if (tester < viceSup) { // 총감독관의 감시 인원을 뺀 수가 부감독관의 감시 인원보다 작은 경우
                totalSup += 1;  // 1명만 더 있으면 된다
            } else {
                
                if (tester % viceSup == 0) {    //  부감독관의 감시 인원으로 나누어 떨어지면
                    tester /= viceSup;      // 값 그대로 사용
                } else {                // 나누어 떨어지지 않으면
                    tester = tester / viceSup + 1;      // 나눈 몫에 1을 더함(올림)
                }
                
                totalSup += tester;
            }
        }
        

       
        
    }
    
    return totalSup;
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int testRoom;
    int supervisor, viceSup;
    
    cin >> testRoom;
    for (int i = 0; i < testRoom; i++) {
        int tmp;
        cin >> tmp;
        testerNum.push_back(tmp);
    }
    
    cin >> supervisor >> viceSup;
    
    cout << supervisorCalc(supervisor, viceSup) << endl;;
    

    return 0;
}



// 참고 링크:
