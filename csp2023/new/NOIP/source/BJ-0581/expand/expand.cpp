// logic wrong
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

const int N=5e5;

inline void optim(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

inline void fio(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
}

int c,n,m,q;
// int x[N+5],y[N+5];
vector<int> x,y,x1,y1;

bool solve(bool mode){
    // cout<<mode<<endl;
    if(mode==1){
        int mn=min(n,m);
        for(int i=1;i<mn;i++){
            if(x[i]<=y[i]){
                x.insert(x.begin()+i,x[i-1]);
            }
        }
        int sx=x.size();
        int sy=y.size();
        int k=abs(sx-sy);
        int mn2=min(sx,sy);
        if(x.size()<y.size()){
            for(int i=mn2+1;i<=mn2+k;i++){
                if(x[mn2-1]<=y[i-1]){
                    return 0;
                }
            }
        }
        else{
            for(int i=mn2+1;i<=mn2+k;i++){
                if(x[i-1]<=y[mn2-1]){
                    return 0;
                }
            }
        }
        return 1;
    }
    else{
        int mn=min(n,m);
        for(int i=1;i<mn;i++){
            if(x[i]>=y[i]){
                y.insert(y.begin()+i,y[i-1]);
            }
        }
        int sx=x.size();
        int sy=y.size();
        int k=abs(sx-sy);
        int mn2=min(x.size(),y.size());
        if(x.size()<y.size()){
            for(int i=mn2+1;i<=mn2+k;i++){
                if(x[mn2-1]>=y[i-1]){
                    return 0;
                }
            }
        }
        else{
            for(int i=mn2+1;i<=mn2+k;i++){
                if(x[i-1]>=y[mn2-1]){
                    return 0;
                }
            }
        }
        return 1;
    }    
}

inline void restore(){
    x.clear();y.clear();
    x=x1;y=y1;
}

inline void _outxy(){
    cout<<endl;
    cout<<"///"<<endl;
    for(auto it=x.begin();it!=x.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it2=y.begin();it2!=y.end();it2++){
        cout<<*it2<<" ";
    }
    cout<<endl;
    cout<<"///"<<endl;
}
inline bool sel(){
    if(x[0]>y[0]) return 1;
    if(x[0]<y[0]) return 0;
    for(int i=1;i<min(x.size(),y.size());i++){
        if(x[i]>y[i]) return 1;
        if(x[i]<y[i]) return 0;
    }
    return 0;
}
signed main(){
    fio();
    scanf("%d %d %d %d",&c,&n,&m,&q);
    bool mode=0;
    int tmp;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        x.push_back(tmp);
        x1.push_back(tmp);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&tmp);
        y.push_back(tmp);
        y1.push_back(tmp);
    }
    mode=sel();
    int ans1=solve(mode);
    printf("%d",ans1);
    restore();
    // _outxy();
    for(int i=1;i<=q;i++){
        int kx,ky;
        scanf("%d %d",&kx,&ky);
        for(int j=1;j<=kx;j++){
            int p,v;
            scanf("%d %d",&p, &v);
            x.insert(x.begin()+p-1,v);
            x.erase(x.begin()+p);
        }
        for(int j=1;j<=ky;j++){
            int p,v;
            scanf("%d %d",&p,&v);
            y.insert(y.begin()+p-1,v);
            y.erase(y.begin()+p);
        }
        // _outxy();
        mode=sel();
        int ans=solve(mode);
        printf("%d",ans);
        restore();
    }
    return 0;
}
