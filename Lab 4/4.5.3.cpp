/*WAP to implement STACK using linked list */
#include<iostream>
using namespace std;
class Stack
{
    struct node
    {
        int data;
        struct node * next;
    };
public:
    struct node * start;
    struct node * newnode,* temp,* ptr,* preptr;
    void creation()
    {
        newnode = new node;
        cout<<"Enter the data for the stack(insert -1 to end the ): ";
        cin>>newnode->data;
        newnode->next=NULL;
        if (start==NULL)
        {
            start=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        do
        {
            push();
        }
        while (newnode->data!=-1);
    }
    void push()
    {
        newnode=new node;
        cout<<"Enter the data to be stored at the top: ";
        cin>>newnode->data;
        if (newnode->data!=-1)
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
    }
    void pop()
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        cout<<"The deleted value is: "<<ptr->data;
        delete ptr;
        preptr->next=NULL;
    }
    void peek()
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        cout<<"Value at the top = "<<ptr->data;
    }
    void display_stack()
    {
        ptr=start;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"\n\nThe stack is: "<<endl;
        cout<<"\t\t\t"<<ptr->data<<endl;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            cout<<"\t\t\t"<<ptr->data<<endl;
        }
        cout<<endl;
        cout<<"Note: top is at the bottom"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
    }
};
int main()
{
    class Stack st;
    st.start=NULL;
    int choice=0,c=0;
    while(choice!=10)
    {
        c++;
        cout<<"\n\nyour Choice please: "<<endl;
        if (c==1)
        {
            cout<<"0-Creating a new Stack "<<endl;
        }
        cout<<"1-Push "<<endl;
        cout<<"2-Pop "<<endl;
        cout<<"3-Peek "<<endl;
        cout<<"10-Exit.\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        switch (choice)
        {
        case 0:
            st.creation();
            break;
        case 1:
            st.push();
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        }
        st.display_stack();
    }
    cout<<"THANK YOU";
}
