#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>deque1;
vector<int>deque2;
int dequeSwitch = 1;    //  현제 데이터들이 저장된 벡터

// MARK: - push_front X
void pushFront(int dqSwitch, int x) {
    if (dqSwitch == 1) {
        deque2.push_back(x);
        for (int i = 0; i < deque1.size(); i++) {
            deque2.push_back(deque1[i]); // 빈 벡터에 요소들을 그대로 삽입
        }
        while (deque1.size() != 0) {    //  원래 벡터 비우기
            deque1.pop_back();
        }
        dequeSwitch = 2;    //  스위치 전환
    }
    else {
        deque1.push_back(x);
        for (int i = 0; i < deque2.size(); i++) {
            deque1.push_back(deque2[i]); // 빈 벡터에 요소들을 그대로 삽입
        }
        while (deque2.size() != 0) {    //  원래 벡터 비우기
            deque2.pop_back();
        }
        dequeSwitch = 1;    //  스위치 전환
    }
}

// MARK: - pop_front
void popFront(int dqSwitch) {
    if (dqSwitch == 1) {
        if (deque1.size() == 0) {   //  들어있는 원소가 없는 경우 -1 출력
            cout << -1 << endl;
            return;
        }
        cout << deque1[0] << endl;
        for (int i = 1; i < deque1.size(); i++) {   //  첫번째 원소 빼고 빈 벡터에 삽입
            deque2.push_back(deque1[i]);
        }
        while (deque1.size() != 0) {    //  원래 벡터 비우기
            deque1.pop_back();
        }
        dequeSwitch = 2;
    }
    else {
        if (deque2.size() == 0) {   //  들어있는 원소가 없는 경우 -1 출력
            cout << -1 << endl;
            return;
        }
        cout << deque2[0] << endl;
        for (int i = 1; i < deque2.size(); i++) {   //  첫번째 원소 빼고 빈 벡터에 삽입
            deque1.push_back(deque2[i]);
        }
        while (deque2.size() != 0) {    //  원래 벡터 비우기
            deque2.pop_back();
        }
        dequeSwitch = 1;
    }
}

// MARK: - <#내용입력#>



// MARK: - Main 함수

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    while (n > 0) {
        string inputStr;
         cin >> inputStr;
        
        if (inputStr == "push_front" ) {
            int x;
            cin >> x;
            pushFront(dequeSwitch,x);
            
        }
        else if (inputStr == "push_back") {
            int x;
            cin >> x;
            if (dequeSwitch == 1) {
                deque1.push_back(x);
            }
            else {
                deque2.push_back(x);
            }
        }
        else if (inputStr == "pop_front") {
            popFront(dequeSwitch);
        }
        else if (inputStr == "pop_back") {
            if (dequeSwitch == 1) {
                if (deque1.size() == 0) {   //  벡터에 아무것도 없으면 -1 출력
                    cout << -1 << endl;
                }
                else {
                    cout << deque1[deque1.size()-1] << endl;
                    deque1.pop_back();
                }
            }
            else {
                if (deque2.size() == 0) {   //  벡터에 아무것도 없으면 -1 출력
                    cout << -1 << endl;
                }
                else {
                    cout << deque2[deque2.size()-1] << endl;
                    deque2.pop_back();
                }
            }
        }
        else if (inputStr == "size") {
            if (dequeSwitch == 1) {
                cout << deque1.size() << endl;
            }
            else {
                cout << deque2.size() << endl;
            }
        }
        else if (inputStr == "empty") {
            if (dequeSwitch == 1) {
                if (deque1.size() == 0) {
                    cout << 1 << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
            else {
                if (deque2.size() == 0) {
                    cout << 1 << endl;
                }
                else {
                    cout << 0 << endl;
                }
            }
        }
        else if (inputStr == "front") {
            if (dequeSwitch == 1) {
                if (deque1.size() == 0) {
                    cout << -1 << endl;
                }
                else {
                    cout << deque1[0] << endl;
                }
            }
            else {
                if (deque2.size() == 0) {
                    cout << -1 << endl;
                }
                else {
                    cout << deque2[0] << endl;
                }
            }
        }
        else if (inputStr == "back") {
            if (dequeSwitch == 1) {
                if (deque1.size() == 0) {
                    cout << -1 << endl;
                }
                else {
                    cout << deque1[deque1.size()-1] << endl;
                }
            }
            else {
                if (deque2.size() == 0) {
                    cout << -1 << endl;
                }
                else {
                    cout << deque2[deque2.size()-1] << endl;
                }
            }
        }
        n--;
    }
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/10866

/**
 


 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
