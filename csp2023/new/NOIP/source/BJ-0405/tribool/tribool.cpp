#include <bits/stdc++.h>
using namespace std;
int n,m;
struct code{
    int n,m,t;
};
code c[100005];
int a[100005];
int o[100005];
int gm(int n,int m){
    int mul=1;
    for (int i=1;i<=m;i++) mul*=n;
    return mul;
}
int nottri(int a){
    if (a==1) return 2;
    if (a==2) return 1;
    return 3;
}
void fix(){
    for (int i=n;i>=1;i--){
        a[i-1]+=a[i]/3;
        a[i]=a[i]%3+1;
    }
    return;
}
void init(){
    for (int i=1;i<=n;i++){
        o[i]=a[i];
    }
    return;
}
bool same(){
    for (int i=1;i<=n;i++){
        if (a[i]!=o[i]) return 0;
    }
    return 1;
}
int findu(){
    int cnt=0;
    for (int i=1;i<=n;i++){
        if(a[i]==3) cnt++;
    }
    return cnt;
}
void print_check(){
    cout<<"a:";
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;
    cout<<"o:";
    for (int i=1;i<=n;i++) cout<<o[i]<<' ';
    cout<<endl;
    return;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,q;
    cin>>C>>q;
    while (q--){
        cin>>n>>m;
        for (int i=1;i<=m;i++){
            char type;
            cin>>type;
            if (type=='+'){
                c[i].t=1;
                cin>>c[i].n>>c[i].m;
            }
            if (type=='-'){
                c[i].t=2;
                cin>>c[i].n>>c[i].m;
            }
            if (type=='T'){
                c[i].t=3;
                cin>>c[i].n;
            }
            if (type=='F'){
                c[i].t=4;
                cin>>c[i].n;
            }
            if (type=='U'){
                c[i].t=5;
                cin>>c[i].n;
            }
        }
        memset(a,1,sizeof a);
        int minn=2e9;
        for (int i=1;i<=gm(3,n);i++){
            a[n]++;
            fix();
            init();
            for (int j=1;j<=m;j++){
                code now=c[j];
                int type=now.t;
                if (type==1){
                    o[now.n]=o[now.m];
                }
                if (type==2){
                    o[now.n]=nottri(o[now.m]);
                }
                if (type==3){
                    o[now.n]=1;
                }
                if (type==4){
                    o[now.n]=2;
                }
                if (type==5){
                    o[now.n]=3;
                }
            }
            if (same()){
                minn=min(minn,findu());
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}
/*
1 3
3 3
©\ 2 1
©\ 3 2
+ 1 3
3 3
©\ 2 1
- 3 2
©\ 1 3
2 2
T 2
U 2
*/

/*
ans:
0
3
1
*/
