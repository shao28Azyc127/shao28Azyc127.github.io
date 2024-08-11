#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen ("uqe.in","r",stdin);
freopen ("uqe.out","w",stdout);
int T,M;
cin>>T>>M;
if (M=0)
{
            cout<<0<<endl;
}
for (int i=0;i<T;i++)
        {
            int a,b,c,x;
            cin>>a>>b>>c;
            if(b*b-4*a*c<0)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                if((0-b+sqrt(b*b-4*a*c))/2>(0-b-sqrt(b*b-4*a*c))/2){
                   x=(0-b+sqrt(b*b-4*a*c))/2;
                }
                else
                {
                    x=(0-b-sqrt(b*b-4*a*c))/2;
                }
                cout<<x<<endl;
            }
        }
return 0;
        }
