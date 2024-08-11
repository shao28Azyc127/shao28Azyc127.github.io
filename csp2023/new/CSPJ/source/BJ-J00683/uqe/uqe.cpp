#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open("uqe.in");
    ofs.open("uqe.out");
    int T,mmmm;
    ifs>>T>>mmmm;
    int a,b,c;
    for(int i = 0;i <T;i++)
    {
        ifs>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0)
        {
            ofs<<"NO"<<endl;
            continue;
        }
        ofs<<int((-b+int(sqrt(delta)))/2/a)<<endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}
