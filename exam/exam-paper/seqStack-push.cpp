/*********Begin**********  ��  **********End**********����ɾ��
��*********Begin*********  ��  ********End********֮������
Ҫ��ʹ��ָ���������������������������������ȣ���д©д���÷�

��֪˳��ջ�����Ͷ������£���ʵ�ֽ�ջ�㷨void push(const T &value)����ջ������Ҫ����ջ�ռ䡣
template <class T>
class seqStack {       
private:
    T * data; 			// ���ջ��Ԫ�ص�����
    int top; 			// ջ��ָ�룬ָ��ջ��Ԫ��
    int maxSize; 			// ջ�Ĵ�С
    void resize();			// ����ջ�ռ�
public:
    seqStack(int initSize = 100); 
    ~seqStack(){ delete [] data;}
    void clear() { top = -1; } 		// ���ջ 
    bool empty() const{ return top == -1;}// �п�
    int size() const{ return top+1; } 	// �󳤶�
    void push(const T &value);   	// ��ջ
    T  pop();   			// ��ջ
    T  getTop() const;	  	// ȡջ��Ԫ��
};

*/
/***************begin***************/
template <class T>
void seqStack<T>::push(const T &value)
{
	if(top==maxSize-1)
	resize();
	data[++top]=value;
 } 
/****************end****************/
