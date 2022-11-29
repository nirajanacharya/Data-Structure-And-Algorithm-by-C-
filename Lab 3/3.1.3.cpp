/*WAP to implement contiguous list using array*/
#include<iostream>
#define max 4
using namespace std;
class List
{
    int avail;
    struct nodeType
    {
        int info;
        int next;
    };
    struct nodeType node [max];
public:
    List()
    {
        avail=0;
        for(int i=0; i<max; i++)
        {
            node[i].next=i+1;
            node[i].info=0;
        }
        node[max-1].next=-1;
    }
    int getnode()
    {
        if (avail==-1)
        {
            cout<<"#############Overflow#############"<<endl;
        }
        else
        {
            int ptr;
            ptr=avail;
            avail=node[ptr].next;
            return ptr;
        }
    }
    void freenode(int ptr)
    {
        node[ptr].next=avail;
        avail=ptr;
    }
    void ins()
    {
        int num,ptr;
        cout<<"Enter the number:\t";
        cin>>num;
        cout<<"\n";
        ptr=getnode();
        if (ptr==0)
        {
            node[ptr].info=num;
            node[ptr].next=-1;
        }
        else
        {
            node[ptr].info=num;
            node[ptr].next=-1;
            bool test=true;
            int temp=0;
            while(test)
            {
                if (node[temp].next==-1)
                {
                    test=false;
                    node[temp].next=ptr;
                }
                temp=node[temp].next;
            }
        }
    }
    void insafter()
    {
        int num,ptr,pos;
        cout<<"\nEnter n-1 position:\t";
        cin>>pos;
        cout<<"Enter the number:\t";
        cin>>num;
        cout<<"\n";
        ptr=getnode();
        if ((ptr==-1)||(ptr>max-1))
        {
            cout<<"#########Invalid############"<<endl;
        }
        else
        {
            node[ptr].info=num;
            node[ptr].next=node[pos].next;
            node[pos].next=ptr;
        }
    }
    void del()
    {
        int pos;
        cout<<"Enter n position:\t";
        cin>>pos;
        cout<<"\n";
        node[pos].info=0;
        bool test=true;
        int temp=0;
        if(pos==-1  || pos>max-1)
        {
            cout<<"#####Cant  REMOVE#####"<<endl;
        }
        else
        {
            while (test)
            {
                if (node[temp].next==pos)
                {
                    test=false;
                    node[temp].next=node[pos].next;
                }
                temp=node[temp].next;
            }
        }
        freenode(pos);
    }
    void delafter()
    {
        int pos;
        cout<<"Enter n-1 position:\t";
        cin>>pos;
        cout<<"\n";
        if (pos==-1 || pos>max-1)
        {
            cout<<"####### Can't remove##########";
        }
        else
        {
            int delptr=node[pos].next;
            node[delptr].info=0;
            node[pos].next=node[delptr].next;
            freenode(delptr);
        }
    }
    void display()
    {
        cout<<"--------------------------------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tavail= "<<avail<<endl;
        cout<<"Node\t\t\t\t\tInfo\t\t\t\t\tNext"<<endl;
        for (int i=0; i<max; i++)
        {
            cout<<i<<"\t\t\t\t\t"<<node[i].info<<"\t\t\t\t\t"<<node[i].next<<endl;
        }
        cout<<"--------------------------------------"<<endl;
        cout<<"--------------------------------------"<<endl;
    }
};
int main()
{
    int option;
    List lobj;
    do
    {
        cout<<"Choose:\n1.Insert\n2.Delete\n3.Insert After\n4.Delete After\n5.Exit"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
        {
            lobj.ins();
            break;
        }
        case 2:
        {
            lobj.del();
            break;
        }
        case 3:
        {
            lobj.insafter();
            break;
        }
        case 4:
        {
            lobj.delafter();
            break;
        }
        default:
            cout<<"****************Exiting**************"<<endl;
        }
        lobj.display();
    }
    while(option!=5);
    return 0;
}
