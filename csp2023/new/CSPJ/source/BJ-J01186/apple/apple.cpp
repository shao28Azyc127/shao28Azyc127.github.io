#include <bits/stdc++.h>
using namespace std;
long long n,cnt,ans=0,l;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=3;
    long long m;
    m=n;
    while(m>3){
        l=m/3+1;
        m-=l;
        cnt++;
    }
    l=0;
    m=n;
    for(int i=1;i<=cnt&&m>3;i++){
        if(m%3==1)
        {
            ans=i;
            break;
        }
        int tmp=m/3;
        if(tmp*3!=m)    l=tmp+1;
        else l=tmp;
        m-=l;
    }
    if(ans==0)  ans=cnt;
    cout<<cnt<<' '<<ans;
    return 0;
}
