#include<bits/stdc++.h>
using namespace std;
long long a[1000050]={};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    if(n%2==1&&n%3==1) cnt=1;

    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int yes=0;
        if(a[i]==0){
            a[i]=1;

            for(int j=i+1;j<=n;j++){
                if(a[j]==0){
                    yes++;
                }
                if(yes==3){
                    a[j]=1;
                    yes=0;
                }
                //cout<<yes;
            }
            //cout<<endl;
            ans++;
        }


        //for(int j=1;j<=n;j++){
        //    cout<<a[j]<<" ";
        //}
        //cout<<endl;
        for(int j=1;j<=n;j++){
            if(a[j]==1){
                sum++;
            }
        }
        if(sum==n) break;
        else sum=0;
    }



    cout<<ans<<" ";
    if(cnt==1) cout<<1;
    else cout<<ans;

    return 0;
}
