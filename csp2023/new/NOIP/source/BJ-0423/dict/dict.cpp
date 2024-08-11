#include <bits/stdc++.h>
using namespace std;
int m,n,tx[3005][259],ty[3005][259];
string a[3005];
char x[3005][3][3005];
bool comp(char a[3005],char b[3005]){
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            return false;
        }
        if(a[i]<b[i]){
            return true;
        }
    }
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>a[i];
        for(int j=0;j<n;j++){
            tx[i][a[i][j]]++;
            ty[i][a[i][j]]++;
        }
    }
    int xx=0;
    for(int i=0;i<m;i++){
        for(int k=0;k<257;k++){
            while(tx[i][k]){
                x[i][1][xx]=char(k);
                xx++;
                tx[i][k]--;
            }
        }
        xx=0;
    }
    for(int i=0;i<m;i++){
        for(int j=n;j>=0;j--){
            x[i][2][n-j-1]=x[i][1][j];
        }
    }
    for(int i=0;i<m;i++){
        bool flag=true;
        for(int j=0;j<m;j++){
            if(!comp(x[i][1],x[j][2])&&j!=i){
                flag=false;
            }
        }
        if(flag){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    return 0;
}
