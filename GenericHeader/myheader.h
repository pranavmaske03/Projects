#include <iostream>
using namespace std;

#define ERR_NOTFOUND -1

//  STRUCTURE OF SINGLY LINKEDLIST.................

template <class T>
struct NodeS                                            
{
    T data;
    struct NodeS *next;
};

//  STRUCTURE OF DOUBLY LINKED LIST..................

template <class T>
struct NodeD                                               
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};


//  STRUCTURE OF BST (Binary Search Tree)...........

template<class T>
struct NodeB
{
    T data;
    struct NodeB *lchild;
    struct NodeB *rchild;
};

//////////////////////////////////////////////////////////////////////////////////////////

//  Singly Linear Linked list

/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{ 
    public:
        struct NodeS<T> *First;
        int iCount;

        SinglyLL();
        ~SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);
        int CountFrequency(T);
        T Minimium();
        T Maximum();
        T Summation();
};

//////////////////////////////////////////////////////////////////////////////////////////

//  Doubly Linear Linked list

/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
       struct NodeD<T> *First;
       int iCount;

        DoublyLL();
        ~DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);
        int CountFrequency(T);
        T Minimium();
        T Maximum();
        T Summation();
};

//////////////////////////////////////////////////////////////////////////////////////////

//  Singly circular Linked list

/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> *First;
        struct NodeS<T> *Last;
        int iCount;

        SinglyCL();
        ~SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);
        int CountFrequency(T);
        T Minimium();
        T Maximum();
        T Summation();
};

//////////////////////////////////////////////////////////////////////////////////////////

//  Doubly circular Linked list

/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
   public:
       struct NodeD<T> *First;
       struct NodeD<T> *Last;
       int iCount;

       DoublyCL();
       ~DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        int SearchFirstOccurence(T);
        int SearchLastOccurence(T);
        int CountFrequency(T);
        T Minimium();
        T Maximum();
        T Summation();
};

/////////////////////////////////////////////////////////////////////////////////////////

//  Stack

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
        struct NodeS<T> *First;
        int iCount;

        Stack();
        ~Stack();

        void Push(T);
        T Pop();
        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////////////

//  Queue

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public:
        struct NodeS<T> *first;
        int iCount;

        Queue();
        ~Queue();

        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////////////

//  Array Searching & Sorting

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;
  
        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);

        bool CheckSorted();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();

};

//////////////////////////////////////////////////////////////////////////////////////////

//   Binary Search tree

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    public:
        static NodeB<T>* first;

        void Insert(T);
        void Preorder(NodeB<T> * temp = first);
        void Postorder(NodeB<T> * temp = first);
        void Inorder(NodeB<T> * temp = first);
        bool Search(T);
        int CountNodes(NodeB<T> * temp = first);
        int CountLeafNodes(NodeB<T> * temp = first);
        int CountParentNodes(NodeB<T> * temp = first);
};


//////////////////////////////////////////////////////////////////////////////////////////

//   Functions of the Singly linear linked list

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
SinglyLL<T>::~SinglyLL()
{
    NodeS<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of the Linked List are : \n";

    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->next = NULL;
    newn->data = no;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->next = NULL;
    newn->data = no;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;

        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *newn = new NodeS<T>;

        newn->next = NULL;
        newn->data = no;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *tempX = NULL;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }
        
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}                                                                       

template <class T>
int SinglyLL<T>::SearchFirstOccurence(T no)
{
    NodeS<T> *temp = First;
    int iCnt = 1;

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            break;
        }

        temp = temp->next;
        iCnt++;
    }
    if(temp == NULL)
    {
        return ERR_NOTFOUND;
    }
    else
    {
        return iCnt;
    }
}

template <class T>
int SinglyLL<T>::SearchLastOccurence(T no)
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    int iPos = ERR_NOTFOUND;

    if(temp == NULL)
    {
        return ERR_NOTFOUND;
    }

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            iPos = iCnt;
        }

        temp = temp->next;
        iCnt++;
    }
    return iPos;
}

template <class T>
int SinglyLL<T>::CountFrequency(T no)
{
    NodeS<T> *temp = First;
    int count = 0;

    if(temp == NULL)
    {
        cout<<"Linked list is empty\n";
        return ERR_NOTFOUND;
    }

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            count++;
        }

        temp = temp->next;
    }
    return count;
}

template <class T>
T SinglyLL<T>::Minimium()
{
    NodeS<T> *temp = First;
    T Min;

    Min = temp->data;
    while(temp != NULL)
    {
        if(Min > temp->data)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}

template <class T>
T SinglyLL<T>::Maximum()
{
    NodeS<T> *temp = First;
    T Max;

    Max = temp->data;
    while(temp != NULL)
    {
        if(Max < temp->data)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
} 

template <class T>
T SinglyLL<T>::Summation()
{
    NodeS<T> *temp = First;
    T Sum = (temp->data - temp->data);

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}                                                     // End of the singly linear linked list

//////////////////////////////////////////////////////////////////////////////////////////

//  Functions of the Doubly Linear linked list

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
    NodeD<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of the Linked List are : \n";

    NodeD<T> *temp = First;

    while(temp != NULL)
    {
        cout<<" |"<<temp->data<<"| <=>";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeD<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        NodeD<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = First;
        NodeD<T> *newn = new NodeD<T>;

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = First;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}                                                                         

template<class T>
int DoublyLL<T>::SearchFirstOccurence(T no)
{
    NodeD<T> *temp = First;
    int iCnt = 1;

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            break;
        }

        temp = temp->next;
        iCnt++;
    }
    if(temp == NULL)
    {
        return ERR_NOTFOUND;
    }
    else
    {
        return iCnt;
    }
}

