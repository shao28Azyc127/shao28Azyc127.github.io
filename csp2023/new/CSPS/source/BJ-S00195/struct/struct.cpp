#include<bits/stdc++.h>
using namespace std;
int op;
int T;
string s1;
string s2;
string s3;
string s4;
map<string,int> mp;
string add[100005];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    s1 = "byte";
    s2 = "short";
    s3 = "int";
    s4 = "long";
    cin >> T;
    int now = 0;;
    for(int i = 1;i <= T;i++)
    {
        cin >> op;
        if(op == 2)
        {
            string t;
            string n;
            cin >> t >> n;
            if(t == s1)
            {
                mp[n] = now;
                now += 1;
                add[now - 1] = n;

            }
            if(t == s2)
            {
                mp[n] = now;
                add[now] = n;
                add[now + 1] = n;
                now += 2;


            }
            if(t == s3)
            {
                mp[n] = now;
                for(int i = now;i <= now + 3;i++)
                {
                    add[i] = n;
                }
                now += 4;
            }
            if(t == s4)
            {

                mp[n] = now;
                for(int i = now;i <= now + 7;i++)
                {
                    add[i] = n;

                }
                now += 8;
            }

        }
        if(op == 3)
        {
            string s;
            cin >> s;
            cout << mp[s] << endl;

        }
        if(op == 4)
        {

            int addr;
            cin >> addr;
            cout << add[addr] << endl;
        }

    }
    return 0;
}
