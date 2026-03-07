// 백준 1213번: 팰린드롬 만들기 - https://www.acmicpc.net/problem/1213
// 문제 요약 : 주어진 문자열을 이용하여 팰린드롬을 만드는 문제
// 풀이 방법 : (그리디), 문자열을 정렬하여 같은 문자를 묶고, 홀수 개인 문자는 중간에 배치
// 시간 복잡도 : O(n log n) - 문자열 정렬에 소요

#include <iostream>
#include <string>
#include <algorithm> // std::reverse()

int solution() {
    int answer = 0;

    std::string S = "";
    std::string T = "";

    std::cin >> S >> T;

    while (T.size() > S.size()) {
        if (T[T.size() - 1] == 'A') { // Last character is A
            T.assign(T.begin(), T.end() - 1);
        }
        else { // Last character is B
            T.assign(T.begin(), T.end() - 1);
            std::reverse(T.begin(), T.end());
        }
    }

    if (S == T) {
        answer = 1;
    }
    else {
        answer = 0;
    }

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}