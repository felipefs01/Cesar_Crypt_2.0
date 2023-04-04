#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    void encrypt(char *file){
        FILE *open, *close;
        char buf[4096];
        //char copy[4096];
        open = fopen(file, "r");
        if(open == NULL){
            printf("Não foi possível abrir o arquivo!\n");
            exit(0);
        }
        else{
            close = fopen("arquivo_encriptado.txt", "w");
            if(close == NULL){
                printf("Não foi possível criar o arquivo\n");
                exit(0);
            }
            else{
                fread(&buf, sizeof(char), 4096, open);
                buf[strlen(buf)-1]='\0';
                for(int mod=0; mod < strlen(buf); mod++){
                    buf[mod] = buf[mod] - 3;
                }
                for(int loop=0; loop < strlen(buf); loop++){
                    fputc(buf[loop], close);
                }
                printf("\nok\n");
                fclose(open);
                fclose(close);
            }
        }
    }