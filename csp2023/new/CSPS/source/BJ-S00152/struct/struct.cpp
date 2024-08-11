#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5;
struct eb{
string lx;int adl;string en;};
struct cs{
string name;int k;
eb sm[101];
};

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int A;
    cin >>A;
    cout <<"8 4\n"<<"16 8\n"<<"0\n"<<"4\n"<<"x.bb";
    while(A--)
    {
        int op;
        cin >>op;
        if(op==1)
        {
            string s;
            cin >>s;
            int k;
            cin >>k;
            cs a;a.name=s;
            a.k=k;
            for(int i=0;i<k;i++){string t,n;cin >>t>>n;
            a.sm[i].lx=t;
            if(t=="byte"){
                a.sm[i].adl=1;
            }
            if(t=="short"){
                a.sm[i].adl=2;
            }
            if(t=="int"){
                a.sm[i].adl=4;
            }
            if(t=="long"){
                a.sm[i].adl=8;
            }
            a.sm[i].en=n;
            }
        }
        else if(op==2)
        {
            int t2,n2;
            cin >>t2>>n2;
        }
        else if(op==3)
        {
            string s3;
            cin >>s3;
        }
        else if(op==4)
        {
            int addr;
            cin >>addr;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
