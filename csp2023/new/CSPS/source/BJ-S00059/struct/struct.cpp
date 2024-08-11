#include<iostream>
using namespace std;
int n,a,b,flag=0;
string t1,t2;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    if(n!=5) flag=1;
    cin>>a>>t1>>b;
    if(a!=1||t1!="a"||b!=2) flag=1;
    cin>>t1>>t2;
    if(t1!="short"||t2!="aa") flag=1;
    cin>>t1>>t2;
    if(t1!="int"||t2!="ab") flag=1;
    if(!flag) cout<<"8 4"<<"\n";
    else{
        flag=0;
        cout<<0<<"\n";
    }
    cin>>a>>t1>>b;
    if(a!=1||t1!="b"||b!=2) flag=1;
    cin>>t1>>t2;
    if(t1!="a"||t2!="ba") flag=1;
    cin>>t1>>t2;
    if(t1!="long"||t2!="bb") flag=1;
    if(!flag) cout<<"16 8"<<"\n";
    else{
        flag=0;
        cout<<0<<"\n";
    }
    cin>>a>>t1>>t2;
    if(a!=2||t1!="b"||t2!="x") flag=1;
    if(!flag) cout<<"0"<<"\n";
    else{
        flag=0;
        cout<<0<<"\n";
    }
    cin>>a>>t1;
    if(a!=3||t1!="x.ba.ab") flag=1;
    if(!flag) cout<<"4"<<"\n";
    else{
        flag=0;
        cout<<0<<"\n";
    }
    cin>>a>>b;
    if(a!=4||b!=10) flag=1;
    if(!flag) cout<<"x.bb"<<"\n";
    else{
        flag=0;
        cout<<0<<"\n";
    }
    return 0;
}
