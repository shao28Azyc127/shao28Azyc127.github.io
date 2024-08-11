# include <bits/stdc++.h>
# define N 100005
using namespace std;
int n;
vector<int> a[10];
bool died[N];
bool ok[N][10];
int get(vector<int> v)
{
    return v[0]+v[1]*10+v[2]*100+v[3]*1000+v[4]*10000;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].resize(5);
        for(int j=0;j<5;j++)
            cin>>a[i][j];
        died[get(a[i])]=1;
        for(int j=0;j<5;j++)
        {
            auto b=a[i];
            for(int k=1;k<=10;k++)
            {
                b[j]=(b[j]+k)%10;
                ok[get(b)][i]=1;
                b[j]=a[i][j];
            }
        }
        for(int j=0;j<4;j++)
        {
            auto b=a[i];
            for(int k=1;k<=10;k++)
            {
                b[j]=(b[j]+k)%10;
                b[j+1]=(b[j+1]+k)%10;
                ok[get(b)][i]=1;
                b[j]=a[i][j];
                b[j+1]=a[i][j+1];
            }
        }
    }
    int ans=0;
    for(int i=0;i<100000;i++)
    {
        bool res=!died[i];
        for(int j=1;j<=n;j++)
            res&=(ok[i][j]);
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}
//-ulimit -s unlimited
//-fsanitize=undefined,address