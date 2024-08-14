#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>cardVec;
vector<int>haveVec;

int biSearch(int target, int start, int end) {
    // 원하는 값이 벡터내에 없는 경우(저구간 이분 탐색 완료)
    if (start > end) {
        return 0;
    }
    
    int mid = (start + end) / 2;
    
    // 목표값을 찾은 경우
    if (cardVec[mid] == target) {
        return 1;
    }
    // 목표값이 중간값보다 작은 경우
    else if (cardVec[mid] > target) {
        return biSearch(target, start, mid - 1);
    }
    // 목표값이 중간값보다 큰 경우
    else {
        return biSearch(target, mid + 1, end);
    }
    
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cardVec.push_back(tmp);
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        haveVec.push_back(tmp);
    }
    
    // MARK: - 정수 벡터 정렬
    sort(cardVec.begin(), cardVec.end());

    
    for (int i = 0; i < m; i++) {
        cout << biSearch(haveVec[i], 0, cardVec.size() - 1) << " ";
    }
    

    return 0;
}

// MARK: - 문제 접근 및 로직

//문제:   https://www.acmicpc.net/problem/10815

/**
 
벡터로 숫자들을 입력받아 반복문을 통해 가지고 있는 모든 숫자카드에 대해
 정수값이 존재하는지 이분탐색을 진행한다
 

 */


// MARK: - 트러블 슈팅

/*
 
 
 */


// MARK: - 참고 링크

// 참고 링크:

/*
 
 
 
 */
