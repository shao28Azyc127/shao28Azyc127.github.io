#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=1e9+5;
int c,t,n,m,cnt,ans;
int a[15],b[15],act[N][10];
bool A[N];
inline bool check(){
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)   b[i]=a[i];
    for(int i=1;i<=m;i++){
        if(act[i][1]==1)    b[act[i][2]]=1;
        if(act[i][1]==2)    b[act[i][2]]=2;
        if(act[i][1]==3)    b[act[i][2]]=3;
        if(act[i][1]==4)    b[act[i][2]]=b[act[i][3]];
        if(act[i][1]==5){
            if(b[act[i][3]]==1)  b[act[i][2]]=2;
            else if(b[act[i][3]]==2)  b[act[i][2]]=1;
            else if(b[act[i][3]]==3)  b[act[i][2]]=3;
        }
    }
    for(int i=1;i<=n;i++)   if(a[i]!=b[i])  return 0;
    return 1;
}
inline void find(int p){
    if(cnt>=ans) return ;
    if(p==n){
        if(check()){
            ans=min(ans,cnt);
        }
        return ;
    }
    for(int i=1;i<=3;i++){
        a[p+1]=i;
        if(i==3)    cnt++;
        find(p+1);
        if(i==3)    cnt--;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2){
        while(t--){
            memset(act,0,sizeof(act));
            memset(a,0,sizeof(a));
            ans=inf;
            cnt=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char c;
                int I,J;
                cin>>c;
                if(c=='T'){
                    cin>>I;
                    act[i][1]=1;
                    act[i][2]=I;
                }
                if(c=='F'){
                    cin>>I;
                    act[i][1]=2;
                    act[i][2]=I;
                }
                if(c=='U'){
                    cin>>I;
                    act[i][1]=3;
                    act[i][2]=I;
                }
                if(c=='+'){
                    cin>>I>>J;
                    act[i][1]=4;
                    act[i][2]=I;
                    act[i][3]=J;
                }
                if(c=='-'){
                    cin>>I>>J;
                    act[i][1]=5;
                    act[i][2]=I;
                    act[i][3]=J;
                }
            }
            find(0);
            cout<<ans<<endl;
        }
    }
    else if(c==3||c==4){
        while(t--){
            memset(A,0,sizeof(A));
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char c;
                int I,J;
                cin>>c;
                if(c=='T'){
                    cin>>I;
                    A[I]=0;
                }
                if(c=='F'){
                    cin>>I;
                    A[I]=0;
                }
                if(c=='U'){
                    cin>>I;
                    A[I]=1;
                }
            }
            for(int i=1;i<=n;i++)   ans+=A[i];
            cout<<ans<<endl;
        }
    }
    else if(c==5||c==6){
        while(t--){
            memset(A,0,sizeof(A));
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char c;
                int I,J;
                cin>>c;
                if(c=='U'){
                    cin>>I;
                    A[I]=1;
                }
                if(c=='+'){
                    cin>>I>>J;
                    A[I]=A[J];
                }
            }
            for(int i=1;i<=n;i++)   ans+=A[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
