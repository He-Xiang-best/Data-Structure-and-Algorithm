/*********Begin**********  ��  **********End**********����ɾ��
��*********Begin*********  ��  ********End********֮������
Ҫ��ʹ��ָ���������������������������������ȣ���д©д���÷�

��֪����������Ͷ������£�
��ʵ���㷨int size()const;������ĳ��ȡ�ע�⣺�뽫���ڱ�������Ĺ���ָ������Ϊp������������Ϊcount��

����������Ͷ��壺
template <class elemType>						// elemTypeΪ������洢��Ԫ������
class linkList { 
private:  
    struct Node { 							// �������
    public:  
        elemType  data;						// ���������� 
        Node 	* next;						// ����ָ����
        Node(const elemType value, Node* p = NULL){	// ���������Ĺ��캯�� 
            data = value;    next = p; 
        } 
        Node(Node* p = NULL)  { 					// һ�������Ĺ��캯�� 
            next = p; 	
        } 
    };
    Node*  head;							// �������ͷָ��    
public:  
    linkList();							// ���캯�� 
    ~linkList();							// �������� 
    int size()const;						// ���ص�����ĵ�ǰʵ�ʳ���  
����
}; 

*/
/***************begin***************/

template <class elemType>
int linkList<elemType>::size()const{ // ��û��curLength
    Node *p =head->next;		// ��Ҫ��ͷ��β������
    int count=0;
    while(p){ count++; p=p->next;}
    return count;
}

/****************end****************/












