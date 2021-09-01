#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char cripto [15];

int main(){
    char Cadeia[121], Cad2[121], Cad3[121];
    int cont [121], cont2[121];
    int i, j, k, n, p, q;
    FILE *f1;
    cripto a, b, c, d, e, f, g, h;

    f1 = fopen("output.txt", "w");
    printf("\tPROGRAMA PARA CRIPTOGRAFAR\n");
    printf("\nDigite a mensagem a ser criptografada (max 120 caracteres):\n");
    setbuf (stdin, NULL);
    gets(Cadeia);
    printf("\nA mensagem digitada foi:\n");
    printf("%s\n", Cadeia);

    //Construir a strinf sem os 'espaços'
    for(i=0, j=0, k=0; i<=strlen(Cadeia); i++, j++){
        if(Cadeia[i]==' '){
            while(Cadeia[i]==' '){
                cont[k]=i;
                i++;
                k++;
            }
            Cad2[j]=Cadeia[i];
        }else{
            Cad2[j]=Cadeia[i];
        }
    }

    for(i=0; i<k; i++){
        fprintf(f1, " %d", cont[i]);
    }
    fprintf(f1, "\n");

    //Construir a string sem letras maiusculas
    for(i=0, k=0; i<=strlen(Cad2); i++){
        if(isalpha(Cad2[i])){
            if(isupper(Cad2[i])){
                Cad3[i]= tolower(Cad2[i]);
                cont2[k]=i;
                k++;
            }else{
                Cad3[i]= Cad2[i];
            }
        }else{
            Cad3[i]= Cad2[i];
        }
    }

    for(i=0; i<k; i++){
        fprintf(f1, " %d", cont2[i]);
    }
    fprintf(f1, "\n");

    //"Criptografar" a mensagem
    n = strlen(Cad3)/8;
    for(i=0; i<strlen(Cad3); i++){
        p = i%8;
        q = i/8;
        switch(p){
            case 0: a[q] = Cad3[i]; break;
            case 1: b[q] = Cad3[i]; break;
            case 2: c[q] = Cad3[i]; break;
            case 3: d[q] = Cad3[i]; break;
            case 4: e[q] = Cad3[i]; break;
            case 5: f[q] = Cad3[i]; break;
            case 6: g[q] = Cad3[i]; break;
            case 7: h[q] = Cad3[i]; break;
        }
    }

    if(strlen(Cad3)%8 >= 1){
        a[n+1] = '\0';
    }else{
        a[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 2){
        b[n+1] = '\0';
    }else{
        b[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 3){
        c[n+1] = '\0';
    }else{
        c[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 4){
        d[n+1] = '\0';
    }else{
        d[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 5){
        e[n+1] = '\0';
    }else{
        e[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 6){
        f[n+1] = '\0';
    }else{
        f[n] = '\0';
    }
    if(strlen(Cad3)%8 >= 7){
        g[n+1] = '\0';
    }else{
        g[n] = '\0';
    }
    if(strlen(Cad3)%8 == 0){
        h[n+1] = '\0';
    }else{
        h[n] = '\0';
    }
    printf("\nA Mensagem Criptografada eh:\n");
    printf("%s%s%s%s%s%s%s%s\n", a, b, c, d, e, f, g, h);
    fprintf(f1, "%s %s %s %s %s %s %s %s", a, b, c, d, e, f, g, h);
    printf("\nEnvie o arquivo output.txt com a mensagem criptografada para o destinatario.\n");

    //Encerramento
    fclose(f1);
    printf("\n\n");
    system("pause");
    return 0;
}


