#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Man
{
    string lei, name;

    Man(string a, string b)
    {
        lei = a;
        name = b;
    }
};

struct Struct
{
    int lon, ned = 1;
    vector<Man> mans;

    Struct(int l, int nd)
    {
        lon = l;
        ned = nd;
    }
};

map<string, Struct> sts;

vector<string> isSet_lei;
vector<string> isSet_name;

int main()
{
    ifstream fin("struct.in");
    ofstream fout("struct.out");

    int n;
    fin >> n;
    sts["byte"] = Struct(1, 1);
    sts["short"] = Struct(2, 2);
    sts["int"] = Struct(4, 4);
    sts["long"] = Struct(8, 8);

    int start = 0;
    while (n--)
    {
        int op;
        fin >> op;
        switch(op)
        {
        case 1:
            string s;
            int k;
            for (int i = 0; i < k; i++)
            {
                string ti, ni;
                fin >> ti >> ni;
                sts[s].mans.push_back(Man(ti, ni));
                sts[s].lon += sts[ti].lon;
                sts[s].ned = max(sts[s].ned, sts[ti].ned);
            }
            fout << sts[s].lon << ' ' << sts[s].ned << endl;
            break;
        case 2:
            string ti, ni;
            fin >> ti >> ni;
            isSet_lei.push_back(ti);
            isSet_name.push_back(ni);
            fout << strat << endl;
            strat += sts[ti].lon;
            break;
        case 3:
            string f;
            string nf;
            fin >> f;
            int l = 0;
            for (int i = 0; i < f.size(); i++)
            {
                if (f[i] == '.')
                {

                }
            }
            for (int i = 0; i < isSet_name.size(); i++)
            {
                if (isSet_name[i] )
            }
            break;
        case 4:
            break;
        }
    }
}