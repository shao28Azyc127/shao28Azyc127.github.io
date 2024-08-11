#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r" ,stdin);
    freopen("apple.out","w",stdout);
    int a,b=0,c,k,flag=1;
    scanf("%d",&a);
    //srand(time(0));
    //for (int L=1;L<=1000;L++)
    //{


    //a=0,b=0,c=0,flag=1;
    //a=rand();
    //int d=a;
    if (flag&&(a-1)%3==0)
    {
        flag=0;
        c=1;
    }
    while (a)
    {
        if (a%3) k=a/3+1;
        else k=a/3;
        a-=k;
        b++;
        if (flag&&(a-1)%3==0)
        {
            flag=0;
            c=b+1;
        }
    }
    //printf("%d %d %d\n",d,b,c);
    printf("%d %d",b,c);

    //}
}
