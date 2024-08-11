#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int m;
    bool x=false;
    int z;
    int sum=0;
    cin >> n;
    m=n;
    while (m>0)
    {
        if (m%3==1 && x==false)
        {
            x=true;
            z=sum+1;
        }
        if (m%3==0) m=m-m/3;
        else
        {
            m=m-m/3-1;
            //cout << m << endl;
        }
        //cout << "&&&" << endl;
        sum++;
    }
    cout << sum << " " << z << endl;

    return 0;
}
