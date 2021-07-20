#include <stdio.h>

int calculo_score( int n1, int n2, int n3){
    int aux, auxiliar;
    //CASO TODOS OS NÚMEROS SEJA DISTINTOS
    if(n1!= n2 && n1!=n3 && n2!= n3){
        //CALCULAR QUAL A VARIÁVEL TEM O MAIOR VALOR E COLOCAR EM N1
        if(n2>n1 && n2>n3){
        aux = n1;
        n1 = n2;
        n2 = aux;
        }
        else if(n3>n1 && n3>n2){
        aux = n1;
        n1 = n3;
        n3 = aux;
        }
        //CALCULAR QUAL A VARIÁVEL TEM O MENOR VALOR E COLOCAR EM N3
        if(n2<n1 && n2<n3){
        auxiliar = n3;
        n3 = n2;
        n2 = auxiliar;
        }
        return n2;
    }
    //CASO TENHAM NÚMEROS IGUAIS
    else{
        if(n1 == n2){
            return n1;
        }
        else if(n1 == n3){
            return n1;
        }
        else if(n2==n3){
            return n2;
        }
        
    }
}
//FUNÇÃO PARA CALCULAR O RESULTADO DO CAMPEONATO
char vencedor(int final1, int final2){
    if(final1 > final2){
        return printf("A\n");
    }
    else if(final1 < final2){
        return printf("B\n");
    }
    else{
        return printf("empate\n");
    }
}

int main(){
    //VARIAVEIS
    int nota1, nota2, nota3, i, sk1, sk2, sk3, final1, final2;

    for (i = 0; i < 6; i++){
        //RECEBER VALOR DAS VARIÁVEIS
        scanf(" %d %d %d", &nota1, &nota2, &nota3);

        //PRIMEIRO SKATISTA
        if(i>=0 && i<=2){
            //FUNÇÃO PARA CALCULAR AS NOTAS
            switch (i){
            case 0: sk1 = calculo_score(nota1, nota2, nota3); break;
            case 1: sk2 = calculo_score(nota1, nota2, nota3); break;
            case 2: sk3 = calculo_score(nota1, nota2, nota3); break;
            }
            final1 = calculo_score(sk1, sk2, sk3);
        }
        //SEGUNDO SKATISTA
        else if(i>2 && i<6){
            //FUNÇÃO PARA CALCULAR AS NOTAS
            switch (i){
            case 3: sk1 = calculo_score(nota1, nota2, nota3); break;
            case 4: sk2 = calculo_score(nota1, nota2, nota3); break;
            case 5: sk3 = calculo_score(nota1, nota2, nota3); break;
            }
            final2 = calculo_score(sk1, sk2, sk3);
        }
    }
    vencedor(final1, final2);

    return 0;

}