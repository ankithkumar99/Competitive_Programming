// LINKED LIST IMPLEMENTATION

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Linked_List{
    private:
    Node *head, *tail;

    public:
    Linked_List(){
        head = NULL;
        tail = NULL;
    }

    void insert_last(int data){
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }

    void insert_first(int data){
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void print_list(){
        Node* node = head;
        while(node != NULL){
            cout << node->data << " ";
            node = node->next;
        }
    }
};

int main()
{
    Linked_List a;
    a.insert_last(1);
    a.insert_last(2);
    a.insert_first(0);
    a.print_list();
    return 0;
}