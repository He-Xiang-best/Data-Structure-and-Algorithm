# ���ݽṹ���㷨C++���Դ���ʵ��

## 1. ���Ա�ĳ�����������

```c++
template<class T>
class List{
public:
    // ������Ա�
    virtual void clear()=0;	 
    // �п�
    virtual bool empty()const=0;
    // �����Ա�ĳ���
    virtual int size()const=0;	
    // ��λ��Ϊi[0..n]��λ�ò���Ԫ��value
    virtual void insert(int i,const T &value)=0;
	// ɾ��λ��Ϊi[0..n-1]��Ԫ��								
    virtual void remove(int i)=0;
    // ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
    virtual int search(const T&value)const=0; 
	// ����λ��Ϊi��Ԫ�ز�������ֵ								
    virtual T visit(int i)const=0;	
    // �������Ա�
    virtual void traverse()const=0;
    // �������Ա�
    virtual void inverse()=0;				
	// ��������						
    virtual ~List(){};
};
```

### 1.1 ˳�������Ͷ���

```c++
template <class elemType>	// elemTypeΪ˳���洢��Ԫ������
class seqList: public List<elemType>{ 
private:
    elemType *data;			// ���ö�̬����洢����Ԫ�� 
    int curLength;			// ��ǰ˳����д洢��Ԫ�ظ���
    int maxSize;			// ˳������󳤶�
    void resize();			// ����ʱ�����ռ�
public:
    seqList(int initSize = 10);		// ���캯�� 
    seqList(seqList & sl) ;			// �������캯��
    ~seqList(){ delete [] data; }	// �������� 
    void clear(){ curLength = 0; }	// ��ձ�ֻ����curLengthΪ0
    bool empty()const{return curLength==0;}// �п�
    int size()const{ return curLength; }// ����˳����е�ǰ�洢Ԫ�صĸ��� 
    void traverse()const ;		// ����˳���
    void inverse();			// ����˳���
    void insert(int i,const elemType &value);
					// ��λ��i�ϲ���ֵΪvalue��Ԫ��
    void remove(int i);          	// ɾ��λ��i�ϵ�Ԫ��
    int search(const elemType &value) const ;// ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
    elemType visit(int i) const;	  
				// ����λ��Ϊi��Ԫ�ص�ֵ����λ��0����ʾ��һ��Ԫ��
};
```

#### 1.1.1 ����һ����˳���

```c++
template <class elemType>
seqList<elemType>::seqList(int initSize=100) { 
    if (initSize <= 0) throw badSize();
    maxSize = initSize;					
    data = new elemType[maxSize];		
    curLength = 0;					
}
```

#### 1.1.2 �������캯��

�ڹ��캯���ﶯ̬�������ڴ���Դ����ʱ��Ҫ�û��Զ��忽�����캯�����������

```c++
template <class elemType>
seqList<elemType>::seqList(seqList & sl) { 
    maxSize = sl.maxSize;				
    curLength = sl. curLength;			
    data = new elemType[maxSize];	
    for (int i = 0; i < curLength; ++i)
        data[i] = sl.data[i];		
}
```

#### 1.1.3 ����˳���

```c++
template<class elemType>
void seqList<elemType>::traverse()const{
    if(empty())cout<<"is empty"<<endl;	// �ձ�
    else{
        cout<<"output element:\n";
        for (int i = 0; i < curLength; i++)	
				// ���η���˳���������Ԫ��
            cout<<data[i]<<"  ";  
        cout<<endl;  	 				
    }						
} 
```

#### 1.1.4 ����ֵΪvalue��Ԫ��

�㷨˼�룺�������Ա������Ա���ÿһ��Ԫ��������value���бȽϡ���value==data[i](0<=i<curLength)����ҳɹ�������data[i]��λ��i���������ʧ�ܷ���-1

```c++
template<class elemType>
int seqList<elemType>::search(const elemType & value) const{
    for (int i = 0; i < curLength; i++)
        if (value == data[i]) return i;
    return -1;			// ����ʧ�ܷ���-1
}
```

#### 1.1.5 ��ǰ���ͺ��

�㷨˼�룺��˳�����λ��Ϊi��Ԫ�ص�ǰ���ͺ�̣��� i==0����Ϊ��һ��Ԫ����ǰ����������ǰ���� data[i-1]���� i==curLength-1����Ϊ���һ��Ԫ���޺�̣����������� data[i+1]��ͨ��Ԫ�ص��±����ֱ�Ӷ�λ��ǰ���ͺ�̣��㷨��ʱ�临�Ӷ�ΪO(1)��

