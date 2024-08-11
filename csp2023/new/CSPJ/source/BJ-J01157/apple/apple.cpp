#include<bits/stdc++.h>
using namespace std;
int n,x,tot;
int a[100000005];


int main(){
freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++){
        x=i;
        tot=3;
        for(int j=1;j<=n;j++){
            if(a[j]==0&&tot<3) {
                    tot++;
            }
            if(a[j]==0&&tot==3){
                a[j]=x;
                tot=0;
            }
        }

    }

    x=0;
    for(int i=1;i<=n;i++) x=max(x,a[i]);
    cout<<x<<" "<<a[n];
   
    return 0;
}
