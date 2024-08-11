#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,a[6];
bool p[100000],ans[100000];
void add(){
    cnt=0;
    for(int i=1;i<=5;i++){
        cnt=cnt*10+a[i];
    }
    p[cnt]=1;
}
void next(){
    for(int i=0;i<100000;i++){
        ans[i]=ans[i]&&p[i];
    }
}
void turn(int i,int j){
    a[i]=(a[i]+j)%10;
}
void twice(int i,int j){
    turn(i,j);
    turn(i+1,j);
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(ans,1,sizeof(ans));
    while(n--){
        for(int i=1;i<=5;i++){
            cin>>a[i];
        }
        memset(p,0,sizeof(p));
        for(int i=1;i<=5;i++){
            for(int j=1;j<=9;j++){
                turn(i,j);
                add();
                turn(i,10-j);
            }
        }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=9;j++){
                twice(i,j);
                add();
                twice(i,10-j);
            }
        }
        next();
    }
    cnt=0;
    for(int i=0;i<100000;i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout<<cnt;
}
