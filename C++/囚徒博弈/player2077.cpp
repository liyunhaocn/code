class Player2077: public Player    //��ѧ�ź���λΪ���������������PlayXXXX
{
private:
  
    /*�ڴ˴��Զ���ע�͵���ʽ˵������ӵ����ݵ���;
	* oppHistory���ڱ����ȥ2�β��Ķ��ֵĲ���
	*/
	int sum_oppscore;//������ֵ�ǰ���ܷ�
	int sum_myscore; //�����ҵ��ܷ�
	int myoppstra;   //�ҵ���һ�ֲ���
	int sum_oppstra; //���ֵ���һ�ֲ��Ժ�
	int i;           //��ǰ�ִ� 
public :
	//�����ṩ�޲ι��캯��
    Player2077()
	{   
		id = 2077;       //����id 
		sum_oppscore=0;  //��ʼ�����ֵ�ǰ�÷�
		sum_myscore=0;   //��ʼ���ҵĵ�ǰ�÷�
		myoppstra=1;     //��ʼ���ҵ�һ�ֵĲ���
	    sum_oppstra=0;   //��ʼ��������һ�ֲ��ۺ�
	    i=0;             //��ʼ����ǰ�ִ�
	}   
	
	
	/*һ��ͳ�ƶ��ֺ��ҵĵ�ǰ�÷֣����Է��ķ�����ȥ�ҵķ���С�ڵ���2����һ�ֺ�������

����*/
	int nextStra()    //���¶���ú����������Player��������߼�����
	{ 
		i++;
        if(i<=21)
		{
	 	    if (sum_oppscore-sum_myscore<=7)
			{   
			myoppstra=1;
			return 1;
			}
			else 
			{
				myoppstra=0;
				return 0 ;
			}
		}
		
		else if(i>21 && i<100)
            if (sum_oppscore-sum_myscore<=6)
			{   
			   myoppstra=1;
			   return 1;
			}
			else 
			{
				myoppstra=0;
				return 0 ;
			}
		else 
		{
		  if (sum_oppscore-sum_myscore<=4)
			{   
			   myoppstra=1;
			   return 1;
			}
			else 
			{
				myoppstra=0; 
				return 0 ;
			} 
		}
		
	
	}
    
	void setOppStra(int oppS)
	{
		sum_oppstra+=oppS;
		if(oppS==1 && myoppstra==1)
		{
	     sum_oppscore+=3;
         sum_myscore+=3;
		}
		else if(oppS==1 && myoppstra==0)
		{
	     sum_oppscore+=5;
         sum_myscore+=0;
		}
		else if(oppS==0 && myoppstra==1)
		{
	     sum_oppscore+=5;
         sum_myscore+=0;
		}
		else
		{
	     sum_oppscore+=1;
         sum_myscore+=1;
		}

	}

	void reset()   // �ָ�����ʼ����
	{
		Player::reset();
		sum_oppscore=0;  
		sum_myscore=0;   
		myoppstra=1;
	    sum_oppstra=0; 
	    i=0;           
             //������ӵ����ݽ���reset
	} 
}; 
