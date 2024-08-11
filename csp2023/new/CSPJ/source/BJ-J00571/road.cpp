#include<iostream>
using namespace std;
int a[100005];
int b[100005];
int n,d=0;
int ans1=0;
int allo=0;
int minans=2147483647;
void dfs(int now,int money,int o) {//now=dang qian dian money=dang qian zong qian shu o=hai neng pao duo shao gong li
    if(o<=0) return ;
    if(now==n && money<minans) {
		minans=money;
        return ;
    }
    for(int i=1;i<=allo;i++) {
        dfs(now+1,money+i*b[now],o-a[now]+i);
    }
    dfs(now+1,money,o-a[now]);
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
    }
    for(int i=1;i<n;i++) {
        cin>>a[i];
        allo+=a[i];
    }
    dfs(0,0,0);
    cout<<minans;
    return 0;
}
