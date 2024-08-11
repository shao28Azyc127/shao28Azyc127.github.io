#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
bool check[10];
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
    else{
        for(int i=1;i<=5;i++){
            for(int x=1;x<=n;x++)
                for(int y=1;y<=n;y++)
                    if(a[x][i]!=a[y][i])
                        check[i]=1;
        }
        for(int i=1;i<=5;i++){
            if(check[i]){
                ans+=10-n;
                //if((check[i]&&check[i+1])){
                 //   if(abs(a[1][i]-a[1][i+1])==abs(a[2][i]-a[2][i+1]))
                 //       ans+=10-n;
                //}
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
