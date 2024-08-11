#include <iostream>
#include <cstdio>

using namespace std;
int main()

    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)
            printf("NO");
        else
        {
            if(b*b-4*a*c=0)
            {
                cout<<-1*b<<"/"<<2*a<<"+"<<"sqrt("<<b*b-4*a*c<<")/"<<2*a;
            }
            else
            cout<<-1*b<<"/"<<2*a<<"+"<<"sqrt("<<b*b-4*a*c<<")/"<<2*a<<" "<<-1*b<<"/"<<2*a<<"-"<<"sqrt("<<b*b-4*a*c<<")/"<<2*a;
                
        }
        
    }
    return 0;
}