#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int cishu=0;
    int sn=n;
    if(n<=3)
    {
        cout<<n<<" "<<n;
        return 0;
    }
    while(sn>0)
    {
        if(sn%3==0)
        {
            sn=sn-sn/3;
        }else{
            sn=sn-sn/3-1;
        }
        cishu++;
    }
    int ci=1;
    while((n-1)%3!=0){
        n=n-(n-1)/3-1;
        ci++;
    }
    cout<<cishu<<" "<<ci;
    return 0;
}