//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//
//
//int arr[32770][32770] = {0,};   //  크기가 너무 커서 사용 불가인 듯 하다
//bool check[32770][32770] = {0,};
//
//int maxLength;
//
//void visitFunc(int row, int col, int visitNum) {
//    arr[row][col] = visitNum;
////    check[row][col] = true;
//    
//    arr[row][col + 1] = visitNum + 1;
////    check[row][col + 1] = true;
//    
//    arr[row + 1][col] = visitNum + 2;
////    check[row + 1][col] = true;
//    
//    arr[row + 1][col + 1] = visitNum + 3;
////    check[row + 1][col + 1] = true;
//    
//    return;
//}
//
//void zuluVisit(int row, int col, int length, int visitNum) {
//    visitFunc(row, col, visitNum);
//
//    if (length == 2) {
//        return;
//    } else {
//        int lengthPow = pow(length / 2, 2);
//        zuluVisit(row, col, length / 2, visitNum);
//        zuluVisit(row, col + length / 2, length / 2, visitNum + lengthPow);
//        zuluVisit(row + length / 2, col, length / 2, visitNum + lengthPow * 2);
//        zuluVisit(row + length / 2, col + length / 2, length / 2, visitNum + lengthPow * 3);
//    }
//
//    return;
//}
//
//int main(){
//    ios::sync_with_stdio(false); //동기화 해제
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n, r, c;
//    
//    cin >> n >> r >> c;
//    
//    maxLength = pow(2, n);
//    
//    zuluVisit(0, 0, maxLength, 0);
//    
//    // ***출력 테스트 코드***
//    for (int i = 0; i < maxLength; i++) {
//        for (int j = 0; j < maxLength; j++) {
//            cout << arr[i][j] << "   ";
//        }
//        cout << endl;
//    }
//
//    
//    cout << arr[r][c] << endl;
//    
//    return 0;
//}
//
//// MARK: - 문제 접근 및 로직
//
////문제:   https://www.acmicpc.net/problem/1074
//
///**
// 
//
//
// */
//
//
//// MARK: - 트러블 슈팅
//
///*
// 
// < BOJ 컴파일 에러 발생 >
//    - 배열크기가 커서 그런것으로 추정
//    - int 배열 대신 다른 자료형이나 알고리즘을 고려해야 할 듯
// 
// 
// */
//
//
//// MARK: - 참고 링크
//
//// 참고 링크:
//
///*
// 
// 
// 
// */