#### 1.1.6 ��������

```c++
template <class elemType>
void seqList<elemType>::insert(int i, const elemType &value){ 
    if (i < 0 || i > curLength) throw outOfRange();	
				// �Ϸ��Ĳ���λ��Ϊ[0.. curLength]
    if (curLength == maxSize) resize();	// ����������

    // �±�j-1��[curLength-1..i]��Χ��Ԫ�������ƶ�һ��
    for (int j = curLength; j > i; j--)
        data[j] = data[j-1];		
	
    data[i] = value; 		// �� value ����λ��Ϊi��λ��
    ++curLength;		// ���ʵ�ʳ�����1
}
```

**���㷨��Ҫע���������⣺**

(1) �������λ�õ���Ч�ԣ����� i ����Ч��Χ�ǣ�0��i��curLength��ע�⣺�ڱ�βԪ�� data[curLength-1] �ĺ������Ԫ�س�Ϊ�µı�β�ǺϷ��ġ�

(2) ����ռ��Ƿ����ˣ��ڱ���������²����������룬�������������󡣴�ʱ�����ֽ��������һ���ǲ�ִ�в��룬������˳�����һ�������������������������õڶ��ַ�����

(3) ע�����ݵ��ƶ����������ƶ����Ǳ�βԪ�ء�

#### 1.1.7 ɾ������

```c++
template <class elemType>
void seqList<elemType>::remove(int i) { 
    // �Ϸ���ɾ��λ��Ϊ[0.. curLength-1] 
    if (i < 0 || i > curLength-1) 
         throw outOfRange();	

    // [i+1.. curLength-1]��Χ��Ԫ����ǰ�ƶ�һ��
    for (int j = i; j < curLength - 1; j++)			 data[j] = data[j+1] ;	
			
    --curLength; 		// ���ʵ�ʳ��ȼ�1
}
```

**���㷨��Ҫע���������⣺**

(1) ���ɾ��λ�õ���Ч�ԡ�i��ȡֵ��ΧΪ��0��i��n-1��

(2) ˳���Ϊ��ʱ������ɾ������˳���Ϊ��ʱcurLength��ֵΪ0������2.6�е��б����� (i<0||i>curLength-1)�����˶Ա�Ϊ�յļ�顣

(3) ɾ����a��i  ֮�󣬸����ݱ����ǣ������Ҫ��������ֵ������ȡ����a��i������ɾ����

#### 1.1.8 ����

```c++
template<class elemType>
void seqList<elemType>::inverse() {
    elemType tmp;
    for (int i = 0; i < curLength/2; i++){			// ���ƽ����Ĵ���
        tmp = data[i];
        data[i] = data[curLength-i-1];
        data[curLength-i-1] = tmp;
    }
}
```

#### 1.1.9 �����ռ�

```c++
template <class elemType>
void seqList<elemType>::resize(){ 
    elemType *p = data;	// pָ��ԭ˳���ռ�
    maxSize *= 2;			// ��ռ�����2��
    data = new elemType[maxSize];
					// dataָ���µı�ռ�
    for (int i = 0; i < curLength; ++i)		
        data[i] = p[i];		// ����Ԫ��
    delete [] p;
}
```

#### 1.1.10 �ϲ�˳���

˳���A��B�Ľ��ؼ���Ϊ������A����B���Ԫ�ؾ��ǵݼ������Ը���һ�ָ�Ч���㷨����B����Ԫ�غϲ���A���У�ʹ�µ�A���Ԫ���Ա��ַǵݼ����򣬸�Чָ����޶ȵı����ƶ�Ԫ�ء�

```c++
template<class elemType>
bool seqList<elemType>::Union(seqList<elemType> &B){	
    int m, n, k, i, j;
    m = this->curLength; 	// ��ǰ����Ϊ���Ա�A
    n = B.curLength;		// m��n�ֱ�Ϊ���Ա�A��B�ĳ���
    k = m+n-1;		// kΪ������Ա�Ĺ���ָ�루�±꣩
    i = m-1, j = n-1;	          // i��j�ֱ�Ϊ���Ա�A��B�Ĺ���ָ�루�±꣩
    while(m+n > this->maxSize){// �ж�A��ռ��Ƿ��㹻��
        resize();			// �ռ䲻���������ռ�
    }
    while (i>=0 && j>=0)	// �ϲ�˳���ֱ��һ����Ϊ��
        if (data[i] >= B.data[j])  data[k--] = data[i--];
        else  data[k--] = B.data[j--];	// Ĭ�ϵ�ǰ����
    while(j>=0) 		// ��B���ʣ��Ԫ�ظ��Ƶ�A��
        data[k--] = B.data[j--];
    curLength = m+n; 	// �޸�A����
    return true;
}
```

