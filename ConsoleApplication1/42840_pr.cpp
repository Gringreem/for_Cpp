#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution_42840(vector<int> answers) {
    vector<int> count = { 0, 0, 0 };
    vector<int> answer;

    vector<int> first = { 1,2,3,4,5 };
    vector<int> second = { 2,1,2,3,2,4,2,5 };
    vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    for (int i = 0;i < answers.size();i++) {
        if (answers[i] == first[i % 5]) {
            count[0]++;
        }
        if (answers[i] == second[i % 8]) {
            count[1]++;
        }
        if (answers[i] == third[i % 10]) {
            count[2]++;
        }
    
    }
    int max = 0;
    for (int i = 0;i < 3;i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    for (int i = 0;i < 3;i++) {
        if (count[i] == max) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}