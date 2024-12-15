#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void dec_to_bin(int n, char *s)
{
    int i = 7;

    while (n > 0)
    {
        int bit = n % 2;

        if (bit == 0)
        {
            s[i] = '0';
        }
        else
        {
            s[i] = '1';
        }
        i--;
        n = n / 2;
    }
    while (i >= 0)
    {
        s[i] = '0';
        i--;
    }
}

int bin_to_dec(char *s)
{
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        if (s[i] == '0')
            res = res + 0 * pow(2, 7 - i);
        else
            res = res + 1 * pow(2, 7 - i);
    }

    return res;
}

char boo_multiply(char s1, char s2)
{
    if (s1 == '0' && s2 == '0')
        return '0';
    if (s1 == '0' && s2 == '1')
        return '0';
    if (s1 == '1' && s2 == '0')
        return '0';
    return '1';
}

char boo_sum(char s1, char s2)
{
    if (s1 == '0' && s2 == '0')
        return '0';
    if (s1 == '0' && s2 == '1')
        return '1';
    if (s1 == '1' && s2 == '1')
        return '1';
    return '1';
}

void trasnpose(char m[][8], char trans[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            trans[j][i] = m[i][j];
        }
    }
}

void matrix_multiplication(char matrix1[][8], char matrix2[][8], char res[][8])
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                res[i][j] = boo_sum(res[i][j], boo_multiply(matrix1[i][k], matrix2[k][j]));
            }
        }
    }
}

void initialisation(char m[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m[i][j] = '0';
        }
        m[i][8] = '\0';
    }
}
int sum_X_0(char m[][8])
{
    int ip, jp, p1, p2, i, j;
    int sum = 8;
    for (int patrat = 1; patrat <= 4; patrat++)
    {
        if (patrat == 1)
        {
            ip = 0;
            jp = 0;
            p1 = 4;
            p2 = 4;
        }
        else if (patrat == 2)
        {
            ip = 0;
            jp = 4;
            p1 = 4;
            p2 = 8;
        }
        else if (patrat == 3)
        {
            ip = 4;
            jp = 0;
            p1 = 8;
            p2 = 4;
        }
        else
        {
            ip = 4;
            jp = 4;
            p1 = 8;
            p2 = 8;
        }
        int linie = 0;
        int coloana = 0;
        int diagoanala1 = 0;
        int diagonala2 = 0;
        for (i = ip; i < p1; i++)
        {
            for (j = jp; j < p2; j++)
            {
                if (m[i][j] == '0' && abs(i - ip) == abs(j - jp))
                    diagoanala1++;
                if (m[i][j] == '0' && abs(i - ip) == abs(j - (jp + 3)))
                    diagonala2++;

                if (m[i][j] == '1')
                    linie = linie + 1;
                else
                    linie = 0;
                if (m[j][i] == '1')
                    coloana++;
                else
                    coloana = 0;
            }
            if (linie == 4){
                sum++;
                linie = 0;
            }
            else
                linie = 0;
            if (coloana == 4){
                sum++;
                coloana = 0;
            }
            else
                coloana = 0;
        }
        if (diagoanala1 > 0)
            sum--;
        if (diagonala2 > 0)
            sum--;
    }
    return sum;
}

int main()
{

    int n;
    char A[8][8], At[8][8], Apatrat[8][8], AAt[8][8];

    initialisation(A);
    initialisation(At);
    initialisation(Apatrat);
    initialisation(AAt);

    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &n);
        dec_to_bin(n, A[i]);
    }

    trasnpose(A, At);
    matrix_multiplication(A, A, Apatrat);
    matrix_multiplication(A, At, AAt);

    if (sum_X_0(A) >= sum_X_0(AAt) && sum_X_0(A) >= sum_X_0(Apatrat))
        for (int i = 0; i < 8; i++)
            printf("%d\n", bin_to_dec(A[i]));
    else if (sum_X_0(AAt) >= sum_X_0(Apatrat))
        for (int i = 0; i < 8; i++)
            printf("%d\n", bin_to_dec(AAt[i]));
    else
        for (int i = 0; i < 8; i++)
            printf("%d\n", bin_to_dec(Apatrat[i]));

    return 0;
}