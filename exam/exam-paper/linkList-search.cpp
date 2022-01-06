/*********Begin**********  ��  **********End**********����ɾ��
��*********Begin*********  ��  ********End********֮������
Ҫ��ʹ��ָ���������������������������������ȣ���д©д���÷�

��֪����������Ͷ������£�
��ʵ�ֲ����㷨int search(const elemType&value)const; ����ֵΪvalue��Ԫ�ص�һ�γ���ʱ��λ������Ϊn����λ��ΧΪ0~n-1�������أ�������ʧ�ܷ���-1��
ע�⣺�뽫���ڱ�������Ĺ���ָ������Ϊp��

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
    int search(const elemType&value)const;			// ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
����
}; 
*/
/***************begin***************/
template <class elemType>
int linkList<elemType>::search(const elemType& value)const
{
	Node *p=head->next;
	int count=0;
	while(p!=NULL && p->data!=value)
	{
		p=p->next;
		count++;
	}
	if(p==NULL)
	return -1;
	else return count;
 } 

/****************end****************/
