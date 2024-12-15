#include <stdio.h>
#include <string.h>

#define SIZE 3

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void rotate_right(int cub_rubik_int[][3][3], int i){
    swap(&cub_rubik_int[i][0][2], &cub_rubik_int[i][0][0]);
    swap(&cub_rubik_int[i][0][0], &cub_rubik_int[i][2][0]);
    swap(&cub_rubik_int[i][2][0], &cub_rubik_int[i][2][2]);

    swap(&cub_rubik_int[i][0][1], &cub_rubik_int[i][1][0]);
    swap(&cub_rubik_int[i][1][0], &cub_rubik_int[i][2][1]); 
    swap(&cub_rubik_int[i][2][1], &cub_rubik_int[i][1][2]);
}

void rotate_left(int cub_rubik_int[6][3][3], int i){
    swap(&cub_rubik_int[i][0][0], &cub_rubik_int[i][0][2]);
    swap(&cub_rubik_int[i][0][2], &cub_rubik_int[i][2][2]);
    swap(&cub_rubik_int[i][2][2], &cub_rubik_int[i][2][0]);

    swap(&cub_rubik_int[i][0][1], &cub_rubik_int[i][1][2]);
    swap(&cub_rubik_int[i][1][2], &cub_rubik_int[i][2][1]);
    swap(&cub_rubik_int[i][2][1], &cub_rubik_int[i][1][0]);
}

