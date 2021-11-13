// Program 6: Write a program to implement internet checksum for error correction and detection.
// https://www.alpharithms.com/internet-checksum-calculation-steps-044921/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checksum(int input){
    // concept of checksum : group your data (here its a string) into 16 bits. then add the 16 bit groups one by one. then get its one's complement, and maintain the 16 bit part as one.
    //  once the addition is done, convert that sum into hex form to get your check
    char inputString[100];
    // here sum is the calculated checksum.
    int n,mid,sum = 0,inp2 =  0,temp,max;
    printf("Enter the String:\n");
    scanf("%s",inputString);
    n = strlen(inputString);
    // got n as half
    n = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    for(int i = 0; i < n; i ++)
    {
        temp = (256 * inputString[2 * i]) + inputString[(i * 2) + 1];
        sum = sum + temp;
    }
    if (input){
        printf("Enter the Checksum value : ");
        scanf("%x",&inp2);
    }
    sum += inp2;
    max = 0b10000000000000000; // 65536 :- max value for 16 bit
    // check if the sum exceeds max value for 16 bit 
    if (sum % max != 0)
        {
            temp = sum % max;
            sum = (sum / max) + temp;
        }
    // basically doing one's complement for the sum (subtract with largest number)
    sum  = max - 1 - sum; 
    return sum;
}


int main()
{   int input,val;
    do{
        printf("\n1:Encode,2:Decode,3:Exit\n");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            val = checksum(0);
            printf("Checksum is %x",val);
            break;
        case 2:
            val = checksum(1);
            if (!val)
                printf("No error in transmissions");
            else
                printf("Error detected!!");
            break;
        case 3:
            exit(1);
        default:
            printf("enter a valid input \n");
            break;
        }
    }while(input != 3);
}