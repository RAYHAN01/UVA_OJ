#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char s[80];
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		double ele = 0.0;
		double total = 0.0;
		int num = 0;
		int p = 0;
		int len = strlen(s);
		for (int i = 0; i < len+1; i++) {
			if (s[i] == '\0') {
				if (p) num = 1;
				total = total + ele * num;
				break;
			}
			if (isdigit(s[i])) {
				num *= 10;
				num += (s[i] - '0');
				p = 0;
			} else {
				if (p) num = 1;
				total = total + ele * num;
				num = 0;
				switch (s[i]) {
					case 67: ele = 12.01; break;
					case 72: ele = 1.008; break;
					case 78: ele = 14.01; break;
					case 79: ele = 16.00; break;
				}
				p = 1;
			}
		}
		printf("%.3f\n", total);
	}
	return 0;
}
