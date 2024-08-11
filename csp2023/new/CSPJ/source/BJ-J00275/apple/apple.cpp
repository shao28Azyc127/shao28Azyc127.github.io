#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool A[1000001];
    long long n,k=0,ans=0,q=1,a;
    cin>>n;
    for(long long i=1;i<=n;i++){
        A[i]=1;
    }
    while(k!=n){
        ans++;
        k++;
        while(!A[q]){
            q++;
        }
        A[q]=0;
        if(q==n){
            a=ans;
        }
        long long p=q+1;
        while(1){
            long long t=0;
            while(t<3){
                if(A[p]){
                    t++;
                }
                p++;
                if(p>n+1){
                    break;
                }
            }
            p--;
            if(p<=n){
                A[p]=0;
                if(p==n){
                    a=ans;
                }
                k++;
            }else{
                break;
            }
        }
    }
    cout<<ans<<' '<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
