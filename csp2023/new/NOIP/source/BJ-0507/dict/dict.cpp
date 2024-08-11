#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,cnt[N][30],f[N],l[N];
char s[N]; bool fl[N],fl1;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<m;j++) cnt[i][s[j]-'a']++;
    }
//    for(int i=1;i<=n;i++) {
//        for(int j=0;j<26;j++) cout<<cnt[i][j]<<" ";
//        puts("");
//    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
            if(cnt[i][j]) {f[i]=j; break;}
        for(int j=25;j>=0;j--)
            if(cnt[i][j]) {l[i]=j; break;}
    }
//    for(int i=1;i<=n;i++) cout<<f[i]<<" "<<l[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        fl[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(f[i]>=l[j]) {fl[i]=0; break;}
            //else if(f[i]==l[j] &&  cnt[i][f[i]]>=cnt[j][l[j]]) {fl[i]=0; break;}
        }
    }
    for(int i=1;i<=n;i++) printf("%d",fl[i]); puts("");
    return 0;
}
