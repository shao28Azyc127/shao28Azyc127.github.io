#include<bits/stdc++.h>
using namespace std;
const int M=1e9+10;
int n,cnt=0,ans,k=1e9;
int a[M];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    while(k>0){
        k=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                k++;
                if(k%3==1)
                {
                    if(i==n)ans=cnt+1;
                    a[i]=0;
                }
            }
        }
        cnt++;
    }
    cout<<cnt<<" "<<ans;
}
