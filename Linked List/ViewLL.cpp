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






int main()
{
    
    return 0;
}