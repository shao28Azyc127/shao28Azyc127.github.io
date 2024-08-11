#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string uqe(int a,int b,int c)
{
    if(pow(b,2)-4*a*c<0)
    {
        return "No";
    }

}
struct question()
{
    int a;
    int b;
    int c;
    string ans;
};
int main()
{
    question ques[m];
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>ques[i].a>>ques[i].b>>ques[i].c;
    }
    for(int i=0;i<m;i++)
    {
        ques[i].ans=uqe(ques[i].a,ques[i].b,ques[i].c);
    }
    return 0;
}
