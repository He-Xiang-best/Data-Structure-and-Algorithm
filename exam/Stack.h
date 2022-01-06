## 2. ջ�ĳ������ݶ���

```c++
template <class T> 			// ջ��Ԫ������Ϊ T 
class Stack {
public: 
    virtual bool empty() const = 0;	// �п�
    virtual int size() const = 0; 	// ��ջ��Ԫ�ظ���
    virtual void push(const T &x) = 0; // ѹջ
    virtual T  pop() = 0;           // ��ջ
    virtual T getTop() const = 0;   // ȡջ��Ԫ�أ��������� 
    virtual void clear() =0; 		// ���ջ
    virtual ~Stack() {}
};
```

### 2.1 ˳��ջ�Ķ���

```c++
template <class T>
class seqStack : public Stack<T> {       
private:
    T * data; 				// ���ջ��Ԫ�ص�����
    int top; 				// ջ��ָ�룬ָ��ջ��Ԫ��
    int maxSize; 			// ջ�Ĵ�С
    void resize();			// ����ջ�ռ�
public:
    seqStack(int initSize = 100); 
    ~seqStack(){ delete [] data;}
    void clear() { top = -1; } 		// ���ջ 
    bool empty() const{ return top == -1;}// �п�
    int size() const{ return top+1; } 	// �󳤶�
    void push(const T &value);   		// ��ջ
    T  pop();   					// ��ջ
    T  getTop() const;	  	  		// ȡջ��Ԫ��
};
```

ͨ���������С�±����Ϊջ�ף�ջ��ʱ��ջ��ָ��top=-1�� ��ջʱ��ջ��ָ���1����++top����ջʱ��ջ��ָ���1����top- -��

#### 2.1.1 ���캯��

��ʼ��һ���յ�˳��ջ����ջ��ָ��topΪ-1

```c++
template <class T>
seqStack<T>::seqStack(int initSize = 100) {
    if(initSize <= 0) throw badSize();
    data = new T[initSize];
    maxSize = initSize ;    
    top = -1;  
}
```

#### 2.1.2 ��ջ

```c++
template <class T>
void seqStack<T>::push(const T &value) {
    // ���˳��ջ�Ƿ�����	
    if (top == maxSize - 1) resize();			
    data[++top] = value;// �޸�ջ��ָ�룬��Ԫ����ջ
}
```

#### 2.1.3 ��ջ

```c++
template <class T>
T seqStack<T>::pop(){ 	
    if(empty())throw outOfRange();	// ��ջ�޷���ջ
    return data[top--];  	// �޸�ջ��ָ�룬����ջ��Ԫ��
} 
```

Ӧ��ָ��������ջ������һ��Ҫ����Ԫ�أ�����Ԫ���ǡ�����Ʒ������ջ����ҪĿ��������ָ�룬�Ƿ�Ҫ����ջ��Ԫ��ȡ������ĿҪ��

#### 2.1.4 ȡջ��Ԫ��

˵�����������޸ķ��ص�ջ��Ԫ�أ�����ʹ��������Ϊ�����ķ���ֵ��

```c++
template <class T>
T seqStack<T>::getTop() const{ 		
    if(empty())throw outOfRange();
    return data[top];  	
}
```

#### 2.1.5 ����ջ�ռ�

```c++
template <class T>
void seqStack<T>::resize(){
    T *tmp = data;	
    data = new T[2 * maxSize];
    for (int i = 0; i < maxSize; ++i)
        data[i] = tmp[i];
    maxSize *= 2;
    delete [] tmp;
} 
```

### 2.2 ��ջ�����Ͷ���

```
template <class T>
class linkStack : public Stack<T> {
private:
    struct Node{
        T data;
        Node* next;
        Node(){ next = NULL; }
        Node(const T &value, Node *p = NULL){ data = value; next = p;}
    }; 
    Node* top;			// ջ��ָ��
public:
    linkStack(){ top = NULL; }	// �����ջ
    ~linkStack(){ clear(); }
    void clear();					// ���
    bool empty()const{ return top == NULL; }	// �п�
    int size()const;				// �󳤶�
    void push(const T &value);			// ѹջ
    T  pop();					// ��ջ
    T getTop()const;				// ȡջ��Ԫ��
};
```

#### 2.2.1 ���ջ

```c++
template <class T>
void linkStack<T>::clear() {
    Node *p;
    while (top != NULL) {
        p = top;								// pָ��ǰջ��Ԫ��
        top = top->next; 						// topָ�������ջ��Ԫ��
        delete p;								// �ͷ�pָ��ĵ�ǰջ��Ԫ��
    }
}
```

#### 2.2.2 ��ջ��Ԫ�ظ���

```c++
template <class T>
int linkStack<T>::size()const {
    Node *p=top;
    int count=0;								// ������
    while (p) {								// ����ջ��ͳ��Ԫ������
        count++;
        p = p->next;
    }
    return count;
}
```

#### 2.2.3 ��ջ

```c++
template <class T>
void linkStack<T>::push(const T &value) {
    // ��ջ������Ԫ��
    Node *p = new Node(value, top); 
    top = p;			// p��Ϊ�µ�ջ��Ԫ�� 
}
```

#### 2.2.4 ��ջ

```c++
template <class T>
T linkStack<T>::pop() {
    if (empty())throw outOfRange();
    Node *p = top;
    T value = p->data;	// value����ջ��Ԫ�ص�ֵ
    top = top->next; 	// topָ������ƶ�
    delete p;			// ɾ��ջ��Ԫ��
    return  value;
}
```

#### 2.2.5 ȡջ��Ԫ��

```c++
template <class T>
T linkStack<T>::getTop() const { 
    if (empty())throw outOfRange();
    return top->data; 
}
```


