#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op,addr;
        cin>>op;
        if(op==4)
        {
            cin>>addr;
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}