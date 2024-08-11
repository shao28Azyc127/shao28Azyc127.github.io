# include <bits/stdc++.h>
# define ll long long
using namespace std;
int n;
ll ans;
int code[9][6];

ll an;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);

    cin>>n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=5; j++)
        {
            cin>>code[i][j];
        }
    }

    if (n == 1)
    {
        ans = 5*9 + 4*9;
        cout<<ans<<'\n';
        return 0;
    }
    if (n==2)
    {

        ll cnt=0;
        vector <int> w;
        for (int j=1; j<=5; j++)
        {
            if (code[1][j]!=code[2][j])
            {
                w.push_back(j);
                cnt +=1;
            }
        }
        //if (code[1][w[1]-code[])
        if (cnt>3)
        {
            cout<<0<<endl;
            return 0;
        }
        if (cnt==1)
        {
            if (w[0]==1 || w[0]==5) cout<<10<<endl;
            else cout<<12<<endl;
            return 0;
        }
        if (cnt==2)
        {
            if(code[1][w[1]]-code[1][w[0]] == code[2][w[1]]-code[2][w[0]])
            {
                cout<<8<<endl;
                return 0;
            }
            if (w[0]+1!=w[1])
            {
                cout<<0<<endl;
            }
            else cout<<4<<endl;
        }
        return 0;
    }
    set <int> w;
    vector <int> r;
    for (int j=1; j<=5; j++)
    {
        w.clear();
        for (int i=1; i<=n; i++)
        {
            if (code[1][j] != code[i][j])
            {
                r.push_back(j);
                break;
            }
            //w.insert(code[i][j]);
        }
        /*
        if (w.size()>=1)
        {
            r.push_back(j);
        }*/

    }
    if (r.size()>=3)
    {
        cout<<0<<endl;
        return 0;
    }
    if (r.size()==1)
    {
        cout<<10-n<<endl;
    }



    return 0;
}
