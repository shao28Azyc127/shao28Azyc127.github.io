#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node
{
    int index;
    string val;
    bool operator <(const node &a) const
    {
        if (val < a.val)
        {
            return true;
        }
        if (val > a.val)
        {

            return false;
        }
        else
        {
            if (index < a.index)
            {
                return true;
            }
            else return false;
        }
    }

}values[3005];
string str;
string rev_dic(string s)
{
    int len = s.length();
    char ss[3005];
    for (int i = 0;i<len;i++)
    {
        ss[i] = s[i];
    }
    sort(ss, ss+len);
    reverse(ss, ss+len);
    for (int i = 0;i<len;i++)
    {
        s[i] = ss[i];
    }
    return s;
}
string dic(string s)
{
    int len = s.length();
    char ss[3005];
    for (int i = 0;i<len;i++)
    {
        ss[i] = s[i];
    }
    sort(ss, ss+len);
    for (int i = 0;i<len;i++)
    {
        s[i] = ss[i];
    }
    return s;
}



int main()
{
    ios::sync_with_stdio(false);
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    if (m == 1)
    {
        node a;
        for (int i = 0;i<n;i++)
        {
            cin >> str;
            a.index = i;
            a.val = str;
            values[i] = a;
        }
        sort(values, values+n);
        string ans = values[0].val;
        int anss[30];
        memset(anss, 0, sizeof(anss));
        for (int i = 0;i<n;i++)
        {
            if (values[i].val == ans)
            {
                anss[values[i].index] = 1;
            }
        }
        for (int i = 0;i<n;i++)
        {
            cout << anss[i];
        }
        cout << endl;
        return 0;
    }
    else if (m == 2)
    {
        node a;
        for (int i = 0;i<n;i++)
        {
            cin >> str;
            a.index = i;
            a.val = str;
            values[i] = a;
        }
        for (int i = 0;i<n;i++)
        {
            if (values[i].val[0] > values[i].val[1])
            {
                swap(values[i].val[0], values[i].val[1]);
            }
            int flag = 0;
            for (int j = 0;j<n;j++)
            {
                if (i == j) continue;
                //cout << values[i].val;
                string str1 = values[i].val;
                string str2 = values[j].val;
                //cout << str1 << " " << str2 << (str1 < str2) << endl;
                if ((str1 < str2) == ("ab" < "ac"));
                {
                    //cout << (str1 < str2) << " " << ("ab" < "ac") << endl;
                    int ori = flag;
                    flag+=(str1 < str2);
                    //cout << "1" << str2 << endl;
                    if (ori != flag)
                        continue;
                }
                //cout << "1111111111" << str2[0] << str2[1] << endl;
                swap(str2[0], str2[1]);
                //cout << str1 << " " << str2 << (str1 < str2) << endl;
                if ((str1 < str2) == ("ab" < "ac"));
                {
                    int ori = flag;
                    flag+=(str1 < str2);
                    //cout << "2" << values[j].val;
                    continue;
                }
            }
            //cout << flag << endl;
            if (flag == n-1)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            };
        }
        cout << endl;
        return 0;
    }
    else
    {
        for (int i = 0;i<n;i++)
        {
            cin >> values[i].val;
            values[i].index = i;
        }
        //cout << 1 << endl;
        for (int i = 0;i<n;i++)
        {
            string ma = dic(values[i].val);
            int flag = 0;
            for (int j = 0;j<n;j++)
            {
                if (i == j) continue;
                string mb = rev_dic(values[j].val);
                flag += (ma < mb);
                //cout << ma << " " << mb << endl;;
            }
            if (flag == n-1)
            {
                cout << 1;
            }
            else cout << 0;
        }
    }
}

//1 2 3 4 5 6 7 8  /10
