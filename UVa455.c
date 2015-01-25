#include<stdio.h>
#include<string.h>
char data[85];

int main()
{
	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", data);
		int len = strlen(data);
		for (int i = 1; i <= len; i++) {
			if(len % i == 0) {
				int j = i;
				for (; j < len; j++) {
					if (data[j % i] != data[j]) break;
				}
				if (j == len) {
					printf("%d\n", i);
					break;
				}
			}
		}		
		if (n) {
			putchar('\n');
		}
	}
	return 0;
}
