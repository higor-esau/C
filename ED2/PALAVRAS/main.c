#include <stdio.h>
int eUmCaracter(char* x){
    return (*x >= 'a' && *x <= 'z') || (*x >= 'A' && *x <= 'Z');
}

int contaPalavra(char* t){
    int total = 0;
    int dentroDaPalavra = 0;
    while (*t != '\0'){
        if(eUmCaracter(t)){
            if(!dentroDaPalavra){
                total++;
                dentroDaPalavra = 1;
            }
        } else{
            dentroDaPalavra = 0;
        }
        t++;
    }
    return total;
}

int main(){
    char input[80] = " ";

    printf("%d\n", contaPalavra(input));



    return 0;
}