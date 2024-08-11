#include<bits/stdc++.h>
using namespace std;
int s[10][20];
int h[20][20];
int sum[20];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,a,b,c,d,e;
    int a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
    cin>>n;
    if(n==1){
        cin>>a>>b>>c>>d>>e;
        cout<<81;
        return 0;
    }
    if(n==2){
        cin>>a1>>b1>>c1>>d1>>e1;
        cin>>a2>>b2>>c2>>d2>>e2;
        if(a1==a2 && b1==b2 && c1==c2 && d1==d2 && e1!=e2){
            cout<<10;
            return 0;
        }
        if(a1==a2 && b1==b2 && c1==c2 && d1!=d2 && e1==e2){
            cout<<10;
            return 0;
        }
        if(a1==a2 && b1==b2 && c1!=c2 && d1==d2 && e1==e2){
            cout<<10;
            return 0;
        }
        if(a1==a2 && b1!=b2 && c1==c2 && d1==d2 && e1==e2){
            cout<<10;
            return 0;
        }
        if(a1!=a2 && b1==b2 && c1==c2 && d1==d2 && e1==e2){
            cout<<10;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>s[j][i];
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            h[i][s[i][j]]++;
        }
    }
    int cnt=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=10;j++){
            if(h[i][j]!=0){
                sum[i]++;
            }
        }
        cnt+=sum[i];
    }
    cout<<cnt;
    return 0;
}
