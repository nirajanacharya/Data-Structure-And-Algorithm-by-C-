/*WAP to implement circular linked list */
#include<iostream>
using namespace std;
class linkList
{
    struct Node
    {
        int data;
        Node *next;
    };
    typedef struct Node* nodeptr;
    nodeptr head;
public:
    linkList()      //constructor
    {
        head=NULL;
    }
    void del_list()     //delete whole list
    {
        if(head!=NULL)
        {
            nodeptr p,q;
            p=head;
            do
            {
                q=p;
                p=p->next;
                delete q;
            }
            while(p!=head);
            head=NULL;
        }
    }
    void create()            // create linked list having some data
    {
        nodeptr ptr=head;
        int val=0;
        cout<<"insert and end with -1"<<endl;
        cin>>val;

        while(val!=-1)
        {
            ins(val);
            cin>>val;
        }
    }
    void push(int new_data)    // insert at the front
    {
        nodeptr p,ptr;
        p=new Node;
        p->data= new_data;
        p->next=head;
        ptr=head;
        if(head==NULL)
        {
            ins(new_data);
        }
        else
        {
            while(ptr->next!=head)      // for changing next of last
            {
                ptr=ptr->next;
            }
            head=p;
            ptr->next=head;
        }
    }
    void ins(int new_data)     //insert at the last
    {
        nodeptr p;
        nodeptr ptr=head;
        if(head==NULL)
        {
            p= new Node;
            p->data= new_data;
            p->next=p;
            head=p;
        }
        else
        {
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            p=new Node;
            ptr->next=p;
            p->data =new_data;
            p->next =head;
        }
    }
    void ins_after(int old_data,int new_data)    //insert after certain data
    {
        nodeptr p;
        nodeptr ptr=head;
        while(ptr->data!=old_data)
        {
            ptr=ptr->next;
            if(ptr==head)
            {
                cout<<"error data not found";
                return;
            }
        }
        p=new Node;
        p->next =ptr->next;
        ptr->next=p;
        p->data =new_data;
    }
    void ins_bef(int old_data,int new_data)    //insert before certain data
    {
        nodeptr p,preptr;
        nodeptr ptr=head;
        if(ptr->data==old_data)
        {
            push(new_data);
        }
        else
        {
            while(ptr->data!=old_data)
            {
                preptr=ptr;
                ptr=ptr->next;
                if(ptr==head)
                {
                    cout<<"error data not found";
                    return ;
                }
            }
            p=new Node;
            p->next =ptr;
            preptr->next=p;
            p->data =new_data;
        }
    }
    void pop()            // delete from the front
    {
        nodeptr ptr=head;
        nodeptr p;
        if(head->next==head)
        {
            delete ptr;
            head=NULL;
        }
        else
        {
            p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=ptr->next;
        }
        if(head!=NULL)
        {
            head=ptr->next;
            delete ptr;
        }
    }
    void del_data(int old_data)     // delete the specified data
    {
        nodeptr ptr=head;
        nodeptr preptr=ptr;
        if(head!=NULL && head->data!=old_data)
        {
            while(ptr->data!=old_data)
            {
                preptr=ptr;
                ptr=ptr->next;
                if(ptr==head)
                {
                    cout<<"data not found"<<endl;
                    return;
                }
            }
            preptr->next=ptr->next;
            delete ptr;
        }
        else if(head->data==old_data)
        {
            pop();
        }
    }
    void del_last()      //delete the last data
    {
        if(head!=NULL)
        {
            nodeptr ptr=head;
            nodeptr preptr=ptr;
            if(head->next==head)
            {
                del_list();
            }
            else if(head!=NULL)
            {
                while(ptr->next!=head)
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
                preptr->next=head;
                delete ptr;
            }
        }
    }
    void del_after(int old_data)     // delete data after the specified data
    {
        nodeptr ptr=head;
        nodeptr preptr=ptr;
        ptr=ptr->next;
        if(head!=NULL)
        {
            while(preptr->data!=old_data)
            {
                preptr=ptr;
                ptr=ptr->next;
                if(ptr==head)
                {
                    cout<<"data not found"<<endl;
                    return;
                }
            }
            preptr->next=ptr->next;
            delete ptr;
        }
    }
    void display()      // display the list
    {
        nodeptr p=head;
        cout<<"\n\t=================X================"<<endl;
        if(head==NULL)
        {
            cout<<"\t\tEmpty"<<endl;
        }
        else
        {
            cout<<"\taddress"<<"\t\tdata"<<"\tnext"<<endl;
            do
            {
                cout<<"\t"<<p<<"\t"<<p->data<<"\t"<<p->next<<endl;
                p=p->next;
            }
            while(p!=head);
        }
        cout<<"\tthats it"<<endl;
        cout<<"\t=================X================\n"<<endl;
    }
};
int main()
{
    linkList li;
    int x,a;
    int choice=0;
    while(choice!=10)
    {
        cout<<"\n\nyour Choice please: "<<endl;
        cout<<"0-create "<<endl;
        cout<<"1-inserting infront of list "<<endl;
        cout<<"2-inserting at the end "<<endl;
        cout<<"3-inserting after value a "<<endl;
        cout<<"4-inserting before value a "<<endl;
        cout<<"5-delete from front "<<endl;
        cout<<"6-delete from the last "<<endl;
        cout<<"7-delete value a"<<endl;
        cout<<"8-delete after value a"<<endl;
        cout<<"9-delete all list"<<endl;
        cout<<"10-Exit\n\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        system("CLS");
        cout<<"\tBEFORE LIST";
        li.display();
        switch (choice)
        {
        case 0:
            li.create();
            break;
        case 1:
            cout<<"enter data to insert: ";
            cin>>x;
            li.push(x);
            break;
        case 2:
            cout<<"enter data to insert: ";
            cin>>x;
            li.ins(x);
            break;
        case 3:
            cout<<"insert after: ";
            cin>>a;
            cout<<"enter data to insert: ";
            cin>>x;
            li.ins_after(a,x);
            break;
        case 4:
            cout<<"insert before: ";
            cin>>a;
            cout<<"enter data to insert: ";
            cin>>x;
            li.ins_bef(a,x);
            break;
        case 5:
            li.pop();
            break;
        case 6:
            li.del_last();
            break;
        case 7:
            cout<<"delete value: ";
            cin>>a;
            li.del_data(a);
            break;
        case 8:
            cout<<"Delete after: ";
            cin>>a;
            li.del_after(a);
            break;
        case 9:
        case 10:
            li.del_list();
            cout<<"this list is deleted!!"<<endl;
            break;
        }
        cout<<"\tAFTER LIST";
        li.display();
    }
    cout<<"\n============X==========="<<endl;
    cout<<"\t THANK YOU "<<endl;
    return 0;
}
