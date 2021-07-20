#include <stdio.h>
#include <math.h>

int calcular_divisores(int numero){
    int soma_divisores=0, j;
    
    //LOOP PARA CALCULAR OS DIVISORES
    for (j = 1; j < numero; j++){
        if (numero % j == 0){
            soma_divisores += j;
        }
    }
    return soma_divisores;
}
char colega(int somaA, int somaB, int a, int b){
    if (abs(somaA - b)<=2 && abs(somaB - a)<= 2){
        return printf("S\n");
    }
    else{
        return printf("N\n");
    }
}


int main(){
    //VARIÁVEIS
    int A, B, soma_A, soma_B, i, soma_divisores;;

    scanf(" %d %d", &A, &B);

    for (i = 0; i < 2; i++){
        //CONDIÇÃO PARA FAZER OS DIVISORES EM APENAS UM LOOP
        if (i == 0){
            soma_A = calcular_divisores(A);
        }
        else if (i==1){
            soma_B = calcular_divisores(B);;
        }
    }

    colega(soma_A, soma_B, A, B);
    printf("%d\n", soma_A);
    printf("%d\n", soma_B);

    return 0;

}