#include <stdio.h>
#define Conv_tmp tmp=0;\
            for(l=4;l>=0;l--)\
            {\
                tmp=(tmp<<3)+(tmp<<1);\
                tmp+=a[l];\
            }\
            //printf("Debug: %05d++\n",tmp);
#define inc_a(j) a[j]++;\
                if(a[j]==10)\
                {\
                    a[j]=0;\
                }\
                //printf("Adding a[%d]\n",j);
int posi[100001];
int main()
{
    int n;
    char a[5];
    register int i,j,k,tmp,l;
    scanf("%d",&n);
    //while(getchar()!='\n');
    for(i=0;i<n;i++)
    {
        j=0;
        do{
            k=getchar();
            if('0'<=k && k<='9')
            {
                a[j]=k-'0';
                j++;
            }
        }while(j!=5);
        /*for(j=0;j<5;j++)
        {
            putchar(a[j]+'0');
        }*/
        for(j=0;j<5;j++)
        {
            //putchar(a[j]+'0');
            for(k=1;k<=9;k++)
            {
                inc_a(j);
                Conv_tmp
                posi[tmp]++;
            }
            inc_a(j);
        }
        for(j=0;j<4;j++)
        {
            for(k=1;k<=9;k++)
            {
                inc_a(j);
                inc_a(j+1);
                Conv_tmp
                posi[tmp]++;
            }
            inc_a(j);
            inc_a(j+1);
        }
    }
    tmp=0;
    for(i=0;i<100001;i++)
    {
        if(posi[i]==n)
        {
            tmp++;
        }
    }
    printf("%d",tmp);
    return 0;
}