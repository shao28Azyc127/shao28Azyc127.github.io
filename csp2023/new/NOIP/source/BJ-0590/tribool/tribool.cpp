#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+1;
char x[N];
struct opr{
char o;int a,b;
}op[N];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin >>c>>t;
    while(t--)
    {
        int n,m;
        cin >>n>>m;
        int k=0;
        for(int i=1;i<=m;i++){x[i]='\0';}
        for(int i=1;i<=m;i++)
        {

            cin >> op[i].o;
            if(op[i].o=='+'||op[i].o=='-')
            {
                cin >>op[i].a>>op[i].b;
                k++;
            }
            else if(op[i].o>='F'&&op[i].o<'X')
            {
                cin >>op[i].a;
                x[op[i].a]=op[i].o;
            }
        }
        int ans=0;
       // if(k){}
        for(int i=1;i<=n;i++){
            if(x[i]=='U'){ans++;}
        }
        cout <<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
