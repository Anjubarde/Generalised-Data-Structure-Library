/*
    Generic Singly Circular LinkedList
*/

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    public:
        struct node<T> * head;
        struct node<T> * tail;
        int iCount;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

        template <class T>
        SinglyCL<T>::SinglyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        template <class T>
        void SinglyCL<T>::InsertFirst(T no)
        {
            struct node<T> * newn = new node<T>;
            newn->data= no;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
                tail = newn;
                newn->next = head;
            }
            else
            {
                newn->next = head;
                head = newn;
                tail->next = head;
            }
            iCount++;
        }

        template <class T>
        void SinglyCL<T>::InsertLast(T no)
        {
            struct node<T> * newn = new node<T>;
            newn->data = no;
            newn->next = head;
        
            if(head == NULL)
            {
                head = newn;
                tail = newn;
                newn->next = head;
            }
            else
            {
                tail->next = newn;
                tail = newn;
                tail->next = head;
            }
            iCount++;
        }

        template <class T>
        void SinglyCL<T>::InsertAtPos(T no, int ipos)
        {
            if(ipos < 1 || ipos > iCount + 1)
            {
                cout<<"Invalid Position"<<endl;
                return;
            }
            if(ipos == 1)
            {
                InsertFirst(no);
            }
            else if(ipos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                struct node<T> * newn = new node<T>;
                newn->data = no;
                struct node<T> * temp = head;

                for(int i = 1; i< ipos -1; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }
        
        template <class T>
        void SinglyCL<T>::DeleteFirst()
        {
            if(head == NULL)
            {
                cout<<"Linkedlist is empty "<<endl;
                return;
            }
            if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else 
            {
                struct node<T> * temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
            iCount--;
        }

        template <class T>
        void SinglyCL<T>::DeleteLast()
        {
            if(head == NULL)
            {
                cout<<"LinkedList is Empty"<<endl;
                return;
            }
            if(head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else 
            {
                struct node<T> * temp = head;
                while(temp->next != tail)
                {
                    temp = temp->next;
                }
                temp->next = head;
                delete tail;
                tail = temp;
            }
            iCount--;
        }

        template <class T>
        void SinglyCL<T>::DeleteAtPos(int ipos)
        {
            if(ipos < 1 || ipos > iCount)
            {
                cout<<"Invalid Position "<<endl;
                return;
            }
            if(ipos == 1)
            {
                DeleteFirst();    
            }
            else if(ipos == iCount)
            {
                DeleteLast();
            }
            else
            {
                struct node<T> * temp = head;
                for(int i = 1; i< ipos - 1; i++)
                {
                    temp = temp->next;
                }

                struct node<T> * target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }

        template <class T>
        void SinglyCL<T>::Display()
        {
            if(head == NULL)
            {
                cout<<"Linkedlist is empty"<<endl;
                return;
            }

            struct node<T> * temp = head;-
            do
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            } while(temp != head);
            
            cout << endl;
        }

        template <class T>
        int SinglyCL<T>::Count()
        {
            return iCount;
        }

int main()
{
    SinglyCL <int>obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.InsertAtPos(75,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}