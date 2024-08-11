#include <iostream>
#include <map>

using namespace std;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    int memory[1000],now=0;
    map<string,int> sss;
    map<int,string> fsss;

    for (int i=0;i<1000;i++)
    {
        memory[i]=-1;
    }

    int n;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            string t,n;
            cin >> t >> n;
            cout << now << endl;
            sss[n]=now;
            fsss[now]=n;
            if (t == "byte")
            {
                memory[now]=now;
                now++;
            }
            if (t == "short")
            {
                memory[now]=now;
                memory[now+1]=now;
                now+=2;
            }
            if (t == "int")
            {
                memory[now]=now;
                memory[now+1]=now;
                memory[now+2]=now;
                memory[now+3]=now;
                now+=4;
            }
            if (t == "long")
            {
                memory[now]=now;
                memory[now+1]=now;
                memory[now+2]=now;
                memory[now+3]=now;
                memory[now+4]=now;
                memory[now+5]=now;
                memory[now+6]=now;
                memory[now+7]=now;
                now+=8;
            }

        }
        
        if (op == 3)
        {
            string ssss;
            cin >> ssss;
            cout << sss[ssss] << endl;

        }
        
        if (op == 4)
        {
            int jf;
            cin >> jf;
            if (memory[jf] != -1)
            {
                
                cout << fsss[memory[jf]] << endl;
                
            }
            
            else
            {
                cout << "ERR" << endl;
            }

        }
    }

    return 0;
}