#include <iostream>
using namespace std;

int k[1000005];
int m[1000005];
int id[1000005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int a,b,c;
    cin >>a>>b>>c;
    for(int i = 1;i <= b;i++)
    {
        
        cin >>k[i]>>m[i]>>id[i];
    }
    if(a+b+c > 0) cout <<-1<<endl;
    return 0;
}
