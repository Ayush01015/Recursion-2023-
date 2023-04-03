#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class SLL{
    node *start;
    public:
        SLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteLastNode();
        void deleteFirstNode();
        void deleteNode(node*);
};
SLL::SLL(){
    start = NULL;
}
void SLL::view(){
    node *t = start;
    while(t){
        cout<<t->item<<" ";
        t=t->next;
    }
    cout<<endl;
}
void SLL::insertAtLast(int data){
    node *n = new node();
    node *t = start;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else{
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
void SLL::insertAtFirst(int data){
    node *n = new node();
    n->item = data;
    n->next = start;
    start = n;   
}
node* SLL::search(int data){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t){
            if(t->item==data)
                return t;
            t=t->next;
        }
    }
    cout<<"Data Not Found\n";
    return NULL;
}
void SLL::insertAfter(node *r,int data){
    node *n = new node();
    n->item = data;
    n->next = r->next;
    r->next = n;
}
void SLL::deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start, *t1 = NULL;
        while(t->next!=NULL){
            t1 = t;
            t = t->next;
        }
        if(t1!=NULL)
            t1->next = NULL;
        else
            start = NULL;
        delete t;
    }
}
void SLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        start = t->next;
        delete t;
    }
}
void SLL::deleteNode(node *r){
    node *t = start;
    if(start == r){
        start = r->next;
    }else{
        while(t->next!=r)
            t=t->next;
        t->next = r->next;
    }
    delete r;
}
int main()
{
    
    return 0;
}