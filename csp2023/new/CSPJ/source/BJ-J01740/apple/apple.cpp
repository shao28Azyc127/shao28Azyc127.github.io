#include<bits/stdc++.h>
using namespace std;
const int NN=1e7;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int s,ans=0,m=n;
    int b,ans2=0;
    while(m!=0){
        ans++;
        if(m%3!=0){
            s=m/3+1;
        }else{
            s=m/3;

        }
        b=s*3-2;
        if(b==m&&ans2==0){
            ans2=ans;
        }
        m=m-s;


    }
    cout<<ans<<" "<<ans2;
    return 0;
}
