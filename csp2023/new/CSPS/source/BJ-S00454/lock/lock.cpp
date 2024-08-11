#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int a[6];
int an;
int n;
int f(int a[]){
    int x;
    for(int i=1;i<=5;i++){
        x=10*x+a[i];
    }
    return x;
}
void bfs(int a[]){
    for(int i=1;i<=5;i++){
        for(int j=0;j<10;j++){
            if(j==a[i])continue;
            int t=a[i];
            a[i]=j;
            mp[f(a)]++;
            a[i]=t;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<10;j++){
            a[i]+=j;
            a[i+1]+=j;
            a[i]%=10;
            a[i+1]%=10;
            mp[f(a)]++;
            a[i]=(a[i]+10-j)%10;
            a[i+1]=(a[i+1]+10-j)%10;
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++)cin>>a[i];
        bfs(a);
    }
    map<int,int>::iterator it;
    it=mp.begin();
    for(it;it!=mp.end();it++){
        //cout<<it->first<<" "<<it->second<<endl;
        if(it->second==n){
            an++;
        }
    }
    cout<<an;
    return 0;
}
