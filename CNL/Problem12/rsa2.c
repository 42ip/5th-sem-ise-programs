#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int gcd(int a , int b){
    if (b == 0){ return a;}
    return gcd(b,a % b);
}
int main(){
    double p = 5, q = 7;
    double n = p * q, toitent = (p - 1) * ( q  - 1),k = 2 , e = 2, msg, m , d,c;
    while(e < toitent){
        if (gcd(e,toitent) == 1){
            break;
        }
        e++;
    }
    d = (1 + (toitent * k)) / e;
    msg = 12;
    c = pow(msg,e);
    c = fmod(c,n);
    m = pow(c,d);
    m = fmod(m,n);
}
 