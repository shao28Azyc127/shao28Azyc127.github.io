#include<bits/stdc++.h>
using namespace std;
string s1,s2,ss;
int op,n,k,dq;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>op>>s1>>k;
        for(int i=1;i<=k;i++)
        {
            getline(cin,s2);
            cin>>ss;
            if(s2[0]=='b')
                dq=max(1,dq);
            if(s2[0]=='s')
                dq=max(2,dq);
            if(s2[0]=='i')
                dq=max(4,dq);
            if(s2[0]=='l')
                dq=max(8,dq);
        }
        cout<<k*dq<<" "<<dq<<endl;
    }
    return 0;
}