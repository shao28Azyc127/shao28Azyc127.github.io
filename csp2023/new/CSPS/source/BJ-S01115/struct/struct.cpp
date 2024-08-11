#include<bits/stdc++.h>
using namespace std;
string s1="byte";
string s2="short";
string s3="int";
string s4="long";
struct node{
    string mc;
    int s,e;
}a[110];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int k=1;
    int d=0;
    while(n--){
        int op;
        cin>>op;
        if(op==2){
            string s6,m;
            cin>>s6>>m;
            a[k].mc=m;
            if(s6==s1){
                a[k].s=d;
                a[k].e=d;
                d++;
            }else if(s6==s2){
                if(d%2==1){
                    d++;
                }
                a[k].s=d;
                a[k].e=d+1;
                d+=2;
            }else if(s6==s3){
                for(int i=1;i<=3;i++){
                    if(d%4==0){
                        break;
                    }
                    d++;

                }
                a[k].s=d;
                a[k].e=d+3;
                d+=4;
            }else{
                for(int i=1;i<=7;i++){
                    if(d%8==0){
                        break;
                    }
                    d++;
                }
                a[k].s=d;
                a[k].e=d+7;
                d+=8;
            }
            cout<<a[k].s<<endl;
            k++;
        }else if(op==3){
            string s7;
            cin>>s7;
            for(int i=1;i<=k-1;i++){
                if(s7==a[i].mc){
                    cout<<a[i].s<<endl;
                }
            }
        }else if(op==4){
            int cx;
            cin>>cx;
            bool flag = false;
            for(int i=1;i<=k-1;i++){
                if(a[i].s<=cx&&a[i].e>=cx){
                    cout<<a[i].mc<<endl;
                    flag=true;
                }
            }
            if(flag==false){
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
