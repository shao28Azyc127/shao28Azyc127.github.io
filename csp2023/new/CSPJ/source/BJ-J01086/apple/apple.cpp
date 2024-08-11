#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int ans1=0,ans2=0,n;
    cin>>n;
    int tmp=n;
    while(tmp>0){
        ans1=ans1+1;
        tmp=tmp-(tmp+2)/3;
    }
    tmp=n;
    while(tmp>0){
        ans2++;
        if(tmp%3==1) break;
        tmp=tmp-(tmp+2)/3;
    }
    cout<<ans1<<" "<<ans2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
