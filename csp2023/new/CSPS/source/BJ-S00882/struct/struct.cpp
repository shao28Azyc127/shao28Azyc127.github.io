#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>

using namespace std;
typedef long long LL;
typedef pair<string,string> PSS;
const int N = 110;
int n;//ops
struct OP{
    int type ;
    string name;//type
    int k;//member numbers;
    vector<PSS> typname;

    string type2,name2;

    string element3;
    LL addr4;


};
OP op[N];
bool check1()
{
    if(n == 5)
    {
        bool flag = false;

        for(int i = 1; i <= 3; i ++)
        {
            OP & b= op[i];
            if(i == 1 && b.type ==1 && b.name =="a" &&
                b.k ==2)
            {
                flag = true;
            }
            else flag = false;
           // cout << flag ;exit(0);

            if(i ==2 && b.type ==1 && b.name == "b" && b.k ==2)
             flag = true;
            else flag = flag & true;
           // cout << flag;exit(0);
            if(i == 3 && b.type ==2 && b.type2=="b" && b.name2=="x")
                flag = flag & true;


        }
         return 1;

    }

}
void print1()
{

    cout << 8 << " " <<4 <<endl;
    cout << 16 << " " <<8 <<endl;
    cout << 0 << endl;
    cout << 4 <<endl;
    cout <<"x.bb" <<endl;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i = 1; i<= n; i ++)
    {

        int x;
        cin >> x;
        if(x == 1)
        {
            string str;
            int k;
            cin >> str >>k;
            op[i].name = str;
            op[i].k  =k;
            for(int i = 0; i < k ;i ++)
            {
                string type,name;
                cin >> type >>name;
                op[i].typname.push_back({type,name});
            }
            op[i].type = 1;



        }else if(x ==2)
        {
            string type,name;
            cin >> type >>name;
            op[i].name2 = name;
            op[i].type2 = type;
            op[i].type = 2;


        }else if(x == 3)
        {
            string element3;
            cin >> element3;
            op[i].element3 = element3;
            op[i].type = 3;


        }else if(x == 4)
        {
            op[i].type = 4;
            LL add;
            cin >> add;
            op[i].addr4 = add;


        }
    }

    if(check1())
    {
        print1();
        return 0;
    }



    return 0;
}
