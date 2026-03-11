// 백준 2122번: 센서 - https://www.acmicpc.net/problem/2122
// 문제 요약 : 주어진 센서의 위치를 이용하여 최소한의 케이블 길이로 모든 센서를 연결하는 문제
// 풀이 방법 : (그리디), 센서 위치를 정렬하고, 인접한 센서 간의 거리를 계산하여 K-1개의 가장 긴 거리를 제거하여 그룹으로 묶음
// 시간 복잡도 : O(n log n) - 센서 위치 정렬에 소요

#include <iostream>
#include <vector>
#include <algorithm> // std::sort, std::less std::unique

int solution() {
    int N = 0;
    int K = 0;

    std::cin >> N >> K;

    std::vector<int> v{};

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        v.push_back(a);
    }

    if (v.size() <= K) {
        return 0;
    }

    std::sort(v.begin(), v.end(), std::less<int>());

    std::vector<int> diff{};

    for (int i = 1; i < v.size(); i++) {
        diff.push_back(v[i] - v[i - 1]);
    }

    std::sort(diff.begin(), diff.end(), std::less<int>());

    for (int i = 0; i < K - 1; i++) {
        diff.pop_back();
    }

    int answer = 0;

    for (int i = 0; i < diff.size(); i++) {
        answer += diff[i];
    }

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}