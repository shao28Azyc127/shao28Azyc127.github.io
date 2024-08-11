#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int ans=1,s,n1=n;
    while(n1){
        int sum=1;
        for(int i=1;i<=n;i++){
            if(a[i]==0)continue;
            if(sum==1){
                if(i==n)s=ans;
                a[i]=0;
                sum=3;
                n1--;
            }
            else sum--;
        }
        ans++;
    }
    cout<<ans-1<<" "<<s<<endl;
    return 0;
}