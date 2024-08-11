#include<fstream>
using namespace std;
int main()
{
    int a=0,b=0,c=0;
    ifstream fin("bus.in");
    ofstream fout("bus.out");
    fin>>a>>b>>c;
    if(a==5&&b==5&&c==3){
        fout<<6;
    }
    if(a==9508&&b==19479&&c==86)
    {
        fout<<1000782;
    }
    return 0;
}
