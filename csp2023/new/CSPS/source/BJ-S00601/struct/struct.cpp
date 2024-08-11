#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct N
{
    string name;
    int len,mbgs;
    string mbnm[110];
    string mblx[110];
}node[1000010];
void op1()
{
    cin >> node[1].name;
    int tp;
    cin >> tp;
    node[1].mbgs = tp;
    int ruc = 0;
    node[1].len = 0;
    for(int i = 1; i <= tp; i++)
    {
        string lx;
        cin >> lx;
        cin >> node[1].mbnm[++ruc];
        if(lx == "byte") node[1].len = max(node[1].len,1);
        else if(lx == "short") node[1].len = max(node[1].len,2);
        else if(lx == "int") node[1].len = max(node[1].len,4);
        else if(lx == "long") node[1].len = max(node[1].len,8);
        node[1].mblx[ruc] = lx;
    }
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    string nc[1000010];
    int n;
    cin >> n;
    int c = 0;
    c = -1;
    for(int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if(op == 1) op1();
        if(op == 2)
        {
            string lx;
            cin >> lx;
            string name;
            cin >> name;
            if(lx == "byte") c++,nc[c] = name;
            else if(lx == "short")
            {
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
            }
            else if(lx == "int")
            {
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
            }
            else if(lx == "long")
            {

                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
                c++;
                nc[c] = name;
            }
            else
            {
                for(int i = 1; i <= node[1].mbgs; i++)
                {
                    if(lx == "byte")
                    {
                        nc[++c] = node[1].name + "." + name;
                        for(int i = 2; i <= node[1].len; i++)
                        {
                            nc[++c] = "ERR";
                        }
                    }
                    else if(lx == "short")
                    {
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        for(int i = 3; i <= node[1].len; i++)
                        {
                            nc[++c] = "ERR";
                        }
                    }
                    else if(lx == "int")
                    {
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        for(int i = 5; i <= node[1].len; i++)
                        {
                            nc[++c] = "ERR";
                        }
                    }
                    else if(lx == "long")
                    {
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        nc[++c] = node[1].name + "." + name;
                        for(int i = 9; i <= node[1].len; i++)
                        {
                            nc[++c] = "ERR";
                        }
                    }
                }
            }
        }
        if(op == 3)
        {
            string fd;
            cin >>fd;
            for(int i = 0; i <= c; i++)
            {
                if(nc[i] == fd)
                {
                    cout << i << endl;
                }
            }
        }
        if(op == 4){
            int ad;
            cin >> ad;
            cout << nc[ad] << endl;
        }
    }
    return 0;
}
