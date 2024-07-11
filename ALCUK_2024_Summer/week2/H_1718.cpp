#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
//문제:   https://www.acmicpc.net/problem/1946

/**
 
 서류점수와 면접점수를 pair vector에 저장하여 서류 점수 순으로 정렬하고
 앞뒤 사람의 면접 점수를 비교하여 면접점수가 앞선 사람보다 뒤쳐지면 선발되지 않는 것으로 전체 인원에서 뺀다
 
 이때 가장 높은 순위 값을 저장하며 비교해나간다. 그래야 앞뒤로 붙어있진 않지만 특정 지원자보다 순위가 둘다 낮은
 지원자를 가려낼 수 있다

 */


void EmployFunc (vector<pair<int, int>>v,int n){
    
    int maxEmploy = n;
    
    int highRank = v[0].second;
    for (int i = 0; i < v.size(); i++) {
        if(highRank < v[i].second) {   // 면접 점수도 뒤떨어지는 경우
            maxEmploy -= 1;
        } else {
            highRank = v[i].second; //  가장 높은 순위를 저장

        }
    }
    
    cout << maxEmploy << "\n";
    
}

bool compareFunc(pair<int, int>a, pair<int, int>b) { //  pair first 기준 오름차순 정렬
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false); //동기화 해제
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        vector<pair<int, int>>v;
        int n;
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            int docuScore, interviewScore;
            cin >> docuScore >> interviewScore;

            
            v.push_back(make_pair(docuScore, interviewScore));
            
        }
        sort(v.begin(), v.end(), compareFunc);  // pair first 기준으로 정렬
        
        EmployFunc(v,n);
    }

    return 0;
}



// 참고 링크:   https://sanghyu.tistory.com/36
