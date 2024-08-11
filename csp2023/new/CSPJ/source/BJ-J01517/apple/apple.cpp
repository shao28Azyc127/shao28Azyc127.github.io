#include<bits/stdc++.h>

using namespace std;

int n;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans=0,day=0;
    int m=n;
    while(m){
        ans++;
        if(day==0 && (m-1)%3==0) day=ans;
        m-=1+(m-1)/3;
    }
    cout<<ans<<" "<<day;
    fclose(stdin);
    fclose(stdout);
    return 0;
}