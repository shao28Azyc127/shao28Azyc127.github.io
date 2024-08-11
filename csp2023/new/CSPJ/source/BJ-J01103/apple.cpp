#include <iostream>
#include <cmath>
using namespace std;
int n,days,ans,f;
int qwq(int num)
{
    if(num%3==1)
        return f+1;
    else if(num%3==2)
        return days;
    else
    {
        f++;
        return qwq(num-ceil(num/3));
    }
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    double cnt=n;
    while(cnt!=0)
    {
        int tk=ceil(cnt/3);
        cnt-=tk;
        days++;
        if(cnt==0)
            break;
    }
    ans=qwq(n);
    cout<<days<<" "<<ans<<endl;
    return 0;
}
