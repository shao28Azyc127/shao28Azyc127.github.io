#include<bits/stdc++.h>
using namespace std;
int m;
long long n,k,d;
long long ans,cnt,v,u,f;
int c,t,q;
struct cmp{
    long long x,y,z;
};
cmp s[100005];
bool cm(cmp aa,cmp bb){
    if(aa.x<bb.x){
        return 1;
    }else{
        return 0;
    }
}
void dfs(long long w){
    if(w==n+1||f>cnt){
        ans=max(ans,v);
        //cout<<ans<<endl;
        return;
    }
    for(int i=1;i<=2;i++){
        if(i==1&&u<k){
            v-=d;
            u++;
            if(w==s[f].x){
                if(u>=s[f].y){
                    v+=s[f].z;
                    f++;
                    dfs(w+1);
                    f--;
                    v-=s[f].z;
                }else{
                    f++;
                    dfs(w+1);
                    f--;
                }
            }else{
                dfs(w+1);
            }
            v+=d;
            u--;
        }else{
            int j=u;
            u=0;
            int r=0;
            if(w==s[f].x){
                f++;
                r=1;
            }
            dfs(w+1);
            if(r==1){
                f--;
            }
            u=j;
        }
    }
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int _=1;_<=t;_++){
        cin>>n>>m;
        cin>>k>>d;
        cnt=1;
        ans=0;
        v=0;
        for(int i=1;i<=m;i++){
            cin>>s[cnt].x>>s[cnt].y>>s[cnt].z;
            if(s[cnt].y<=k){
                cnt++;
            }
        }
        sort(s+1,s+cnt,cm);
        //cout<<s[1].x<<" "<<s[2].x<<endl;
        u=0;
        f=1;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
