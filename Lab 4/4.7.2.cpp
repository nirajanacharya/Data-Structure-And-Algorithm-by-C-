/*Write a program to store a polynomial using linked list. Also, perform addition and subtraction on two polynomials*/
#include<iostream>
#include<cmath>
using namespace std;
struct Term
{
    float coef;
    float x_index;
    float y_index;
    float z_index;
    Term *next;
};
class Polynomial
{
public:
    Term *head;
    Polynomial()
    {
        head = NULL;
    }
    void assign_polynomial(float c, float x, float y, float z)
    {
        Term *newTerm= new Term;
        newTerm->coef = c;
        newTerm->x_index = x;
        newTerm->y_index = y;
        newTerm->z_index = z;
        if(head == NULL)
        {
            head = newTerm;
            head->next = NULL;
        }
        else
        {
            Term *ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newTerm;
            newTerm->next = NULL;
        }
    }
    Polynomial& operator+(Polynomial& P2)
    {
        Polynomial P3;
        Term *ptr2 = P2.head;
        while(ptr2 != NULL)
        {
            Term *ptr1 = head;
            while(ptr1 != NULL)
            {
                if(ptr1->x_index == ptr2->x_index && ptr1->y_index == ptr2->y_index && ptr1->z_index == ptr2->z_index )
                {
                    ptr1->coef = ptr1->coef + ptr2->coef;
                    break;
                }
                ptr1 = ptr1->next;
            }
            if(ptr1 == NULL)
            {
                this->assign_polynomial((ptr2->coef),ptr2->x_index, ptr2->y_index, ptr2->z_index);
            }
            ptr2 = ptr2->next;
        }
        return *this;
    }
    Polynomial& operator-(Polynomial& P2)
    {
        Polynomial P3;
        Term *ptr2 = P2.head;
        while(ptr2 != NULL)
        {
            Term *ptr1 = head;
            while(ptr1 != NULL)
            {
                if(ptr1->x_index == ptr2->x_index && ptr1->y_index == ptr2->y_index && ptr1->z_index == ptr2->z_index )
                {
                    ptr1->coef = ptr1->coef - ptr2->coef;
                    break;
                }
                ptr1 = ptr1->next;
            }
            if(ptr1 == NULL)
            {
                this->assign_polynomial((ptr2->coef),ptr2->x_index, ptr2->y_index, ptr2->z_index);
            }
            ptr2 = ptr2->next;
        }
        return *this;
    }
    void display()
    {
        Term *ptr = head;
        while(ptr != NULL)
        {
            if(ptr->coef >= 0)
            {
                cout<<"+("<<ptr->coef<<"(x^"<<ptr->x_index<<")(y^"<<ptr->y_index<<")(z^"<<ptr->z_index<<")) ";
            }
            else
            {
                 cout<<"("<<ptr->coef<<"(x^"<<ptr->x_index<<")(y^"<<ptr->y_index<<")(z^"<<ptr->z_index<<")) ";
            }

            ptr = ptr->next;
        }
    }
};
int main()
{
    Polynomial POLY1,POLY2;
    char choice ='y';
    char trash;
    float coef,x_index,y_index,z_index;
    cout<<endl<<endl<<"First polynomial"<<endl;
    while(true)
    {
        cout<<"Enter coef, x_index, y_index, z_index: "<<endl;
        cin>>coef>>trash>>x_index>>trash>>y_index>>trash>>z_index;
        POLY1.assign_polynomial(coef,x_index,y_index,z_index);
        cout<<endl<<"Add more?(y/n): ";
        cin>>choice;
        if(choice == 'n')
        {
            break;
        }
    }
    choice = 'y';
    cout<<endl<<endl<<"Second polynomial: "<<endl;
    while(true)
    {
        cout<<endl<<"Enter coef, x_index, y_index, z_index: "<<endl;
        cin>>coef>>trash>>x_index>>trash>>y_index>>trash>>z_index;
        POLY2.assign_polynomial(coef,x_index,y_index,z_index);
        cout<<endl<<"Add more?(y/n): ";
        cin>>choice;
        if(choice == 'n')
        {
            break;
        }
    }
    cout<<"1. Add"<<endl;
    cout<<"2. Subtract"<<endl;
    cout<<"3. Exit"<<endl;
    int option;
    cout<<"Enter the option:";
    cin>>option;
    switch(option)
    {
    case 1:
        POLY1 = POLY1 + POLY2;
        cout<<endl<<"Sum= ";
        POLY1.display();
        break;
    case 2:
        POLY1 = POLY1 - POLY2;
        cout<<endl<<"Difference= ";
        POLY1.display();
        break;
    case 3:
        exit(1);
        break;
    default:
        cout<<endl<<"Error input"<<endl;
        break;
    }
    return 0;
}

