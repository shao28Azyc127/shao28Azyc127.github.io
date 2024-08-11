#include <bits/stdc++.h>

using namespace std;
struct tS{
    char name[10];
    int addrF,m,s;
}a[101];
int n;
int Max,num;
char addr[801][10];
bool flag[801];
char cmptp[4][5];

void Do(int x){
    if(x==1){
        char t1[10];
        int t2;
        strcpy(a[num].name,t1);
        cin>>t1>>t2;
        for(int i=1;i<=t2;i++){
            char t[10],namet[10];
            cin>>t>>namet;
            bool tflag=true;
            if(strcmp(t,"byte")==0){
                a[num].m=max(a[num].m,1);
            }else if(strcmp(t,"short")==0){
                a[num].m=max(a[num].m,2);
            }else if(strcmp(t,"int")==0){
                a[num].m=max(a[num].m,4);
            }else if(strcmp(t,"long")==0){
                a[num].m=max(a[num].m,8);
            }else{
                for(int i=0;i<num;i++){
                    if(strcmp(t,a[i].name)==0){
                        a[num].m=max(a[num].m,a[i].m);
                        break;
                    }
                }
            }
        }
        cout<<a[num].m*t2<<" "<<a[num].m<<endl;
        Max+=t2*a[num].m;
        num++;
    }
    if(x==2){
        int t;
        char t1[10],t2[10];
        cin>>t1>>t2;
        cout<<Max<<endl;
        if(t1[0]=='b'){
            t=1;
        }
        if(t1[0]=='s'){
            t=2;
        }
        if(t1[0]=='i'){
            t=4;
        }
        if(t1[0]=='l'){
            t=8;
        }
        for(int i=Max;i<Max+t;i++){
            strcpy(addr[i],t2);
            flag[i]=true;
        }
        strcpy(a[num].name,t2);
        a[num].addrF=Max;
        Max+=t;
        num++;
        return;
    }
    if(x==3){
        char t[10];
        cin>>t;
        for(int i=0;i<num;i++){
            if(strcmp(a[i].name,t)==0){
                cout<<a[i].addrF<<endl;
                return;
            }
        }
    }
    if(x==4){
        int t;
        cin>>t;
        if(flag[t]){
            cout<<addr[t]<<endl;
        }else{
            cout<<"ERR"<<endl;
        }
        return;
    }

}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        Do(t);
    }
    return 0;
}
