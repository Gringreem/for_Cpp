#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<int> solution_67258(vector<string> gems) {
    vector<int> answer;
    set<string> check;

    for (int i = 0;i < gems.size();i++) {
        check.insert(gems[i]);
    }
    int size = check.size();
    int start = 0, end = 0;

    map<string, int> gem;
    gem[gems[0]]++;
    int min = 100001;
    int fast = -1;

    while (start <= end && end < gems.size()) {
        if (size == gem.size()) {
            if ((end - start) < min) {
                min = end - start;
                fast = start;
            }
            gem[gems[start]]--;
            if (gem[gems[start]] == 0) {
                gem.erase(gems[start]);
            }
            start++;
            continue;
        }
        if (end == gems.size() - 1) {
            break;
        }
        end++;
        gem[gems[end]]++;
        if (gems[end] == gems[start]) {
            gem[gems[start]]--;
            start++;
            continue;
        }
        if (gems[start] == gems[start+1]) {
            gem[gems[start]]--;
            start++;
            continue;
        }
    }
    answer.push_back(fast + 1);
    answer.push_back(fast + min + 1);

    return answer;
}