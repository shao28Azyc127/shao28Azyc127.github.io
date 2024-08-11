#include <iostream>

using namespace std;
int n,d,a[100001],v[100001],sum=0,now=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sum+=a[1]*((v[1]+d-1)/d);
    now=sum/a[1]*d-v[1];
    //cout<<a[1]<<" "<<v[1]+d-1<<" "<<(v[1]+d-1)/d<<" "<<sum<<endl;
    for(int i=2;i<n;i++)
    {
        int x,y;
        int ne=v[i]-now;//从第 i 个站点走到第 i+1 个站点，还需要通过加油获得多少里程
        if(a[i]>a[i-1])//从前一个站点加油更便宜
        {
            sum+=(ne+d-1)/d*a[i-1];
            //cout<<1<<" "<<ne<<" "<<(ne+d-1)/d<<" "<<(ne+d-1)/d*a[i-1]<<" ";
            //1 还剩多少里程需要通过加油获得 加了多少升油 花费了多少钱
        }
        else{
            sum+=(ne+d-1)/d*a[i];
            //cout<<2<<" "<<ne<<" "<<(ne+d-1)/d<<" "<<(ne+d-1)/d*a[i]<<" ";
        }
        int m=(ne+d-1)/d;
        now=m*d-v[i];//还有多少里程余额
        //cout<<sum<<endl;
    }
    cout<<sum;
    return 0;
}
