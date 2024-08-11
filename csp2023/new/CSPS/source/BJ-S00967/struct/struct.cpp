#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int k;
            cin>>s;
            cin>>k;
            cout<<k*8<<" "<<0;
        }
        if(op==4) cout<<"ERR"<<endl;
    }
    return 0;
}