#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int p10[15];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    p10[0]=1;
    for(int i=1;i<10;i++){
        p10[i]=p10[i-1]*10;
    }
    cin>>n;
    int m=n;
    while(n--){
        int k=0;
        for(int j=4;j>=0;j--){
            int gtr;
            cin>>gtr;
            k+=gtr*p10[j];
        }
        //cout<<"k = "<<k<<endl;
        for(int i=0;i<5;i++){
            int wei=k/p10[i]%10;
            int sb=k-wei*p10[i];
            for(int j=1;j<10;j++){
                a[sb+((wei+j)%10)*p10[i]]++;
                //cout<<"A:   "<<sb+((wei+j)%10)*p10[i]<<endl;
            }
        }
        for(int i=0;i<4;i++){
            int wei1=k/p10[i]%10;
            int wei2=k/p10[i+1]%10;
            int sb=k-wei1*p10[i]-wei2*p10[i+1];
            for(int j=1;j<10;j++){
                a[sb+((wei1+j)%10)*p10[i]+((wei2+j)%10)*p10[i+1]]++;
                //cout<<"B:   "<<sb+((wei1+j)%10)*p10[i]+((wei2+j)%10)*p10[i+1]<<endl;
            }
        }
    }
    int ans=0;
    for(int i=0;i<100005;i++){
        //cout<<"a[ "<<i<<" ] = "<<a[i]<<endl;
        if(a[i]==m){
            //cout<<"i = "<<i<<endl;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}