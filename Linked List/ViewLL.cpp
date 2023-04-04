#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int item;
    node *next;
};
class SLL
{
    node *start;

public:
    SLL();
    void view();
    void view(node *);
    void view(node *s, int &); // view from last pos
    void view(int);            // view from last pos
    node* reverse(node*);
    void reverse();
    node* kReverse(node*);
    node* iterativeReverse();
    void insertAtFirst(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteLastNode();
    void deleteFirstNode();
    void deleteNode(node *);
};
SLL::SLL()
{
    start = NULL;
}
void SLL::view(node *r)
{
    if (r == NULL)
        return;
    cout << r->item << " ";
    view(r->next);
}
void SLL::view()
{
    if (start == NULL)
        cout << "List is Empty\n";
    else
    {
        view(start);
    }
    cout << endl;
}
void SLL::view(int pos)
{
    if (start == NULL)
        cout << "List is Empty\n";
    else
    {
        view(start, pos);
    }
    cout << endl;
}
void SLL::view(node *s, int &pos)
{ // pos node from last
    if (s == NULL)
    {
        return;
    }
    view(s->next, pos);
    pos--;
    if (pos == 0)
        cout << s->item << " ";
}

node* SLL::reverse(node *s)
{
    if (s == NULL || s->next == NULL)
        return s;
    node *head = reverse(s->next);
    s->next->next = s;
    s->next = NULL;
    return head;
}
void SLL::reverse(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else
        start = reverse(start);
}
node* SLL::iterativeReverse(){
    node* prev = NULL;
    node* curr = start;
    node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    start = prev;
}
void SLL::insertAtLast(int data)
{
    node *n = new node();
    node *t = start;
    n->item = data;
    n->next = NULL;
    if (start == NULL)
        start = n;
    else
    {
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}
void SLL::insertAtFirst(int data)
{
    node *n = new node();
    n->item = data;
    n->next = start;
    start = n;
}
node *SLL::search(int data)
{
    if (start == NULL)
        cout << "List is Empty\n";
    else
    {
        node *t = start;
        while (t)
        {
            if (t->item == data)
                return t;
            t = t->next;
        }
    }
    cout << "Data Not Found\n";
    return NULL;
}
void SLL::insertAfter(node *r, int data)
{
    node *n = new node();
    n->item = data;
    n->next = r->next;
    r->next = n;
}
void SLL::deleteLastNode()
{
    if (start == NULL)
        cout << "List is Empty\n";
    else
    {
        node *t = start, *t1 = NULL;
        while (t->next != NULL)
        {
            t1 = t;
            t = t->next;
        }
        if (t1 != NULL)
            t1->next = NULL;
        else
            start = NULL;
        delete t;
    }
}
void SLL::deleteFirstNode()
{
    if (start == NULL)
        cout << "List is Empty\n";
    else
    {
        node *t = start;
        start = t->next;
        delete t;
    }
}
void SLL::deleteNode(node *r)
{
    node *t = start;
    if (start == r)
    {
        start = r->next;
    }
    else
    {
        while (t->next != r)
            t = t->next;
        t->next = r->next;
    }
    delete r;
}
int main()
{
    SLL l;
    l.insertAtFirst(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.view();
    l.reverse();
    l.view();
    l.iterativeReverse();
    l.view();
    return 0;
}