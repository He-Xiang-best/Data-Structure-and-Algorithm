#include <iostream>
using namespace std;

typedef struct Node *PtrToNode;

struct Node
{
    int Coefficient;    //ϵ��
    int Exponent;       //ָ����
    PtrToNode Next;
};

typedef PtrToNode Polynomial; /* Nodes sorted by exponent */

void AddPolynomial();
void MultPolynomial();

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
