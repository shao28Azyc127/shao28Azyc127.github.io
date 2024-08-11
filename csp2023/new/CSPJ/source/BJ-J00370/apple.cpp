#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+1,1);
    int ans1=1,ans2=1,i=0;
    while(i<n){
        int t=1;
        while(!a[t]){
            t++;
        }
        while(t<=n){
            if(t<=n){
                a[t]=0;i++;
            }
            int k=0;
            while(k<2 && t<=n){
                if(a[t]==1){
                    k++;
                }
                t++;
            }
            while(!a[t]){
                t++;
            }
        }
        if(a[n])
            ans1++;
        if(i<n)ans2++;
    }
    cout<<ans2<<" "<<ans1;
    return 0;
}