#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution_12927(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> q(works.begin(), works.end());

    for (int i = 0;i < n;i++) {
        if (q.top() > 0) {
            int tmp = q.top();
            q.pop();
            q.push(tmp - 1);
        }
    }

    while (!q.empty()) {
        answer += (long long)q.top() * (long long)q.top();
        q.pop();
    }

    return answer;
}