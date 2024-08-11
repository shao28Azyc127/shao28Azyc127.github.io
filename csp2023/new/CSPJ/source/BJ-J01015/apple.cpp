#include<bits/stdc++.h>
using namespace std;
int n,len,cnt=0,ans,b[100000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    len=n;
    for(int i=1;i<=n;i++){
        b[i]=i;
    }
    while(len!=0){
        for(int i=1;i<=len;i+=2){
            if(b[i]==n){
                ans=cnt+1;
            }
            for(int j=i;j<=len;j++){
                b[j]=b[j+1];
            }
            len--;
        }
        cnt++;
    }
    cout << cnt << ' ' << ans;
    return 0;
}
