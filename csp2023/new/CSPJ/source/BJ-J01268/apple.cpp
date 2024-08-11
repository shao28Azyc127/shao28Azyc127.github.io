#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,v=0,num=0,k=0;
    cin>>n;
    long long a[n];
    bool flag=true;
    while(flag=false)
    {
        long long i=1;
        for(long long c=0;c<n;c++)
        {
            if(c*3+i<n)
                a[c*3+i]=0;
        }
        i+=3;
        v++;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                k++;
        }
        if(k==8)
            flag==false;
    }
    cout<<v<<" "<<(num+v)%3;
    return 0;
}
