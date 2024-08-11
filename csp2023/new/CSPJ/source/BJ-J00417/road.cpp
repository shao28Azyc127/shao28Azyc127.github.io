#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v;
vector<int> a;
int vmin=100001;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int vsum=0;
    for(int i=1;i<=n-1;i++)
    {
        int b;
        cin>>b;
        v.push_back(b);
        vsum+=b;
        vmin=min(vmin,b);
    }
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }

    if(vmin==v[0])
    {
        cout<<vsum/a[0]<<endl;
        return 0;
    }
    return 0;
}
