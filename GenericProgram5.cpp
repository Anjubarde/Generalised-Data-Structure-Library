/*
    Generic Queue
*/

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class queue
{
    public:
        struct node<T> * head;
        int iCount;

        queue();
        void enqueue(T no);   
        int dequeue();   
        void Display();
        int Count();
        
};

        template<class T>
        queue<T>::queue()
        {
            head = NULL;
            iCount = 0;
        }

        template<class T>
        void queue<T>::enqueue(T no)   // InsertLast
        {
            struct node<T> * newn = NULL;
            struct node<T> * temp = NULL;

            newn = new node<T>;
            newn->data = no;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = newn;
            }
            iCount++;
        }

        template<class T>
        int queue<T>::dequeue()   // DeleteFirst
        {
            int no = -1;
            struct node<T> * temp = NULL;

            if(head == NULL)
            {
                cout<<"Queue is empty\n";
                return -1;
            }
            else if(head->next == NULL)
            {
                no = head->data;
                delete head;
                head = NULL;
            }
            else
            {
                no = head->data;
                temp = head;
                head = head->next;
                delete temp;
            }
            iCount--;
            return no;
        }

        template<class T>
        void queue<T>::Display()
        {
            cout<<"Elements of queue are : \n";
            struct node<T> * temp = head;

            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" |\n";
                temp = temp -> next;
            }
        }

        template<class T>
        int queue<T>::Count()
        {
            return iCount;
        }



int main()
{
    queue <int>qobj1;
    queue <int>qobj2;
    queue <int>qobj3;
    
    qobj1.enqueue(5);
    qobj1.enqueue(7);
    qobj1.enqueue(10);
    
    qobj2.enqueue(2);
    qobj2.enqueue(15);

    qobj3.enqueue(23);
    qobj3.enqueue(67);
    qobj3.enqueue(75);
    qobj3.enqueue(50);

    cout << "Queue 1:" << endl;
    qobj1.Display();

    cout << "Queue 2:" << endl;
    qobj2.Display(); 

    cout << "Queue 3:" << endl;
    qobj3.Display();

    return 0;
}