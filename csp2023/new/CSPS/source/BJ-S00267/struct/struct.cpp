#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
};
struct len{
    int aaa,aa;
};
vector<string>A;//struct name
map<string,int>B;//struct name's number
vector<string>C[105];//struct element name
vector<node>D[105];//struct element address
vector<len>E;//opr1 answer
vector<string>F;//element name
int cntstruct;
long long cntaddress;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int opr;
        cin>>opr;
        if(opr==1){
            string s;//struct name
            int num,cnt=0;
            len ans;
            cin>>s>>num;
            B[s]=cntstruct++;
            A.push_back(s);
            for(int j=1;j<=num;j++){
                string x,y;//element and name
                cin>>x>>y;
                C[B[s]].push_back(y);
                if(x=="byte"){
                    node tmp;
                    tmp.l=cnt;tmp.r=cnt;
                    D[B[s]].push_back(tmp);
                    cnt+=1;
                    ans.aa=max(ans.aa,1);
                }
                else if(x=="short"){
                    node tmp;
                    if(cnt%2!=0)cnt+=1;
                    tmp.l=cnt;tmp.r=cnt+1;
                    D[B[s]].push_back(tmp);
                    cnt+=2;
                    ans.aa=max(ans.aa,2);
                }
                else if(x=="int"){
                    node tmp;
                    if(cnt%4!=0)cnt=(cnt/4+1)*4;
                    tmp.l=cnt;tmp.r=cnt+3;
                    D[B[s]].push_back(tmp);
                    cnt+=4;
                    ans.aa=max(ans.aa,4);
                }
                else if(x=="long"){
                    node tmp;
                    if(cnt%8!=0)cnt=(cnt/8+1)*8;
                    tmp.l=cnt;tmp.r=cnt+7;
                    D[B[s]].push_back(tmp);
                    cnt+=8;
                    ans.aa=max(ans.aa,8);
                }
            }
            if(cnt%ans.aa!=0)ans.aaa=(cnt/ans.aa+1)*ans.aa;
            else ans.aaa=cnt;
            E.push_back(ans);
            cout<<ans.aaa<<' '<<ans.aa<<endl;
        }
        else if(opr==2){
            string x,y;
            cin>>x>>y;
            F.push_back(y);
            cout<<cntaddress<<endl;
            if(x=="byte"){
                cntaddress+=1;
            }
            else if(x=="short"){
                if(cntaddress%2!=0)cntaddress+=1;
                cntaddress+=2;
            }
            else if(x=="int"){
                if(cntaddress%4!=0)cntaddress=(cntaddress/4+1)*4;
                cntaddress+=4;
            }
            else if(x=="long"){
                if(cntaddress%8!=0)cntaddress=(cntaddress/8+1)*8;
                cntaddress+=8;
            }
        }
        else if(opr==3){
            string x;
            cin>>x;
        }
        else if(opr==4){
            long long x;
            cin>>x;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
