#include <stdio.h>
#include <math.h>

double distancia(double X, double Y, double X0, double Y0){
    double distancia;

    distancia = sqrt(pow((X - X0), 2) + pow((Y- Y0), 2));

    return distancia;
}

int calcular_pontuacao(double dist1){
    int pontuacao =0;

    if(dist1>=0 && dist1<=1){
        pontuacao +=10;
    }
    else if(dist1>1 && dist1 <=2){
        pontuacao += 6;
    }
    else if(dist1>2 && dist1 <=3){
        pontuacao += 4;
    }
    else if(dist1>3){
        pontuacao += 0;
    }
    return pontuacao;
}

int main(){
    //VARIÁVEIS
    double X=0, Y=0, X0 =0, Y0=0, dist=0, guardarx=0, guardary=0, distancia_anterior=-1;
    int i=0, ponto1=0, ponto2=0, total;

    for (i = 0; i < 10; i++){
        
        //LER AS ENTRADAS
        scanf(" %lf %lf", &X, &Y);

        //CALCULAR DISTANCIA EM RELAÇÃO A ORIGEM
        dist = distancia(X, Y, X0, Y0);
        
        if(i != 0){
            //CALCULAR DISTANCIA EM RELAÇÃO A OUTRO PONTO
            distancia_anterior = distancia(X, Y, guardarx, guardary);
        }

        //CALCULAR A PONTUAÇÃO DO PONTO ATE A ORIGEM
        ponto1 = calcular_pontuacao(dist);
        
        //CALCULAR PONTUAÇÃO ENTRE PONTOS
        ponto2 = (calcular_pontuacao(distancia_anterior))/2;

        //SOMAR A PONTUAÇÃO DOS PONTOS
        total += ponto1 + ponto2;


        //ATUALIZAÇÃO PARA GRAVAR O VALOR ANTERIOR DA DISTÂNCIA
        guardary = Y;
        guardarx = X;
        dist = 0;
        X0 = 0;
        Y0 = 0;
    }

    printf("%d\n", total);

    return 0;
    
}