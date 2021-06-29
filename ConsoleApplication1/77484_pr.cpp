#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution_77484(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0;
    int count_zero = 0;

    for (int i = 0;i < 6;i++) {
        auto check = find(win_nums.begin(), win_nums.end(), lottos[i]);
        if (lottos[i] == 0) {
            count_zero++;
        }

        if (check == win_nums.end()) {
                
        }
        else {
            count++;
        }
    }
    int max = count + count_zero;
    int min = count;

    if (max < 2) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - max);
    }

    if (min < 2) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - min);
    }

    return answer;
}