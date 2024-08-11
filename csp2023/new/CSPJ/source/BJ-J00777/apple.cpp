#include<bits/stdc++.h>
using namespace std;
int main(){
    bool k[1000005];
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int t = n,ans1 = 0,ans2;
    memset(k,true,sizeof(k));
    int q = 0,p = 0;
    while(t > 0){
            q++;
        if(p == 2 && k[q]){
            k[q] = false;
            t--;
            p = 0;
            if(q == n)ans2 = ans1;
        }
        else if(p != 2 && k[q]){
            p++;
        }
        if(q == n && t != 0){
            q = 0;
            p = 0;
            ans1++;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}