### 1.2 ��������

```c++
template <class elemType>	
struct Node { 
public: 
    elemType  data;		// ������ 
    Node 	* next;	// ָ����  
    Node(const elemType value, Node* p = NULL)  {	
				// ���������Ĺ��캯�� 
        data = value; 
        next = p; 
    } 
    Node(Node* p = NULL)  { // һ�������Ĺ��캯�� 
        next = p; 
    } 
};
template <class elemType>   // elemTypeΪ������洢��Ԫ������
class linkList: public List<elemType>  { 
private:  
    struct Node { 			// �������
    public:  
        elemType  data;			// ���������� 
        Node 	* next;			// ����ָ����
        Node(const elemType value, Node* p = NULL){
					// �����ι��캯�� 
            data = value;    next = p; 
        } 
        Node(Node* p = NULL)  { 	// һ���ι��캯�� 
            next = p; 
        } 
    };
    Node*  head;			// �������ͷָ�� 
    Node*  tail;    			// �������βָ�� 
    int  curLength;			// ������ĵ�ǰ���ȣ������ռ任ʱ��
    Node*  getPosition(int i)const;	// ����ָ��λ��Ϊi��Ԫ�ص�ָ��      
public:  
    linkList();					// ���캯�� 
    ~linkList();					// �������� 
    void clear(); 				// �����������
    bool empty()const{ return head->next==NULL;}// �п�
    int size()const{ return curLength; } 	// ���ص�����ĵ�ǰʵ�ʳ���  
    void insert(int i,const elemType &value); // ��λ��i�ϲ���һ��Ԫ��value
    void remove(int i);			// ɾ��λ��i�ϵ�Ԫ��
    int search(const elemType&value)const;	
				// ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
    int prior(const elemType&value)const;	
				// ����ֵΪvalue��Ԫ�ص�ǰ����λ��
    elemType visit(int i)const; // ����λ��Ϊi��Ԫ��ֵ��0��λ����Ԫ���
    void traverse()const;			// ����������	
    void headCreate();			// ��ͷ�巨������������
    void tailCreate();				// ��β�巨������������
    void inverse();				// ���õ�����
}; 

```

#### 1.2.1 ������ĳ�ʼ��

```c++
template <class elemType>  
linkList<elemType>::linkList(){ 
    head = tail = new Node(NULL);  // ��������ͷ���Ŀձ�
    curLength=0;
}
```

#### 1.2.2 ��������

```c++
template <class elemType> 
linkList<elemType>::~linkList(){ 
    clear();				    // ��յ�����
    delete head;			    // �ͷ�ͷ���
} 
```

#### 1.2.3 ��յ�����

��յ��������Ҫ�����ǽ�����ָ���ͷ���һֱ�ƶ�������β�����ƶ�ָ����ͷŽ��

```c++
template <class elemType>  
void linkList<elemType>::clear(){ 
    Node * p, * tmp; 		// pΪ����ָ�룬ָ����Ԫ���
    p = head->next;	// ���빤��ָ����Ϊ�˷�ֹ�����޸�ͷָ��
    while (p != NULL) {	// ��Чwhile(p)
        tmp = p; 
        p = p->next;		// ָ�����
        delete tmp;			
    } 
    head->next=NULL;	// ͷ����ָ�����ÿ�
    tail = head;		// ͷβָ���ָ��ͷ���
    curLength=0;	
}
```

#### 1.2.4 ���

�����������Ͷ�����û�����ñ���curLength���ڴ洢������ô������Ҫ�ӵ�һ����㿪ʼ��һ�����һ�����ļ�����ֱ������β��

```c++
template <class elemType>  
int linkList<elemType>::size()const{  
    return  curLength;	// ֱ�ӷ���curLength
}
```

�����������Ͷ�����û�����ñ���curLength���ڴ洢������ô������Ҫ�ӵ�һ����㿪ʼ��һ�����һ�����ļ�����ֱ������β��

