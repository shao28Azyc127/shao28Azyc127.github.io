#include <bits/stdc++.h>
using namespace std;


class State{
public:
    int n1,n2,n3,n4,n5;

    bool isCmped = false;


    State(){
        cin>>n1>>n2>>n3>>n4>>n5;
    }
    State(int a,int b,int c,int d,int e){

        n1=a%10;n2=b%10;n3=c%10;n4=d%10;n5=e%10;
    }

    void Print(){
    }

    vector<State> pas;
    vector<State> pasTmp;

    bool cmp(State s){
        return s.n1==n1&&s.n2==n2
        &&s.n3==n3&&s.n4==n4&&s.n5==n5;
    }

    void CalcPass(){
        //T1
        for(int i=1;i<10;i++){
                State s=State(n1+i,n2,n3,n4,n5);
        pas.push_back(s);
        s=State(n1,n2+i,n3,n4,n5);
        pas.push_back(s);
        s=State(n1,n2,n3+i,n4,n5);
        pas.push_back(s);
        s=State(n1,n2,n3,n4+i,n5);
        pas.push_back(s);
        s=State(n1,n2,n3,n4,n5+i);
        pas.push_back(s);

        }
        //T2
        for(int i=1;i<10;i++){
        State s=State(n1+i,n2+i,n3,n4,n5);
        pas.push_back(s);
        s=State(n1,n2+i,n3+i,n4,n5);
        pas.push_back(s);
        s=State(n1,n2,n3+i,n4+i,n5);
        pas.push_back(s);
        s=State(n1,n2,n3,n4+i,n5+i);
        pas.push_back(s);
        }

    }

    vector<State> cmpWith(vector<State> cm){
        // write same into pasTmp
        for(State s : this->pas){
            // do cmp
            for(State ss : cm){
                if(s.cmp(ss)){
                    pasTmp.push_back(s);
                }
            }
        }
        return pasTmp;
    }
};


// vars
int n;// zhuang tai shu
vector<State> zt;// zhuangtai


int main(){
    // default
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin >> n;
    for(int i=0;i<n;i++){
        State s = State();
        //s.Print();
        zt.push_back(s);
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=0;i<n;i++){
        zt[i].CalcPass();
        //cout<<s.pas.size();
    }
    int cnt = 0;

    vector<vector<State>> veee;
    vector<State> ve;
    vector<State> tmp;
    ve = zt[0].cmpWith(zt[1].pas);
    for(int i=1;i<n;i++){
            ve = zt[i].cmpWith(ve);
            tmp = ve;
    }



    cout<<tmp.size();
    // ret
    return 0;
}
