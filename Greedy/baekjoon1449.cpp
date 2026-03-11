// 백준 1449번: 수리공 항승 - https://www.acmicpc.net/problem/1449
// 문제 요약 : 구멍이 있는 파이프를 수리하기 위해 필요한 테이프의 최소 개수를 구하는 문제
// 풀이 방법 : (그리디), 구멍의 위치를 정렬한 후, 테이프의 길이만큼 움직이며 구멍들을 한 번에 덮는 방식으로 풀이
// 시간 복잡도 : O(n log n) - 구멍의 위치를 정렬하는 데 소요

#include <iostream>
#include <vector>
#include <algorithm> // std::sort()

int solution() {
    int N;
    int L;

    std::cin >> N >> L;

    std::vector<int> leakage;

    for (int i = 0; i < N; i++) {
        int spot;
        std::cin >> spot;
        leakage.push_back(spot);
    }

    std::sort(leakage.begin(), leakage.end());

    int answer = 0;
    
    for (int i = 0; i < leakage.size(); ) {
        answer++;

        int tape = leakage[i] + L - 1;
        while (i < leakage.size() && leakage[i] <= tape) {
            i++;
        }
    }

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}