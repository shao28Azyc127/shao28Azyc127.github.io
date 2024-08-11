#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int n,m,k,d;
    int x,y,z;
    int c,t;
    cin>>c>>t;
    int o;
    int i,j;
    int p;
    int q;//jishu
    int nimabi=-100000;
    int e[1005]={0};
    for(o=0;o<t;o++){
        cin>>n>>m>>k>>d;
        for(i=0;i<m;i++){
            p=0;q=0;
            for(j=0;j<1005;j++)
                e[j]=0;
            cin>>x>>y>>z;
            if(n>=x){
                p=n/(k+1);
                p*=k;//daka tianshu
                if(k>=y){
                    q+=z;
                    q-=p*d;
                }
            }
            if(q>nimabi){
                nimabi=q;
            }
        }
        e[o]=nimabi;
    }
    for(o=0;o<t;o++){
        cout<<e[o]<<" ";
    }
    return 0;
}
