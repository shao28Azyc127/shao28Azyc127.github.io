#include <bits/stdc++.h>
#define N 2000002
using namespace std;
long long n,cnt,p,ans;
//unordered_map<int,bool> a;
bool a[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(cnt<n){
        long long tmp=0;
        for(int i=1;i<=n;i++){
            if(a[i])  continue;
            tmp++;
            if(tmp%3==1){
                a[i]=1;
                cnt++;
                if(i==n)  ans=p+1;
            }
        }
        p++;
    }
    cout<<p<<" "<<ans;
    return 0;
}
//t1 baoli