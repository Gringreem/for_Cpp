#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    map<string, string> parent;
    map<string, int> mp;

    for (int i = 0;i < enroll.size();i++) {
        parent[enroll[i]] = referral[i];
        mp[enroll[i]] = i;
    }
    for (int i = 0;i < seller.size();i++) {
        int sell = amount[i] * 100;
        int up = sell / 10;
        string upper = parent[seller[i]];
        int n = mp[seller[i]];
        answer[n] += sell - up;
        sell = up;
        up = sell / 10;
        while (sell > 0 && upper != "-") {
            n = mp[upper];
            answer[n] += sell - up;
            sell = up;
            up = sell / 10;
            upper = parent[upper];
        }

    }

    return answer;
}