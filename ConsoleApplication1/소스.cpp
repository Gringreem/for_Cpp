#include <string>
#include <vector>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    
    vector<string> tmp = user_id;

    for (int i = 0;i < banned_id.size();i++) {
        int size = banned_id[i].size();

        for (int j = 0;j < tmp.size();) {
            bool same = false;
            string check = tmp[j];

            if (check.size() == size) {
                for (int k = 0;k < size;k++) {
                    if (banned_id[i][k] == '*') {
                        if (k == size - 1) {
                            same = true;
                        }
                    }
                    else {
                        if (banned_id[i][k] == check[k]) {
                            if (k == size - 1) {
                                same = true;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            if (same) {
                tmp.erase(tmp.begin() + j + 1);
            }
            else {
                j++;
            }
        }

    }

    return tmp.size();
}