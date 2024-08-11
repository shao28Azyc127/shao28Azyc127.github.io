#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,cnt=0,a[1000000005],b,c;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    c=n;
    while(c>0){
        if(a[i]!=0){
            while(i<=n){
                if(i==n){
                    b=i;
                }
                a[i]=0;
                c--;
                i+=2;
            }
            i=1;
            continue;
        }else{
            i++;
        }
        cnt++;
    }
    cout<<cnt<<" "<<b;
    return 0;
}
