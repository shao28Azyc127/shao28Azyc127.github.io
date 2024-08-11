#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int T;
map<string, int> mp_stru;
int mp_stru2[105]; // sum addr
struct defi_stru
{
    string bas_ty, bas_ele;
};
vector<defi_stru> adj[105];
int cnt_stru = 0;
int ele_cnt[105];
int max_addr = -1;
struct deef
{
    string typ;
    string nam;
    int las_addr;
};
map<string, string> mp_ele; // ele's type
map<string, string> mp_elee; // ele's belong_to
map<string, int> mp_posi;
map<string, int> mp_ele_pos; // ele's first_addr
deef def_queue[105];
int queuecnt = 0;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &T);
    while(T --)
    {
        int oper;
        scanf("%d", &oper);
        if(oper == 1)
        {
            // define a "struct" type
            string typ;
            cin >> typ;
            cnt_stru ++;
            mp_stru[typ] = cnt_stru;
            scanf("%d", &ele_cnt[cnt_stru]);
            int maxu = 0;
            int anss = 0;
            for(int j = 1;j <= ele_cnt[cnt_stru];j ++)
            {
                string bas_typ;
                cin >> bas_typ;
                string ele;
                cin >> ele;
                if(bas_typ == "byte" && maxu < 1)
                {
                    maxu = 1;
                }
                else if(bas_typ == "short" && maxu < 2) maxu = 2;
                else if(bas_typ == "int" && maxu < 4) maxu = 4;
                else if(bas_typ == "long" && maxu < 8) maxu = 8;
                else
                {
                    int numb = mp_stru[bas_typ];
                    if(maxu < mp_stru2[numb]) maxu = mp_stru2[numb];
                }
                mp_posi[ele] = mp_stru[bas_typ];
                mp_elee[ele] = bas_typ;
                adj[cnt_stru].push_back(defi_stru{bas_typ, ele});
                anss += maxu;
            }
            mp_stru2[cnt_stru] = maxu * ele_cnt[cnt_stru];
            printf("%d %d\n", maxu * ele_cnt[cnt_stru], maxu);
        }
        if(oper == 2)
        {
            // use a type
            string typ, ele;
            cin >> typ >> ele;
            if(typ == "byte")
            {
                max_addr += 1;
                def_queue[++ queuecnt] = deef{"byte", ele, max_addr};
                mp_ele[ele] = "byte";
                mp_ele_pos[ele] = max_addr - 1 + 1;
            }
            else if(typ == "short")
            {
                max_addr += 2;
                def_queue[++ queuecnt] = deef{"short", ele, max_addr};
                mp_ele[ele] = "short";
                mp_ele_pos[ele] = max_addr - 2 + 1;
            }
            else if(typ == "int")
            {
                max_addr += 4;
                def_queue[++ queuecnt] = deef{"int", ele, max_addr};
                mp_ele[ele] = "int";
                mp_ele_pos[ele] = max_addr - 4 + 1;
            }
            else if(typ == "long")
            {
                max_addr += 8;
                def_queue[++ queuecnt] = deef{"long", ele, max_addr};
                mp_ele[ele] = "long";
                mp_ele_pos[ele] = max_addr - 8 + 1;
            }
            else
            {
                int numb = mp_stru[typ];
                int sum = mp_stru2[numb];
                max_addr += sum;
                def_queue[++ queuecnt] = deef{typ, ele, max_addr};
                mp_ele[ele] = typ;
                mp_ele_pos[ele] = max_addr - sum + 1;
            }
            printf("%d\n",mp_ele_pos[ele]);
        }
        if(oper == 3)
        {
            string s;
            cin >> s;
            s += '.';
            string ele_nam = ""; // first ele
            int i;
            for(i = 0;i < s.length();i ++)
            {
                if(s[i] != '.') ele_nam += s[i];
                else
                {
                    i ++;
                    break;
                }
            }
            string typ_nam = mp_ele[ele_nam];
            int numb = mp_stru[typ_nam];
            int sum_ele = mp_stru2[numb];
            int now_ele = mp_ele_pos[typ_nam];
            string nex_ele = "";
            for( ;i < s.length();i ++)
            {
                if(s[i] != '.') nex_ele += s[i];
                else
                {
                    for(int j = 0;j < adj[numb].size();j ++)
                    {
                        string tmp = adj[numb][j].bas_ele;
                        //cout << tmp << endl;
                        if(tmp == nex_ele)
                        {
                            ele_nam = nex_ele;
                            nex_ele = "";
                            typ_nam = mp_elee[ele_nam];
                            numb = mp_posi[ele_nam];
                            sum_ele = mp_stru2[numb];
                            //cout << now_ele + sum_ele - 1 << endl;
                            //cout << typ_nam << " " <<numb<< endl;
                            break;
                        }
                        now_ele += sum_ele / ele_cnt[numb];
                    }
                }
            }
            printf("%d\n", now_ele);
        }
        if(oper == 4)
        {
            int g;
            cin>> g;
            puts("ERR");
        }
    }
    return 0;
}