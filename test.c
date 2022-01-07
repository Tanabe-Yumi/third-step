#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int sci[20] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
	int eng[20] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
	int sum_s = 0, sum_e = 0;
	double avg_s, avg_e;
	double sdd_s, sdd_e;

	for (int i = 0; i < 20; i++) {
		sum_s += sci[i];
		sum_e += eng[i];
	}
	avg_s = sum_s / 20.0;
	avg_e = sum_e / 20.0;

	for (int i = 0; i < 20; i++) {
		sdd_s += powf((double)(sci[i] - avg_s), 2.0);
		sdd_e += powf((double)(eng[i] - avg_e), 2.0);
	}

	sdd_s = sqrt(sdd_s / 20.0);
	sdd_e = sqrt(sdd_e / 20.0);
	printf("-- 理科 --\n");
	printf("平均点　：%.2f\n", avg_s);
	printf("標準偏差：%.2f\n", sdd_s);
	printf("合計点　：%d\n", sum_s);
	
	printf("\n-- 英語 --\n");
	printf("平均点　：%.2f\n", avg_e);
	printf("標準偏差：%.2f\n", sdd_e);
	printf("合計点　：%d\n", sum_e);

	printf("\n-- 偏差値 --\n");
	printf("num | science | english\n");
	for (int i = 0; i < 20; i++) {
		printf(" %2d : %7.2f", i + 1, (sci[i] - avg_s) / sdd_s * 10 + 50);
		printf("   %7.2f\n", i + 1, (eng[i] - avg_e) / sdd_e * 10 + 50);
	}

	int sorted_sci[20][2] = {0};
	int max = 0, id = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (sci[j] > max){
				max = sci[j];
				id = j;
			}
		}
		sorted_sci[i][0] = id;
		sorted_sci[i][1] = max;
		sci[id] = -1;
		max = 0;
		id = 0;
	}
	printf("\n-- 理科 点数の高い順 --\n");
	printf("No. | score\n");
	for (int i = 0; i < 20; i++) {
		printf("%3d : %4d\n", sorted_sci[i][0] + 1, sorted_sci[i][1]);
	}

	int sorted_eng[20][2] = {0};
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (eng[j] > max){
				max = eng[j];
				id = j;
			}
		}
		sorted_eng[i][0] = id;
		sorted_eng[i][1] = max;
		eng[id] = -1;
		max = 0;
		id = 0;
	}
	printf("\n-- 英語 点数の高い順 --\n");
	printf("No. | score\n");
	for (int i = 0; i < 20; i++) {
		printf("%3d : %4d\n", sorted_eng[i][0] + 1, sorted_eng[i][1]);
	}

	return 0;
}
