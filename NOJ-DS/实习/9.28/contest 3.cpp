#include <iostream>
//1 1时报错
using namespace std;

struct Node{
    int a;
    int b;
    Node *next;
};
extern void sort(Node *h);
extern void output(Node *h);
extern void clear_repeat(Node *h);
//extern void remove(Node *h);

int main(int argc, char *argv[]) {
    Node *h1=NULL;
    Node *t1=NULL;       
    Node *h2=NULL;
    Node *t2=NULL; 
    int m;
    int n;
    cin>>m>>n;
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

    //output(h1);
    for (int i = 0; i < n; ++i)
    {
        int a2,b2;
        cin>>a2>>b2;
        Node *p2 = new Node;
        p2->a = a2;
        p2->b = b2;
        p2->next = NULL;
        if (h2 == NULL)
            h2 = t2 = p2;
        else
        {
            t2->next = p2;
            t2 = p2;
        }
    }
    //output(h2);
    t1->next=h2;
    output(h1);
    clear_repeat(h1);
    output(h1);
    sort(h1);
    output(h1);
for(Node *w = h1;w != NULL; w = w->next)
    {
        if(w->a == 0)
            continue;
        else
            cout<<w->a<<" "<<w->b<<endl;
    }

    //remove(h1);
    //remove(h2);

    return 0;
}
void output(Node *h)//
{
    cout<<endl<<"output\t";
    for (Node *p = h; p != NULL; p = p->next)
        cout << p->a << " , "<<p->b << " ; ";
    cout << endl;
}
/*void remove(Node *h)
{
    while (h != NULL)
    {
        Node *p = h;
        h = h->next;
        delete p;
    }
}*/
void sort(Node *h)
{
    for (Node *p1 = h; p1->next != NULL; p1 = p1->next)
    {
        Node *p_max = p1;
        for (Node *p2 = p1->next; p2 != NULL; p2 = p2->next)
            if (p2->b>p_max->b)
                p_max = p2;

        if (p_max != p1)
        {
            int temp1 = p1->b;
            p1->b = p_max->b;
            p_max->b = temp1;
            int temp2 = p1->a;
            p1->a = p_max->a;
            p_max->a = temp2;
        }
    }
}

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
