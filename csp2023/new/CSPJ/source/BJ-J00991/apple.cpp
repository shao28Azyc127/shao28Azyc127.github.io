#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
bool a[10000005];
int cnt=3,cnt2=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n<1e4){
    int i;
    for(i=1;;i++){
        for(int j=1;j<=n;j++){
            //cout<<cnt<<" ";
            if(a[j]==1)
                continue;
            else if(a[j]==0&&cnt==3){
                a[j]=1;
                //cout<<"p"<<" ";
                cnt2++;
                cnt=1;
                if(j==n){
                    ans2=i;
                    //cout<<"f"<<" ";
                }
                continue;
            }
            cnt++;
        }
        //cout<<endl;
        cnt=3;
        if(cnt2==n)
            break;
    }
    cout<<i<<" "<<ans2;
    }
    else{
    int t=n;
    int i;
    for(i=1;;i++){
        if(t%3==0){
            t-=t/3;
        }
        else{
            t-=(t/3+1);
        }
        if(t<=0)
            break;
    }
    cout<<i<<" "<<1;
    }
    return 0;
}
