#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
bool a[1000000050];
bool flag=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << i << ans;
        }
        for(int j=1;j<=n;i++){
            if(a[j]==0&&((j-i)%3==0||j-i==1)){
                a[j]=1;
                if(a[j]==n){
                    ans=n;
                }
            }
        }
    }
    return 0;
}