template<class T>
int DoublyLL<T>::SearchLastOccurence(T no)
{
    NodeD<T> *temp = First;
    int iCnt = 1;
    int iPos = ERR_NOTFOUND;

    if(temp == NULL)
    {
        return ERR_NOTFOUND;
    }

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            iPos = iCnt;
        }

        temp = temp->next;
        iCnt++;
    }
    return iPos;
}

template <class T>
int DoublyLL<T>::CountFrequency(T no)
{
    NodeD<T> *temp = First;
    int count = 0;

    while(temp != NULL)   
    {
        if(temp->data == no)
        {
            count++;
        }

        temp = temp->next;
    }
    return count;
}

template <class T>
T DoublyLL<T>::Minimium()
{
    NodeD<T> *temp = First;
    T Min;

    Min = temp->data;
    while(temp != NULL)
    {
        if(Min > temp->data)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}

template <class T>
T DoublyLL<T>::Maximum()
{
    NodeD<T> *temp = First;
    T Max;

    Max = temp->data;
    while(temp != NULL)
    {
        if(Max < temp->data)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
} 

template <class T>
T DoublyLL<T>::Summation()
{
    NodeD<T> *temp = First;
    T Sum = (temp->data - temp->data);

    while(temp != NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}                                                     // End of the Doubly linear linked list


//////////////////////////////////////////////////////////////////////////////////////////

//    Functions of the Singly Circular linked list

/////////////////////////////////////////////////////////////////////////////////////////
template<class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
    NodeS<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> *temp = First;

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->next = NULL;
    newn->data = no;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->next = NULL;
    newn->data = no;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else    
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *newn = new NodeS<T>;

        newn->next = NULL;
        newn->data = no;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp = First;
        NodeS<T> *tempX = NULL;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }
        
        tempX = temp->next;
        temp->next = temp->next->next;
        delete tempX;

        iCount--;
    }
}                                                                       // End of the Singly circular linked list

template <class T>
int SinglyCL<T>::SearchFirstOccurence(T no)
{
    NodeS<T> *temp = First;
    int iCnt = 1;

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp == Last->next)
    {
        return ERR_NOTFOUND;
    }
    else
    {
        return iCnt;
    }
}

template <class T>
int SinglyCL<T>::SearchLastOccurence(T no)
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    int iPos = ERR_NOTFOUND;

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->next;
    }
    return iPos;
}

template <class T>
int SinglyCL<T>::CountFrequency(T no)
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    int count = 0;

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            count++;
        }
        temp = temp->next;
    }   
    return count;
}

template <class T>
T SinglyCL<T>::Minimium()
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    T Min;

    Min = temp->data;
    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > temp->data)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }   
    return Min;
}

template <class T>
T SinglyCL<T>::Maximum()
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    T Max;

    Max = temp->data;
    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < temp->data)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }   
    return Max;
}

template <class T>
T SinglyCL<T>::Summation()
{
    NodeS<T> *temp = First;
    int iCnt = 1;
    T Sum;

    Sum = (temp->data-temp->data);

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }   
    return Sum;
}

//////////////////////////////////////////////////////////////////////////////////////////

//    Functions of the Doubly Circular linked list

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
    NodeD<T> *temp = First;
 
    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<" |"<<temp->data<<"| <=>";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    First->prev = Last;
    Last->next = First;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
    }
    First->prev = Last;
    Last->next = First;

    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == count+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = First;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        NodeD<T> *newn = new NodeD<T>;

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    int count = Count();

    if((iPos < 1) || (iPos > count))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == count)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = First;

        for(int icnt = 1; icnt < iPos-1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}                                                                      

template <class T>
int DoublyCL<T>::SearchFirstOccurence(T no)
{
    
    NodeD<T> *temp = First;
    NodeD<T> *tempx = First;
    int iCnt = 0,i = 0;
    int iPos = -1;
    
    for(iCnt = 1; iCnt <= iCount; iCnt++)    
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        temp = temp->next;
    }
    return iPos;
}

template <class T>
int DoublyCL<T>::SearchLastOccurence(T no)
{
    NodeD<T> *temp = First;
    NodeD<T> *tempx = Last;
    int iCnt = 0;
    int iPos = -1;
    int i = 0;

    for(iCnt = 1, i = iCount; iCnt <= iCount; iCnt++, i--)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        else if(tempx->data == no)
        {
            iPos = i;
            break;
        }
        temp = temp->next;
        tempx = tempx->prev;
    }
    return iPos;
}

