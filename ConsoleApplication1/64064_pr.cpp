#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check[8];
int user_len, ban_len;
set<string> s;

void find(int index, string res, vector<string> user_id, vector<string> banned_id) {
    if (index == ban_len) {
        sort(res.begin(), res.end());
        s.insert(res);
        return;
    }

    string ban = banned_id[index];
    int ban_len = ban.size();

    for (int i = 0; i < user_len;i++) {
        string user = user_id[i];

        if (user.size() != ban_len) continue;
        if (check[i]) continue;

        bool same = true;
        for (int j = 0;j < ban_len;j++) {
            if (ban[j] == '*')continue;
            if (user[j] != ban[j]) {
                same = false;
                break;
            }
        }

        if (same) {
            check[i] = true;
            find(index + 1, res + to_string(i), user_id, banned_id);

            check[i] = false;
        }
    }
}

int solution_64064(vector<string> user_id, vector<string> banned_id) {
    
    int answer = 0;

    user_len = user_id.size();
    ban_len = banned_id.size();

    find(0, "", user_id, banned_id);
    answer = s.size();
    
    return answer;
}