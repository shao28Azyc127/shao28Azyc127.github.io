#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
char c[2000200];
struct node
{
    ll id,color;
}s[2000200];
ll vis[2000200];
ll top=0;
map<int,int> mp;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(top!=0&&s[top].color==c[i]-'a')
        {
            mp[s[top].id]=i;
            mp[i]=s[top].id;
            top--;
        }
        else s[++top].id=i,s[top].color=c[i]-'a';
    }
    for(auto i:mp)
    {
//        cout<<i.first<<" "<<i.second<<endl;
        if(vis[i.first]==1||i.first>i.second) continue;
        vis[i.first]=vis[i.second]=1;
        int anss=0,x=i.first,y=i.second,anst=0;
        while(x<y)
        {
            anss++;
            if(y+1<=n&&c[y]==c[y+1])
            {
//                cout<<y<<" "<<y+1<<" "<<c[y]<<" "<<c[y+1]<<endl;
                anst++;
            }
            x=y+1;
            if(x>n) break;
            y=mp[x];
            vis[x]=vis[y]=1;
        }
//        cout<<(anss+1)*anss/2<<endl;
        ans+=(anss+1)*anss/2;
        ans+=(anst+1)*anst/2;
    }
    cout<<ans;
    return 0;
}
