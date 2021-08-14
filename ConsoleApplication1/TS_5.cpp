#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fruitWeights, int k) {
    vector<int> answer;

    for (int i = 0;i <= fruitWeights.size() - k;i++) {
        priority_queue<int> q(fruitWeights.begin() +i, fruitWeights.begin() + i +k);
        answer.push_back(q.top());
    }

    sort(answer.begin(), answer.end(), greater<int>());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}