template <class T>
int DoublyCL<T>::CountFrequency(T no)
{
    NodeD<T> *temp = First;
    int iCnt = 0;
    int count = 0;

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

template <class T>
T DoublyCL<T>::Minimium()
{
    NodeD<T> *temp = First;
    int iCnt = 0;
    T Min;

    Min = temp->data;
    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Min > temp->data)
        {
            Min = temp->data;
        }
        temp = temp->next;
    }
    return Min;
}

template <class T>
T DoublyCL<T>::Maximum()
{
    NodeD<T> *temp = First;
    int iCnt = 0;
    T Max;

    Max = temp->data;
    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(Max < temp->data)
        {
            Max = temp->data;
        }
        temp = temp->next;
    }
    return Max;
}

template <class T>
T DoublyCL<T>::Summation()
{
    NodeD<T> *temp = First;
    T Sum = (temp->data - temp->data);

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

/////////////////////////////////////////////////////////////////////////////////////////

//  Functions of the stack

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
    this->First = NULL;
    this->iCount = 0;
}

template<class T>
Stack<T>::~Stack()
{
    NodeS<T> *temp = First;
 
    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

template<class T>      
void Stack<T>::Display()
{
    NodeS<T> *temp = First;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int Stack<T>::Count()
{
    return this->iCount;
}

template<class T>
void Stack<T>::Push(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->next = NULL;
    newn->data = no;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template<class T>  
T Stack<T>::Pop()   
{
    T Value;

    if(iCount == 0)
    {
        cout<<"Stack is empty \n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First->data;
        delete First;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
    return Value;
}            

/////////////////////////////////////////////////////////////////////////////////////////

//  Functions of the Queue

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>  
Queue<T>::Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

template<class T>  
Queue<T>::~Queue()
{
    NodeS<T> *temp = first;
 
    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

template<class T>  
void Queue<T>::Display()
{
    NodeS<T> *temp = first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>  
int Queue<T>::Count()
{
    return this->iCount;
}
 
template<class T>  
void Queue<T>::Enqueue(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template<class T>  
T Queue<T>::Dequeue()
{
    T Value;

    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(first->next == NULL)
    {
        Value = first->data;
        delete first;
    }
    else
    {
        NodeS<T> *temp = first;

        Value = first->data;
        first = first->next;
        delete temp;
    }

    iCount--;
    return Value;
}           

/////////////////////////////////////////////////////////////////////////////////////////

//  Functions of Array for Search

/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
ArrayX<T>::ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template<class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

template<class T>
void ArrayX<T>::Accept()
{
    cout<<"Enter elements of the array :\n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template<class T>
void ArrayX<T>::Display()
{
    cout<<"Elements of the array are :\n";

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template<class T>
bool ArrayX<T>::LinearSearch(T no)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == no)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template<class T>
bool ArrayX<T>::BidirectionalSearch(T no)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template<class T>
bool ArrayX<T>::BinarySearch(T no)
{
    bool flag = false;
    
    int iStart = 0,iEnd = 0,iMid = 0;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < no)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > no)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

template<class T>
bool ArrayX<T>::CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

template<class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0,j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize-1-i; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

template<class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0,j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

template <class T>
void ArrayX <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++) 
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

//  Functions BST

/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
NodeB<T>*BST<T>::first = NULL;

template<class T>
void BST<T>::Insert(T no)
{
    NodeB<T>* newn = NULL;
    NodeB<T>* temp = first;

    newn = new NodeB<T>;
    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate element : Unable to insert \n";
                delete newn;
                break;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template<class T>
bool BST<T>::Search(T no)
{
    bool flag = false;
    NodeB<T> * temp = first;

    if(temp == NULL)
    {
        cout<<"Tree is empty \n";
        return flag;
    }

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            flag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return flag;
}

template<class T>
void BST<T>::Preorder(NodeB<T>* temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

template<class T>
void BST<T>::Postorder(NodeB<T>* temp)
{
    if(temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        cout<<temp->data<<"\t";
    }
}

template<class T>
void BST<T>::Inorder(NodeB<T>* temp)
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<temp->data<<"\t";
        Inorder(temp->rchild);
    }
}


template<class T>
int BST<T>::CountNodes(NodeB<T>* temp)
{
    static int iCnt = 0;

    if(temp != NULL)
    {
        iCnt++;
        CountNodes(temp->lchild);
        CountNodes(temp->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::CountLeafNodes(NodeB<T>* temp)
{
    static int iCnt = 0;
     
    if(temp != NULL)
    {
        if((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(temp->lchild);
        CountLeafNodes(temp->rchild);
    }
    return iCnt;
}

template<class T>
int BST<T>::CountParentNodes(NodeB<T>* temp)
{
    static int iCnt = 0;

    if(temp != NULL)
    {
        if((temp->lchild != NULL) || (temp->rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(temp->lchild);
        CountParentNodes(temp->rchild);
    }
    return iCnt;
}
