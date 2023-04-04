#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "desencrypt.h"
    void banner(){
        printf("############################################################\n");
        printf("#             CesarCrypt v2.0 by: felipe silva             #\n");
        printf("############################################################\n");
    }
    int main(void){
        char cmd[256];
        char txt[256];
        banner();
        do{
            printf("CMD>");
            fgets(cmd, 256, stdin);
            cmd[strlen(cmd)-1]='\0';
            if(strcmp(cmd, "encode")==0){
                printf("txt>");
                scanf("%[^\n]", txt);
                encrypt(txt);
            }
            else if(strcmp(cmd, "decode")==0){
                printf("txt>");
                scanf("%[^\n]", txt);
                desencrypt(txt);
            }
            else if(strcmp(cmd, "bye")==0){
                printf("Saindo\n");
            }
            else{
                printf("comandos aceitos: encode, decode, bye\n");
                printf("encode: criptografa, decode: decifra, bye: fecha\n");
            }
        }while(strcmp(cmd, "bye")==0);


        return EXIT_SUCCESS;
    }