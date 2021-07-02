#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution_17677(string str1, string str2) {
    
    vector<string> sub_str1;
    vector<string> sub_str2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for (int i = 0;i < str1.size() - 1;i++) {
        string str = str1.substr(i, 2);
        if (str[0] >= 'a' && str[0] <= 'z' && str[1] >= 'a' && str[1] <= 'z') {
            sub_str1.push_back(str);
        }
    }

    for (int i = 0;i < str2.size() - 1;i++) {
        string str = str2.substr(i, 2);
        if (str[0] >= 'a' && str[0] <= 'z' && str[1] >= 'a' && str[1] <= 'z') {
            sub_str2.push_back(str);
        }
    }

    if (sub_str1.empty() && sub_str2.empty()) {
        return 65536;
    }

    int min = 0;
    int max = sub_str1.size() + sub_str2.size();

    if (sub_str1.size() > sub_str2.size()) {
        for (int i = 0;i < sub_str2.size();i++) {
            auto itr = find(sub_str1.begin(), sub_str1.end(), sub_str2[i]);
            if (itr != sub_str1.end()) {
                min++;
                sub_str1.erase(itr);
            }
        }
    }
    else {
        for (int i = 0;i < sub_str1.size();i++) {
            auto itr = find(sub_str2.begin(), sub_str2.end(), sub_str1[i]);
            if (itr != sub_str2.end()) {
                min++;
                sub_str2.erase(itr);
            }
        }
    }

    max -= min;

    if (max == 0) return 65536;

    double temp = (double)min / (double)max;

    return temp * 65536;
}