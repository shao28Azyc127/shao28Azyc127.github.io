#include<bits/stdc++.h>
using namespace std;
int c,t;
long long ans;
int main(){
freopen("run5.in","r",stdin);
freopen("run.ans","w",stdout);
cin>>c>>t;
if(1==1){
    for(int i=0;i<t;++i){

        int n,m,k,d;
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int j=0;j<m;++j){
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            if(y>k or v<=d*y) continue;
            ans+=(v-d*y);
        }
        cout<<ans<<endl;
        ans=0;
    }

}


}
