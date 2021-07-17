#include <string>
#include <vector>

using namespace std;

vector<char> second;

bool check(string str, int k, int start) {
	
	for (int i = 0;i < second.size();i++) {
		if (second[i] != str[start + (i*(k+1))]) {
			return false;
		}
	}
	return true;
}

int solution(string line1, string line2) {
	int answer = 0;

	int size1 = line1.size();
	int size2 = line2.size();

	for (int i = 0;i < size2;i++) {
		second.push_back(line2[i]);
	}
	int k = 0;
	int len = size2 + (k * (size2 - 1));

	while (size1-len >= 0) {
		for (int i = 0;i < (size1 - len);i++) {
			if (check(line1, k, i)) {
				answer++;
			}
		}
		
		k++;
		
	}

	return answer;
}