#include <bits/stdc++.h>

using namespace std;

int n,m;
char c[3010];
int f[3010][3010];
int tong[3010][30];

int b,w;
bool flag;

int i,j;
int k;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    scanf("%d%d",&n,&m);

    if(n==1)
    {
        printf("1\n");

        return 0;
    }

    for(i=1;i<=n;++i)
    {
        cin>>c;

        for(j=0;j<m;++j)
        {
            ++tong[i][c[j]-'a'+1];
        }
    }

    for(i=1;i<=n;++i)
    {
        flag=true;

        for(j=1;j<=26;++j)//best
        {
            if(tong[i][j]>0)
            {
                b=j;
                break;
            }
        }

        for(j=1;j<=n;++j)//worse
        {
            if(j==i)
            {
                continue;
            }

            for(k=26;k>=1;--k)
            {
                if(tong[j][k]>0)
                {
                    w=k;
                    break;
                }
            }

            //cout<<i<<"  "<<j<<endl;
            //cout<<b<<" "<<w<<endl;

            if(w<b)
            {
                flag=false;
                break;
            }
            else if(w==b)
            {
                if(tong[i][b]==tong[j][w])
                {
                    flag=false;
                    break;
                }
                else if(tong[i][b]>tong[j][w])
                {
                    flag=false;
                    break;
                }
            }
        }

        if(flag==true)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    return 0;
}
