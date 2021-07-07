#include <string>
#include <vector>

using namespace std;

int solution_17676(vector<string> lines) {
    int answer = 0;
    vector<int> start, end;

    for (int i = 0;i < lines.size();i++) {
        string h = lines[i].substr(11, 2);
        string m = lines[i].substr(14, 2);
        string s = lines[i].substr(17, 2);
        string ms = lines[i].substr(20, 3);

        int process = stof(lines[i].substr(24, 5)) * 1000;
        int hour = stoi(h) * 3600 * 1000;
        int min = stoi(m) * 60 * 1000;
        int sec = stoi(s) * 1000 + stoi(ms);

        start.push_back(hour + min + sec - process + 1);
        end.push_back(hour + min + sec);
    }

    for (int i = 0;i < lines.size();i++) {
        int plusSecTime = end[i] + 1000;
        int count = 0;

        for (int j = i; j < lines.size();j++) {
            if (start[j] < plusSecTime) {
                count++;
            }
        }
        if (answer < count) {
            answer = count;
        }
    }

    return answer;
}