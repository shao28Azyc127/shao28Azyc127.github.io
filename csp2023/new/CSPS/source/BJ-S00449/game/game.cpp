#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int len;
    string a;
    cin >> len >> a;
    long long ans=0;
    for(int i=0;i<len-1;i++){
        while(a[i]=='0') i++;
        int k=i+1;
        while(a[k]=='0') k++;
        if(a[i]==a[k]){
            a[i]='0';
            a[i+1]='0';
            ans++;
            i=-1;
        }

    }
    cout << ans+1;
    return 0;
}
