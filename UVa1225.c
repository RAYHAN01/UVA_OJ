#include<stdio.h>
#include<string.h>
int data[10];

int main()
{
	int n = 0;
	scanf("%d", &n);
	while(n--) {
		int num = 0;
		memset(data, 0, sizeof(data));
		scanf("%d", &num);
		for (int i = 1; i <= num; i++) {
			int j = i;
			do {
				data[j%10] = data[j%10] + 1;
				j /= 10;
			} while (j);
		}
		printf("%d %d %d %d %d %d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9]);
	}
}
