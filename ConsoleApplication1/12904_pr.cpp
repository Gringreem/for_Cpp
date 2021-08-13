#include <iostream>
#include <string>

using namespace std;

int solution_12904(string s)
{
    int answer = 0;
    
    int len = s.size();
    
    while (len >= 2) {
        for (int i = 0;i <= s.size() - len;i++) {
            int left = i;
            int right = len + i - 1;
            bool check = true;
            while(left < right) {
                if (s[left] != s[right]) {
                    check = false;
                    break;
                }
                left++;
                right--;
            }
            if (check) {
                return len;
            }

        }
        len--;
    }

    return 1;
}