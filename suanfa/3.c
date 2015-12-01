#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int row;

void initArray(int n, int **array)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			array[i][j] = 0;
	
}

int **mallocArray(int n, int **array)
{
	int i;
	array = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
	{
		array[i] = (int *)malloc(n * sizeof(int));
	}
	return array;
}

int **read(int **array)
{
	FILE *fp;
	int n, i, j;

	fp=fopen("/home/hexing/shujujiegou/suanfa/input.txt","rt");
	fscanf(fp, "%d", &n);
	row = n;

	array = mallocArray(n, array);
	initArray(n,array);

	for (i=0; i<n; i++)
		for (j=0; j<=i; j++)
			fscanf(fp, "%d", &array[i][j]);

	fclose(fp);

	return array;
}

int maxTwo(int x, int y)
{
	return (x>y)?x:y;
}

int NumTriangle(int **triArray, int **resArray)
{
	int i, j;

	for (i = row-1; i>=1; i--) 
		for (j = 0; j <=i-1;j++) 
			resArray[i-1][j] = maxTwo((triArray[i-1][j]+resArray[i][j]), (triArray[i-1][j]+resArray[i][j+1]));

	return resArray[0][0];	
}

int main()
{
	int n, i, j;
	int **triArray, **resArray;

	triArray = read(triArray);
	resArray = mallocArray(row, resArray);
	
	for (i=0; i<row; i++)
		for (j=0; j< row; j++)
			resArray[i][j] = triArray[i][j];

    printf("最优距离是:%d\n", NumTriangle(triArray, resArray));

	return 0;
}
