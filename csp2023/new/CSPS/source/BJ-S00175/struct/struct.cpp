#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    long long pos=0;
    map<string,int>mp1;
    map<string,int>mp2;
    map<int,string>mp3;
    mp1["short"]=2;
    mp1["int"]=4;
    mp1["long"]=8;
    mp1["byte"]=1;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==2){
            string a,b;
            cin>>a>>b;
            cout<<pos<<endl;
            mp2[b]=pos;
            mp3[pos]=b;
            pos+=mp1[a];
        }
        if(t==3){
            string a;
            cin>>a;
            cout<<mp2[a]<<endl;
        }
        if(t==4){
            int a;
            cin>>a;
            if(mp3[a]==""){
                cout<<"ERR"<<endl;
            }
            else{
                cout<<mp3[a]<<endl;
            }
        }
    }
}
