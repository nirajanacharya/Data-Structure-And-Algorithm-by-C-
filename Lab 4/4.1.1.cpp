/*WAP to implement singly linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *next;
};
class Slist
{
    node *START;
public:
    Slist():START(NULL) {}
    void InsertNodeAtBegining(int val)
    {
        node *temp = new node;
        if(temp==NULL)
        {
            cout<<"\nFailed to initialize memory for new node\n\n";
        }
        else
        {
            temp->info=val;
            if(START==NULL)
            {
                START=temp;
                START->next=NULL;
            }
            else
            {
                temp->next=START;
                START=temp;
            }
        }
    }
    void InsertNodeAtLast(int val)
    {
        node *temp = new node;
        if(temp==NULL)
        {
            cout<<"\nFailed to initialize memory for new node\n\n";
        }
        else
        {
            temp->info=val;
            temp->next=NULL;
            if(START==NULL)
            {
                START=temp;
            }
            else
            {
                node *point;
                point=START;
                while(point->next!=NULL)
                {
                    point=point->next;
                }
                point->next=temp;
            }
        }
    }
    void InsertNodeBeforeGivenData(int data,int val)
    {
        if(START->info==data)
            InsertNodeAtBegining(val);
        else
        {
            int c=0;
            node *ptr,*preptr;
            preptr=START;
            ptr=START->next;
            while(ptr!=NULL)
            {
                if(ptr->info==data)
                {
                    c=1;
                    node *temp = new node;
                    if(temp==NULL)
                    {
                        cout<<"\nFailed to initialize memory for new node\n\n";
                        break;
                    }
                    else
                    {
                        temp->info=val;
                        preptr->next=temp;
                        temp->next=ptr;
                        break;
                    }
                }
                else
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
            }
            if(c==0)
                cout<<"\n\nThere is no matching data in linked list\n\n";
        }
    }
    void InsertNodeAfterGivenData(int data,int val)
    {
        int c=0;
        node *ptr;
        ptr=START;
        while(ptr!=NULL)
        {
            if(ptr->info==data)
            {
                c=1;
                node *temp = new node;
                if(temp==NULL)
                {
                    cout<<"\nFailed to initialize memory for new node\n\n";
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
            cout<<"\n\nThere is no matching data in linked list\n\n";
    }
    void DeleteFirstNode()
    {
        if(START==NULL)
            cout<<"\n\nThere is no list\n\n";
        else if(START->next==NULL)
        {
            cout<<"\n\nThe deleted value of node is : "<<START->info<<endl<<endl;
            delete START;
            START=NULL;
        }
        else
        {
            node *temp;
            temp=START;
            START=START->next;
            cout<<"\n\nThe deleted value of node is : "<<temp->info<<endl<<endl;
            delete temp;
        }
    }
    void DeleteLastNode()
    {
        if(START==NULL)
            cout<<"\n\nThere is no list\n\n";
        else
        {
            if(START->next==NULL)
            {
                cout<<"\n\nThe deleted value of node is : "<<START->info<<endl<<endl;
                delete START;
                START=NULL;
            }
            else
            {
                node *preptr,*ptr;
                preptr=START;
                ptr=START->next;
                while(ptr->next!=NULL)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                preptr->next=NULL;
                cout<<"\n\nThe deleted value of node is : "<<ptr->info<<endl<<endl;
                delete ptr;
            }
        }
    }
    void DeleteNodeBeforeGivenData(int data)
    {
        if(START->info==data)
            cout<<"\n\nThere is no node before given data\n\n";
        else if(START->next->info==data)
        {
            node *temp;
            temp=START;
            START=START->next;
            cout<<"\n\nThe deleted value of node is :  "<<temp->info<<endl<<endl;
            delete temp;
        }
        else
        {
            int c=0;
            node *ptr,*preptr;
            preptr=START;
            ptr=START->next;
            while(ptr->next!=NULL)
            {
                if(ptr->next->info==data)
                {
                    preptr->next=ptr->next;
                    cout<<"\n\nThe deleted value of node is :  "<<ptr->info<<endl<<endl;
                    delete ptr;
                    c=1;
                    break;
                }
                else
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
            }
            if(c==0)
                cout<<"\n\nThere is no matching data in linked list\n\n";
        }
    }
    void DeleteNodeAfterGivenData(int data)
    {
        int c=0;
        node *ptr;
        ptr=START;
        while(ptr!=NULL)
        {
            if(ptr->info==data)
            {
                c=1;
                if(ptr->next==NULL)
                {
                    cout<<"\n\nThere is no node after given data\n\n";
                    break;
                }
                else
                {
                    node *temp;
                    temp=ptr->next;
                    ptr->next=temp->next;
                    cout<<"\n\nThe deleted value of node is :  "<<temp->info<<endl<<endl;
                    delete temp;
                    break;
                }
            }
            else
                ptr=ptr->next;
        }
        if(c==0)
            cout<<"\n\nThere is no matching data in linked list\n\n";
    }
    bool display()
    {
        if(START==NULL)
        {
            cout<<"\n\nThere is no existing linked list\n\n";
            return false;
        }
        else
        {
            cout<<"\n\nThe linked list is : "<<endl;
            node *ptr;
            ptr=START;
            while(ptr!=NULL)
            {
                cout<<ptr->info<<"\t";
                ptr=ptr->next;
            }
            cout<<"\n\n";
            return true;
        }
    }
};
int main()
{
    Slist l;
    int choice,data,val;
    while(1)
    {
        cout<<"1. Insert Node at begining\n2. Insert node at last\n3. Insert node before given data\n4. Insert node after given data\n5. Delete first node\n6. Delete last node\n7. Delete node before given data\n8. Delete node after given data\n9. Display singly linked list\n10. Exit\nEnter your choice : ";
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
