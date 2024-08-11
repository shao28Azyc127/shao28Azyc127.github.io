#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,ans;
ll f[200004];
ll n,m;
bool flag[200004];
int findx(int x){
    if(f[x]==x) return x;
    return f[x]=findx(f[x]);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    f[200001]=200001;
    f[200002]=200002;
    f[200003]=200003;
    for(int k=1;k<=T;k++){
        ans=0;
        cin>>n>>m;
        f[200001]=200001;
        f[200002]=200002;
        f[200003]=200003;
        for(int i=1;i<=200003;i++){
            f[i]=i;
        }
        for(int i=1;i<=m;i++){
            char u;
            int t1,t2;
            cin>>u;
            if(u=='+'){
                cin>>t1>>t2;
                if(t1!=t2){
                    f[t1]=findx(t2);
                    f[t1+n]=findx(t2+n);
                }
            }
            if(u=='-'){
                cin>>t1>>t2;
                if(t1==t2){
                    f[t1]=200003;
                    f[t1+n]=200003;
                }else{
                    f[t1+n]=findx(t2);
                    f[t1]=findx(t2+n);
                }
            }
            if(u=='T'){
                cin>>t1;
                f[t1]=200001;
                f[t1+n]=200002;
            }
            if(u=='F'){
                cin>>t1;
                f[t1]=200002;
                f[t1+n]=200001;
            }
            if(u=='U'){
                cin>>t1;
                f[t1]=200003;
                f[t1+n]=200003;
            }
        }
        for(int i=1;i<=n;i++){
            if(findx(i)==findx(i+n)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
