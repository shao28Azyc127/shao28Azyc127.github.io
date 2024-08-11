#include <bits/stdc++.h>
using namespace std;
int a[9][6];
int cmp(int a,int b)
{
    if(a==b)
    {
        return 0;
    }
    else
    if(a==9)
    {
        return b+10-9;
    }
    else if(b==0)
    {
        return 10-a;
    }
    else if(a>b)
    {
        return b+10-a;
    }
    else
        return b-a;

}
// 9 0 1
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    //cout<<a[1][3];
    int ans=0;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                for(int l=0;l<=9;l++)
                    for(int q=0;q<=9;q++)
        //if(i==0&&j==7&&k==8&&l==1&&q==5)
        {
            int flag=1;

            for(int x=1;x<=n;x++)
            {
                int c1=0,c2=0,c3=0;
                int x1=cmp(i,a[x][1]),
                x2=cmp(j,a[x][2]),
                x3=cmp(k,a[x][3]),
                x4=cmp(l,a[x][4]),
                x5=cmp(q,a[x][5]);

                if(x1==x2&&x1!=0)c1++;
                if(a[x][1]==i)c2++;

                if(x2==x3&&x2!=0)c1++;
                if(a[x][2]==j)c2++;

                if(x3==x4&&x3!=0)c1++;
                if(a[x][3]==k)c2++;

                if(x4==x5&&x4!=0)c1++;
                if(a[x][4]==l)c2++;

                if(a[x][5]==q)c2++;

                if(a[x][1]!=i)c3++;
                if(a[x][2]!=j)c3++;
                if(a[x][3]!=k)c3++;
                if(a[x][4]!=l)c3++;
                if(a[x][5]!=q)c3++;

                if(c2==4);
                else if(c1==1&&c2==3&&c3==2);
                else flag=0;
                //cout<<x2<<' '<<x3;
                //if(c1==1&&c2==3&&c3==2)cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<q<<endl;
            }
            if(flag)ans++;
        }
        cout<<ans<<endl;
    return 0;
}//0 0 1 1 5
