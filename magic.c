#include <stdio.h>

#define N 8

void printMatrix(int arr[N][N]);
int takeInput(int matrix[N][N]);
void checkMagic(int arr[N][N]);

int main()
{
	int matrix[N][N];
	int test = takeInput(matrix); 
	if (test)
	{
	printMatrix(matrix);
	checkMagic(matrix);
	}
	return 0;
}


void printMatrix(int arr[N][N])		/* prints the matrix */
{				
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ", arr[i][j]);
        		if(j==(N-1))
			{
           			 printf("\n");
			}
		}
	}
}


int takeInput(int matrix[N][N])	/* takes input for the matrix*/
{
	int i, j, c,val;
	printf("Please enter %d numbers between the values 1 to %d:\n", N*N, N*N);
	i = 0;			/* rows index */
	j = 0;			/* columns index */
	while ((val=scanf("%d ", &c)) != EOF)	/* input */
	{
		if (i > N - 1 || val != 1)
		{
			printf("Error - wrong input\n");
			return 0;
		}
		matrix[i][j] = c;
		j++;
		if(j == N)
		{
			i++;
			j = 0;
		}
	}
	if ( j != 0 && i != N)			/* check for to little input */
	{
		printf("Error - less than required values\n");
		return 0;
	}
	return 1;
}


void checkMagic(int arr[N][N])		/* check if the matrix ia a magic square */
{
	int check[N*N] = {0};	/* array that check if there is a repution of values */
	int r, l, k, i;
	int id = 0;
	int sums[N+N+2] = {0};
	for (r = 0; r < N; r++)
	{
		for(l=0; l < N; l++)
		{
			sums[id] += arr[r][l];		/* calculate sums of rows */
			sums[id+1] += arr[l][r];	/* calculate sums of columns */

			if(0<arr[r][l] && arr[r][l]<=(N*N) && check[arr[r][l]-1] == 0)	/* checks if the input is valid */
			{
				check[arr[r][l]-1] = 1;			
			}
			else
			{
				printf("The matrix is not a magic square because of repetition or out of range value.\n");
				return;
			}

		}
		id += 2;
	}
	for (k=0; k < N; k++)	/* calculate sum of first diagonal line */
	{
		sums[id] += arr[k][k];
	} id++;
	k = N-1;
	for(i=0; i < N; i++)	/* calculate sum of second diagonal line */
	{
		sums[id] += arr[i][k];
		k--;
	}
	for(i=1; i < (N+N+2); i++)	/* check if all the sums are the same */
	{
		if (sums[0] != sums[i])
		{
			printf("The matrix is not a magic square because of uneven sums.\n");
			return;
		}
	}
	printf("The matrix is a magic square.\n");
}
	
