#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    sort(scoville.begin(), scoville.end());

    int first = scoville[0];
    int i = 1;

    if (first < K) {
        int check = first + (scoville[1]*2);
        answer++;

        while (check < K) {
            check += (2 *scoville[i+1]);
            i++;
            answer++;
        }
    }

    return answer;
}