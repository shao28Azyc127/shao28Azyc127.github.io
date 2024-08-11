#include<bits/stdc++.h>
using namespace std;
int a[0x3f];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,da=1,cnt=0;
    int ans=0
    bool fi=false;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(fi==true){
        cnt=0;
        for(int i=da;i<=n;i++){
            if(cnt%3==0){
                if(a[i]==n){
                    ans=da;
                }
                a[i]=0;
            }
            if(a[i]!=0) cnt++;
        }
        if(cnt==0){
            break;
        }
        da++;
    }
    cout<<da<<" "<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}