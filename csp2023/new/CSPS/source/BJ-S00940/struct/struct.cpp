#include<bits/stdc++.h>
using namespace std;
string t[105];
string n[105];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,k;
    string s;
    int op;
    cin>>n;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            int maxll=0;
            for(int i=1;i<=k;i++)
            {
                cin>>t[i];
                cin>>n[i];
            }
            for(int i=1;i<=k;i++)
            {
                if(t[i]=='byte')
                {
                    maxll=max(maxll,1);
                }
                else if(t[i]=='short')
                {
                    maxll=max(maxll,2);
                }
                else if(t[i]=='int')
                {
                    maxll=max(maxll,4);
                }
                else if(t[i]=='long')
                {
                    maxll=max(maxll,8);
                }
            }
            int longl=0;
            for(int i=1;i<=k;i++)
            {
                if(t[i]=='byte')
                {
                    longl+=max(1,maxll);
                }
                else if(t[i]=='short')
                {
                    longl+=max(2,maxll);
                }
                else if(t[i]=='int')
                {
                    longl+=max(4,maxll);
                }
                else if(t[i]=='long')
                {
                    longl+=max(8,maxll);
                }
            }
            cout<<longl<<" "<<maxll<<endl;
        }
    }
    return 0;
}
