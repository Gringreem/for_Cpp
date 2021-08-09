#include <string>
#include <vector>

using namespace std;

int dp1[1000001], dp2[1000001];

int solution_68646(vector<int> a) {
    int answer = 0;

    dp1[0] = a[0];
    for (int i = 1;i < a.size();i++) {
        if (dp1[i - 1] > a[i]) {
            dp1[i] = a[i];
        }
        else {
            dp1[i] = dp1[i - 1];
        }
    }
    dp2[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2;i >= 0;i--) {
        if (dp2[i + 1] > a[i]) {
            dp2[i] = a[i];
        }
        else {
            dp2[i] = dp2[i + 1];
        }
    }
    for (int i = 0;i < a.size();i++) {
        if (a[i] <= dp1[i] || a[i] <= dp2[i]) {
            answer++;
        }
    }

    return answer;
}