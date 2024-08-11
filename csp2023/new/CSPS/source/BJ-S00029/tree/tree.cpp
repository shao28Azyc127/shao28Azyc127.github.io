#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001],st[100000],en[100000],vis[100001];
int moni(int x,int tree,int wish){
    while(wish>0){
        wish-=max(b[tree]+x*c[tree],1);
        x++;
    }
    return x;
}
int main(){
    int n;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin >>st[i]>>en[i];
    }
    int x=0;
    while(true){
            x++;
        if(x==1){
            vis[1]=moni(1,1,a[1]);
            x++;
        }
        int maxn,maxx=-1;
        for(int i=1;i<n;i++){
            if(vis[st[i]]>0&&vis[en[i]]==0){
                if(moni(x,en[i],a[en[i]])>maxx){
                    maxx=moni(x,en[i],a[en[i]]);
                    maxn=en[i];
                }
            }else if(vis[en[i]]>0&&vis[st[i]]==0){
                maxx=moni(x,st[i],a[st[i]]);
                maxn=st[i];
            }

        }
        cout <<maxn<<" "<<maxx<<endl;
        if(maxx==-1){
                int ans=0;
                for(int i=1;i<=n;i++){
                    ans=max(ans,vis[i]);
                }
                cout <<ans-1;
                return 0;

        }
        vis[maxn]=maxx;
  
    }
    return 0;
}
