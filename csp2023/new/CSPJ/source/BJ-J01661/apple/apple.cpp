#include<iostream>
using namespace std;
struct Node
{
    int io,*next,*pre;
}*head,*r;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i=1;
    cin>>n;
    head=new Node;
    r=new Node;
    r->pre=head;
    head->next=r;
    for(int i=1;i<=n;i++)
    {
        r->io=i;
        r=r->next;
    }
    r=NULL;
    for(int i=1;;i++)
    {
        r=head->next;
        for(int j=1;r!=NULL;j++)
        {
            if(j%3==1)
            {
                r->pre->next=r->next;
                r->next->pre=r->pre;
                if(r->io===n)
                {
                    cout<<i;
                    return 0;
                }
            }
            r=r->next;
        }
    }
}