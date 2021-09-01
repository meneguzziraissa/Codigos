#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    int i, j, k, n, q1, r1, p, q, r, nt=0, aux=0;
    int space[121], upper[121];
    char lixo [121], crip[121], Cad1[121], Cad2[121], Final[121];
    char Cadeia[8][15];
    FILE *f1;
    f1 = fopen("output.txt", "r");
    i = 0;
    j = 0;
    printf("\tPROGRAMA PARA DESCRIPTOGRAFAR MENSAGENS\n");

    //Identificar onda há espaços
    for(i=0; i<121;i++){
        fscanf(f1, "%d", &space[i]);
        fscanf(f1, "%c", &lixo[i]);
        if(lixo[i]=='\n'){
            break;
        }
    }

    //Identificar onde há Maiusculas
    for(i=0; i<121;i++){
        fscanf(f1, "%d", &upper[i]);
        fscanf(f1, "%c", &lixo[i]);
        if(lixo[i]=='\n'){
            break;
        }
    }

    //Desembaralhar a mensagem
    for(i=0; i<8; i++){
        fscanf(f1, "%s", Cadeia[i]);
        n = strlen(Cadeia[i]);
        nt = nt+n;
    }
    Cadeia[8][0]='\0';
    q=nt/8;
    r=nt%8;

    for(i=0; i<8; i++){
        if(i<r){
            for(j=0; j<q+1; j++){
                Cad1[j*8+i]=Cadeia[i][j];
            }
        }else{
            for(j=0; j<q; j++){
                Cad1[j*8+i]=Cadeia[i][j];
            }
        }
    }
    Cad1[nt]='\0';

//Transformar letras em Maiusculas
    for(i=0, j=0; i<=nt; i++){
        if(i==upper[j]){
            Cad2[i]=toupper(Cad1[i]);
            j++;
        }else{
            Cad2[i]=Cad1[i];
        }
    }

//Colocar novamente os Espaços
    for(i=0, j=0; i<nt; i++){
        if(i+aux==space[j]){
            while(i+aux==space[j]){
                Final[i+aux]=' ';
                aux++;
                j++;
            }
            Final[i+aux]=Cad2[i];
        }else{
            Final[i+aux]=Cad2[i];
        }
    }
    Final[i+aux]='\0';

        printf("\nA mensagem descriptografada eh:\n%s", Final);

    //Encerramento
    printf("\n\n");
    system ("pause");
    return 0;
}
