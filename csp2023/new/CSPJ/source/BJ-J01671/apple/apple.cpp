#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >>n;
    int z[n+1];
    for(int i=0;i<n+1;i++)
        z[i]=0;
    z[1]=1;
    z[0]=1;
    int n1=0;
    int i=1;
    while(n1<n)
    {
        int j=0;
        int j1=3;
        while(1)
        {
            if(z[i+j1]==0)
                break;
            else{
                j1++;
            }
        }
        i=i+j1;
        if(i>n)
        {
            i=i%n;
            ans1++;
        }
        z[i]=1;
        if(i==n)
            ans2=ans1;
        cout <<i <<' ';
        n1++;
    }
    return 0;
}
