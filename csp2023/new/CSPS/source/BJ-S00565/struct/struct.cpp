#include <bits/stdc++.h>

using namespace std;

struct stru
{
    string name;
    vector<string> vname;
    vector<int> vsize;
    int max_mem = 0;
};

vector<stru> structs;
vector<stru> memory;

int n;
string operation;

string split_op(string operation)
{
    string name, n;
    int i = 2;
    while (operation[i] != ' ')
    {
        name += operation[i];
    }
    i++;
    for (; i < operation.size(); ++i)
    {
        n += operation[i];
    }
    return name, n;
}



int get_type_size(string var)
{
    string vtype;
    int i = 0;
    while (var[i] != ' ')
    {
        vtype += var[i];
    }
    i++;


    if (vtype ==  "short")
        return 2, i+1;

    if (vtype ==  "int")
        return 4, i+1;

    if (vtype ==  "long")
        return 8, i+1;
    
    for (auto s : structs)
    {
        if (s.name == vtype)
        {
            return s.vname.size() * s.max_mem, i+1;
        }
    }

}

string get_var_name(string operation, int i)
{
    string name;
    for (int i = i; i < operation.size(); ++i)
    {
        name += operation[i];
    }
    return name;
}

void define_struct(string name, int num)
{
    stru tmp;
    tmp.name = name;
    string variable;
    for (int i = 0; i < num; ++i)
    {
        cin >> variable;
        int a,b;
        a, b = get_type_size(variable);
        tmp.vname.push_back(get_var_name(variable, b));
        tmp.vsize.push_back(a);
        tmp.max_mem = max(tmp.max_mem, a);
    }
    structs.push_back(tmp);
    cout << tmp.vname.size() * tmp.max_mem << ' ' << tmp.max_mem << endl;
}

void define_element(string operation)
{
    string var_type, detail;
    var_type, detail = split_op(operation);
    if (var_type == "byte")
    {
        stru tmp;
        tmp.name = detail;
        tmp.max_mem = 1;

    }
    stru tmp;
    int a,b;
    a, b = get_type_size(operation);
    tmp.name = get_var_name(operation, b);
    tmp.max_mem = a;
    tmp.vsize.push_back(0);
    for (int i = 0; i < tmp.max_mem; ++i)
    {
        memory.push_back(tmp);
    }
}




int main()
{
    fstream();
    freopen("struct.in", stdin);
    freopen("struct.out", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> operation;
        if (operation[0] == '1') define_struct(split_op(operation)[0], split_op(operation)[1] - '0');
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}