int main(){
    char culori[10][10];
    char fete_cub[100][100];
    int nr_mutari;
    char mutari[1000][1000];
    int cub_rubik_int[6][3][3];

    for (int i = 0; i < 6; i++){

        scanf("%s", culori[i]);
    }

    for (int i = 0; i < 18; i++){
        
        scanf("%s", fete_cub[i]);
    }
    scanf("%d", &nr_mutari);
    getchar();
    for (int i = 0; i < nr_mutari; i++){
        
        scanf("%s", mutari[i]);
        mutari[i][strcspn(mutari[i], "\n")] = '\0';
    }
    //
    int k = 0;
    int kk = 0;
    char *pch;
    for (int i = 0; i < 18; i++){
        
        pch = strtok(fete_cub[i], ".");
        for(int j = 0; j < 3; j++){
    
            if (strcmp(pch, culori[0]) == 0){
                cub_rubik_int[k][kk][j] = 1;
            }
            if (strcmp(pch, culori[1]) == 0){
                cub_rubik_int[k][kk][j] = 2;
            }
            if (strcmp(pch, culori[2]) == 0){
                cub_rubik_int[k][kk][j] = 3;
            }
            if (strcmp(pch, culori[3]) == 0){
                cub_rubik_int[k][kk][j] = 4;
            }
            if (strcmp(pch, culori[4]) == 0){
                cub_rubik_int[k][kk][j] = 5;
            }
            if (strcmp(pch, culori[5]) == 0){
                cub_rubik_int[k][kk][j] = 6;
            }
            pch = strtok(NULL, ".");
        }
        kk++;  

        if (kk == 3 ){
        k++;
        kk = 0;
        }
    }

   for (int i = 0; i < nr_mutari; i++){
        if (strcmp(mutari[i], "F") == 0){
            rotate_right(cub_rubik_int, 0);
            for(int i = 0; i < 3; i++){
                swap(&cub_rubik_int[2][2][i], &cub_rubik_int[4][2-i][2]);
                swap(&cub_rubik_int[4][2-i][2], &cub_rubik_int[3][0][2-i]);
                swap(&cub_rubik_int[3][0][2-i], &cub_rubik_int[5][i][0]);
            }

        }
        if (strcmp(mutari[i], "F'") == 0){
            rotate_left(cub_rubik_int, 0);
            for(int i = 0; i < 3; i++){
                swap(&cub_rubik_int[2][2][i], &cub_rubik_int[5][i][0]);
                swap(&cub_rubik_int[5][i][0], &cub_rubik_int[3][0][2-i]);
                swap(&cub_rubik_int[3][0][2-i], &cub_rubik_int[4][2-i][2]);
            }
        }
        if (strcmp(mutari[i], "B") == 0){
            rotate_right(cub_rubik_int, 1);
            for(int i = 0; i < 3; i++){
                swap(&cub_rubik_int[2][0][i], &cub_rubik_int[5][i][2]);
                swap(&cub_rubik_int[5][i][2], &cub_rubik_int[3][2][2-i]);
                swap(&cub_rubik_int[3][2][2-i], &cub_rubik_int[4][2-i][0]);
            }
        }
        if (strcmp(mutari[i], "B'") == 0){
            rotate_left(cub_rubik_int, 1);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[2][0][i], &cub_rubik_int[4][2-i][0]);
                swap(&cub_rubik_int[4][2-i][0], &cub_rubik_int[3][2][2-i]);
                swap(&cub_rubik_int[3][2][2-i], &cub_rubik_int[5][i][2]);
            }
        }
        if (strcmp(mutari[i], "U") == 0){
            rotate_right(cub_rubik_int, 2);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][0][i], &cub_rubik_int[4][0][i]);
                swap(&cub_rubik_int[5][0][i], &cub_rubik_int[0][0][i]);
                swap(&cub_rubik_int[1][0][i], &cub_rubik_int[5][0][i]);
            }
        }
        if (strcmp(mutari[i], "U'") == 0){
            rotate_left(cub_rubik_int, 2);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][0][i], &cub_rubik_int[4][0][i]);
                swap(&cub_rubik_int[4][0][i], &cub_rubik_int[1][0][i]);
                swap(&cub_rubik_int[1][0][i], &cub_rubik_int[5][0][i]);
            }
        }
        if (strcmp(mutari[i], "D") == 0){
            rotate_right(cub_rubik_int, 3);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][2][i], &cub_rubik_int[4][2][i]);
                swap(&cub_rubik_int[4][2][i], &cub_rubik_int[1][2][i]);
                swap(&cub_rubik_int[1][2][i], &cub_rubik_int[5][2][i]);
            }
        }
        if (strcmp(mutari[i], "D'") == 0){
            rotate_left(cub_rubik_int, 3);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][2][i], &cub_rubik_int[4][2][i]);
                swap(&cub_rubik_int[5][2][i], &cub_rubik_int[0][2][i]);
                swap(&cub_rubik_int[1][2][i], &cub_rubik_int[5][2][i]);
            }
        }
        if (strcmp(mutari[i], "R") == 0){
            rotate_right(cub_rubik_int, 5);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][i][2], &cub_rubik_int[2][i][2]);
                swap(&cub_rubik_int[3][i][2], &cub_rubik_int[0][i][2]);
                swap(&cub_rubik_int[1][2-i][0], &cub_rubik_int[3][i][2]);
            }
        }
        if (strcmp(mutari[i], "R'") == 0){
            rotate_left(cub_rubik_int, 5);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][i][2], &cub_rubik_int[2][i][2]);
                swap(&cub_rubik_int[2][i][2], &cub_rubik_int[1][2-i][0]);
                swap(&cub_rubik_int[1][2-i][0], &cub_rubik_int[3][i][2]);
            }
        }
        if (strcmp(mutari[i], "L") == 0){
            rotate_right(cub_rubik_int, 4);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][i][0], &cub_rubik_int[2][i][0]);
                swap(&cub_rubik_int[2][i][0], &cub_rubik_int[1][2-i][2]);
                swap(&cub_rubik_int[1][2-i][2], &cub_rubik_int[3][i][0]);
            }
        }
        if (strcmp(mutari[i], "L'") == 0){
            rotate_left(cub_rubik_int, 4);
            for (int i = 0; i < 3; i++){
                swap(&cub_rubik_int[0][i][0], &cub_rubik_int[2][i][0]);
                swap(&cub_rubik_int[3][i][0], &cub_rubik_int[0][i][0]);
                swap(&cub_rubik_int[1][2-i][2], &cub_rubik_int[3][i][0]);
            }
        }
        
   }

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){

                printf("%s", culori[cub_rubik_int[i][j][k]-1]);
                if (k != 2){
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;



    

     
    
}