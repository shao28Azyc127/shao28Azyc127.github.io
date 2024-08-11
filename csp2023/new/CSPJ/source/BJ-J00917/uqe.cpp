#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    int T,M;
    cin>>T>>M;
    M*=3;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int a2=2*a;
        int delta=b*b-4*a*c;
        if(delta<0)
        {
            cout<<"NO\n";
            continue;
        }
        //q2
        int back_xi=1;
        for(int i=M;i>=1;i--)
            if(delta%(i*i)==0)
            {
                delta/=i*i;
                back_xi=i;
                break;
            }
        int q2_m=2*a;
        int q2_z=back_xi;
        int tmp_q2=gcd(abs(q2_z),abs(q2_m));
        q2_z/=tmp_q2;
        q2_m/=tmp_q2;
        if(q2_m<0)
        {
            q2_m*=-1;
            q2_z*=-1;
        }
        q2_z=abs(q2_z);
        //cout<<delta<<" "<<back_xi<<" "<<q2_m<<" "<<q2_z<<endl;
        //q1
        int q1_m=2*a;
        int q1_z=0-b;
        int tmp_q1=gcd(abs(q1_z),abs(q1_m));
        q1_z/=tmp_q1;
        q1_m/=tmp_q1;
        if(q1_m<0)
        {
            q1_m*=-1;
            q1_z*=-1;
        }
        //cout<<q1_m<<" "<<q1_z<<endl;
        //cout
        if(delta==0)
        {
            if(q1_m==1) cout<<q1_z<<"\n";
            else cout<<q1_z<<"/"<<q1_m<<"\n";
        }
        else if(delta==1)
        {
            //q1 q2
            int gcd_q1q2=gcd(q1_m,q2_m);
            int lcm_q1q2=q1_m*q2_m/gcd_q1q2;
            q1_z=q1_z*(lcm_q1q2/q1_m);
            q2_z=q2_z*(lcm_q1q2/q2_m);
            int q_z=q1_z+q2_z;
            int q_m=lcm_q1q2;
            int tmp_q=gcd(abs(q_z),abs(q_m));
            q_z/=tmp_q;
            q_m/=tmp_q;
            if(q_m==1) cout<<q_z<<"\n";
            else cout<<q_z<<"/"<<q_m<<"\n";
        }
        else
        {
            bool fl_q1=1,fl_q2=1;
            if(q1_z!=0)
            {
                if(q1_m==1) cout<<q1_z;
                else cout<<q1_z<<"/"<<q1_m;
                fl_q1=0;
            }
            if(q2_z!=0)
            {
                if(!fl_q1&&q2_z>0) cout<<"+";
                if(q2_z<0) cout<<"-";
                q2_z=abs(q2_z);
                if(q2_m==1)
                {
                    if(q2_z!=1) cout<<q2_z<<"*"<<"sqrt("<<delta<<")\n";
                    else cout<<"sqrt("<<delta<<")\n";
                }
                else
                {
                    if(q2_z!=1) cout<<q2_z<<"*"<<"sqrt("<<delta<<")/"<<q2_m<<"\n";
                    else cout<<"sqrt("<<delta<<")/"<<q2_m<<"\n";
                }
                fl_q2=0;
            }
            if(fl_q1&&fl_q2) cout<<"0\n";
            if(!fl_q1&&fl_q2) cout<<"\n";
        }
    }
    return 0;
}
