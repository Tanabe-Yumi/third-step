#include <stdio.h>
#include <math.h>

void swap (int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int array[], int array_size) {
	int i, j;
	for(i = 0; i < array_size - 1; i++) {
		for(j = array_size - 1; j >= i + 1; j--) {
			if(array[j] > array[j - 1]){
				swap(&array[j], &array[j - 1]);
			}
		}
	}
}

int main()
{
	int i, j;
	int science[20] = { 65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70 };
	int english[20] = { 44, 87, 100, 65, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84 };
	double avg[2] = {0}, dev[2] = {0}, sum[2] = {0};
	double hensa[2][20] = {0};
	double var[2] = {0.0};

	for(i = 0; i < 2; i++) {
		for(j = 0; j < 20; j++) {
			if(i == 0)
				sum[i] += science[j];
			if(i == 1)
				sum[i] += english[j];
		}
	}
	for(i = 0; i < 2; i++) {
		avg[i] = sum[i] / 20;
		for(j = 0; j < 20; j++)
		{
			var[i] += pow(( science[j] - avg[i] ), 2.0);	
		}
		dev[i] = sqrt(var[i] / 20);
	}
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 20; j++) {
			if(i == 0)
				hensa[i][j] = (science[j] - avg[i]) / dev[i] * 10 + 50;
			else
				hensa[i][j] = (english[j] - avg[i]) / dev[i] * 10 + 50;
		}
	}

	bubble_sort(science, 20);
	bubble_sort(english, 20);

	printf("avg_science = %lf, avg_english = %lf\n", avg[0], avg[1]);
	printf("dev_science = %lf, dev_english = %lf\n", dev[0], dev[1]);
	printf("sum_science = %lf, sum_english = %lf\n", sum[0], sum[1]);
	for(i = 0; i < 20; i++) {
		printf("(%d) hensa_science = %lf, hensa_english = %lf\n", i, hensa[0][i], hensa[1][i]);
	}
	printf("science, english\n");
	for(i = 0; i < 20; i++) {
		printf("%d	, %d\n", science[i], english[i]);
	}
}
