#include<iostream>
#include<set>
#include<vector>
#include<unordered_set>
using namespace std;
int n;
unordered_set<string> s;
int Plus(int a, int b)
{
    if (a + b > 9)
        return (a + b) % 9;
    else
        return a + b;
}
string change(string a, int wei, int value, bool type)
{
    string ans = "";
    if (!type) // single
    {
        for (unsigned i = 0;i<5;i++)
        {
            if (wei == i) ans += char((int(a[i] - '0') + value)%10 + '0');
            else ans += a[i];
        }
    }
    else
    {
        for (unsigned i = 0;i<5;i++)
        {

            if (wei == i || wei + 1 == i) ans += char((int(a[i] - '0') + value)%10 + '0');
            else ans += a[i];
        }

    }
    return ans;
}




int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    char a;
    string lock = "";
    string olock;
    string locks[10];
    unsigned count = 0;
    for (unsigned i = 0;i<5;i++)
    {
        cin >> a;
        lock += a;
    }
    locks[0] = lock;
    s.insert(locks[0]);
    //cout << lock << endl;
    for (unsigned i = 0;i<5;i++)
    {
        for (unsigned j = 1;j<10;j++)
        {
            s.insert(change(lock, i, j, false));
        }
    }
    //cout << s.size() << endl;
    for (unsigned i = 0;i<4;i++)
    {
        for (unsigned j = 1;j<10;j++)
        {
            s.insert(change(lock, i, j, true));
            //cout << change(lock, i, j, true) <<endl;
        }
    }
    //cout << s.size() << endl;
    unordered_set<string> s2;
    s2.insert(locks[0]);
    for (unsigned i = 1;i<n;i++)
    {
        lock = "";
        if (i % 2 == 1)
        {
            for (unsigned i = 0;i<5;i++)
            {
                cin >> a;
                lock += a;
            }
            locks[i] = lock;
            //cout << lock << endl;
            for (unsigned i = 1;i<=5;i++)
            {
                for (unsigned j = 1;j<10;j++)
                {
                    string out = change(lock, i, j, false);
                    if (s.find(out) != s.end())
                    {
                        // cout << change(lock, i, j, false) << " ";
                        s2.insert(out);
                    }
                }
            }
            for (unsigned i = 1;i<=4;i++)
            {
                for (unsigned j = 1;j<10;j++)
                {
                    string out = change(lock, i, j, true);
                    if (s.find(out) != s.end())
                    {
                        // cout << change(lock, i, j, true) << " ";
                        s2.insert(out);
                    }
                }
            }
            s.clear();
            for (unsigned j = 0;j<i;j++)
                s.insert(locks[i]);
        }
        else
        {
            for (unsigned i = 0;i<5;i++)
            {
                cin >> a;
                lock += a;
            }
            //cout << lock << endl;
            for (unsigned i = 1;i<=5;i++)
            {
                for (unsigned j = 1;j<10;j++)
                {
                    string out = change(lock, i, j, false);
                    if (s2.find(change(lock, i, j, false)) != s2.end())
                        s.insert(change(lock, i, j, false));
                }
            }
            for (unsigned i = 1;i<=4;i++)
            {
                for (unsigned j = 1;j<10;j++)
                {
                    string out = change(lock, i, j, true);
                    if (s2.find(change(lock, i, j, true)) != s2.end())
                        s.insert(change(lock, i, j, true));
                }
            }
            s2.clear();
            for (unsigned j = 0;j<i;j++)
                s2.insert(locks[i]);
        }
    }
    cout << max(s.size(), s2.size()) - n;
    return 0;
}
