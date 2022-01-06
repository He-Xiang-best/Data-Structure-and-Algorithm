/*********Begin**********  ��  **********End**********����ɾ��
��*********Begin*********  ��  ********End********֮������
Ҫ��ʹ��ָ���������������������������������ȣ���д©д���÷�

��֪ѭ�����е����Ͷ������£���ʵ�ֳ����㷨T deQueue();�����зǿ�ɾ������Ԫ�أ������ض���Ԫ�ص�ֵ��
���У���ͷָ��frontָ���ͷԪ�ص�ǰһλ�ã���βָ��rearָ���βԪ��
template <class T>
class seqQueue{
private:
    T *data; 							// ָ����Ԫ�ص�����
    int maxSize;					 		// ���еĴ�С
    int front, rear; 						// ��ͷ�Ͷ�βָ��
    void resize();							// ������пռ�
public:
    seqQueue(int initsize = 100);
    ~seqQueue(){ delete [] data; }
    void clear(){ front = rear = 0; }					// ��ն���
    bool empty()const { return  front == rear; }			// �п�
    bool full()const { return (rear + 1) % MaxSize == front; }		// ����
    int size()const{ return (rear-front+maxSize)%maxSize; } 		// ���г���
    void enQueue(const T &x);					// ���
    T deQueue();							// ����
    T getHead()const;						// ȡ����Ԫ��
};

*/
/***************begin***************/
template <class T>
T seqQueue<T>::deQueue()
{
	if(empty())throw outOfRange();
	front=(front+1)%maxSize;
	return data[front];
}
/****************end****************/






