#include <iostream>
//2 3  11 22 －1 -1 －2 2 3 3
using namespace std;

struct Node{
    int a;
    int b;
    Node *next;
};
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
void output(Node *h)//
{
    cout<<endl<<"output\t";
    for (Node *p = h; p != NULL; p = p->next)
        cout << p->a << " , "<<p->b << " ; ";
    cout << endl;
}
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
    for(Node *pp1 = h1;pp1 != NULL;pp1 = pp1->next)
    {
            Node *pp2 = h2;
            for(;pp2 != NULL;pp2 = pp2->next)
             {
                    if(pp2->b==pp1->b)
                        pp1->a+=pp2->a;
             }
    }

    output(h1);
    //output(h2);
    for(Node *ppp1 = h2;ppp1 != NULL;ppp1 = ppp1->next)
    {
            int flag=0;
            Node *ppp2 = h1;
            for(;ppp2 != NULL;ppp2 = ppp2->next)
             {
                    if(ppp2->b==ppp1->b)
                        flag=1;
             }
             if (flag==0)
             {
                    if (h1 == NULL)
                        h1 = t1 = ppp1;
                    else
                    {
                        t1->next = ppp1;
                        t1 = ppp1;
                    }
             }
    }
    output(h1);

    sort(h1);
for(Node *w = h1;w != NULL; w = w->next)
    {
        if(w->a == 0)
            continue;
        else
            cout<<w->a<<" "<<w->b<<endl;
    }

    return 0;
}
