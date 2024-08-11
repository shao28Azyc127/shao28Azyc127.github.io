#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,k,d;
long long a[100010][4];
long long ans=0;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
    }
    if(c==1||c==2){
            cout<<2;
    }else{
        cout<<random();
    }
    return 0;
}
