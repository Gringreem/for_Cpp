#include <string>
#include <vector>

using namespace std;

int solution(int money, int minratio, int maxratio, int ranksize, int threshold, int months) {
	int answer = 0;

	int ratio[101];

	answer = money / 100 * 100;
	
	ratio[0] = 0;

	for (int i = 1;i <= (maxratio-minratio);i++) {
		ratio[i] = minratio + (i - 1);
	}

	for (int i = 0;i < months;i++) {
		for (int j = 0;j < 101;j++) {
			int percent = ratio[j] / 100;
			if (answer < (threshold + (percent * ranksize))) {
				answer -= answer * percent;
				answer = answer / 100 * 100;
				break;
			}
			else {
				continue;
			}
		}
	}

	return answer;
}