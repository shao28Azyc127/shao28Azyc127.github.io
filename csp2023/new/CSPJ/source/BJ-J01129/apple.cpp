#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,maxn,v[100000020];
bool a[100000020];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int b=n;
    int c=b;
    int t=0;
    if(n%3==1)
        maxn=1;
    else
    {
        while(c%3!=1)
        {
            for(int i=1;i<=c;i++)
            {
                if(i%3==1)
                    c--;
            }
            cnt++;
        }
        maxn=cnt;
    }
    cnt=0;
    b=n;
    c=b;
    for(int i=1;i<=n;i++)
            a[i]=1;
    while(b>0)
    {
        for(int i=1;i<=b;i++)
        {
            if(a[i]==0)
            {
                for(int j=i;j<=b;j++)
                    a[j]=a[j+1];
            }
        }
        for(int i=1;i<=b;i++)
        {
            if(i%3==1)
            {
                a[i]=0;
                c--;
            }
        }
        b=c;
        cnt++;
    }
    cout<<cnt<<" "<<maxn;
    return 0;
}