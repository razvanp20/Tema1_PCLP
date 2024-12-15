#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_anagram(char *s1, char *s2){
    if (strlen(s1) != strlen(s2)){
        return 0;
    }
    char *s11, *s22;
    int k = 0;
    s11 = malloc (100* sizeof(char));
    s22 = malloc (100* sizeof(char));
    strcpy(s11, s1);
    strcpy(s22, s2);

    for (int i = 0; i < strlen(s11); i++){
        for (int j = 0; j < strlen(s22); j++){
            if (s11[i] == s22[j]){
                k = k + 1;
                s22[j] = 'A';
                break;
            }
        }
    }
    if (k == strlen(s22))
    return 1;
    else 
    return 0;

}

double compute_grade(char *s1, char *s2){
    if (is_anagram(s1, s2) == 0){
        return -1;
    }

    double x = 0.00;
    double y = strlen(s1); 
    double res = 0.00;
    for (int i = 0; i < y; i++){
        if (s1[i] != s2[i]){
            x = x + 1; 
        }
    }
    res = x/y;
    return res;
}

void sort_rank(double *x, int N, char cuvant1[][100], char cuvant2[][100]){
    int n = N;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j] < x[j + 1]){
                double temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;

                // Schimbăm cuvintele din cuvant1
                char tempCuv1[100];
                strcpy(tempCuv1, cuvant1[j]);
                strcpy(cuvant1[j], cuvant1[j + 1]);
                strcpy(cuvant1[j + 1], tempCuv1);

                // Schimbăm cuvintele din cuvant2
                char tempCuv2[100];
                strcpy(tempCuv2, cuvant2[j]);
                strcpy(cuvant2[j], cuvant2[j + 1]);
                strcpy(cuvant2[j + 1], tempCuv2);

            }
                
        }
    }
}
void sort_rank2(double *x, int N, char cuvant1[][100], char cuvant2[][100]){
    int n = N;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (x[j] == x[j + 1] && strcmp(cuvant1[j], cuvant1[j + 1]) < 0){
                
                double temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;

                // Schimbăm cuvintele din cuvant1
                char tempCuv1[100];
                strcpy(tempCuv1, cuvant1[j]);
                strcpy(cuvant1[j], cuvant1[j + 1]);
                strcpy(cuvant1[j + 1], tempCuv1);

                // Schimbăm cuvintele din cuvant2
                char tempCuv2[100];
                strcpy(tempCuv2, cuvant2[j]);
                strcpy(cuvant2[j], cuvant2[j + 1]);
                strcpy(cuvant2[j + 1], tempCuv2);

            }
                
        }
    }
}
int main(){
    int N;
    double x[1000];
    char cuvant1[1000][100], cuvant2[1000][100];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++){
        scanf("%s %s", cuvant1[i], cuvant2[i]);
        x[i] = compute_grade(cuvant1[i], cuvant2[i]);
    }
    sort_rank(x, N, cuvant1, cuvant2);
    sort_rank2(x, N, cuvant1, cuvant2);
    for (int i = 0; i < N; i++){
       
        // printf("%f\n", x[i]);
        printf("%s %s\n", cuvant1[i], cuvant2[i]);
    }
    

    
}