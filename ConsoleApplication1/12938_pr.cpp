#include <string>
#include <vector>

using namespace std;

vector<int> solution_12938(int n, int s) {
    vector<int> answer;

    if (s / n == 0) {
        answer.push_back(-1);
        return answer;
    }
    else {
        int first = s / n;
        int rest = s % n;

        for (int i = 1;i <= n;i++) {
            if (n-i >= rest) {
                answer.push_back(first);
            }
            else {
                answer.push_back(first + 1);
            }

        }
    }

    return answer;
}