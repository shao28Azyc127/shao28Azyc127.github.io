#include<bits/stdc++.h>
using namespace std;

int n,cnt;
int a[10][10][10][10][10];
int s[6];

void Read()
{
    for(int i=1;i<=5;i++)
        scanf("%d",&s[i]);
    //only change one
    for(int i=0;i<10;i++)if(i!=s[1])a[i][s[2]][s[3]][s[4]][s[5]]++;
    for(int i=0;i<10;i++)if(i!=s[2])a[s[1]][i][s[3]][s[4]][s[5]]++;
    for(int i=0;i<10;i++)if(i!=s[3])a[s[1]][s[2]][i][s[4]][s[5]]++;
    for(int i=0;i<10;i++)if(i!=s[4])a[s[1]][s[2]][s[3]][i][s[5]]++;
    for(int i=0;i<10;i++)if(i!=s[5])a[s[1]][s[2]][s[3]][s[4]][i]++;
    //change two
    for(int i=1;i<=9;i++)
    {
        a[(s[1]+i)%10][(s[2]+i)%10][s[3]][s[4]][s[5]]++;
    }
    for(int i=1;i<=9;i++)
    {
        a[s[1]][(s[2]+i)%10][(s[3]+i)%10][s[4]][s[5]]++;
    }
    for(int i=1;i<=9;i++)
    {
        a[s[1]][s[2]][(s[3]+i)%10][(s[4]+i)%10][s[5]]++;
    }
    for(int i=1;i<=9;i++)
    {
        a[s[1]][s[2]][s[3]][(s[4]+i)%10][(s[5]+i)%10]++;
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        Read();
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    for(int m=0;m<10;m++)
                    {
                        if(a[i][j][k][l][m]==n)
                        {
                            cnt++;
                            //printf("[%d] %d %d %d %d %d\n",cnt,i,j,k,l,m);
                        }
                    }
                }
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
