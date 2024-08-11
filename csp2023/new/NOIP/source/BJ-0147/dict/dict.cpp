#include<bits/stdc++.h>
using namespace std;
const int maxn=3100;
int n,m,cnt[30];
char a[maxn][maxn],b[maxn],mn1[maxn],mn2[maxn],mn[maxn][maxn],mx[maxn][maxn];
void init()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
}
inline bool check(char x[],char y[])
{
    for(int i=1;i<=m;i++)
    {
        if(x[i]<y[i]) return true;
        else if(x[i]>y[i]) return false;
    }
    return true;
}
inline bool equal(char x[],char y[])
{
    for(int i=1;i<=m;i++) 
    {
        if(x[i]!=y[i]) return false;
    }
    return true;
}
inline void val(char x[],char y[])
{
    for(int i=1;i<=m;i++) x[i]=y[i];
}
inline void sort1(char x[])
{
    for(int i=0;i<26;i++) cnt[i]=0;
    int tmp=0;
    for(int i=1;i<=m;i++) cnt[x[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        for(int j=1;j<=cnt[i];j++) x[j+tmp]=i+'a';
        tmp+=cnt[i];
    }
}
inline void sort2(char x[])
{
    for(int i=0;i<26;i++) cnt[i]=0;
    int tmp=0;
    for(int i=1;i<=m;i++) cnt[x[i]-'a']++;
    for(int i=25;i>=0;i--)
    {
        for(int j=1;j<=cnt[i];j++) x[j+tmp]=i+'a';
        tmp+=cnt[i];
    }
}
void work()
{
    for(int i=1;i<=m;i++) mn1[i]=mn2[i]='z';
    for(int i=1;i<=n;i++)
    {
        val(b,a[i]);
        sort2(b);
        // for(int j=1;j<=m;j++) cout<<b[j]<<" ";
        // cout<<endl;
        val(mx[i],b);
        if(check(b,mn1))
        {
            val(mn2,mn1);
            val(mn1,b);
        }
        else if(check(b,mn2)) val(mn2,b);
        sort1(b);
        val(mn[i],b);
        // for(int j=1;j<=m;j++) cout<<mn[i][j]<<" ";
        // cout<<endl;
    }
    // for(int i=1;i<=m;i++) cout<<" "<<mn1[i];
    // cout<<endl;
    // for(int i=1;i<=m;i++) cout<<" "<<mn2[i];
    // cout<<endl;
}
void output()
{
    if(n==1)
    {
        cout<<1;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(equal(mx[i],mn1))
        {
            if(check(mn2,mn[i])) printf("0");
            else printf("1");
        }
        else
        {
            if(check(mn1,mn[i])) printf("0");
            else printf("1");
        }
    }
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int tmp=clock();
    init();
    work();
    output();
    // printf("\ntime: %lf",1.0*(clock()-tmp)/CLOCKS_PER_SEC);
    return 0;
}