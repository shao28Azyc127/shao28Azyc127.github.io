#include <bits/stdc++.h>

using namespace std;

const int N=3e3+10,K=27;
int tim[K],ans[N];
struct node{
    int id;
    string t;
}min_s[N],max_s[N];
string s[N];
int n,m;

bool cmp(node x,node y)
{
    return x.t<y.t;
}

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)
            tim[s[i][j]-'a']++;
        for(int j=0;j<=25;j++)
            for(int k=1;k<=tim[j];k++)
                min_s[i].t+=('a'+j);
        for(int j=25;j>=0;j--)
            for(int k=1;k<=tim[j];k++)
                max_s[i].t+=('a'+j);
        min_s[i].id=max_s[i].id=i;
        memset(tim,0,sizeof(tim));
    }
    if(n==1) cout<<1<<endl;
    else{
        sort(max_s+1,max_s+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(min_s[i].id==max_s[1].id){
                if(min_s[i].t>=max_s[2].t) ans[i]=0;
                else ans[i]=1;
            }
            else{
                if(min_s[i].t>=max_s[1].t) ans[i]=0;
                else ans[i]=1;
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i];
    }
    return 0;
}
