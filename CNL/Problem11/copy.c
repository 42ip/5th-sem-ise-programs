int diffie(int g, int a ,int p){
    int r, y = 1;
    while (a > 0)
    {
        r = a % 2;
        if (r == 1){
            y = (y * g) % p;
        }
        g = g * g % p;
        a /= 2;
    }
    return y;
}

int compute(int g, int a, int p){
    int r, y = 1;
    while( a > 0){
        r = a % 2;
        if (r == 1){
            y = (y * g) % p;
        }
        g = g * g % p;
        a /= 2;
    }
    return y;
}
int main(){
    int g = 29,p = 31;
    int a = 5;
    int b = 7;
    int A = compute(g,a,p);
    int B  = compute(g,b,p);
    int keya = compute(B,a,p);
    int keyb = compute(A,b,p);
}