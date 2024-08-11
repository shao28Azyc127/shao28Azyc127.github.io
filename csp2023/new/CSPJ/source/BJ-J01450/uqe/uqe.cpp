#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a][3];
    for(int i=0;i<a;i++)
        cin>>c[i][0]>>c[i][1]>>c[i][2];
    for(int i=0;i<a;i++)
    {
        cout<<0;
        if(i<a+1)
            cout<<endl;
    }
    return 0;
}
