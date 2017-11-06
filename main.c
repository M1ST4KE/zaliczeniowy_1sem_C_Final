#include <stdio.h>
#include <stdlib.h>

int **makeMatrix(int **M, int x, int y){
    M = (int **) malloc(x * sizeof(int *));

    for (int i = 0; i < x; ++i) {
        M[i] = (int *) malloc(y * sizeof(int));
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            scanf("%d", &M[i][j]);
    }
    return M;
}

int **makeEmptyMatrix(int **M, int x, int y){
    M = (int**) malloc(x * sizeof(int *));
    for (int i = 0; i < x; ++i) {
        M[i] = (int*) malloc(y * sizeof(int));
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            M[i][j] = 0;
    }
    return M;
}

void matrixMultiplication(int **M1, int **M2, int **wyn, int x, int y, int innyY){
    int s;
    for(int i = 0; i < x; i++){
        for (int j = 0; j < y; j++) {
            s = 0;
            for(int k = 0; k < innyY; k++)
                s = s + M1[i][k] * M2[k][j];
            wyn[i][j] = s;
        }
    }
}

void printMatrix(int **M, int x, int y){
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void deleteMatrix(int **M, int x, int y){
    for (int i = 0; i < x; ++i) {
        free(M[i]);
    }
    free(M);
}

void matrix(){
    int x1, x2, y1, y2;
    int **M1, **M2, **wyn;
    printf("podaj rozmairy pierwszej macierzy\n");
    scanf("%d %d", &x1, &y1);
    printf("podaj rozmiary drugiej macierzy\n");
    scanf("%d %d", &x2, &y2);

    if(y1 == x2){
        printf("wypełnij macierz A\n");
        M1 = makeMatrix(M1, x1, y1);
        printf("wypełnij macierz B\n");
        M2 = makeMatrix(M2, x2, y2);
        wyn = makeEmptyMatrix(wyn, x1, y2);

        matrixMultiplication(M1, M2, wyn, x1, y2, y1);

        printMatrix(wyn, x1, y2);

        deleteMatrix(M1, x1, y1);
        deleteMatrix(M2, x2, y2);
        deleteMatrix(wyn, x1, y2);
    } else {
        printf("Nie da sie pomnozyc takich macierzy\n");
    }
}

int toDec(char wej[], int p, int size){
    int dec = 0;
    for(int i = 0; i < size; i++){
        if(wej[i] <= 57){
            dec = dec * p + (wej[i] - '0');
        }
        else{
            dec = dec * p + (wej[i] - 'A' + 10);
        }
    }
    return dec;
}

void dec2any(int dec, int pWyj){
    char wyjB[1000];
    char tmp;
    int tmpDec;
    int size = 0;
    while(dec > 0) {
        tmpDec = dec % pWyj;
        dec = dec / pWyj;
        if(tmpDec < 10)
            tmp = (char)(tmpDec + '0');
        else
            tmp = (char)(tmpDec + 'A' - 10);
        wyjB[size] = (char) tmp;
        size++;
    }
    for (int i = 1; i <= size; i++) {
        tmp = wyjB[size - i];
        printf("%c", tmp);
    }
    printf("\n");
}

void converting() {
    char wej[1000];
    int pWej, pWyj, size;
    printf("podaj liczbę cyfr w liczbie\n");
    scanf("%d", &size);
    printf("podaj liczbe\n");
    scanf("%s", wej);
    printf("podaj podstawe wejsciowa\n");
    scanf("%d", &pWej);
    printf("podaj podstawe wyjsciowa\n");
    scanf("%d", &pWyj);
    if(pWyj == pWej){
        wej;
    }
    else {
        if (pWyj == 10) {
            printf("%d", toDec(wej, pWej, size));
        }
        else {
            dec2any(toDec(wej, pWej, size), pWyj);
        }
    }
}

int main() {
    int def, loop = 1;
    char decision;
    while(loop){
        printf("By pomnozyc macierze wybierz [1]\nBy zamienic systemy liczb wybierz [2]\nBy zakonczyc działanie programu wybierz [0]");
        scanf("%d", &def);
        switch(def) {
            case 1:
                matrix();
                break;
            case 2:
                converting();
                break;
            case 0:
                loop = 0;
                break;
            default:
                printf("Bledna instrukcja, sprobuj jeszcze raz\n");
                break;
        }
        printf("Czy na pewno chcesz zakonczyc dzialanie programu? [T/N]\n");
        scanf("%s", &decision);
        if (decision == 'N')
            loop = 1;
    }

    return 0;
}