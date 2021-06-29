#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution_42889(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> percent;
    double all = stages.size();

    for (int i = 1;i <= N;i++) {
        int fail = 0;

        for (int j = 0;j < stages.size();j++) {
            if (stages[j] == i) {
                fail++;
            }
        }
        if (fail == 0) {
            percent.push_back(0);
        }
        else {
            percent.push_back(fail / all);
        }
        all -= fail;
        
    }

    for (int i = 0;i < N;i++) {
        auto itr = max_element(percent.begin(), percent.end());
        answer.push_back(itr - percent.begin() + 1);
        *itr = -1;
    }
    

    return answer;
}
