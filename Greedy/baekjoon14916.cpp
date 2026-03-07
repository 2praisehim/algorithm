// 백준 14916번: 거스름돈 - https://www.acmicpc.net/problem/14916
// 문제 요약 : 5원과 2원으로 거슬러 줄 수 있는 최소 개수의 동전을 구하는 문제
// 풀이 방법 : (그리디), 5원으로 최대한 거슬러 주고, 나머지를 2원으로 거슬러 주는 방식으로 풀이
// 시간 복잡도 : O(n) - 최악의 경우 2원으로만 거슬러 주는 경우 n/2번 반복

#include <iostream>

int solution() {
    int answer = 0;

    int n = 0;
    std::cin >> n;

    if (n % 5 == 0) {
        answer = n / 5;
    }
    else {
        int count = 0;

        while (n > 0) {
            n = n - 2;
            count++;
            if (n % 5 == 0) {
                answer = count + n / 5;
                break;
            }
        }

        // break에 걸리지 않고 나왔을 경우
        if (n < 0)
            answer = -1;
    }

    return answer;
}

int main()
{
    std::cout << solution();

    return 0;
}