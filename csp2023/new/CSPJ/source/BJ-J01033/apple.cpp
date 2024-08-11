#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int ans1=0,ans2=0,n;
    cin>>n;
    while(n>0){
        ans1++;
        int c=n%3;
        if(c==0) c=3;
        n-=((n-c)/3)+1;
        if(ans2==0 && c==1) ans2=ans1;
    }
    cout<<ans1<<' '<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
