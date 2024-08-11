#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,s=0,sum=0,z=0,x=0;
    cin>>n;
    long long a[n]={};
    for(long long i=1;i<=n;i++){
        a[i]=i;
    }
    while(x=n){
        for(long long i=1;i<=n;i+=3){
            if(a[i]!=0){
                if(a[n]==a[i]){
                    z=sum;
                }
                a[i]=0;
            }else{
                i+=1;
                x+=1;
            }
            sum+=1;
        }
    }
    cout<<sum-1<<" "<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
