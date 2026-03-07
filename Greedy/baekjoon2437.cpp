// 백준 2437번: 저울 - https://www.acmicpc.net/problem/2437
// 문제 요약 : 주어진 무게를 이용하여 저울에 올려놓을 수 있는 모든 무게를 구하는 문제
// 풀이 방법 : (그리디), 무게를 정렬한 후, 각 무게를 더하여 만들 수 있는 모든 무게를 구하는 방식으로 풀이
// 시간 복잡도 : O(n log n) - 무게를 정렬하는 데 소요

#if 0 // 풀이 방법 1: 모든 무게의 조합을 구하는 방식 -> 시간 초과
#include <iostream>
#include <vector>
#include <algorithm> // std::sort(), std::insert, std::unique

int solution() {
    int N;

    std::cin >> N;

    std::vector<int> inputWeight{};
    std::vector<int> makeWeight{};

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        inputWeight.push_back(a);
    }

    std::sort(inputWeight.begin(), inputWeight.end());

    for (int i = 0; i < N; i++) {
        if (makeWeight.empty()) {
            makeWeight.push_back(inputWeight[i]);
            continue;
        }

        int weight = inputWeight[i];
        std::vector<int> v{};

        v.push_back(weight);

        for (int j = 0; j < makeWeight.size(); j++) {
            v.push_back(weight + makeWeight[j]);
        }

        makeWeight.insert(makeWeight.end(), v.begin(), v.end());

        std::sort(makeWeight.begin(), makeWeight.end());
        makeWeight.erase(std::unique(makeWeight.begin(), makeWeight.end()), makeWeight.end());
    }

    return makeWeight.back() + 1;
}
#else // 풀이 방법 2: 무게를 정렬한 후, 새로운 무게가 들어올 때마다 만들 수 없는 무게를 찾는 방식 -> 통과
#include <iostream>
#include <vector>
#include <algorithm> // std::sort()

int solution() {
    int N;
    std::cin >> N;

    std::vector<int> w(N);

    for (int i = 0; i < N; i++)
        std::cin >> w[i];

    std::sort(w.begin(), w.end());

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        if (w[i] > sum + 1)
            break;

        sum += w[i];
    }

    return sum + 1;
}
#endif

int main()
{
    std::cout << solution();

    return 0;
}