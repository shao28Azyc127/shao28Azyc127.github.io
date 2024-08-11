#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    //cout << "Hello world!" << endl;
    int a,b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)cout<<0<<endl;
    return 0;
}

/*
#include <bits/stdc++.h>
#define int long long

using namespace std;

int x_v[100001],x_vt[100001];
string x_gx[100001];

signed main()
{
    freopen("tribool.in","r",stdin);
    //freopen("dict.out","w",stdout);
    //cout << "Hello world!" << endl;
    int c,t;
    cin >> c >> t;
    for (int i = 1; i <= t; i++){
        int n,m;
        cin >> n >> m;
        for (int k = 1; k <= n; k++){
            char op;
            scanf("%s",&op);
            //cout << op << endl;
            if (op == '-'){
                int t1,t2;
                scanf("%lld%lld",&t1,&t2);
                x_gx[t1] = "-"+to_string(t2);
            } else if (op == '+'){
                int t1,t2;
                scanf("%lld%lld",&t1,&t2);
                x_gx[t1] = to_string(t2);
            } else {
                int t1;
                scanf("%lld",&t1);
                if (op == 'T') x_v[t1] = 1;
                else if (op == 'F') x_v[t1] = 2;
                else x_v[t1] = 3;
            }
        }

    }
    return 0;
}
*/