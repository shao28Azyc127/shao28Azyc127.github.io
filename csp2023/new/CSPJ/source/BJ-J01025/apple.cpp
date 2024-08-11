#include<bits/stdc++.h>
using namespace std;
queue<int> q,fq;
int main(){
    int a,ans2=0,ran2=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&a);
    int fa=a;
    for(int i=1;i<=a;i++){
        q.push(i);
    }
    while(a){
        ans2++;
        int l=q.size();
        for(int i=0;i<l;i+=3){
            if(q.front()==fa){
                ran2=ans2;
            }
            q.pop();
            a--;
            fq.push(q.front());
            q.pop();
            fq.push(q.front());
            q.pop();
        }
        while(fq.size()){
            q.push(fq.front());
            fq.pop();
        }
    }
    printf("%d %d",ans2,ran2);
}
