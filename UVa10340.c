#include<stdio.h>
#include<string.h>

char s[200000];
char t[200000];

int main() {
	while (scanf("%s", s) != EOF) {
		scanf("%s", t);
		int len_s = strlen(s);
		int len_t = strlen(t);
		int i, j;
		for(i = 0, j = 0; i < len_s && j < len_t; j++) {
			if (s[i] == t[j]) {
				i++;
			}
		}
		
		if (i == len_s) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
