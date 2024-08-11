#include <bits/stdc++.h>
using namespace std;

int n;
int a[15][15];
int ans1=45;
int ans2=36;
int cnt1=0;
int cnt2=0;
int main()
{
    //freopen("lock.in",r,stdin);
   // freopen("lock.out",w,stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=a[i-1][j]){
                cnt1++;
                if(cnt1>1){
                    ans1=0;
                    break;
                }
                else if(cnt1==1){
                    cnt1=0;
                    ans1=10-n;
                }
            }
        }
        if(cnt1>1) break;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[i][j]!=a[i-1][j] && a[i][j-1]!=a[i-1][j-1] && a[i][j+1]!=a[i-1][j+1]){
                ans2=0;
                break;
            }
            else if((j==2) && (a[i][j]-a[i][j+1]==a[i-1][j]-a[i-1][j+1] && a[i][j-1]-a[i][j]!=a[i-1][j-1]-a[i-1][j])){
                ans2=0;
                break;
            }
            else if((j==4) && (a[i][j]-a[i][j+1]!=a[i-1][j]-a[i-1][j+1] && a[i][j-1]-a[i][j]==a[i-1][j-1]-a[i-1][j])){
                ans2=0;
                break;
            }
            else{
                if(a[i][j]==a[i-1][j] && a[i][j]-a[i][j+1]==a[i-1][j]-a[i-1][j-1]) continue;
                if(a[i][j]==a[i-1][j] && a[i][j]-a[i][j+1]!=a[i-1][j]-a[i-1][j-1] || a[i][j]-a[i][j+1]!=a[i-1][j]-a[i-1][j-1] && a[i][j+1]==a[i-1][j+1]){
                    cnt2++;
                    if(cnt2==2)
                    ans2=10-n;
                }
            }
        }
    }
    //cout<<cnt2<<" ";
    int ans3=0;
    ans3=ans1+ans2;
    //cout<<ans1<<" "<<ans2<<" ";
    cout<<ans3;

    return 0;
}
