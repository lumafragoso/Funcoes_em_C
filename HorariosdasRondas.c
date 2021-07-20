#include <stdio.h>

void imprime(int xhora, int xmin, int xseg){
    //TODOS MAIORES QUE 10
    if(xmin <10 && xhora < 10 && xseg <10){
        printf("0%d:0%d:0%d\n", xhora, xmin, xseg);
    }
    //SOMENTE HORA MAIOR QUE 10
    else if(xmin < 10 && xseg <10 && xhora >=10){
        printf("%d:0%d:0%d\n", xhora, xmin, xseg);
    }
    //SOMENTE SEGUNDO MAIOR QUE 10
    else if(xmin < 10 && xhora <10 && xseg>= 10){
        printf("0%d:0%d:%d\n", xhora, xmin, xseg);
    }
    //SOMENTE MINUTO MAIOR QUE 10
    else if(xseg < 10 && xhora <10 && xmin>=10){
        printf("0%d:%d:0%d\n", xhora, xmin, xseg);
    }
    //HORA E SEGUNDO MAIOR QUE 10
    else if(xmin <10 && xhora >= 10 && xseg >=10){
        printf("%d:0%d:%d\n", xhora, xmin, xseg);
    }
    //MINUTO E SEGUNDO MAIOR QUE 10
    else if(xmin >=10 && xhora < 10 && xseg >=10){
        printf("0%d:%d:%d\n", xhora, xmin, xseg);
    }
    //HORA E MINUTO MAIOR QUE 10
    else if(xmin >=10 && xhora >= 10 && xseg <10){
        printf("%d:%d:0%d\n", xhora, xmin, xseg);
    }
    else{
        printf("%d:%d:%d\n", xhora, xmin, xseg);
    }
}

void horario_condicoes(int hora, int minutos, int segundos, int adicional_hora, int adicional_minuto, int adicional_segundo){
    int xhora, xmin, xseg;
    //SEGUNDOS
    if(segundos + adicional_segundo >= 60){
        xseg = (segundos + adicional_segundo) - 60;
        xmin = 1;
    }
    else if(segundos + adicional_segundo < 60){
        xseg = segundos + adicional_segundo;
        xmin=0;
    }
    //MINUTOS
    if(minutos + adicional_minuto + xmin >= 60){
        xmin = (minutos + adicional_minuto + xmin) - 60;
        xhora = 1;
    }
    else if(minutos + adicional_minuto + xmin < 60){
        xmin = (minutos + adicional_minuto + xmin);
        xhora =0;
    }
    //HORA
    if(hora + adicional_hora + xhora > 23){
        xhora = abs((hora + adicional_hora + xhora) - 24);
    }
    else if(hora + adicional_hora + xhora <= 23){
        xhora = hora + adicional_hora + xhora;
    }
    imprime(xhora, xmin, xseg);
    xseg = xmin = xseg =0;
}

int main(){
    //VARIÁVEIS
    int hora, minutos, segundos, i, adicional_hora=0, adicional_min=0, adicional_seg=0, h;

    //LER AS VARIÁVEIS
    scanf(" %d %d %d", &hora, &minutos, &segundos);

    if(hora>=0 && hora<=23 && minutos>=0 && minutos<=60 && segundos>=0 && segundos<=60){
        for (i = 0; i < 4; i++){
        if(i==0){
            if((hora + 1) > 23){
                h = abs(hora -23);
            }
            else if((hora + 1 <= 23)){
                h = hora + 1;
            }
            imprime(h, minutos, segundos);
        }
        if(i==1){
            adicional_hora=2;
            adicional_min=10;
            adicional_seg=30;
            horario_condicoes(hora, minutos, segundos, adicional_hora, adicional_min, adicional_seg );
        }
        if(i==2){
            adicional_hora=4;
            adicional_min=40;
            adicional_seg=50;
            horario_condicoes(hora, minutos, segundos,  adicional_hora, adicional_min, adicional_seg );
        }
        if(i==3){
            adicional_hora=12;
            adicional_min=5;
            adicional_seg=5;
            horario_condicoes(hora, minutos, segundos,  adicional_hora, adicional_min, adicional_seg);
        }
        
    }
    return 0;

    }
}