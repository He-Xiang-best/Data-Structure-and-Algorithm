#include <iostream>
using namespace std;

typedef struct TreeNode *PtrToNode;

struct TreeNode //�������ֵܱ�ʾ�� *��UNIXϵͳ���ļ���ʵ��ʹ�������� ����һ��ָ��Ŀ¼*
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
