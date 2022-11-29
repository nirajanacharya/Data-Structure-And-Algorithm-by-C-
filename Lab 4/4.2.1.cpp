/*WAP to implement circular linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *next;
};
class CSlist
{
    node *last;
public:
    CSlist():last(NULL) {}
    void InsertNodeAtBegining(int );
    void InsertNodeAtLast(int );
    void InsertNodeBeforeGivenData(int,int );
    void InsertNodeAfterGivenData(int,int);
    void DeleteFirstNode();
    void DeleteLastNode();
    void DeleteNodeBeforeGivenData(int );
    void DeleteNodeAfterGivenData(int);
    bool display();
};
void CSlist::InsertNodeAtBegining(int val)
{
    node *temp=new node;
    if(temp==NULL)
        cout<<"\n\nFailed to initialize memory for new node\n\n";
    else
    {
        temp->info=val;
        if(last==NULL)
        {
            temp->next=temp;
            last=temp;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
        }
    }
}
void CSlist::InsertNodeAtLast(int val)
{
    node *temp=new node;
    if(temp==NULL)
        cout<<"\n\nFailed to initialize memory for new node\n\n";
    else
    {
        temp->info=val;
        if(last==NULL)
        {
            temp->next=temp;
            last=temp;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
            last=temp;
        }
    }
}
void CSlist::InsertNodeBeforeGivenData(int data,int val)
{
    if(last->next->info==data)
        InsertNodeAtBegining(val);
    else
    {
        int c=0;
        node *ptr;
        ptr=last->next;
        while(ptr!=last)
        {
            if(ptr->next->info==data)
            {
                c=1;
                node *temp=new node;
                if(temp==NULL)
                {
                    cout<<"\n\nFailed to initialize the memory for new node.\n\n";
                    break;
                }
                else
                {
                    temp->info=val;
                    temp->next=ptr->next;
                    ptr->next=temp;
                    break;
                }
            }
            else
                ptr=ptr->next;
        }
        if(c==0)
            cout<<"\n\nThere is no matching data in linked list.\n\n";
    }
}
void CSlist::InsertNodeAfterGivenData(int data,int val)
{
    if(last->info==data)
        InsertNodeAtLast(val);
    else
    {
        int c=0;
        node *ptr;
        ptr=last->next;
        while(ptr!=last)
        {
            if(ptr->info==data)
            {
                c=1;
                node *temp=new node;
                if(temp==NULL)
                {
                    cout<<"\n\nFailed to initialize the memory for new node.\n\n";
                    break;
                }
                else
                {
                    temp->info=val;
                    temp->next=ptr->next;
                    ptr->next=temp;
                    break;
                }
            }
            else
                ptr=ptr->next;
        }
        if(c==0)
            cout<<"\n\nThere is no matching data in the linked list.\n\n";
    }
}
void CSlist::DeleteFirstNode()
{
    if(last==NULL)
        cout<<"\n\nThere is no existing list.\n\n";
    else if(last->next==last)
    {
        cout<<"\n\nThe deleted value of first node is : "<<last->info<<"\n\n";
        delete last;
        last=NULL;
    }
    else
    {
        node *temp;
        temp=last->next;
        last->next=last->next->next;
        cout<<"\n\nThe deleted value of node is : "<<temp->info<<"\n\n";
        delete temp;
    }
}
void CSlist::DeleteLastNode()
{
    if(last==NULL)
        cout<<"\n\nThere is no existing list.\n\n";
    else if(last->next==last)
    {
        cout<<"\n\nThe deleted value of last node is : "<<last->info<<"\n\n";
        delete last;
        //cout<<"\n\nThe deleted value of last node is : "<<last->info<<"\n\n";
        last=NULL;
    }
    else
    {
        node *temp;
        temp=last->next;
        while(temp->next!=last)
            temp=temp->next;
        temp->next=last->next;
        cout<<"\n\nThe deleted value of node is : "<<last->info<<"\n\n";
        delete last;
        last=temp;
    }
}
void CSlist::DeleteNodeBeforeGivenData(int data)
{
    if(last->next->info==data)
        DeleteLastNode();
    else
    {
        int c=0;
        node *ptr,*preptr;
        preptr=ptr=last->next;
        while(ptr->next!=last->next)
        {
            if(ptr->next->info==data)
            {
                c=1;
                preptr->next=ptr->next;
                cout<<"\n\nThe deleted value is : "<<ptr->info<<"\n\n";
                delete ptr;
                break;
            }
            else
            {
                preptr=ptr;
                ptr=ptr->next;
            }
        }
        if(c==0)
            cout<<"\n\nThere is no matching data in the linked list.\n\n";
    }
}
void CSlist::DeleteNodeAfterGivenData(int data)
{
    if(last->info==data)
        DeleteFirstNode();
    else
    {
        int c=0;
        node *ptr;
        ptr=last->next;
        while(ptr!=last)
        {
            if(ptr->info==data)
            {
                c=1;
                if(ptr->next==last)
                {
                    ptr->next=last->next;
                    cout<<"\n\nThe deleted value of node is : "<<last->info<<"\n\n";
                    delete last;
                    last=ptr;
                    break;
                }
                else
                {
                    node *temp;
                    temp=ptr->next;
                    ptr->next=ptr->next->next;
                    cout<<"\n\nThe deleted value of node is : "<<temp->info<<"\n\n";
                    delete temp;
                    break;
                }
            }
            else
                ptr=ptr->next;
        }
        if(c==0)
            cout<<"\n\nThere is no matching data in the linked list.\n\n";
    }
}
bool CSlist::display()
{
    if(last==NULL)
    {
        cout<<"\n\nThere is no existing list.\n\n";
        return false;
    }
    else
    {
        node *temp;
        temp=last->next;
        cout<<"\n\nElements of linked list are :\n";
        do
        {
            cout<<temp->info<<"\t";
            temp=temp->next;
        }
        while(temp!=last->next);
        cout<<"\n\n";
    }
}
int main()
{
    CSlist l;
    int choice,data,val;
    while(1)
    {
        cout<<"1. Insert Node at begining\n2. Insert node at last\n3. Insert node before given data\n4. Insert node after given data\n5. Delete first node\n6. Delete last node\n7. Delete node before given data\n8. Delete node after given data\n9. Display circular singly linked list\n10. Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"\nEnter the value : ";
            cin>>val;
            l.InsertNodeAtBegining(val);
            break;
        }
        case 2:
        {
            cout<<"\nEnter the value :";
            cin>>val;
            l.InsertNodeAtLast(val);
            break;
        }
        case 3:
        {
            if(l.display())
            {
                cout<<"\nEnter the value of node before you want to insert new node: ";
                cin>>data;
                cout<<"\nEnter the value for new node : ";
                cin>>val;
                l.InsertNodeBeforeGivenData(data,val);
            }
            break;
        }
        case 4:
        {
            if(l.display())
            {
                cout<<"\nEnter the value of node after you want to insert new node: ";
                cin>>data;
                cout<<"\nEnter the value for new node : ";
                cin>>val;
                l.InsertNodeAfterGivenData(data,val);
            }
            break;
        }
        case 5:
        {
            l.DeleteFirstNode();
            break;
        }
        case 6:
        {
            l.DeleteLastNode();
            break;
        }
        case 7:
        {
            if(l.display())
            {
                cout<<"\nEnter the value of node who's previous node you want to delete : ";
                cin>>data;
                l.DeleteNodeBeforeGivenData(data);
            }
            break;
        }
        case 8:
        {
            if(l.display())
            {
                cout<<"\nEnter the value of node who's next node you want to delete : ";
                cin>>data;
                l.DeleteNodeAfterGivenData(data);
            }
            break;
        }
        case 9:
        {
            bool a=l.display();
            break;
        }
        default :
            exit(0);
        }
    }
    return 0;
}
