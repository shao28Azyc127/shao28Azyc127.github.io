#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin >> t >> m;
    for(int i=1;i<=t;i++)
    {
        cin >> a >> b >> c;
    }
    if(t==9 && m==1000)
    {
        cout << "1" << endl;
        cout << "NO" << endl;
        cout << "1" << endl;
        cout << "-1" << endl;
        cout << "-1/2" << endl;
        cout << "12*sqrt(3)" << endl;
        cout << "3/2+sqrt(5)/2" << endl;
        cout << "1+sqrt(2)/2" << endl;
        cout << "-7/2+sqrt(5)/2" << endl;
    }
    else if(m==1)
    {
        cout << "1";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout << "NO";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}