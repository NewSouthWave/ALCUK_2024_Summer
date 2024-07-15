#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/1268

/**
 
 문제 조건은 같은 반을 한 횟수가 아닌 "한번이라도 같은반을 했던 횟수" 이므로
 조건을 잘 따져봐야 한다
 
 조건문을 통해 같은 학년별로 같은 반이었던 횟수를 카운트 하되, 다른 학년에서 이미 같은 반이 었던  학생들은 스킵한다

 */

vector<vector<int>>studentClass;
int sameClass[1001] = {0,};
bool isSameClass[1001][1001] = {0,};

void findSameClass (int n, int targetStudent, int grade) {
    for (int i = 0; i < n; i++) {
        if(i == targetStudent) {
            continue;
        }
        
        if (isSameClass[targetStudent][i]) {    //  이미 한번 같은 반이었던 경우는 스킵
            continue;
        }
        if(studentClass[i][grade] == studentClass[targetStudent][grade]) {
            sameClass[targetStudent]++;
            isSameClass[targetStudent][i] = true;   // 같은반이었던 적이 있다고 체크한다
        }
    }
}


int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {
        vector<int>tmpVec;

        for (int j = 0 ; j < 5; j++) {
            int tmp;
            cin >> tmp;

            tmpVec.push_back(tmp);
        }
        studentClass.push_back(tmpVec);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < 5; j++) {
            findSameClass(n,i,j);
        }
    }
    
    int maxStudent = -1;
    int maxStudentNum = 0;
    for (int i = 0; i < n; i++) {
        if(sameClass[i] > maxStudent) {
            maxStudent = sameClass[i];
            maxStudentNum = i;
        }
    }
    
    cout << maxStudentNum +1<< endl;
    
    

    return 0;
}



// 참고 링크:
