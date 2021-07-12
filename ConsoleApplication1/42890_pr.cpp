#include <string>
#include <vector>
#include <set>

using namespace std;

bool check(vector<int> v, int n) {
    for (int i = 0;i < v.size();i++) {
        if ((v[i] & n) == v[i]) {
            return false;
        }
    }
    return true;
}

int solution_42890(vector<vector<string>> relation) {
    vector<int> answer;

    int key = relation[0].size();
    int tuple = relation.size();

    for (int i = 1;i < (1 << key); i++) {
        set<string> s;
        for (int j = 0;j < tuple;j++) {
            string now = "";

            for (int k = 0;k < key;k++) {
                if (i & (1 << k)) {
                    now += relation[j][k];
                }
            }
            s.insert(now);
        }

        if (s.size() == tuple && check(answer, i)) {
            answer.push_back(i);
        }
    }

    return answer.size();
}