#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,cnt,used;
struct Bas_Ty{
    int ty;
    string name;
}b[5];
struct fcb{
    int al,ar,ty;
    string name;
}c[MAXN];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    b[1]=(Bas_Ty){1,"byte"};
    b[2]=(Bas_Ty){2,"short"};
    b[3]=(Bas_Ty){4,"int"};
    b[4]=(Bas_Ty){8,"long"};
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int op;
        scanf("%d",&op);
        switch(op){
            case 2:{
                string a,b;
                cin>>a>>b;
                if(a=="byte") c[++cnt]=(fcb){used+1,used+1,1,b},used++;
                if(a=="short") c[++cnt]=(fcb){used+1,used+2,2,b},used+=2;
                if(a=="int") c[++cnt]=(fcb){used+1,used+4,3,b},used+=4;
                if(a=="long") c[++cnt]=(fcb){used+1,used+8,4,b},used+=8;
                break;
            }
            case 3:{
                string s;
                cin>>s;
                for(int i=1;i<=cnt;i++){
                    if(c[i].name==s){
                        printf("%d\n",c[i].al);
                        break;
                    }
                }
                break;
            }
            case 4:{
                int x;
                scanf("%d",&x);
                for(int i=1;i<=cnt;i++){
                    if(c[i].al<=x&&c[i].ar>=x){
                        cout<<c[i].name<<endl;
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}

