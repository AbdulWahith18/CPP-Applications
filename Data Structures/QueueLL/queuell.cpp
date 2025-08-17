#include<iostream>
using namespace std;
class Node;
int count=0;
int maxSize;
Node *Head=NULL;
class Node
{
    int data;
    Node *next;
public:
    Node()
    {
        cout<<"Enter data to be inserted : ";
        cin>>data;
    }
    static int isEmpty()
    {
        if(Head==NULL||count==0)
            return 1;
        else
            return 0;
    }
    static int isFull()
    {
        if(count==maxSize)
            return 1;
        else
            return 0;
    }
    void enqueue()
    {
        if(Head==NULL)
        {
            Head = this;
            this->next=NULL;
            count++;
            cout<<"Successfully enqueued\n";
        }
        else
        {    
            Node *temp=Head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=this;
            this->next=NULL;
            count++;
            cout<<"Successfully enqueued\n";
        }
    }
    static void dequeue()
    {
        if(isEmpty())
        {
            cout<<"\nThe queue is empty cannot be dequeued\n";
        }
        else
        {
            Node* temp=Head;
            Head=temp->next;
            delete temp;
            count--;
            cout<<"Successfully dequeued\n";
        }
    }
    static void display()
    {
        if(Head==NULL||count==0)
        {
            cout<<"\nThe queue is empty\n";
            return;
        }
        Node *temp=Head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
    cout<<"\nEnter the maximum size of queue :";
    cin>>maxSize;

    while(1)
    {
        cout<<"\nEnter the options below to perform:\n";
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Is Empty\n";
        cout<<"4.Is Full\n";
        cout<<"5.Display\n";
        cout<<"6.Exit\n";
        int op;
        cout<<"Enter option : ";
        cin>>op;
        switch(op)
        {
            case 1:
                {
                    if(Node::isFull())
                    {
                        cout<<"The queue is full\n";
                        break;
                    }
                    Node *n = new Node();
                    n->enqueue();
                    break;
                }
            case 2:
                {
                    Node::dequeue();
                    break;
                }
            case 3:
                {
                    if(Node::isEmpty())
                    {
                        cout<<"\nThe queue is empty\n";
                    }
                    else
                    {
                        cout<<"The queue is not empty\n";
                    }
                    break;
                }
            case 4:
                {
                    if(Node::isFull())
                    {
                        cout<<"\nThe queue is full \n";
                    }
                    else
                    {
                        cout<<"\nThe queue is not full\n";
                    }
                    break;
                }
            case 5:
                {
                    Node::display();
                    break;
                }
            case 6:
                {
                    cout<<"\n The program has ended\nThank You!";
                    return 0;
                }
            default:
                {
                    cout<<"\nInvalid option\n";
                }
        }
    }
}