/*********Begin**********  ��  **********End**********����ɾ��
��*********Begin*********  ��  ********End********֮������
Ҫ��ʹ��ָ���������������������������������ȣ���д©д���÷�

��֪��ջ�����Ͷ������£���ʵ�ֳ�ջ�㷨T  pop()����ջ�ǿյ���ջ��Ԫ�أ�������ջ��Ԫ�ص�ֵ��
�뽫����ָ��������Ϊp��
template <class T>
class linkStack {
private:
    struct Node{
        T data;
        Node* next;
        Node(){ next = NULL; }
        Node(const T &value, Node *p = NULL){ data = value; next = p;}
    }; 
    Node* top;				// ջ��ָ��
public:
    linkStack(){ top = NULL; }		// �����ջ
    ~linkStack(){ clear(); }
    void clear();				// ���
    bool empty()const{ return top == NULL; }	// �п�
    int size()const;				// �󳤶�
    void push(const T &value);		// ѹջ
    T  pop();				// ��ջ
    T getTop()const;			// ȡջ��Ԫ��
};*/
/***************begin***************/


template<class T>
T linkStack<T>::pop(){
	if(!empty()){
		Node *p=top;
		T value = p->data;
		top=top->next;
		delete p;
		return value;
	}

}
/****************end****************/
