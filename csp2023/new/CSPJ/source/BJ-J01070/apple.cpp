#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int cnt=2;
        //cout<<"i="<<i<<endl;
        for(int j=1;j<=n;j++){
            //cout<<"j="<<j<<endl;
            //cout<<"cnt="<<cnt<<endl;
            if(a[j]==0&&cnt!=2){
                cnt++;
                continue;
            }
            else if(a[j]==0&&cnt==2){
                cnt=0;
                a[j]=i;
                //cout<<"a[j]="<<a[j]<<endl;
                continue;
            } else if(a!=0)continue;
        }
    }
    long long maxn=0;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
    cout<<maxn<<" "<<a[n];
    //for(int i=1;i<=n;i++)cout<<a[i]<<endl;
    return 0;
}
