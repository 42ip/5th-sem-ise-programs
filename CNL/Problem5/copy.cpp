#include <iostream>
#include<stdlib.h>
#include<string.h>

int crc(char in[100],char out[100],int encode){
    char *poly = "11000000000000101";
    strcpy(out,in);
    if (encode){
        for(int i = 0 ; i < strlen(poly); i++)
            strcat(out,"0");
    }
    for(int i = 0; i < strlen(in); i++){
        if(out[i] == '1'){
            for(int j = 0 ; j < strlen(poly); j++){
                if (out[i + j] != poly[j]){
                    out[i + j] = '1';
                }
                else
                    out[i + j] = '0';
            }
        }
    }
    for(int i = 0 ; i < strlen(in); i++)
        if (out[i] == '1')
            return 0;
    return 1;



}