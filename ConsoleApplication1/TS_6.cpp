#include <string>
#include <vector>

using namespace std;

long long  check(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    else if (n > 0) {
        long long first = 1;
        long long second = 2;
        long long third = 4;

        long long tmp = 0;
        int count = n - 3;

        for (int i = 0;i < count;i++) {
            tmp = first;
            first = second;
            second = third;
            third += tmp + first;
        }
        return third;
    }
    else {
        return -1;
    }
}

long long solution(int numOfStairs) {
    long long answer = 0;

    answer = check(numOfStairs);

    return answer;
}