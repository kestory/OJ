#include <iostream>

using namespace std;
struct Node{
    int a;
    int b;
    Node *next;
};
void clear_repeat(Node *h)
{    for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
        {   //cout<<"\tp1->b="<<p1->b<<endl;
            for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next)   
            {
                if(p1->b==p2->b)
                    {   //cout<<"\tp1->b="<<p1->b;
                        p1->a+=p2->a;
                        Node *p=h;
                        while(p->next!=p2)
                        {   
                            p=p->next;                      
                        }
//                      if(p2->next!=NULL)
                            p->next=p2->next;
                            //delete p2;
                    }

            }
        }
}
void output(Node *h)//
{
    cout<<endl<<"output\t";
    for (Node *p = h; p != NULL; p = p->next)
        cout << p->a << " , "<<p->b << " ; ";
    cout << endl;
}
int main(int argc, char *argv[]) {
    Node *h1=NULL;
    Node *t1=NULL;       
    int m;
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int a1,b1;
        cin>>a1>>b1;
        Node *p1 = new Node;
        p1->a = a1;
        p1->b = b1;
        p1->next = NULL;
        if (h1 == NULL)
            h1 = t1 = p1;
        else
        {
            t1->next = p1;
            t1 = p1;
        }
    }
    clear_repeat(h1);
    output(h1);
}