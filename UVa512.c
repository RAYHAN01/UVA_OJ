#include<stdio.h>
#include<string.h>

#define MAXNUM 10000

typedef struct {
	char nm[4];
	int r[5];
	int op[20];
} ins;

int r, c, in_curr;
int p[2];
ins in[MAXNUM];

void readline() {
	scanf("%s", in[in_curr].nm);
	if(in[in_curr].nm[0] == 'E') {
		scanf("%d%d%d%d", in[in_curr].r, (in[in_curr].r)+1, (in[in_curr].r)+2, (in[in_curr].r)+3);
	} else {
		scanf("%d", in[in_curr].op);
		for (int i = 1; i <= in[in_curr].op[0]; i++) {
			scanf("%d", (in[in_curr].op) + i);
		} 
	}
}

void opline() {
	int i = 1, temp = 0;
	switch(in[in_curr].nm[0]) {
		printf("%s", in[in_curr].nm);
		case 'I':
			if (in[in_curr].nm[1] == 'R') {
				while(*p >= in[in_curr].op[i] && i <= in[in_curr].op[0]) {
					temp += 1;
					i++;
				}
				*p += temp;
			} else if (in[in_curr].nm[1] == 'C'){
				while(*(p+1) >= in[in_curr].op[i] && i <= in[in_curr].op[0]) {
					temp += 1;
					i++;
				}
				*(p+1) += temp;
			}
			break;
		case 'D':
			if (in[in_curr].nm[1] == 'R') {
				while(*p >= in[in_curr].op[i] && i <= in[in_curr].op[0]) {
					if (in[in_curr].op[i] == *p) {
						*p = 0;
						return;
					}
					temp += 1;
					i++;
				}
				*p -= temp;				
			} else if (in[in_curr].nm[1] == 'C'){
				while(*(p+1) >= in[in_curr].op[i] && i <= in[in_curr].op[0]) {
					if (in[in_curr].op[i] == *(p+1)) {
						*(p+1) = 0;
						return;
					}
					temp += 1;
					i++;
				}
				*(p+1) -= temp;				
			}
			break;
		case 'E':
			if ((*p == *(in[in_curr].r)) && (*(p+1) == *((in[in_curr].r) + 1))) {
				*p = *((in[in_curr].r) + 2);
				*(p+1) = *((in[in_curr].r) + 3); 
			} else if ((*p == *((in[in_curr].r) + 2)) && (*(p+1) == *((in[in_curr].r) + 3))) {
				*p = *(in[in_curr].r);
				*(p+1) = *((in[in_curr].r) + 1); 
			}
			break;
	}
}

int main() {
	int intotal, optotal, index = 0;
	while(scanf("%d%d", &r, &c) == 2 && r) {
		scanf("%d", &intotal);
		if (index) printf("\n");
		printf("Spreadsheet #%d\n", ++index);
		for (in_curr = 1; in_curr <= intotal; in_curr++) {
			readline();
		}		
		scanf("%d", &optotal);
		for (int j = 0; j < optotal; j++) {
			int rx, cx, flag = 0;
			scanf("%d%d", p, p+1);
			rx = *p;
			cx = *(p+1);
			for(in_curr = 1; in_curr <= intotal; in_curr++) {
				opline();
				if ((*p == 0) || (*(p+1) == 0)) {
					flag = 1;
					break;
				}
			}
			printf("Cell data in (%d, %d) ", rx, cx);
			if (flag) printf("GONE\n");
			else printf("moved to (%d, %d)\n", *p, *(p+1));
		}
	}
	return 0;
}
