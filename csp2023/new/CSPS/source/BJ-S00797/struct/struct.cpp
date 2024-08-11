#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Struct
{
    ll a;
    ll b;
    string Name;
}stru[102];

int n;
int tot;
ll End;

int main()
{
    ios::sync_with_stdio(false);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    cin >> n;
    while(n--)
    {
        int type;
        cin >> type;
        int k;
        string s;
        ll e = End;
        ll maxv = 0;
        cin >> s >> k;
        for(int i = 1;i <= k;i++)
        {
            string x,y;
            cin >> x >> y;
            ll c = 0;
            int id = 0;
            if(x == "byte") c = 1;
            else if(x == "short") c = 2;
            else if(x == "int") c = 4;
            else if(x == "long") c = 8;
            else
            {
                for(int i = 1;i <= tot;i++)
                    if(x == stru[i].Name)
                        c = stru[i].b,id = i;
            }
            maxv = max(maxv,c);
            End += (id == 0 ? c : stru[id].a);
            if(End % c != 0)
                End += (c - End % c);
        }
        if(End % maxv != 0)
            End += (maxv - End % maxv);
        ll Big = End - e;
        stru[++tot] = {Big,maxv,s};
        cout << Big << " " << maxv << endl;
    }

    return 0;
}