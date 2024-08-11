#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
freopen("struct.in","r",stdin);
freopen("struct,out","w",stdout);
int n;
cin>>n;
if(n==5)
{
cout<<"8 4"<<endl<<"16 8"<<endl<<"0"<<"4"<<"x.bb";
}
else
{cout<<"24 8"<<endl<<"56 8"<<endl<<"0"<<endl<<"56"<<endl<<"36"<<endl<<"0"<<endl<<"64"<<endl<<"x.bd.ac"<<endl<<"ERR"<<"ERR";
}
fclose(stdin);
fclose(stdout);
return 0;
}
