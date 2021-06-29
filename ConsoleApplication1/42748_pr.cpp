#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution_42748(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0;i < commands.size();i++) {
        int first = commands[i][0];
        int end = commands[i][1];
        int where = commands[i][2];

        vector<int> newvec;
        for (int j = first-1;j < end;j++) {
            newvec.push_back(array[j]);
        }
        sort(newvec.begin(), newvec.end());
        answer.push_back(newvec[where - 1]);
    }

    return answer;
}