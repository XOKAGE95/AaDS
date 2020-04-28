#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    int size;
    Node *first;
    Node *last;
};



using namespace std;

bool CreateQueue(Queue *Q);
int Top(Queue *Q);
bool Add(Queue *Q);
bool Delete(Queue *Q);
bool Full(Queue *Q);
int Size(Queue *Q);

int main()
{
    Queue Q;
    CreateQueue(&Q);
    char command;
    cout << "1 - Add element\n2 - Delete element\n3 - Enter top element\n4 - Enter queue size\n0 - out\n";
    do
    {
        cout << "Enter command: ";
        cin >> command;
        switch(command)
        {
        case '1':
            Add(&Q);
            break;
        case '2':
            Delete(&Q);
            break;
        case '3':
            cout << "Top element = " << Top(&Q) << endl;
            break;
        case '4':
            cout << "Size = " << Size(&Q) << endl;
            break;
        }


    }while(command != 0);
}

bool CreateQueue(Queue *Q)
{
    Q -> first = new Node;
    Q -> first -> next = NULL;
    Q -> last = Q -> first;
    Q -> size = 0;
    return true;
}

int Top(Queue *Q)
{
    return Q -> first -> next -> data;
}

int Size(Queue *Q)
{
    return Q -> size;
}

bool Add(Queue *Q)
{
    int value;
    cout << "Enter value: ";
    cin >> value;
    Q -> last -> next = new Node;
    Q -> last = Q -> last -> next;
    Q -> last -> next = NULL;
    Q -> last -> data = value;
    Q -> size ++;
    return true;
}

bool Delete(Queue *Q)
{
    Q -> first = Q -> first -> next;
    Q -> size --;
    return true;
}

bool Full(Queue *Q)
{
    return (Q -> first == Q -> last);
}


