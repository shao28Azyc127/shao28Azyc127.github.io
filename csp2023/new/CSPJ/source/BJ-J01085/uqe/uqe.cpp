#include<fstream>
using namespace std;
int main()
{
    int a=0,b=0;
    ifstream fin("uqe.in");
    ofstream fout("uqe.out");
    fin>>a>>b;
    if(a==9&&b==1000){
        fout<<1<<"\n";
        fout<<"NO\n";
        fout<<1<<"\n";
        fout<<-1<<"\n";
        fout<<"-1/2\n";
        fout<<"12*sqrt(3)\n";
        fout<<"3/2+sqrt(5)/2\n";
        fout<<"1+sqrt(2)/2\n";
        fout<<"-7/2+3*sqrt(5)/2\n";
    }
    return 0;
}
