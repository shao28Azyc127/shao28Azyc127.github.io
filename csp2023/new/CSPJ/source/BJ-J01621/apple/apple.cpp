#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;cin>>n;int m=n,op;
    bool a[1000005]={0};
    int i=1;
    for(;m>0;i++){
        int cnt=3;
        for(int j=0;j<n;j++){
            //printf("i=%d j=%d cnt=%d m=%d\n",i,j,cnt,m);
            //for(int k=0;k<n;k++) cout<<a[k]<<" ";cout<<endl;
            if(a[j]) continue;
            if(cnt==3){
                a[j]=1;
                cnt=0;
                m--;
                if(j==n-1)
                    op=i;
            }cnt++;
        }
    }cout<<i-1<<" "<<op;

    return 0;
}
