// 백준 1213번: 팰린드롬 만들기 - https://www.acmicpc.net/problem/1213
// 문제 요약 : 주어진 문자열을 이용하여 팰린드롬을 만드는 문제
// 풀이 방법 : (그리디), 문자열을 정렬하여 같은 문자를 묶고, 홀수 개인 문자는 중간에 배치
// 시간 복잡도 : O(n log n) - 문자열 정렬에 소요

#include <iostream>
#include <string>
#include <algorithm> // std::sort(), std::reverse()

std::string solution() {
    std::string str;
    std::string outputStr = "";

    std::cin >> str;

    int strSize = str.size();
    std::sort(str.begin(), str.end());

    bool haveRootChar = false;
    std::string rootString = "";

    if (strSize % 2 != 0) { // 홀수일 때
        haveRootChar = true;
    }

    int i = 0;

    while (i < strSize) {
        if (str[i] == str[i + 1]) {
            outputStr.push_back(str[i]);

            i = i + 2;
        }
        else if (haveRootChar) {
            haveRootChar = false;
            rootString.push_back(str[i]);

            i = i + 1;
        }
        else {
            return "I'm Sorry Hansoo";
        }
    }

    std::string answer = outputStr;

    if (!rootString.empty()) {
        answer += rootString;
    }

    std::reverse(outputStr.begin(), outputStr.end());

    answer += outputStr;

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}