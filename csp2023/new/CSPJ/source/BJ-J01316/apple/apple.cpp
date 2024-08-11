#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct node{
    int i;
    bool o;
}s[100000001];
int main()
{
    int i,j,k,n,ans=0,t,num;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    //for(n=1;n<=100;n++){
    ans=0;
    num=n;
    for(i=1;i<=n;i++){
        s[i].i=i;
        s[i].o=1;
    }
    while(num){
        ans++;
        k=1;
        for(i=1;i<=n;i++){
            if(!s[i].o){
                continue;
            }
            if(k%3==1){
                num--;
                s[i].o=0;
                if(s[i].i==n){
                    t=ans;
                }
            }
            k++;

        }
    }

    cout<<ans<<" "<<t<<endl;
    //}
    return 0;
}
