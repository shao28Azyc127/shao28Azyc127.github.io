#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
int jp8(int x){
    int ans;
    for(int i=1;i*i<=x;i++){
        if(x%(i*i)==0)ans=i;
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    //cout<<t<<m;
    while(t--){
        cin>>a>>b>>c;
        int dt=b*b-4*a*c;//cout<<a<<" "<<b<<" "<<c<<endl;
        if(dt<0){
            printf("NO\n");
            continue;
        }
        int k=jp8(dt);
        if(dt==0){
            if(b%(2*a)==0)cout<<-b/2/a<<'\n';
            else printf("%d/%d\n",-b/gcd(b,2*a),2*a/gcd(b,2*a));
        }
        if(dt>0){
                if(dt/k/k==1){b-=sqrt(dt);if(b%(2*a)==0)cout<<-b/2/a<<'\n';
            else printf("%d/%d\n",-b/gcd(b,2*a),2*a/gcd(b,2*a));continue;}
            if(b!=0)
            if(b%(2*a)==0)cout<<-b/2/a<<'+';
            else {int q=-b/gcd(b,2*a),w=2*a/gcd(b,2*a);if(w<0){q=-q;w=-w;}printf("%d/%d+",q,w);}
            int r=dt/k/k;
            int l=gcd(k,2*a);
            if(k%(2*a)==0)
            if(k==2*a)
                printf("sqrt(%d)\n",r);
            else printf("%d*sqrt(%d)\n",k/2/a,r);
            else if(l==k){
                printf("sqrt(%d)/%d\n",r,2*a/l);
            }
            else printf("%d*sqrt(%d)/%d\n",k/l,r,2*a/l);
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

