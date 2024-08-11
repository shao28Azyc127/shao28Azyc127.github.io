#include <iostream>

using namespace std;

bool panduan(long long a[],long long m,long long s)
{
    m=0;
    for (int h=0;h<s;h++){
        if (a[h]==-1){
            m++;
        }
        if (m!=s-1){
            return false;
        }
    }
    return true;
}

int main()
{
    long long n;
    cin>>n;
    long long s=n;
    long long a[100000]={0};
    long long k=0;
    long long j=0;
    long long l=0;
    long long m=0;
    while (n!=0){
        for (long long i=0;i<n;i++){
            a[i]=i+1;
            if (i==-1){
                continue;
            }
            if (i!=-1){
               j++;
               if (j%3==1){
                    cout<<a[i]<<endl;
                    a[i]=-1;
                    if (a[i]==n){
                        l=k;
                    }
               }
            }
        }
        k++;
    }
    cout<<l<<endl;
    cout<<k;
    return 0;
}
