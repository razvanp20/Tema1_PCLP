#include <stdio.h>
#include <stdlib.h>

void modul(int *p)
{
	if (*p < 0)
	{
		*p = -*p;
	}
}

int ataca_reciproc_faramatrix(int N[][2], int n, int nebuni[][2])
{
	int k = 0; // Counter for conflicts

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{ // Compare each pair only once
			// Check if N[i] and N[j] are on the same diagonal
			if (abs(N[i][0] - N[j][0]) == abs(N[i][1] - N[j][1]))
			{
				// Record conflict
				if (k < 1000)
				{
					nebuni[k][0] = N[i][0];
					nebuni[k][1] = N[i][1];

					nebuni[k + 1][0] = N[j][0];
					nebuni[k + 1][1] = N[j][1];
					k++;
				}
			}
		}
	}

	return k; // Return the total number of conflicts recorded
}

int schimba(int N[][2], int m, int n, int nebuni[][2])
{
	int k1 = 0;
	int nebunul1[1000][2];
	for (int i = 0; i < n; i++)
	{
		// Check if current piece is a conflicting bishop
		if ((N[i][0] == nebuni[0][0] && N[i][1] == nebuni[0][1]) ||
			(N[i][0] == nebuni[1][0] && N[i][1] == nebuni[1][1]))
		{
			int original_x = N[i][0];
			int original_y = N[i][1];

			for (int j = 0; j < m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					N[i][0] = j;
					N[i][1] = k;
					k1 = ataca_reciproc_faramatrix(N, n, nebunul1);
					if (k1 == 0)
						return k1;
				}
			}

			// Restore original position if no solution found
			N[i][0] = original_x;
			N[i][1] = original_y;
		}
	}
	return k1;
}

int main()
{
	int N[1000][2];
	int nebuni[1000][2];
	int m, n, x, y, k;

	// Read board size and number of bishops
	scanf("%d", &m);
	scanf("%d", &n);

	// Read initial positions of bishops
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		N[i][0] = x;
		N[i][1] = y;
	}

	// Detect conflicts
	k = ataca_reciproc_faramatrix(N, n, nebuni);
	printf("%d\n", k);

	// Resolve conflicts if necessary
	if (k > 0)
	{
		int res = schimba(N, m, n, nebuni);
		if (res == 0)
			printf("DA\n");
		else
			printf("NU\n");
	}
	else
		printf("NU\n");

	return 0;
}
