#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N=3010,mod=998244353;
const ll base=131;
char AAA;
int n,m,t[N];
int s1[N][N],s2[N][N];
int mx[N][N],mn[N][N];
int ans[N];
char s[N];
char BBB;

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
//    cout<<(abs(&AAA-&BBB)/1024.0/1024.0)<<endl;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) t[j]=s[j]-'0';
        sort(t+1,t+m+1);
        for(int j=1;j<=m;j++) s1[i][j]=t[j];
        for(int j=1;j<=m;j++) mn[i][j]=(1LL*mn[i][j-1]*base+t[j])%mod;

        sort(t+1,t+m+1,[](int x,int y){return x>y;});
        for(int j=1;j<=m;j++) s2[i][j]=t[j];
        for(int j=1;j<=m;j++) mx[i][j]=(1LL*mx[i][j-1]*base+t[j])%mod;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            int l=1,r=m;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(mn[i][mid]==mx[j][mid]) l=mid+1;
                else r=mid-1;
            }
            if(l>m||s1[i][l]>s2[j][l]) ans[i]=0;
        }
    }
    for(int i=1;i<=n;i++) putchar(ans[i]+'0');
    putchar('\n');

    return 0;
}
