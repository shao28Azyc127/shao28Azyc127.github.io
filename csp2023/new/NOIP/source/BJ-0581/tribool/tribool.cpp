#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

using namespace std;

const int N=1e5;

inline void fio(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
}
// // define 1 U 0 T -1 F
// int vars[N+5];
// int fa[N+5];
map<int,int > fa,vars;

int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}

void merge(int x,int y){
    fa[x]=getfa(fa[y]);
}

void check(int i,int j,bool fl,int mid){ // check and merge
    if(fl==1){
        if(vars[mid+i]==0){
            vars[mid+i]=j;
        }else{
            merge(vars[mid+i],j);
        }
        if(vars[mid-i+1]==0){
            vars[mid-i+1]=-j;
        }else{
            merge(vars[mid-i+1],-j);
        }

        return;
    }
    if(vars[mid+i]==0){
        vars[mid+i]=-j;
    }else{
        merge(vars[mid+i],j);
    }
    if(vars[mid-i+1]==0){
        vars[mid-i+1]=j;
    }else{
        merge(vars[mid-i+1],-j);
    }

    return;    
}

inline void work34(int t){
    int n,m,t1=t,ans;
    while(t1--){
        ans=0;vars.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            char v;
            int k;
            cin>>v;
            scanf("%d",&k);
            if(v=='T'){
                vars[k]=0;
            }
            if(v=='F'){
                vars[k]=-1;
            }
            if(v=='U'){
                vars[k]=1;
            }
        }

        for(int i=1;i<=n;i++){
            if(vars[i]==1) ans++;
        }
        printf("%d\n",ans);
    }
}

inline void work56(int t){
    int n,m,t1=t,ans;
    while(t1--){
        ans=0;vars.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            char v;
            int k,l;
            cin>>v;
            if(v=='U'){
                scanf("%d",&k);
                vars[k]=1;
            }
            if(v=='+'){
                scanf("%d %d",&k,&l);
                vars[k]=vars[l];
            }
        }
        for(int i=1;i<=n;i++){
            if(vars[i]==1) ans++;
        }
        printf("%d\n",ans);
    }

}

inline void work78(int t){
    int n,m,t1=t,ans;
    while(t1--){
        ans=0;
        scanf("%d %d",&n,&m);
        vars.clear();
        // memset(vars,1,sizeof(vars));
        for(int i=1;i<=m;i++){
            char v;
            int k,l;
            cin>>v;
            if(v=='-'){
                scanf("%d %d",&k,&l);
                vars[k]=-vars[l];
            }
            if(v=='+'){
                scanf("%d %d",&k,&l);
                vars[k]=vars[l];
            }
            
        }   
        for(int i=1;i<=n;i++){
            if(vars[i]==1) ans++;
        }
        printf("%d\n",ans);
    }

}

signed main(){
    fio();
    int c,t;
    scanf("%d %d",&c,&t);
    // for(int i=1;i<=n;i++){
    //     fa[i]=i;
    // }
    if(c==3||c==4){
        work34(t);
    }
    if(c==5||c==6){
        work56(t);
    }
    if(c==7||c==8){
        work78(t);
    }
    // while(t--){
    //     int n,m;
    //     scanf("%d %d",&n,&m);
    //     memset(vars,0,sizeof(vars));
    //     for(int i=1;i<=m;i++){
    //         int mid=n;
    //         // + n+1 - n-i+1;
    //         char v;
    //         int k,l;
    //         v=getchar();
    //         // if(v=='T'||v=='F'||v=='U'){
    //         //     scanf("%d",&i);
    //         //     if(v=='T'){
    //         //         vars[i+mid]=1;
    //         //     }
    //         //     if(v=='F'){
    //         //         vars[i+mid]=-1;
    //         //     }
    //         //     if(v=='U'){
    //         //         vars[i+mid]=0;
    //         //     }
    //         // }
    //         if(v=='+'||v=='-'){
    //             scanf("%d %d",&k,&l);
    //             if(v=='+'){
    //                 check(k,l,1,mid);
    //             }
    //             if(v=='-'){
    //                 check(k,l,0,mid);
    //             }
    //         }
    //     }
    //     int ans=0;
    //     for(int i=1;i<=n;i++){
    //         if(vars[i]==0) ans++;
    //     }
    //     cout<<ans<<endl;
    // }
    return 0;
}
