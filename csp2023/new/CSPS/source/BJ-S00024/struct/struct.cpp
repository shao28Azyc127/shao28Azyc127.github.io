#include <bits/stdc++.h>
using namespace std;
int num[1005][10];
int n;
int t[10];
bool check(int a,int b,int c,int d,int e)
{
    memset(t,0,sizeof(t));
    t[0]=100;
    for(int i=1;i<=n;i++)
    {
        t[1]=a-num[i][1];
        t[2]=b-num[i][2];
        t[3]=c-num[i][3];
        t[4]=d-num[i][4];
        t[5]=e-num[i][5];
        if(a<num[i][1]) t[1]=a+10-num[i][1];
        if(b<num[i][2]) t[2]=b+10-num[i][2];
        if(c<num[i][3]) t[3]=c+10-num[i][3];
        if(d<num[i][4]) t[4]=d+10-num[i][4];
        if(e<num[i][5]) t[5]=e+10-num[i][5];
        int sum=0;
        int wei1=-1;
        int wei2=-1;
        for(int i=1;i<=5;i++)
        {
            if(t[i]!=0)
            {
                sum++;
                if(sum>2)
                {
                    return false;
                }
                if(wei1==-1) wei1=i;
                else wei2=i;
            }
        }
        if(sum==2)
        {
            if(abs(wei1-wei2)>1)
            {
                return false;
            }
            if(t[wei1]!=t[wei2])
            {
                return false;
            }
        }
        if(sum==0)
        {
            return false;
        }
    }
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
    return true;

}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>num[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    for(int z=0;z<=9;z++)
                    {
                        if(check(i,j,k,l,z))
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
