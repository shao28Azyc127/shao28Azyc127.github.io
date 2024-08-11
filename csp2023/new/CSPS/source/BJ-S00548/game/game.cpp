#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
char T[N];
map<pair<int,int>,bool>mp;
int lt,ans=0,n;
inline void check(int l,int r)
{
    if((r-l+1)&1)return;
    if(r==l+1)
    {
        if(T[l]==T[l+1])ans++,mp[make_pair(l,l+1)]=true;
        return;
    }
    bool flag1=true,flag2=true,flag3=true;
    char op=T[l];
    int head=l,tail=r;
    for(int i=l+1;i<=r;i++)
        if(T[i]!=op)flag1=false;
    for(int i=l;i<=r;i++)
    {
        if(T[tail]!=T[head])flag2=false;
        tail--,head++;
    }
    for(int k=l+1;k<r;k++)
    {
        if(mp[make_pair(l,k)]&&mp[make_pair(k+1,r)])
        {
            flag3=true,ans++,mp[make_pair(l,r)]=true;
            return;
        }
    }
    //cout<<flag1<<" "<<flag2<<" "<<flag3<<endl;
    if(flag1||flag2)
        ans++,mp[make_pair(l,r)]=true;
    return;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> lt;
    for(int i=1;i<=lt;i++)cin >> T[i];
    for(int len=2;len<=lt;len+=2)
        for(int l=1;l<=lt-len+1;l++)
            check(l,l+len-1);
    /*for(int i=1;i<=lt;i++)
    {
        for(int j=i+1;j<=lt;j++)
            if(mp[make_pair(i,j)])
                cout<<i<<" "<<j<<endl;
    }*/
    cout<<ans;
    return 0;
}