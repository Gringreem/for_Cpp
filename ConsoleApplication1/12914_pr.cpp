#include <string>
#include <vector>

using namespace std;

long long solution_12914(int n) {
    int DP[2001];

    DP[1] = 1;
    DP[2] = 2;
    for (int i = 3;i <= n;i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 1234567;
    }

    return DP[n];
}