```c++
template <class elemType>  
int linkList<elemType>::size()const{ // ��û��curLength
    Node *p =head->next;		// ��Ҫ��ͷ��β������	
    int count=0;
    while(p){ count++; p=p->next;}
    return count;
}
```

#### 1.2.5 ��������

```c++
template <class elemType>  		
void  linkList<elemType> ::traverse()const{ 
    Node *p = head->next; // ����ָ��pָ����Ԫ���
    cout << "traverse:" ; 
    while (p != NULL) {  
        cout << p->data <<"  "; 
        p = p->next; 	    // ����ƶ�ָ
    } 
    cout << endl; 
}
```

#### 1.2.6 ����λ��Ϊi��Ԫ��

```c++
template <class elemType>  		
typename linkList<elemType> :: Node* linkList<elemType> :: getPosition(int i)const { 
    if(i < -1 || i > curLength-1)	// �Ϸ�����λ��Ϊ[-1..n-1]
        return NULL;		  	// ��i�Ƿ�ʱ����NULL
    Node *p = head;      		// ����ָ��pָ��ͷ���
    int count = 0; 
    while(count <= i) { 
        p = p-> next; 
        count++; 
    } 
    return p;				// ����ָ��λ��Ϊ i �Ľ���ָ�� 
}
```

#### 1.2.7 ����ֵΪvalue��Ԫ�ص�λ��

```c++
template <class elemType>  			
int linkList<elemType> ::search(const elemType&value)const{ 
    Node *p = head->next; 	// ����ָ��pָ����Ԫ���
    int count = 0;		// ��Ԫ����λ��Ϊ0
    while(p != NULL && p->data != value) {   
        p = p->next; 
        count++;
    } 
    if(p == NULL)return -1;	// ����ʧ�ܷ���-1������-1����ͷ���
    else return count; 		// ���ҳɹ���countΪԪ�ص�λ��
}  
```

#### 1.2.8 ����ֵΪvalue��Ԫ�ص�ǰ����λ��

��ֵΪvalue��Ԫ�ص�ǰ������Ҫ������ĵ�һ����㿪ʼ��������������������ָ��p��pre���ֱ�ָ��ǰ���ڷ��ʵĽ�������ǰ����㣬����Ҫһ��������count��������ĵ�һ����㿪ʼ��������
(1) ��p == NULL�������ֵΪvalue��Ԫ��ʧ�ܣ�����-1��
(2) ������ֵΪvalue��Ԫ�سɹ����Ҹ�Ԫ������Ԫ��㣬����ǰ��������-1��
(3) ������ֵΪvalue��Ԫ�سɹ����Ҹ�Ԫ�ز�����Ԫ��㣬�򷵻���ǰ����λ��

```c++
template <class elemType>  
int linkList<elemType> ::prior(const elemType&value)const{
    Node *p = head->next; 	// p�ǹ���ָ��ָ����Ԫ���
    Node *pre = NULL; 	// preָ��p��ǰ�����
    int count = -1;		// ע�⣺-1��ʾ��Ԫ�����ǰ��
    while(p &&p->data != value){
        pre = p; 		// ǰ��ָ�����
        p = p->next; 		// ָ���¸���������
        count++;
    }
    if(p == NULL) return -1;	// ����ʧ�ܷ���-1������-1����ͷ���
    else return count; 		// ���ҳɹ���countΪԪ�ص�λ��
}

```

#### 1.2.9 ����Ԫ��

��λ��Ϊi��λ�ò���ֵΪvalue���½��q����Ҫ���ҵ�λ��Ϊi-1�Ľ��p����q��ָ����ָ��pԭ���ĺ�̣�Ȼ���޸�p�ĺ��Ϊq

```c++
template  <class elemType>  			 	
void linkList<elemType> :: insert(int i,const elemType &value)  { 
    Node *p, *q; 
    if (i < 0 || i > curLength)		// �Ϸ��Ĳ���λ��Ϊ[0..n]
        throw outOfRange();		// ����λ�÷Ƿ����׳��쳣
    p = getPosition(i-1);		// p��λ��Ϊi�Ľ���ǰ�� 
    q = new Node(value, p->next); 	// �����½��q
    p->next = q; 			// q�����뵽p���ĺ���
    if (p == tail)tail = q;		// ��������ڱ�β��q��Ϊ�µı�β
    curLength++;
}
```

#### 1.2.10 ɾ��Ԫ�� 

