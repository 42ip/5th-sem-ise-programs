// Program 5: Write a program for implementing the error detection technique for data transfer in unreliable network code using CRC (16-bits) Technique

#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h> 
#include<time.h>
void divide(char agdtw[],char divs[],char remd[])
{
    int i,r,l,a,t;
    l   =   0; 
    r   =  strlen(divs); 
    t   =  strlen(agdtw)-r+1; 
    // we divide agdtw with its divisor till the end. the padded zeros are to check if any mistakes happen.
    char divd[18],rem[18]; 
    strncpy(divd,agdtw,r);
    divd[r]='\0';
    // memset  : fill a byte string with a byte value. here we fill rem with 0 . 
    memset(rem, 0,18); 
    while(l<t)
    {
        a=0;
        memset(rem, 0,18); 
        if(divd[0]==divs[0]) 
        {
            for(i=1;i<r;i++)
            {
                if(divd[i]==divs[i])
                    rem[a++]='0'; 
                else
                    rem[a++]='1'; 
            }
            rem[a]='\0';
            strcpy(divd,rem); 
        }
        else
        {
            // basically left shift the number
            strncpy(divd,&divd[1],strlen(divd)-1);
            divd[r-1]='\0'; 
        }
        int o = strlen(divd); 
        divd[o]=agdtw[l+r]; 
        divd[r]='\0';
        l++; 
    }
    strncpy(remd,divd,r-1);
    remd[r-1]='\0'; 
}
void binary(char letter,char bin[])
{
    int value,character,i=7;
    // cast the letter into its integer equivalent.
    character = (int) letter; 
        while(i>=0)
    {
        value = character %2;
        character = character / 2;
        bin[i--]= value +'0'; 
    }
        bin[8]='\0'; 
}
char ascii(char bin[])
{
    int t=0,c,i=7; 
    while(i>=0) 
    {
        // here, bin[i] is interpreted as a character.
        t=t+pow(2,7-i)*(bin[i]-'0');
        i--; 
    }
    return t; 
}
void main()
{
    //  dw = data word
    //  augdw = augmented data word
    // cw = coded word (the data word + the remainder part) 
    // bin = binary
    // r here stands for recieved.
    char dw[126],augdw[1018],div[18],rem[18],cw[1018],rcw[1018],bin[9],rdw[1001],msg[126];
    printf("Enter a Message to be sent (Max 125 Char)\n"); 
    fgets(dw, sizeof(dw), stdin); // get dataword from stdin.
    // insert first character of message into bin string.
    binary(dw[0],bin); 
    strcpy(augdw,bin);

    // e = number of erros introduced.
    int j,k,e; 
    for(j=1;j < strlen(dw);j++)
        {
        binary(dw[j],bin);
        // add each binary equivalent of the dataword into augmented data word using string concatenation.
        strcat(augdw,bin);
        }
    // to signify end of the dataword
    strcat(augdw,"0000000000000000");

    printf("\nEnter Divisor (generator) of 17 bits\n"); scanf("%s",div);

    divide(augdw,div,rem);

    //  remainder is appended to the dataword in codeword.
    strcpy(cw,augdw); 
    strcpy(&cw[strlen(augdw)-16],rem); 
    // we copy codeword into the error ridden codeword rcw to introduce errors into it.
    strcpy(rcw,cw);
    printf("\nEnter no. of errors to be introduced during transmission :"); scanf("%d",&e);
    // srand is a function that will generate random numbers with a seed. we use time(0) as seed here. time is usually used to create random numbers.
    srand(time(0));

    for(j=0;j<e;j++)
    {
        k =  rand() % strlen(rcw)-1;
        // flip the random bit we have. k here is a random number between 0 and length of string.
        if(rcw[k]=='0')
            rcw[k]='1';
        else
            rcw[k]='0';
        printf("Error Generated at %d th bit %d thcharacter\n",k,(k/8)+1);
    }
    divide(rcw,div,rem);
    if(strcmp(rem,"0000000000000000")!=0)
        printf("\n\nErroneous Transmission detected!\n");
    // copy the error ridden message into rdw to convert it back to the ascii format.
    strncpy(rdw,rcw,strlen(rcw)-16); 
    rdw[strlen(rcw)-16] = '\0'; 
    for(j=0,k=0;j<strlen(rdw);j=j+8)
    {
        // copy into bin the 8 bits of each character one by one. then msg will be built from the ascii character values of these binary numbers.
        strncpy(bin,&rdw[j],8);
        bin[8]='\0';
        msg[k++]=ascii(bin);
    }
    msg[k]='\0';
    printf("\nRecieved Message = %s\n\n",msg);
}