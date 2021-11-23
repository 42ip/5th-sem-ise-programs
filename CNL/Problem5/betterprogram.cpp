#include <iostream>
#include <string.h>

using namespace std;

int crc(char *ip,char *op,int encode){
    char poly[20] = "11000000000000101";
    strcpy(op,ip);
    if (encode){
        for (int i = 0 ; i < strlen(poly);i++)
            strcat(op,"0");
    }
    for(int i = 0; i < strlen(ip);i++)
        {
            if(op[i] == '1'){
                for (int j = 0; j < strlen(poly); j++)
                    if (op[i + j] == poly[j])
                        op[i + j] = '0';
                    else
                        op[i + j] = '1';
            }
        }
    for( int i = 0; i < strlen(op); i++)
        if (op[i] == '1')
            return 0;
    return 1;

}
int main(){
    char ip[100],op[100],recv[100];
    cout<< "Enter the input string in binary : ";
    cin>> ip;
    crc(ip,op,1);
    cout << "String sent is " << ip << op + strlen(ip) << endl;
    cout<< "Enter the recieved string in binary : ";
    cin>> recv;
    int worked = crc(recv,op,0);
    if (worked)
        cout << "No errors" << endl;
    else
        cout << "Yes errors" << endl;

}