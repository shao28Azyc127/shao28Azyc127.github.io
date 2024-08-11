#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans=0;
    int u=0;
    bool f=false;
    while(n){
        ans++;
        if((n%3==1)&&(!f)){
            u=ans;
            f=true;
        }
        n-=((n+2)/3);
    }
    cout<<ans<<" "<<u<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
zyctc AK IOI
F1amir3 AK IOI
Ranger_HoFr AK IOI
*/
