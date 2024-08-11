#include <bits/stdc++.h>
using namespace std;
const int N=10;
int n,ans=0;

int con[N][6],minu[N][5],dif[N][N];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>con[i][j];
        }
        for(int j=1;j<5;j++)
        {
            minu[i][j]=con[i][j+1]-con[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int l=1;l<=5;l++)
            {
                if(con[i][l]!=con[j][l])dif[i][j]++;
            }
            if(dif[i][j]>3){
                cout<<0;
                return 0;
            }
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    else{

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
                            bool flag=true;
                            for(int p=1;p<=n;p++)
                            if(abs(con[p][1]-i)+abs(con[p][2]-j)+abs(con[p][3]-k)+abs(con[p][4]-l)+abs(con[p][5]-m)>3){
                                    flag=false;
                                    break;

                            }
                            if(flag)ans++;
                        }
                    }
                }
            }
        }
        cout<<ans-n+1;
    }
}
