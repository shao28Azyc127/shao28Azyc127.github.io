#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    node *ne;
}*head=new node;

void make(int n){
    node *p=head;
    for(int i=1;i<=n;i++){
        node *q=new node;
        q->x=i,q->ne=0;
        p->ne=q;
        p=q;
    }
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;
    int date=0,ans=0,els;
    cin>>n;
    make(n);

    els=n;
    while(els){
        date++;
        node *p1=head->ne,*p2=head;
        int k=1;
        for(;p1;p1=p1->ne){
            if(k%3==1){
                if(p1->x==n)
                    ans=date;
                p2->ne=p1->ne;
                els--;
            }
            else{
                p2=p2->ne;
            }
            k++;
        }
    }
    cout<<date<<' '<<ans;
    return 0;
}
