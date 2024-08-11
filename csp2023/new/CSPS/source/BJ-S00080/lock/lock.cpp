#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=10;
int a[MAXN][MAXN];
int n;
bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        int pos1=0,num1=-1,pos2=0,num2=-1;
        int tmp=10000;
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]!=(x/tmp)%10)
            {
                if(pos1&&pos2) return false;
                else if(pos1) pos2=j,num2=(x/tmp)%10;
                else pos1=j,num1=(x/tmp)%10;
            }
            tmp/=10;
        }
        if(pos1&&pos2&&pos2-pos1!=1) return false;
        if(!pos1&&!pos2) return false;
        if(pos1&&pos2)
        {
            bool flag=false;
            for(int j=1;j<=9;j++)
            {
                num1=(num1+1)%10,num2=(num2+1)%10;
                if(num1==a[i][pos1]&&num2==a[i][pos2])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag) return false;
        }
    }
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    //freopen("/home/noip02/CSP-S/lock2.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) cin>>a[i][j];
    int cnt=0;
    for(int i=0;i<100000;i++)
    {
        if(check(i))
        {
            cnt++;
            //cout<<i<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}