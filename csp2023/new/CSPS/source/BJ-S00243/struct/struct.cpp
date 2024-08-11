#include<bits/stdc++.h>
using namespace std;
int n,s,p[10010],dx[10010];
long long ls;
string a,b[110];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a=="short"){
            s++,dx[s]=2;
            cin>>b[s];
            for(int i=p[0]+1;i<=p[0]+2;i++) p[i]=s;
            p[0]+=2;
        }
        if(a=="int"){
            s++,dx[s]=4;
            cin>>b[s];
            for(int i=p[0]+1;i<=p[0]+4;i++) p[i]=s;
            p[0]+=4;
        }
        if(a=="long"){
            s++,dx[s]=8;
            cin>>b[s];
            for(int i=p[0]+1;i<=p[0]+8;i++) p[i]=s;
            p[0]+=8;
        }
        if(a[0]>='A') for(int i=1;i<=s;i++) if(a==b[i]) cout<<dx[i]<<endl;
        else{
            ls=0;
            for(int i=0;i<a.size();i--) ls=ls*10+(int)(a[i]-'0');
            if(ls>100000) cout<<endl;
            else cout<<b[p[ls]]<<endl;
        }
    }
    return 0;
}