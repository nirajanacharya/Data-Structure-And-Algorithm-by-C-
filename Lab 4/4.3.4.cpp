/*WAP to implement doubly linked list */
#include<iostream>
using namespace std;
class linkList
{
    struct Node
    {
        Node *prev;
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
            while(p!=NULL)
            {
                q=p;
                p=p->next;
                delete q;
            }
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
        nodeptr p;
        if(head==NULL)
        {
            ins(new_data);
        }
        else
        {
            p=new Node;
            p->prev=NULL;
            p->data= new_data;
            p->next=head;
            head->prev=p;
            head=p;
        }
    }
    void ins(int new_data)     //insert at the last
    {
        nodeptr p;
        nodeptr ptr=head;
        if(head==NULL)
        {
            p=new Node;
            p->prev=NULL;
            p->next=NULL;
            p->data=new_data;
            head=p;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            p=new Node;
            p->prev=ptr;
            ptr->next=p;
            p->data =new_data;
            p->next =NULL;
        }
    }
    void ins_after(int old_data,int new_data)    //insert after certain data
    {
        nodeptr p;
        nodeptr ptr=head;
        while(ptr->data!=old_data)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                cout<<"error data not found";
                return;//exit(1);
            }
        }
        p=new Node;
        p->prev=ptr;
        p->next =ptr->next;
        ptr->next=p;
        ptr->next->prev=p;
        p->data =new_data;
    }
    void ins_bef(int old_data,int new_data)    //insert before certain data
    {
        nodeptr p;
        nodeptr ptr=head;
        if(ptr->data==old_data)
        {
            push(new_data);
        }
        else
        {
            while(ptr->data!=old_data)
            {
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    cout<<"error data not found";
                    return;//exit(1);
                }
            }
            p=new Node;
            p->prev=ptr->prev;
            p->next =ptr;
            ptr->prev=p;
            p->prev->next=p;
            p->data =new_data;
        }
    }
    void pop()            // delete from the front
    {
        nodeptr ptr=head;
        if(head!=NULL)
        {
            head=ptr->next;
            head->prev=NULL;
            delete ptr;
        }
        else
        {
            cout<<"Empty"<<endl;
        }
    }
    void del_data(int old_data)     // delete the specified data
    {
        nodeptr ptr=head;
        //nodeptr preptr=ptr;
        if(head!=NULL)
        {
            while(ptr->data!=old_data)
            {
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    cout<<"data not found"<<endl;
                    return;//exit(1);
                }
            }
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            delete ptr;
        }
    }
    void del_last()      //delete the last data
    {
        if(head!=NULL)
        {
            nodeptr ptr=head;
            //nodeptr preptr=ptr;
            if(head!=NULL)
            {
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->prev->next=NULL;
                delete ptr;
            }
        }

    }
    void del_after(int old_data)     // delete data after the specified data
    {
        nodeptr ptr=head,p;
        //nodeptr preptr=ptr;
        if(head!=NULL)
        {
            while(ptr->data!=old_data)
            {
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    cout<<"data not found"<<endl;
                    return;//exit(1);
                }
            }
            p=ptr->next;
            ptr->next=p->next;
            p->next->prev=ptr;
            delete p;
        }
    }
    void del_before(int old_data)     // delete data before the specified data
    {
        nodeptr ptr=head,p;
        //nodeptr preptr=ptr;
        if(head!=NULL)
        {
            while(ptr->data!=old_data)
            {
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    cout<<"data not found"<<endl;
                    return;//exit(1);
                }
            }
            p=ptr->prev;
            ptr->prev=p->prev;
            p->prev->next=ptr;
            delete p;
        }
    }
    void display()
    {
        nodeptr p=head;
        cout<<"\n\t=================X================"<<endl;
        cout<<"\taddress"<<"\t\tdata"<<"\tnext"<<endl;
        while(p!=NULL)
        {
            cout<<"\t"<<p<<"\t"<<p->data<<"\t"<<p->next<<endl;
            p=p->next;
        }
        if(head==NULL)
        {
            cout<<"\tEmpty"<<endl;
        }
        cout<<"\tthats it"<<endl;
        cout<<"\t=================X================\n"<<endl;
    }
    void displaydetail()      // display the list
    {
        nodeptr p=head;
        cout<<"\n\t==========================X==========================="<<endl;
        //cout<<"\tprev\t\taddress\t\tdata\tnext"<<endl;
        while(p!=NULL)
        {

            cout<<"\tpre: "<<p->prev<<"\t\tadd: "<<p<<"\t\tval: "<<p->data<<"\t\tnex: "<<p->next<<endl;
            p=p->next;
        }
        if(head==NULL)
        {
            cout<<"\t\t\tEmpty"<<endl;
        }
        cout<<"\t\t\tthats it"<<endl;
        cout<<"\t==========================X===========================\n"<<endl;
    }
};
int main()
{
    linkList li;
    int x,a;
    int choice=0;
    while(choice!=12)
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
        cout<<"9-delete before value a"<<endl;
        cout<<"10-delete all list"<<endl;
        cout<<"11-display detailed"<<endl;
        cout<<"12-Exit\n"<<endl;
        cout<<"*** auto display doesnt show previous address so try option 11 to see it***"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        system("CLS");
        if(choice<10)
        {
            cout<<"\tBEFORE LIST";
            li.display();
        }
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
            cout<<"Inserting after: ";
            cin>>a;
            cout<<"enter data to insert: ";
            cin>>x;
            li.ins_after(a,x);
            break;
        case 4:
            cout<<"inserting before: ";
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
            cout<<"delete Value: ";
            cin>>a;
            li.del_data(a);
            break;
        case 8:
            cout<<"Delete after : ";
            cin>>a;
            li.del_after(a);
            break;
        case 9:
            cout<<"Delete before : ";
            cin>>a;
            li.del_before(a);
            break;
        case 10:
        case 12:
            li.del_list();
            cout<<"this list is deleted!!\n"<<endl;
            break;
        case 11:
            li.displaydetail();

        }
        if(choice<10)
        {
            cout<<"\tAFTER LIST";
            li.display();
        }
    }
    cout<<"\n============X==========="<<endl;
    cout<<"\t THANK YOU "<<endl;
    return 0;
}

