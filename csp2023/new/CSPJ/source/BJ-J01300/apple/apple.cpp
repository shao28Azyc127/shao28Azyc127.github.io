#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
int n,ans1=0,ans2=0;
int a[maxn];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i] = i;
    int r = n;
    while(r){
        for(int i=1;i<=r;i+=3){
            a[i-i/3] = a[i+1];
            a[i-i/3+1] = a[i+2];
        }
        if(r%3!=0 && r>3) r--;
        if(r>=3) r = r-r/3;
        else r--;
        ans1++;
        if(a[r]!=n && !ans2) ans2 = ans1;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
