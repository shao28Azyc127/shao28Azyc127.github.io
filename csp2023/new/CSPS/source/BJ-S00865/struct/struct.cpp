//#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

ifstream cin("struct.in");
ofstream cout("struct.out");

#define int long long

struct type {
    vector<pair<string, string> > members;
    int siz, tab;
    type() : siz(0), tab(1) {}
    type(int _siz, int _tab) : siz(_siz), tab(_tab) {}
} type_byte(1, 1), type_short(2, 2), type_int(4, 4), type_long(8, 8);
map<string, type> name_to_type = {{"byte", type_byte}, {"short", type_short}, {"int", type_int}, {"long", type_long}};

struct element {
    string element_type_name;
    string name;
    int address;
    element(){}
    element(string _element_type_name, string _name, int _address) : element_type_name(_element_type_name), name(_name), address(_address) {}
};
vector<element> elements;

inline string get_first(string& s)
{
    string res;
    if(s.find('.') == string::npos)
    {
        res = s;
        s.clear();
    } else {
        res = s.substr(0, s.find('.'));
        s.erase(0, s.find('.') + 1);
    }
    return res;
}

signed main()
{
    int n;
    cin >> n;
    int max_address = 0;
    for(int loop_var = 1; loop_var <= n; loop_var++)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            string s;
            int k;
            cin >> s >> k;
            type new_type;
            for(int i = 1; i <= k; i++)
            {
                string member_type_name, member_name;
                cin >> member_type_name >> member_name;
                new_type.members.push_back(make_pair(member_type_name, member_name));
                while(new_type.siz % name_to_type[member_type_name].tab) new_type.siz++;
                new_type.siz += name_to_type[member_type_name].siz;
                if(new_type.tab < name_to_type[member_type_name].tab) new_type.tab = name_to_type[member_type_name].tab;
            }
            while(new_type.siz % new_type.tab) new_type.siz++;
            cout << new_type.siz << " " << new_type.tab << endl;
            name_to_type[s] = move(new_type);
        }
        if(op == 2)
        {
            string t, n;
            cin >> t >> n;
            while(max_address % name_to_type[t].tab) max_address++;
            cout << max_address << endl;
            elements.push_back(element(t, n, max_address));
            max_address += name_to_type[t].siz;
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            string name = get_first(s);
            int ans;
            type* now;
            for(element e : elements)
            {
                if(e.name == name)
                {
                    ans = e.address;
                    //cout << e.address << endl;
                    now = &name_to_type[e.element_type_name];
                    break;
                }
            }
            //cout << name << " " << s << " " << ans << endl;
            while(!s.empty())
            {
                string nxt = get_first(s);
                //cout << nxt << " " << s << " " << ans << endl;
                int addition = 0;
                for(pair<string, string> pts : now->members)
                {
                    //cout << pts.first << " " << pts.second << endl;
                    while(addition % name_to_type[pts.first].tab) addition++;
                    //cout << addition << " " << pts.second << endl;
                    if(pts.second == nxt)
                    {
                        ans += addition;
                        now = &name_to_type[pts.first];
                        break;
                    }
                    addition += name_to_type[pts.first].siz;
                }
            }
            cout << ans << endl;
        }
        if(op == 4)
        {
            int addr;
            cin >> addr;
            int element_address;
            type* now = &type_byte;
            string res = "ERR";
            for(element e : elements)
            {
                if(e.address + name_to_type[e.element_type_name].siz > addr)
                {
                    element_address = e.address;
                    now = &name_to_type[e.element_type_name];
                    res = e.name;
                    break;
                }
            }
            while(!now->members.empty())
            {
                bool okay = false;
                int addition = 0;
                for(pair<string, string> pts : now->members)
                {
                    while(addition % name_to_type[pts.first].tab) addition++;
                    if(addr < element_address + addition)
                    {
                        res = "ERR";
                        now = &type_byte;
                        okay = true;
                        break;
                    }
                    if(element_address + addition <= addr && addr < element_address + addition + name_to_type[pts.first].siz)
                    {
                        element_address += addition;
                        now = &name_to_type[pts.first];
                        res = res + "." + pts.second;
                        okay = true;
                        break;
                    }
                    addition += name_to_type[pts.first].siz;
                }
                if(!okay)
                {
                    res = "ERR";
                    break;
                }
            }
            cout << res << endl;
        }
    }
}
