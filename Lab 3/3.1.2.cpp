/*WAP to implement contiguous list using array*/
#include<iostream>
#include<cstdlib>
#define MAX 10
using namespace std;
int avail =0;
struct nodetype
{
    int info,next;
};
class List
{
    nodetype node[MAX];
    int root;
    int getnode()
    {
        int p;
        if(avail==-1)
        {
            cout<<"\nOverflow\n";
            return -1;
        }
        p=avail;
        avail=node[avail].next;
        return p;
    }
    void freenode(int p)
    {
        node[p].info=-11;  /** -11 denotes empty*/
        node[p].next=avail;
        avail=p;
    }
    bool checklist()
    {
        if(root!=-1)
        {
            char ch;
            cout<<"\n\aThere is an existing node !!!   Do you want to replace it? y/n ";
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                Initializearray();
                return true;
            }
            else
                return false;
        }
        else
            return true;
    }
    void Initializearray()
    {
        for(int i=0; i<=MAX-1; i++)
        {
            node[i].info=-11;   /** -11 denotes empty*/
            node[i].next=i+1;
        }
        node[MAX-1].next=-1;
    }
public:
    List():root(-1)
    {
        Initializearray();
    }
    void createlist()
    {
        if(checklist())
        {
            root = getnode();
            int num,ptr,point=root;
            cout<<"\nEnter the value of node : ";
            cin>>node[root].info;
            node[root].next=-1;
            while(1)
            {
                cout<<"\nEnter -1 to end input\nEnter the value : ";
                cin>>num;
                if(num==-1)
                    break;
                ptr=getnode();
                node[point].next=ptr;
                point=ptr;
                node[ptr].info=num;
                node[ptr].next=-1;
            }
        }
    }
    void inslast(int num)
    {
        if(root==-1)
            cout<<"\nThere is no existing list\n";
        else
        {
            int ptr=root;
            while(node[ptr].next!=-1)
                ptr=node[ptr].next;
            node[ptr].next=getnode();
            ptr=node[ptr].next;
            node[ptr].info=num;
            node[ptr].next=-1;
        }
    }
    void insafter ( int ptr, int val)
    {
        int newptr;
        if(ptr == MAX-1)
        {
            cout<<"\nInvalid Insertion\n";
        }
        else
        {
            newptr = getnode();
            if(newptr==-1)
            {
                cout<<"\nThere is no new available node\n";
            }
            else
            {
                node[newptr].info = val;
                int point=root;
                for(int i=1; i<ptr; i++)
                {
                    point=node[point].next;
                }
                node[newptr].next = node[point].next;
                node[point].next = newptr;
            }
        }
    }
    void dellast()
    {
        if(root==-1)
            cout<<"\nThere is no existing list\n";
        else
        {
            if(node[root].next==-1)
            {
                cout<<"\nThe deleted value is : "<<node[root].info<<"\n\n";
                freenode(root);
                root=-1;
            }
            else
            {
                int point,ptr;
                point=ptr=root;
                while(node[ptr].next!=-1)
                {
                    point=ptr;
                    ptr=node[ptr].next;
                }
                node[point].next=-1;
                cout<<"\nThe deleted value is : "<<node[ptr].info<<endl;
                freenode(ptr);
            }
        }
    }
    void delafter(int ptr)
    {
        int delptr,delval;
        if((ptr== MAX-1)||node[ptr].next== -1)
            cout<<"\nInvalid deletion after the given pointer\n";
        else
        {
            int point=root;
            for(int i=1; i<ptr; i++)
            {
                point=node[point].next;
            }

            delptr=node[point].next;
            delval=node[delptr].info;
            cout<<"\nThe deleted value is : "<<delval<<endl;
            node[point].next=node[delptr].next;
            freenode(delptr);
        }
    }
    void displaylist()
    {
        if(root==-1)
            cout<<"\n\nThere is no existing list\n\n";
        else
        {
            int ptr=root;
            cout<<"\n\nThe list is : \n";
            while(node[ptr].next!=-1)
            {
                cout<<node[ptr].info<<"\t";
                ptr=node[ptr].next;
            }
            cout<<node[ptr].info<<"\n\n";
        }
    }
    void displayarr()
    {
        cout<<"\n\nIndex\tValue\tNext\n";
        for(int i=0; i<MAX; i++)
        {
            cout<<i<<"\t"<<node[i].info<<"\t"<<node[i].next<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    List l;
    int choice,num,ptr;
    while(1)
    {
        cout<<"1. Create a list\n2. Insert node at last\n3. Insert node after certain node\n4. Delete last node\n5. Delete node after certain node\n6. Display list\n7. Display array\n8. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            l.createlist();
            break;
        case 2:
        {
            cout<<"\nEnter the value : ";
            cin>>num;
            l.inslast(num);
            break;
        }
        case 3:
        {
            cout<<"\nEnter the node : ";
            cin>>ptr;
            cout<<"\nEnter the value : ";
            cin>>num;
            l.insafter(ptr,num);
            break;
        }
        case 4:
            l.dellast();
            break;
        case 5:
        {
            cout<<"\nEnter the node : ";
            cin>>ptr;
            l.delafter(ptr);
            break;
        }
        case 6:
            l.displaylist();
            break;
        case 7:
            l.displayarr();
            break;
        default :
            exit(0);
        }
    }
}
