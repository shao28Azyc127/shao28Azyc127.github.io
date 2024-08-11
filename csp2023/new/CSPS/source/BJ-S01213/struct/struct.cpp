# include <bits/stdc++.h>
using namespace std;
int n;
struct bll{
    string name;
    int type;
    int addrr;
    int max_addr;
}bl[10005];
struct node{
    string name;
    int id;
    int type;
    int max_addr;
    vector <bll> x;
}no[1005];
int type[1005]; //byte-1,short-2,int-3,long-4,struct-5
int ty_num = 5;
map <string,int> num;
map <string,int> blm;
int id_num = 0;
int blm_num = 0;
int addr_num = 0;
void cl2(int addr){
    int q = -1;
    for(int i=0;i<blm_num;i++){
        if(bl[i].addrr>=addr){
            q = i-1;
            break;
        }
    }
    if(q==-1){
        if(bl[blm_num-1].addrr+bl[blm_num-1].max_addr<addr){
            printf("ERR\n");
            return;
        }
    }
    cout<<bl[q].name<<endl;
    return;
}
void cl(string s){
    string bh[20];
    int nu = 0;
    string ls = "";
    for(int i=0;i<s.length();i++){
        if(i==s.length()-1) ls += s[i];
        if(s[i]=='.'||i==s.length()-1){
            bh[nu] = ls;
            nu++;
            ls = "";
        }
        else{
            ls += s[i];
        }
    }
    int addr = 0;
    int blid = blm[bh[0]];
    addr += bl[blid].addrr;
    int ty = bl[blid].type;
    if(ty<=4){
        cout<<addr<<"\n";
        return;
    }
    ty-=5;
    for(int i=1;i<nu;i++){
        int id2;
        for(int j=0;j<no[ty].x.size();j++){
            if(no[ty].x[j].name==bh[i]){
                id2 = j;
                break;
            }
            else{
                addr += no[ty].max_addr;
            }
        }
        bll d = no[ty].x[id2];
        ty = d.type;
        if(ty<=4){
            cout<<addr<<"\n";
            return;
        }
        ty-=5;

    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string s;
            cin>>s;
            num[s] = id_num;
            id_num++;
            int id1 = id_num-1;
            type[id1+5] = id1;
            ty_num++;
            int k;
            cin>>k;
            no[id1].name = s;
            no[id1].id = id1;
            int kkk = k;
            int max_add = -1;
            while(k--){
                string t,n;
                cin>>t>>n;
                int ty;
                bll d;
                if(t=="byte"){
                    ty = 1;
                    d.max_addr = 1;
                }
                else if(t=="short"){
                    ty = 2;
                    d.max_addr = 2;
                }
                else if(t=="int"){
                    ty = 3;
                    d.max_addr = 4;
                }
                else if(t=="long"){
                    ty = 4;
                    d.max_addr = 8;
                }
                else{
                    ty = num[t]+5;
                    bll no1;
                    no1.name = n;
                    no1.type = ty;
                    no1.max_addr = no[num[t]].max_addr;
                    max_add = max(max_add,no1.max_addr);
                    no[id1].x.push_back(no1);
                    continue;
                }
                d.name = n;
                d.type = ty;
                no[id1].x.push_back(d);
                max_add = max(max_add,d.max_addr);
            }
            no[id1].max_addr = max_add;
            printf("%d %d\n",kkk*max_add,no[id1].max_addr);
        }
        else if(op==2){
            string t,n;
            cin>>t>>n;
            blm[n] = blm_num;
            int id = blm_num;
            blm_num++;
            bll bb;
            bb.name = n;
            int ty;
            if(t=="byte"){
                    ty = 1;
                    bb.max_addr = 1;
                }
                else if(t=="short"){
                    ty = 2;
                    bb.max_addr = 2;
                }
                else if(t=="int"){
                    ty = 3;
                    bb.max_addr = 4;
                }
                else if(t=="long"){
                    ty = 4;
                    bb.max_addr = 8;
                }
            else{
                int id1 = num[t];
                ty = id1+5;
                bb.max_addr = no[id1].max_addr;
            }
            bb.type = ty;
            bb.addrr = addr_num;
            addr_num += bb.max_addr;
            bl[id] = bb;
            printf("%d\n",bb.addrr);
        }
        else if(op==3){
            string s;
            cin>>s;
            cl(s);
        }
        else{
            int addr;
            cin>>addr;
            cl2(addr);
        }
    }
    return 0;
}
