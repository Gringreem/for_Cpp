#include <vector>
#include<algorithm>

using namespace std;

int solution_1845(vector<int> nums)
{
    int answer = 0;
    int whole = nums.size();
    int get = whole / 2;
    int count = 1;

    sort(nums.begin(), nums.end());
    
    for (int i = 0;i < whole-1;i++) {
        if (nums[i] < nums[i + 1]) {
            count++;
        }
    }

    if (count > get) {
        answer = get;
    }
    else {
        answer = count;
    }

    return answer;
}