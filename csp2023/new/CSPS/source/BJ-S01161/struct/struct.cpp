#include<bits/stdc++.h>
using namespace std;
string l[1100];
int m[1100];
int i;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    long long a,b,c,d,e,f,g,h;
    string s,t;
    cin>>a;
    while (a--)
    {
        cin>>b;
        if (b==1)
        {
            cin>>s>>c;
            e=0;
            f=0;
            for (d=1;d<=c;d++)
            {
                cin>>t>>l[d];
                if (t=="byte") m[d]=1;
                else if (t=="short") m[d]=2;
                else if (t=="int") m[d]=4;
                else m[d]=8;
                if (m[d]>e) e=m[d];
                f+=m[d];
            }
            cout<<e*c<<" "<<e<<endl;;
        }
        else if (b==2)
        {
            cin>>s>>t;
            cout<<i<<endl;
            if (s=="byte") i++;
            else if (s=="short") i+=2;
            else if (s=="int") i+=4;
            else i+=8;
        }
        else cout<<"ERR"<<endl;
    }
    return 0;
}
