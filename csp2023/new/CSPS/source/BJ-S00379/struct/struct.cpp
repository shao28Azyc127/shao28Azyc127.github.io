#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int m;
    int ad=0;
    string a[100001];
    cin >> m;
    while(m--)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            cout << "^_^" << endl;
        }
        else if(op==2)
        {
            string b,c;
            cin >> b >> c;
            if(b=="byte")
            {
                a[ad]=c;
                cout << ad << endl;
                ad+=1;

            }
            else if(b=="short")
            {
                a[ad]=a[ad+1]=c;
                cout << ad << endl;
                ad+=2;
            }
            else if(b=="int")
            {
                a[ad]=a[ad+1]=a[ad+2]=a[ad+3]=c;
                cout << ad << endl;
                ad+=4;
            }
            else if(b=="long")
            {
                a[ad]=a[ad+1]=a[ad+2]=a[ad+3]=a[ad+4]=a[ad+5]=a[ad+6]=a[ad+7]=c;
                cout << ad << endl;
                ad+=8;
            }
        }
        else if(op==3)
        {
            string b;
            cin >> b;
            for(int i=0;i<ad;i++)
            {
                if(a[i]==b)
                {
                    cout << i << endl;
                    break;
                }
            }
        }
        else if(op==4)
        {
            int b;
            cin >> b;
            if(b<ad)
            {
                cout << a[b] << endl;
            }
            else
            {
                cout << "ERR" << endl;
            }
        }
    }
    return 0;
}
