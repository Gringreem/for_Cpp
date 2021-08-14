#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(int servers, bool sticky, vector<int> requests) {
    vector<vector<int>> answer(servers);

    if (sticky) {
        int k = 0;
        answer[k++].push_back(requests[0]);
        for (int i = 1;i < requests.size();i++) {
            if (k >= servers) {
                k = 0;
            }
            for (int j = 0;j < servers;j++) {
                if (find(answer[j].begin(), answer[j].end(), requests[i]) != answer[j].end()) {
                    k = j;
                    break;
                }
            }
            answer[k++].push_back(requests[i]);
        }
    }
    else {
        for (int i = 0;i < requests.size();i++) {
            int r = i % servers;
            answer[r].push_back(requests[i]);
        }
    }

    return answer;
}