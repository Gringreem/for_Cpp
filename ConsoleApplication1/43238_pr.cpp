#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution_43238(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    int desk = times.size();

    long long first = 1;
    long long last = (long long) times[desk - 1] * n;
    long long mid;

    while (first <= last) {
        mid = (first + last) / 2;
        long long cnt = 0;

        for (int i = 0;i < desk;i++) {
            cnt += mid / times[i];
        }
        if (cnt < n) {
            first = mid + 1;
        }
        else {
            if (mid <= last) {
                answer = mid;
            }
            last = mid - 1;
        }
    }
    

    return answer;
}