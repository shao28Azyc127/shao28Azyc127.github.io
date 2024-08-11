#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int shijian=0;

int chazhao(int n,int num){
    int sum=2;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            if(num!=1){
                if(sum==2){
                    a[i]=num;
                    //cout<<i<<endl;
                    sum=0;
                    if(i==n){
                        shijian=num;
                    }
                }
                else sum++;
            }
            if(num==1){
                if(sum==2){
                    a[i]=0;
                    //cout<<i<<endl;
                    sum=0;
                    if(i==n){
                        shijian=num;
                    }
                }
                else sum++;
            }
        }
    }
    int k=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            //cout<<i<<endl;
            k++;
        }

    }
    if(k==n){
        cout<<num<<" "<<shijian;
        return 0;
    }
    return chazhao(n,num+1);
}

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    chazhao(n,1);


    return 0;
}