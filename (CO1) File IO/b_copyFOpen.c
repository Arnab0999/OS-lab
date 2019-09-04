#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fs, *ft;
    int ch;

    fs = fopen("input.out", "rb");
    if(fs == NULL){
        puts("Cannot open source file! Exiting...\n");
        exit(1);
    }

    ft = fopen("output.out", "wb");

    if(ft == NULL){
        puts("Cannot open taget file! Exiting...\n");
        fclose(fs);
        exit(2);
    }

    while (1) {
        ch = fgetc(fs);

        if(ch == EOF){
            break;
        }
        else{
            fputc(ch, ft);
        }
    }
    
    fclose(fs);
    fclose(ft);

    return 0;

}
