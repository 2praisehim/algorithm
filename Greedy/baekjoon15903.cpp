// 백준 15903번: 카드 합체 놀이 - https://www.acmicpc.net/problem/15903
// 문제 요약 : 주어진 카드의 값을 이용하여 최소한의 연산으로 하나의 카드를 만드는 문제
// 풀이 방법 : (그리디), 우선순위 큐를 사용하여 가장 작은 두 카드를 선택하여 합친 후 다시 큐에 삽입
// 시간 복잡도 : O(m log n) - m번의 연산과 각 연산당 log n의 시간 소요

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // std::greater

long long solution() {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
 
        pq.push(sum);
        pq.push(sum);
    }

    long long answer = 0;

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}