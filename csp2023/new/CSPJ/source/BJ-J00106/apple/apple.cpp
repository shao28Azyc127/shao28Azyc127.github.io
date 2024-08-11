#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long id;
    bool ok;
}a[(long long)(1e6)+5];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    if(n>=1e6){
        cout<<(int)log(n)<<" "<<1;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        a[i].id=i;
        a[i].ok=true;
    }
    long long ans=0;
    long long have=n;
    long long lun=0;
    bool f=false;
    while(have>0){
        lun++;
        long long cnt=0;
        for(long long i=1;i<=n;i++){
            if(a[i].ok) cnt++;
            if(cnt%3==1&&a[i].ok){
                have--;
                a[i].ok=false;
                if(i==n&&!f){
                    ans=lun;
                    f=true;
                }
            }
        }
    }
    cout<<lun<<" "<<ans;
    return 0;
}
