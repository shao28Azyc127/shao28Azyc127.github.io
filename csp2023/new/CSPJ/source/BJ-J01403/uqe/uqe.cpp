#include<bits/stdc++.h>
using namespace std;
int T,M;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>T>>M;
    while(T--)
    {
        int a,b,c;
        int triangle=b*b - 4*c*c;
        if(triangle < 0)
        {
            cout<<"NO"<<endl;
            break;
        }
        double x_1=(-b+sqrt(triangle)) / (2*a);
        double x_2=(-b-sqrt(triangle)) / (2*a);
        int x=max(x_1,x_2);
        cout<<x<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
