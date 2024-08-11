#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    char a[n][2];
    for(int i=0;i<n;i++){
        cin>>a[i][0];
        a[i][1]='a';
    }
    int si=n;
    int sum=0;
    int tt=0;
    while(si>0){
        for(int i=1;i<n;i++){
                for(int j=i-1;i>=0;j--){
                    if(a[j][1]=='a'){
                        tt=j;
                        break;
                    }
                }
            if(a[i][0]==a[tt][0]&&a[i][1]=='a'){
                sum++;
                a[i][1]='b';
                a[tt][1]='b';
                si-=2;
                tt=0;
            }
        }
    }
    cout<<sum+1;
    return 0;
}
