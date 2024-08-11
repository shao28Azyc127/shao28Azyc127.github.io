#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int a[maxn],b[maxn],v[maxn],n,m,ans=1e18,f[maxn];
char c[maxn],s[maxn],s1[maxn];
char fu(char c){
    if (c=='F')return 'T';
    if (c=='T')return 'F';
    if (c=='U')return 'U';
}
void dfs(int k,int cnt){
    if (k==n+1){
        for (int i=1;i<=n;i++)s1[i]=s[i];
        int flag=1;
        for (int i=1;i<=m;i++){
            if (c[i]=='T'||c[i]=='U'||c[i]=='F'){
                s1[v[i]]=c[i];
            }
            if (c[i]=='+'){
                s1[a[i]]=s1[b[i]];
            }
            if (c[i]=='-'){
                s1[a[i]]=fu(s1[b[i]]);
            }
        }
        for (int i=1;i<=n;i++){
            if (s1[i]!=s[i])flag=0;
        }
        if (flag)ans=min(ans,cnt);
        return;
    }
    s[k]='T';
    dfs(k+1,cnt);
    s[k]='F';
    dfs(k+1,cnt);
    s[k]='U';
    dfs(k+1,cnt+1);
}
int getf(int k){
    if (f[k]!=f[f[k]])f[k]=getf(f[k]);
    return f[k];
}
void comb(int a,int b){
    a=getf(a),b=getf(b);
    if (a!=b)f[a]=b;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int x,t;
    cin>>x>>t;
    if (x==1||x==2){
        while  (t--){
            ans=1e18;
            cin>>n>>m;
            for (int i=1;i<=m;i++){
                cin>>c[i];
                if (c[i]=='T'||c[i]=='U'||c[i]=='F'){
                    cin>>v[i];
                }
                if (c[i]=='+'||c[i]=='-')cin>>a[i]>>b[i];
            }
            dfs(1,0);
        cout<<ans<<endl;
        }
    }
    if (x==3||x==4){
        while (t--){
            cin>>n>>m;
            for (int i=1;i<=n;i++)s[i]='0';
            for (int i=1;i<=m;i++){
                cin>>c[i]>>v[i];
                s[v[i]]=c[i];
            }
            int cnt=0;
            for (int i=1;i<=n;i++){
                if (s[i]=='U')cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    /*if (x==5||x==6){
        while (t--){
            cin>>n>>m;
            for (int i=1;i<=n;i++)s[i]='0';
            for (int i=1;i<=n;i++){
                f[i]=i;
            }
            for (int i=1;i<=m;i++){
                cin>>c[i];
                if (c[i]=='U'){
                    cin>>v[i];
                    s[v[i]]='U';
                }
                else {
                    cin>>a[i]>>b[i];
                    //if (s[b[i]]=='U')s[a[i]]='U';
                }
            }
            for (int i=1;i<=m;i++){
                if (c[i]=='+'){
                    if (s[b[i]]=='U')s1[a[i]]='U';
                    else ()
                    if (s[a[i]]!='U'&&s1[b[i]]!='U')s[a[i]]=
                }
            }
            int cnt=0;
            for (int i=1;i<=n;i++)if (s[i]=='U')cnt++;
            cout<<cnt<<endl;
        }
    }*/
}