//Orz dls
//Orz wsc
//Orz lhk
//Orz lzc
//Orz xht
//Orz dyh
//Orz xhr
//Orz dhx
#include<bits/stdc++.h>
using namespace std;
short vis[1000005];
int n,ans;
int zhu(int y,int e){
    return (y+e+10)%10;
}
int ya(int a[]){
    int Sum=0;
    for(short i=1;i<=5;++i){
        Sum=Sum*10+a[i];
    }
    return Sum;
}
int a[5][8];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++j){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        vis[ya(a[i])]++;
        for(int j=1;j<=5;++j){
            int TT=a[i][j];
            for(int k=0;k<=9;++k){
                if(k==TT) continue;
                a[i][j]=k;
                vis[ya(a[i])]++;
                a[i][j]=TT;
            }
            if(j==5) continue;
            set<pair<int,int> > S;
            for(int k=-9;k<=9;++k){
                if(k==0) continue;
                S.insert({zhu(a[i][j],k),zhu(a[i][j+1],k)});
            }
            int TT1=a[i][j+1];
            for(set<pair<int,int> >::iterator it=S.begin();it!=S.end();++it){
                a[i][j]=(*it).first,a[i][j+1]=(*it).second;
                vis[ya(a[i])]++;
                a[i][j]=TT,a[i][j+1]=TT1;
            }
        }
    }
    for(int i=0;i<=1000000;++i){
        if(vis[i]==n){
            ans++;
        }
    }
    cout<<ans-n;
    return 0;
}
