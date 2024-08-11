#include <bits/stdc++.h>
using namespace std;
int n,m[10][10],s=0;
bool equ(int a,int b,int c,int d,int e,int ni)
{
    if(a==m[ni][0] && b==m[ni][1] && c==m[ni][2] && d==m[ni][3] && e==m[ni][4])
    {
        return true;
    }
    else
    {
        return false;
    }
}
void chack(int a,int b,int c,int d,int e)
{
    int chacks=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(equ((a+j)%10,(b+j)%10,c,d,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,(b+j)%10,(c+j)%10,d,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,b,(c+j)%10,(d+j)%10,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,b,c,(d+j)%10,(e+j)%10,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ((a+j)%10,b,c,d,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,(b+j)%10,c,d,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,b,(c+j)%10,d,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,b,c,(d+j)%10,e,i))
            {
                chacks++;
                continue;
            }
        }
        for(int j=1;j<=9;j++)
        {
            if(equ(a,b,c,d,(e+j)%10,i))
            {
                chacks++;
                continue;
            }
        }
    }
    if(chacks==n)
    {
        s++;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> m[i][j];
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int p=0;p<10;p++)
                    {
                        chack(i,j,k,l,p);
                    }
                }
            }
        }
    }
    cout << s;
    return 0;
}
