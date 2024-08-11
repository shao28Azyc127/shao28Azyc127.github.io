#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int M=1e3*1e3+50;
int t,m,a,b,c;
bool pf[M];
string ans;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >>t>>m;
    for(int i=1;i<=m;i++)
    {
        if(i*i>=M) break;
        pf[i*i]=1;
    }
    while(t--)
    {
        cin >>a>>b>>c;
        double delta=(b*b)-(4*a*c);
        if(delta <0){
            cout <<"NO\n";
            continue;
        }
        
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
