// 백준 12904번: A와 B - https://www.acmicpc.net/problem/12904
// 문제 요약 : 문자열 S를 T로 바꿀 수 있는지 판별하는 문제
// 풀이 방법 : (그리디), T의 길이가 S와 같아질 때까지 T의 마지막 글자를 제거하는 방식으로 풀이
// 시간 복잡도 : O(n) - T의 길이가 S와 같아질 때까지 최대 n번 반복

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