## 3. ���еĳ����������Ͷ���

```c++
template <class T>		// ���е�Ԫ������ΪT 
class Queue{
public:
    virtual bool empty()const = 0;	// �жӿ�
    virtual void clear()=0;			// ��ն���
    virtual int size()const=0 ; 		// ����г���
    virtual void enQueue(const T &x) = 0;	// ���
    virtual T deQueue() = 0;			// ����
    virtual T getHead()const = 0; 	// ����ͷԪ��
    virtual ~Queue() {}         		// ����������
};
```

### 3.1 ѭ������

#### 3.1.1 ��ʼ��һ���ն���

```c++
template <class T>
seqQueue<T>::seqQueue(int initsize){
    if(initsize <= 0)throw badSize();
    data = new T[initsize];
    maxSize = initsize; 
    front = rear = -1;
}
```

#### 3.1.2 ���

```c++
template <class T>
void seqQueue<T>::enQueue(const T &x){
    // �����������������
    if ((rear + 1) % maxSize == front) resize();
    rear = (rear + 1) % maxSize; 	// �ƶ���βָ��
    data[rear] = x;		 	// x���
}
```

#### 3.1.3 ����

```c++
template <class T>
T seqQueue<T>::deQueue(){
    // �����пգ��׳��쳣
    if (empty())throw outOfRange(); 
    front = (front + 1) % maxSize; 	// �ƶ�����ָ��
    return  data[front]; 			// ���ض���Ԫ��
}	
```

#### 3.1.4 ȡ����Ԫ��

```c++
template <class T>
T seqQueue<T>::getHead()const{
    if (empty())throw outOfRange();
    // ���ض���Ԫ�أ����ƶ�����ָ��
    return  data[(front + 1) % maxSize]; 		
}
```

#### 3.1.5 ������пռ�

```c++
template <class T>
void seqQueue<T>::resize(){
    T *p = data;
    data = new T[2 * maxSize];
    for (int i = 1; i < maxSize; ++i)
        data[i] = p[(front + i) % maxSize]; // ����Ԫ��
    front = -1; rear = maxSize - 2; // ���ö��׺Ͷ�βָ��
    maxSize *= 2;
    delete p;
}
```

### 3.2 �����е����Ͷ���

```c++
template <class T>
class linkQueue: public Queue<T>{
private:
    struct node {
        T  data;    node *next;
        node(const T &x, node *N = NULL){ data = x; next = N; }
        node():next(NULL) {}
        ~node() {}
    };
    node *front, *rear;  			// ��ͷָ�롢��βָ��
public:
    linkQueue(){ front = rear = NULL; }	   
    ~linkQueue(){ clear(); }
    void clear();				// ��ն���
    bool empty()const{ return front == NULL;} 	// �п�
    int size()const;				// ���г���
    void enQueue(const T &x); 		// ���
    T deQueue();				// ����
    T getHead()const;				// ȡ����Ԫ��
};
```

#### 3.2.1 ���

```c++
template <class T>
void linkQueue<T>::enQueue(const T &x) {
    if (rear == NULL)			// ԭ����Ϊ��
        front = rear = new node(x);	// ���Ԫ�ؼ��Ƕ������Ƕ�β
    else {
        rear->next = new node(x);	// �ڶ�β���
        rear = rear->next; 		// �޸Ķ�βָ��
    }
}
```

#### 3.2.2 ����

���Ӳ�����һ����������������ִ��deQueue����ʱ������ֻ��һ��Ԫ�أ�����deQueue����������Ϊ�գ���ʱ���뽫front��rearͬʱ�ó�NULL

```c++
template <class T>
T linkQueue<T>::deQueue() {
    if(empty())throw outOfRange();	// ���пգ��׳��쳣
    node *p = front;
    T value = front->data;		// �������Ԫ��
    front = front->next;			// �ڶ��׳���
    // ԭ��ֻ��һ��Ԫ�أ����Ӻ����Ϊ��
    if(front == NULL) 							  rear = NULL;			// �޸Ķ�βָ��
    delete  p;
    return value;
} 
```

#### 3.2.3 ȡ����Ԫ��

```c++
template <class T>
T linkQueue<T>::getHead()const {
    if(empty())throw outOfRange();	// ���пգ��׳��쳣
    return  front->data; 			// ���ض���Ԫ��
}
```

#### 3.2.4 ��ն���

```c++
template <class T>
void linkQueue<T>:: clear(){
    node *p;
    while (front != NULL) {	// �ͷŶ��������н��
        p = front; 
        front = front->next;
        delete p;
    }
    rear = NULL;			// �޸�βָ��
}
```

#### 3.2.5 ����г���

```c++
template <class T>
int linkQueue<T>::size()const {
    node *p = front;
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
```
