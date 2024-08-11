#include<bits/stdc++.h>
using namespace std;
int n,m=5,a[10][10],b[10],ans;
bool check(int x){
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(a[x][i]!=b[i]) cnt++;
    }
    if(cnt==1) return 1;
    cnt=0;
    for(int i=1;i<=m;i++){
        if(a[x][i]==b[i]) continue;
        if((a[x][i]-b[i]+10)%10==(a[x][i+1]-b[i+1]+10)%10) cnt++,i++;
        else return 0;
    }
    if(a[x][m-1]==b[m-1]&&a[x][m]!=b[m]) return 0;
    return cnt==1;
}
void s(int x){
    if(x==m+1){
        for(int i=1;i<=n;i++) if(!check(i)) return;
        //for(int i=1;i<=m;i++) cout<<b[i]<<' ';cout<<endl;
        ans++;
        return;
    }
    for(int i=0;i<=9;i++){
        b[x]=i;
        s(x+1);
    }
    return;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    //if(n==1){
    //    cout<<81<<endl;
    //    return 0;
    //}
    s(1);
    cout<<ans<<endl;
}
