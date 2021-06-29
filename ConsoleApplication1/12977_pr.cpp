#include <vector>
#include <iostream>

using namespace std;

int solution_12977(vector<int> nums) {
    int answer = 0;
    vector<int> list;

    for (int i = 0;i < nums.size()-2;i++) {
        for (int j = i + 1;j < nums.size()-1;j++) {
            for (int k = j + 1;k < nums.size();k++) {
                int sum = nums[i] + nums[j] + nums[k];
                list.push_back(sum);
            }
        }
    }

    for (int i = 0;i < list.size();i++) {
        int check = 0;
        for (int j = 2;j < list[i];j++) {
            if (list[i] % j == 0) {
                check++;
            }
        }
        if(check <1){
            answer++;
        }
    }

    return answer;
}