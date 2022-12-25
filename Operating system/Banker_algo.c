#include <stdio.h>
int main()
{

	int n, m, i, j, k;
	n = 5;  //process
	m = 4;  //resource
	int alloc[5][4] = { { 0, 0, 1, 2 },
						{ 1, 0, 0, 0 },
						{ 1, 3, 5, 4 },
						{ 0, 6, 3, 2 },
						{ 0, 0, 1, 4 } };

	int max_need[5][4] = { { 0, 0, 1, 2 },
                    { 1, 7, 5, 0 },
					{ 2, 3, 5, 6 },
					{ 0, 6, 5, 2 },
					{ 0, 6, 5, 6 } };

	int avail[4] = { 1, 5, 2, 0 };  //total instance- total allocated resource

	int fin[n], ans[n], work[n], ind = 0,need[n][m];

	for (k = 0; k < n; k++) {
		fin[k] = 0;
	}
	for (k = 0; k < n; k++) {
		work[k]=avail[k];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max_need[i][j] - alloc[i][j];
	}

	printf("Need Matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%d\t",need[i][j]);
        printf("\n");
	}

	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (fin[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > work[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						work[y] = work[y] + alloc[i][y];
					fin[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	for(int i=0;i<n;i++)
	{
	if(fin[i]==0)
	{
		flag=0;
		printf("The system is not safe");
		break;
	}
	}

	if(flag==1)
	{
	printf("\nThe safe Sequence is\n");
	for (i = 0; i < n - 1; i++)
		printf("T%d ->", ans[i]);
	printf(" T%d\n", ans[n - 1]);
	}


	return 0;
}
