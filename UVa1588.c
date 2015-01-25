#include<stdio.h>
#include<memory.h>
#define MAX(x, y) x>y?x:y
#define MIN(x, y) x<y?x:y
char top[110];
char bottom[110];

int main() {
	int i, j, lenb, lent, min_1, min_2;
	memset(top, '0', sizeof(top));
	memset(bottom, '0', sizeof(bottom));
	while(scanf("%s%s", bottom, top) != EOF) {
		lenb = strlen(bottom);
		lent = strlen(top);
		for(i = 0; i < lenb;) {
			for(j = 0; j < lent; j++) {
				if((top[j] - '0' + bottom[i+j] - '0') > 3) {
					i++;
					break;
				}
			}
			if (j == lent) {
				min_1 = MAX(lenb, lent + i);
				break;
			}
		}
		if (i == lenb) min_1 = lenb + lent;
		if (min_1 == MAX(lenb, lent)) printf("%d\n", min_1);
		else {
			for(i = 0; i < lent;) {
				for(j = 0; j < lenb; j++) {
					if((bottom[j] - '0' + top[i+j] - '0') > 3) {
						i++;
						break;
					}
				}
				if (j == lenb) {
					min_2 = MAX(lent, lenb + i);
					break;
				}
			}
			if (i == lent) min_2 = lenb + lent;
			printf("%d\n", MIN(min_1, min_2));
		}
		memset(top, '0', sizeof(top));
		memset(bottom, '0', sizeof(bottom));
	}
	return 0;
}
