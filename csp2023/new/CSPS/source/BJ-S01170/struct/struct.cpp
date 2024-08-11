#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
struct Node
{
    string nam;
    int siz;
    long long int l, r;
}alls[N];
int cnt = 0;
long long int addr;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    while(n --)
    {
        int op;
        string nams, whi;
        cin >> op;
        if(op == 2)
        {
            cin >> whi >> nams;
            if(whi == "short") alls[cnt].siz = 2;
            else if(whi == "int") alls[cnt].siz = 4;
            else if(whi == "byte") alls[cnt].siz = 1;
            else alls[cnt].siz = 8;
            alls[cnt].nam = nams;
            if(addr % alls[cnt].siz == 0) 
            {
                alls[cnt].l = addr;
                alls[cnt].r = addr + alls[cnt].siz;
                addr += alls[cnt].siz;
            }
            else
            {
                long long int ne = addr / alls[cnt].siz + 1;
                ne = ne * alls[cnt].siz;
                alls[cnt].l = ne;
                alls[cnt].r = ne + alls[cnt].siz;
                addr = ne + alls[cnt].siz;
            }
            cout << alls[cnt].l << endl;
            cnt ++ ;
        }
        else if(op == 3)
        {
            cin >> nams;
            for(int i = 0; i < cnt; i ++)
                if(nams == alls[i].nam)
                {
                    cout << alls[i].l << endl;
                    break;
                }
        }
        else if(op == 4)
        {
            int ad;
            cin >> ad;
            bool flag = 0;
            for(int i = 0; i < cnt; i ++)
                if(alls[i].l <= ad && ad <= alls[i].r)
                {
                    cout << alls[i].nam << endl;
                    flag = 1;
                    break;
                }
            if(flag == 0) cout << "ERR" << endl;
        }
    }
    return 0;
}