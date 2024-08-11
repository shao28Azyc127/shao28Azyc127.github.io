#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c,x,p,q,q1_p,q1_q,q2_p,q2_q,memgcd,delta,sdelta;
inline void file(){
  freopen("uqe.in","r",stdin);
  freopen("uqe.out","w",stdout);
}
inline int gcd(int a,int b){return(b)?(gcd(b,a%b)):(a);}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  file();
  cin >> t >> m;
  while(t--){
    cin >> a >> b >> c;
    if(a<0) a=-a,b=-b,c=-c;
    delta=b*b-4*a*c;
    if(delta<0){
      cout << "NO\n";
      continue;
    }
    sdelta=sqrt(delta);
    if(sdelta*sdelta==delta){
      p=sdelta-b,q=2*a;
      memgcd=gcd(p,q);
      p/=memgcd,q/=memgcd;
      if(q==1){
        cout << p << '\n';
        continue;
      }
      if(q<0) p=-p,q=-q;
      cout << p << '/' << q << '\n';
      continue;
    }
    if(b!=0){
      q1_p=-b,q1_q=a*2;
      memgcd=gcd(q1_p,q1_q);
      q1_p/=memgcd,q1_q/=memgcd;
      if(q1_q==1) cout << q1_p << '+';
      else if(q1_q>0) cout << q1_p << '/' << q1_q << '+';
      else cout << -q1_p << '/' << -q1_q << '+';
    }
    q2_q=a*2,q2_p=1;
    for(int i=2;i*i<delta;++i) while(delta%(i*i)==0) q2_p*=i,delta/=(i*i);
    if(q2_p==q2_q) cout << "sqrt(" << delta << ")\n";
    else if(q2_p%q2_q==0) cout << q2_p/q2_q << "*sqrt(" << delta << ")\n";
    else if(q2_q%q2_p==0) cout << "sqrt(" << delta << ")/" << q2_q/q2_p << '\n';
    else{
      memgcd=gcd(q2_q,q2_p);
      q2_q/=memgcd,q2_p/=memgcd;
      cout << q2_p << "*sqrt(" << delta << ")/" << q2_q << '\n';
    }
  }
  return 0;
}