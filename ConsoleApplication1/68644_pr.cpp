#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution_68644(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0;i < numbers.size()-1;i++) {
        for (int j = i + 1;j < numbers.size();j++) {
            int sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    } h

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}