#include <bits/stdc++.h>

using namespace std;

struct cla{
    string name;
    long long siz;
}s[5];

struct sub{
    string name;
    string cl;
    long long str;
}a[105];

long long i,n,opt,cnt,k;
string ss,x;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    s[0].name="byte";
    s[0].siz=1;
    s[1].name="short";
    s[1].siz=2;
    s[2].name="int";
    s[2].siz=4;
    s[3].name="long";
    s[3].siz=8;
    cin >> n ;
    long long j,num;
    while(n--)
    {
        cin >> opt ;
        if(opt==2)
        {
            cin >> ss >> x ;
            a[i].cl=ss;
            a[i].name=x;
            a[i].str=cnt;
            for(j=0;j<4;j++)
            {
                if(a[i].cl==s[j].name)
                    num=s[j].siz;
            }
            while(cnt%num!=0)
                cnt++;
            a[i].str=cnt;
            cout << cnt << endl ;
            cnt+=num;
            i++;
        }
        if(opt==3)
        {
            cin >> ss ;
            for(j=0;j<i;j++)
            {
                if(ss==a[j].name)
                    cout << a[j].str << endl ;
            }
        }
        if(opt==4)
        {
            cin >> k ;
            for(j=0;j<i;j++)
            {
                if(a[j].str>k)
                    break;
            }
            j--;
            long long w=j;
            for(j=0;j<4;j++)
                if(a[w].cl==s[j].name)
                    break;
            if(a[w].str+s[j].siz<=k)
                cout << "ERR" << endl ;
            else
                cout << a[w].name << endl ;
        }
    }
}
