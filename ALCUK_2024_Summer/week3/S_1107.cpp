#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//문제:   https://www.acmicpc.net/problem/1107

/**
 
 1.  초기값 숫자가 목표 채널인  두 개의 변수에 각각 1씩 더하고 1씩 뺀 값을 저장한다. 목표 채널에서 상행과 하행으로 탐색한다
 2. 고장나지 않은 버튼들로 각 채널들을 만들 수 있는지 검사한다. 만들 수 없으면 각 변수에 1씩 더하거나 1씩 뺀다
 3. 고장나지 않은 버튼의 숫자들로 이루어진 경우에, 두 개의 변수와 원래 채널의 차가 작은 쪽을 택한다
 4. 마지막으로 그냥 + , - 버튼 만 눌렀을 때와의 횟수중 작은 쪽을 택한다
 
 그리고 수많은 삽질 결과 꽤 많은 경우를 고려해야 한다
 
  1. 모든 버튼이 고장난 경우
  2. 모든 버튼이 정상인 경우
  3. 0번 버튼만 정상인 경우
 
 */

#define MAX_NUM 5000000 // 범위 넉넉하게 (최대 채널보다 큰 숫자를 누를 수 있으므로
int channel = 100;
int firstChannel = 100;
bool btn[10] = {0,};
int btnCnt = 0;


// MARK: - 고장안난 버튼들로 채널을 누를 수 있는지 체크

bool checkBtn(string num) {
    for (int i = 0; i < num.length(); i++) {
        int index = num[i]-'0'; // char형 int로 변환
        if (btn[index]) {  // 각 자릿수들을 눌러 고장난 버튼인 경우에 함수 종료 -> 다른 수로 탐색
            return false;
            break;
        }
    }
    return true;
}

// MARK: - 메인 로직 함수

void remoteFunc() {
    
    if (channel == 0) { //  0번 채널일 경우
        int upNum = 0;
        for (int i = channel ; i <= MAX_NUM ; i++) {   //  인덱스 상행 검사
            if(checkBtn(to_string(i))) {
                upNum = i;
                break;
            }
        }
        int tmpChannel = upNum; //  + , - 조절 버튼을 누르기 전에 고장안난 버튼들로 설정하는 채널

        int tmpCnt = to_string(tmpChannel).length() + abs(channel - tmpChannel);
        
        btnCnt = min(tmpCnt,abs(channel - firstChannel));   //  + , - 키로만 조작한 횟수와 비교하여 작은 수로 결정

        
    }
    else {
        bool isDown = false;
        int downNum = 0, upNum = 0;
        
        for (int i = channel  ; i >= 0 ; i--) {   //  인덱스 하행 검사
            if(checkBtn(to_string(i))) {
                isDown -= true;
                downNum = i;
                break;
            }
        }
        
        for (int i = channel ; i <= MAX_NUM ; i++) {   //  인덱스 상행 검사
            if(checkBtn(to_string(i))) {
                upNum = i;
                break;
            }
        }
        
        if (isDown) {   //  상행과 하행 둘다 채널을 이동할 수 있는 경우
            int tmpChannel; //  + , - 조절 버튼을 누르기 전에 고장안난 버튼들로 설정하는 채널
            
            if ((channel - downNum) > (upNum - channel)) {
                tmpChannel = upNum;
            } else {
                tmpChannel = downNum;
            }
            
            int tmpCnt = (to_string(tmpChannel)).length() + abs(channel - tmpChannel);
            
            btnCnt = min(tmpCnt,abs(channel - firstChannel));   //  + , - 키로만 조작한 횟수와 비교하여 작은 수로 결정
        } else {    // 상행으로만 이동가능한 채널이 존재하는 경우
            int tmpCnt = (to_string(upNum)).length() + abs(channel - upNum);
            btnCnt = min(tmpCnt,abs(channel - firstChannel));   //  + , - 키로만 조작한 횟수와 비교하여 작은 수로 결정

        }
        
        
        
    }
    
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> channel;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        btn[tmp] = true;    //  true된 인덱스는 버튼이 고장난 것
    }
    
    if (channel == 100 && n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (!btn[0]) {  //  0버튼만 남는 경우
        int brokenNum = 0;
        for (int i = 1; i <= 9; i ++) {
            if (btn[i]) {
                brokenNum++;
            }
        }
        if (brokenNum == 9) { //  0버튼 빼고 1~9까지 모두 고장난 경우
            if (channel < firstChannel) {
                cout << min(channel + 1, abs(channel - firstChannel))  << endl; //  목표 채널 + 1 한값과 채널 100에서 목표채널까지의 +-버튼 이동 횟수 중 최솟값 채택
                return 0;
                
            }
        }
    }
    
    
    
    if(n == 10) {   //  모든 버튼 고장난 경우
        cout << abs(firstChannel - channel) << endl;    // +- 로만 이동가능
        return 0;
    }
    else if(n == 0) {   //  고장나지 않은경우
        int len = to_string(channel).length();
        int ans = min(len, abs(firstChannel - channel));
        cout << ans  << endl;
        return 0;
    } else {    // 위의 사례들을 제외하고 1개 이상 고장난 경우
        remoteFunc();
    }
    
    
    cout << btnCnt << endl;
    
    return 0;
}



// 참고 링크:
