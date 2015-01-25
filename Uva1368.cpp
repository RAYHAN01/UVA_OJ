#include<cstdio>
#include<cstring>

char stat[5][1010];
char result[1010];

int main()
{
	char *temp;
	temp = (char *) malloc (1005);
	if(temp == NULL) {
		return 1;
	}
	int count, m, n, sum;
	char imina, iminb, imin, mina, minb, min;
	scanf("%d", &count);
	for (int idx = 0; idx < count; idx++) {
		scanf("%d", &m);
		scanf("%d", &n);
		memset(stat[0], 0, n);
		memset(stat[1], 0, n);
		memset(stat[2], 0, n);
		memset(stat[3], 0, n);
		for (int i = 0; i < m; i++) {
			scanf("%s", temp);
			for (int j = 0; j < n; j++) {
				switch(temp[j]) {
					case 'A':
						stat[0][j]++;
						break;
					case 'C':
						stat[1][j]++;
						break;
					case 'G':
						stat[2][j]++;
						break;
					case 'T':
						stat[3][j]++;
						break;
				}				
			}
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			if(stat[0][i] >= stat[1][i]) {
				imina = 0;
				mina = stat[0][i];
			} else {
				imina = 1;
				mina = stat[1][i];
			}
			if(stat[2][i] >= stat[3][i]) {
				iminb = 2;
				minb = stat[2][i];
			} else {
				iminb = 3;
				minb = stat[3][i];
			}
			if(stat[imina][i] >= stat[iminb][i]) {
				imin = imina;
			} else {
				imin = iminb;
			}
			min = stat[imin][i];
			switch(imin) {
				case 0:
					result[i] = 'A';
					break;
				case 1:
					result[i] = 'C';
					break;
				case 2:
					result[i] = 'G';
					break;
				case 3:
					result[i] = 'T';
					break;
			}
			sum	+= (int) min;					
		}
		result[n] = '\0';
		sum = (n * m - sum);
		printf("%s\n%d\n", result, sum);
	}
	free(temp);
	return 0;
}
