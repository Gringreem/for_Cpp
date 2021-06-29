#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution_42891(vector<int> food_times, long long k) {

    long long sum = 0, before = 0;
    priority_queue<pair<int, int>> timeQ;
    for (int i = 0;i < food_times.size();i++) {
        sum += food_times[i];
        timeQ.push(make_pair(-food_times[i], i + 1));
    }
    if (sum <= k) return -1;
    while ((-timeQ.top().first - before) * timeQ.size() <= k) {
        k -= (-timeQ.top().first - before) * timeQ.size();
        before = -timeQ.top().first;
        timeQ.pop();
    }

    vector<pair<int, int>> timeV;
    while (!timeQ.empty()) {
        timeV.push_back(make_pair(timeQ.top().second, -timeQ.top().first));
        timeQ.pop();
    }
    sort(timeV.begin(), timeV.end());

    return timeV[k % timeV.size()].first;
}