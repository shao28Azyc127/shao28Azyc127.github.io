#include<bits/stdc++.h>
using namespace std;
int n,sum,ans,m;
const int M=1e8+3;
int a[M];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(m!=n){
        sum++;
        for(int i=1;i<=n;){
            if(a[i]==0){
                a[i]=1;
                m++;
                if(i==n) ans=sum;
                int cnt=0;
                for(int j=i+1;j<=n,cnt<3;j++){
                    i=j;
                    if(a[j]==0){
                        cnt++;
                    }
                }
            }
            else i++;
        }
    }
    cout<<sum<<" "<<ans;
    return 0;
}
