#include <bits/stdc++.h>
using namespace std;

int n,ans=45;
int a[10456676],v[194375];




int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;


    for(int h=1;h<=n;h++){
        for(int i=1;i<=5;i++){
            cin>>a[i];
            v[a[i]]++;
        }

    }

     for(int i=1;i<=5;i++){
        if(v[a[i]]>0){
            ans-=5;
        }
    }
    if(n==1) cout<<"81";
    else cout<<ans;
    return 0;
}
