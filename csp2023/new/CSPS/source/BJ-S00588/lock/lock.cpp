#include<iostream>
#include<cstdio>
#include<cstdint>
using namespace std;

#define N 9

int n;

int a[N];

int x[100000];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            a[i]*=10;
            int tmp;
            cin>>tmp;
            a[i]+=tmp;
        }
        x[i]=INT32_MAX;
    }

    // if(n==1){
    //     cout<<81<<endl;
    // }

    for(int i=0;i<n;i++){
        for(int j=1;j<100000;j*=10){
            for(int k=1;k<=9;k++){
                int t=(a[i]/j)%10;
                t=(t+k)%10;
                int y=a[i]/10/j*10*j+t*j+a[i]%j;
                if(x[y]!=INT32_MAX)x[y]++;
                // cout<<y<<endl;

                if(j!=10000){
                    int l=j*10;
                    t=(y/l)%10;
                    t=(t+k)%10;
                    int z=y/10/l*10*l+t*l+y%l;
                    if(x[z]!=INT32_MAX)x[z]++;
                    // cout<<z<<endl;
                }
            }
        }
    }

    int ans=0;
    for(int i=0;i<100000;i++){
        if(x[i]==n)ans++;
    }
    cout<<ans<<endl;


    return 0;
}