ɾ��λ��Ϊi�Ľ��

```c++
template  <class elemType>  				
void  linkList<elemType>::remove(int i){ 
    Node *pre, *p;  		// p�Ǵ�ɾ��㣬pre����ǰ��
    if (i < 0 || i > curLength-1) // �Ϸ���ɾ��λ��Ϊ[0..n-1] 
        throw outOfRange();	// ����ɾ��㲻����ʱ���׳��쳣
    pre = getPosition(i-1);
    p = pre->next;		// p��������ɾ��� 
    if (p == tail) {		// ��ɾ���Ϊ��β��㣬���޸�βָ�� 
        tail = pre;    pre->next=NULL;    
    } 
    else {  pre->next = p->next; }
    delete p; 
    curLength--;
}
```

#### 1.2.11 ͷ�巨����������

```c++
template <class elemType>  		 
void linkList<elemType> :: headCreate(){// ͷ�巨����������
    Node *p; 
    elemType value,flag;
    cout<<"input elements,ended with:";
    cin>>flag;			  // ���������־
    while(cin>>value,value != flag){
        // �����½��p->data = value, p->next = head->next
        p = new Node(value,head->next); 
        head->next = p;	  // ���p���뵽ͷ���ĺ���
        if(head == tail) tail = p;// ԭ����Ϊ�գ��½��p��Ϊ��β���
        curLength++;
    }
}
```

#### 1.2.12 β�巨���������� 

```c++
template <class elemType>  					
void linkList<elemType> ::tailCreate(){// β�巨��������
    Node *p; 
    elemType value,flag;
    cout<<"input elements,ended with:";
    cin>>flag;				// ���������־
    while(cin>>value,value!=flag){
        p=new Node(value,NULL);
        tail->next=p;			// ���p���뵽��β���ĺ���
        tail=p;				// ���p��Ϊ�µı�β
        curLength++;
    }
}
```

#### 1.2.13 ���õ�����

�ù���ָ��p���η��������е�ÿ����㣬ÿ����һ����㣬�������뵽ͷ���ĺ��棨ͷ�巨����

```c++
template <class elemType>  
void linkList<elemType> :: inverse(){// ͷ�巨����
    Node *p,*tmp;
    p=head->next;		// pΪ����ָ��ָ����Ԫ���
    head->next=NULL;	// ͷ����ָ�����ÿգ����ɿ�����
    if(p)tail=p;			// ���ú�ԭ��Ԫ��㽫��ɱ�β���
    while(p){
        tmp=p->next;		// �ݴ�p�ĺ��
        p->next=head->next;		
        head->next=p;	// ���p���뵽ͷ���ĺ���
        p=tmp; 		// ����������һ�����
    }
}
```

�ϲ�����
���ǵݼ�����ĵ�����la��lb�ϲ����µķǵݼ���������lc��Ҫ������ԭ��ռ䡣
�㷨˼�룺��Ϊ�´����ĵ�����lc��Ȼ�Ƿǵݼ�����ģ�������β�巨����lc��
[����2.24]��������ĳ�Ա����ʵ�֣�la��Ϊthisָ����ָ��ĵ�ǰ����

```c++
template <class elemType> 
typename linkList<elemType> * linkList<elemType> ::Union(linkList<elemType> * lb){
    Node *pa,*pb,*pc;		// �ֱ�������la��lb��lc�Ĺ���ָ��
    linkList<elemType>* lc = this;	// lc������la��ռ�
    pa=head->next;  head->next=NULL;	// la���ɿ�����
    pb=(lb->head)->next;  (lb->head)->next=NULL;// lb���ɿ�����
    pc=lc->head;
    while(pa && pb){		// la��lb���ǿ�
        if(pa->data<=pb->data) {	// pa��ָ���β�巨����lc��
            pc->next=pa;  pc=pa;  pa=pa->next;    
        }
        else{			// pb��ָ���β�巨����lc��
            pc->next=pb;  pc=pb;  pb=pb->next;   
        }
    }
    if(pa){ 			// ��paδ��β����pcָ��pa
        pc->next=pa;						
        lc->tail=tail;		// �޸�βָ�룬��lc=la����������ʡ��
    }
    else{
        pc->next=pb;		// ��pbδ��β����pcָ��pb
        lc->tail=lb->tail;	// �޸�βָ��
    }
    lc->curLength = curLength+lb->curLength;
    delete lb;	 return lc;
}
```












































