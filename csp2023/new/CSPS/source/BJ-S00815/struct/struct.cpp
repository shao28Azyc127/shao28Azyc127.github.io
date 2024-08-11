#include <bits/stdc++.h>

using namespace std;
const int N = 1e8+5;
int n,ans,maxn;
string s;int k;
string name[102],by[102];
int nc[102];
string addr[N];
//string addr2[N];
int taill = 0;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    fill(addr,addr+1+n,"CCC");
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            cin >> s >> k;
            for(int i = 1;i<=k;i++)
            {
                cin >> name[i] >> by[i];
                if(name[i] == "byte") ans+=4,maxn = 4;
                if(name[i] == "short") ans+=4,maxn = 4;
                if(name[i] == "int") ans+=4,maxn = 4;
                if(name[i] == "long") ans+=8,maxn = 8;
            }
            cout << ans << " "  << maxn << endl;
        }
        if(op == 2)
        {
            string q,p;
            cin >> q >> p;
            cout << taill << endl;
            if(q == "byte") {addr[taill] = p;taill+=4;}
            else if(q == "short") {addr[taill] = addr[taill+1] = p;taill+=4;}
            else if(q == "int") {addr[taill] = addr[taill+1] = addr[taill+2] = addr[taill+3] = p;taill+=4;}
            else if(q == "long") {addr[taill] = addr[taill+1] = addr[taill+2] = addr[taill+3]  = addr[taill+4] = addr[taill+5] = addr[taill+6] = addr[taill+7]= p;taill+=8;}
            else
            {
                for(int i = 1;i<=k;i++)
                {
                    if(name[i] == "byte") {addr[taill] = p+"."+by[i];taill+=4;}
                    else if(name[i] == "short") {addr[taill] = addr[taill+1] = p+"."+by[i];taill+=4;}
                    else if(name[i] == "int") {addr[taill] = addr[taill+1] = addr[taill+2] = addr[taill+3] = p+"."+by[i];taill+=4;}
                    else if(name[i] == "long") {addr[taill] = addr[taill+1] = addr[taill+2] = addr[taill+3]  = addr[taill+4] = addr[taill+5] = addr[taill+6] = addr[taill+7]= p+"."+by[i];taill+=8;}
                }

            }
        }
        if(op == 3)
        {
            string q;
            cin >> q;
            for(int i = 0;i<taill;i++)
            {
                if(addr[i] == q) cout << i << endl;
            }
        }
        if(op == 4)
        {
            int i;
            cin >> i;
            if(addr[i]!="CCC") cout << addr[i] << endl;
            else cout << "ERR" << endl;
        }
    }
    return 0;
}
