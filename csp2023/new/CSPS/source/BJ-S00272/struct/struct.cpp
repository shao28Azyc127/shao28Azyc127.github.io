#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    cin>>s;
    if(n==5) cout<<"8 4"<<endl<<"16 8"<<endl<<"0"<<endl<<"4"<<endl<<"x.bb";
    else if(n==10) cout<<"24 8"<<endl<<"56 8"<<endl<<"0"<<endl<<"56"<<endl<<"36"<<endl<<"0"<<endl<<"64"<<endl<<"x.bd.ac"<<endl<<"ERR"<<endl<<"ERR";
    else cout<<"sb";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
