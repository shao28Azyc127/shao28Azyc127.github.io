#include<bits/stdc++.h>
using namespace std;

struct xishu
{
    double a,b,c;
}p[1005];

int x;
double panduan(double x,double y,double z)
{
    return (y * y - 4 * x * z);

}

int m,t;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","r",stdout);
    cin >> m >> t;
    for(int i = 1; i <= m; i ++) cin >> p[i].a >> p[i].b >> p[i].c;
    for(int i = 1; i <= m; i ++)
    {
       if(panduan(p[i].a,p[i].b,p[i].c) < 0) cout << "NO"<< endl;
       else
       {
           cout << (-p[i].b + sqrt(panduan(p[i].a,p[i].b,p[i].c)))/ 2 * p[i].a <<" " << (-p[i].b - sqrt(panduan(p[i].a,p[i].b,p[i].c))) / 2 * p[i].a << endl;
       }
    }

    return 0;
}