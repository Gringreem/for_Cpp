#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0;

    for (int i = 0;i < dartResult.size();i++) {
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
        
        
        }
        else if (dartResult[i] == '#' || dartResult[i] == '*') {

        }
        else {
            num = dartResult[i] - '0';
        }
    }

    return answer;
}