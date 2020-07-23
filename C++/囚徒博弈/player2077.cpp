class Player2077: public Player    //用学号后四位为你的类命名，形如PlayXXXX
{
private:
  
    /*在此处以多行注释的形式说明你添加的数据的用途
	* oppHistory用于保存过去2次博弈对手的策略
	*/
	int sum_oppscore;//计算对手当前的总分
	int sum_myscore; //计算我的总分
	int myoppstra;   //我的上一轮策论
	int sum_oppstra; //对手的上一轮策略和
	int i;           //当前局次 
public :
	//必须提供无参构造函数
    Player2077()
	{   
		id = 2077;       //命名id 
		sum_oppscore=0;  //初始化对手当前得分
		sum_myscore=0;   //初始化我的当前得分
		myoppstra=1;     //初始化我第一轮的策略
	    sum_oppstra=0;   //初始化对手上一轮策论和
	    i=0;             //初始化当前轮次
	}   
	
	
	/*一、统计对手和我的当前得分，若对方的分数减去我的分数小于等于2，下一轮合作，否

则背叛*/
	int nextStra()    //重新定义该函数，让你的Player按照你的逻辑博弈
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

	void reset()   // 恢复到初始设置
	{
		Player::reset();
		sum_oppscore=0;  
		sum_myscore=0;   
		myoppstra=1;
	    sum_oppstra=0; 
	    i=0;           
             //对新添加的数据进行reset
	} 
}; 
