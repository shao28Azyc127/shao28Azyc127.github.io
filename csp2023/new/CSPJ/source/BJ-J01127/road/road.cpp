#include<iostream>
#include<cstdio>
using namespace std;
long long km=0;
long long prime(long long a,long long b)
{
    bool flag=true;
    long long i=1;
    while(flag)
    {
        a*=i;
        if(a+km>=b)
        {
            return i;
            flag=false;
            break;
        }
        else
        {
            i++;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    long long a[10024],b[10024];
    for(long long i=1;i<n;i++)//juli
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)//qian
    {
        cin>>b[i];
    }

    long long mon=0,lessn=b[1];
    mon+=(prime(d,a[1]))*lessn;
    km+=(prime(d,a[1]))*d-a[1];
    for(long long i=2;i<n;i++)
    {

        if(lessn<b[i])//a<b,qian++;
        {
            mon+=(prime(d,a[2]))*lessn;
            km+=(prime(d,a[2]))*d-a[i];
        }
        else if(lessn>b[i])
        {
            lessn=b[i];
            mon+=(prime(d,a[2]))*lessn;
            km+=(prime(d,a[2]))*d-a[i];
        }
    }
    cout<<mon<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
