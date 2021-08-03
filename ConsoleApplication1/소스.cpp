#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<char> vec;

    for (int i = 65;i <= 90;i++) {
        vec.push_back((char)i);
    }

    for (int i = 0;i < msg.length();i++) {
        char check;
        check += msg[i];
        check += msg[i + 1];
    }

    return answer;
}