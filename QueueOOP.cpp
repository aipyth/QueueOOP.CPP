#include <iostream>
#include "Queue.h"

int main()
{
    using namespace std;

    Node<int>* n = new Node<int>(11);
    OneDirectionQueue<int>* q = new OneDirectionQueue<int>();

    q->push(n);

    cout << q->pop()->getData() << endl;

    delete q;

    return 0;
}
