#include<iostream>
#include <queue>//����
#include <vector>//�ܹ�����������Ķ�̬���飬��û���õ�
#include <windows.h>
using namespace std;
int serveTime=4;//ÿ���û��ķ���ʱ��
class User//�û���
{
public:
	int id;//�û�ID
	int isWait;//�ȴ�ʱ��
	int arriveTime;//����ʱ��
	int serveTime;//��ʼ����ʱ��
	char *type;//�û�����
	User(){type=NULL;}//���캯��
	User(int id, int isWait,int arriveTime,int serveTime,char *type)
	{
		this->id=id;
		this->isWait=isWait;
		this->arriveTime=arriveTime;
		this->serveTime=serveTime;
		this->type=type;
	}
	void getServed()//�������
	{
		cout<<this->type<<this->id<<"�뿪���С�"<<endl;
	}
};
//��ͨ�û�
class NormalUser: public User
{
public:
	NormalUser(){}
	NormalUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"��ͨ�û�")
	{}
	void getServed()
	{
		cout<<this->type<<this->id<<"�뿪���С�"<<endl;
	}
};
//VIP�û�
class VIPUser: public User
{
public:
	VIPUser():User(){}
	VIPUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"VIP�û�"){}
	void getServed()
	{
		cout<<this->type<<this->id<<"�뿪���С�"<<endl;
	}
};
//�����û�
class OfficialUser: public User
{
public:
	OfficialUser():User(){}
	OfficialUser(int id, int isWait,int arriveTime,int serveTime):User(id,isWait,arriveTime,serveTime,"�����û�"){}
	void getServed()
	{
		cout<<this->type<<this->id<<"�뿪���С�"<<endl;
	}
};
//������
class BankWindow
{
public:
	bool isBusy;//�����Ƿ�æ
	int id;//����ID
	User client;//�û�
	char *type;//��������
	BankWindow(){type=NULL;}//���캯��
	BankWindow(bool isBusy,int id,User client,char *type)
	{
		this->isBusy=isBusy;
		this->id=id;
		this->client=client;
		this->type=type;
	}
	void HandleUser()//�����û�����
	{
		cout<<this->type<<this->id<<"����Ϊ"<<this->client.type<<this->client.id<<"����"<<endl;
	}
};
//��ͨ����
class NormalBankWindow: public BankWindow
{
public:
	NormalBankWindow():BankWindow(){}
	NormalBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"��ͨ����"){}
};
//VIP����
class VIPBankWindow: public BankWindow
{
public:
	VIPBankWindow():BankWindow(){}
	VIPBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"VIP����"){}
};
//���ô���
class OfficialBankWindow: public BankWindow{
public:
	OfficialBankWindow():BankWindow(){}
	OfficialBankWindow(bool isBusy,int id,User client):BankWindow(isBusy,id, client,"���ô���"){}
};
//ģ����
class Simulater
{
public:
	queue<NormalUser> NormalUserQueue;//��ͨ�û�����
	queue<VIPUser> VIPUserQueue;//VIP�û�����
	queue<OfficialUser> OfficialUserQueue;//�����û�����
	vector<NormalBankWindow> nbw;//��ͨ��������
	vector<VIPBankWindow> vbw;//VIP��������
	vector<OfficialBankWindow> obw;//���ô�������
	Simulater(){}//���캯��
	bool IsServed(int time,User user)
	{
		if(time-user.serveTime>=serveTime)
			return true;
		return false;
	}
	//�û����
	void customerEnter(User user)
	{
		if(user.type=="��ͨ�û�")
		{
			this->NormalUserQueue.push((NormalUser&)user);
		}
		else if(user.type=="VIP�û�")
		{
			this->VIPUserQueue.push((VIPUser&)user);
		}
		else
		{
			this->OfficialUserQueue.push((OfficialUser&)user);
		}
	}
	//ģ���û���������
	void simulaterCustomerEnter(User user)
	{
		this->customerEnter(user);
		cout<<user.type<<user.id<<"��������"<<endl;
	}
	//ģ��к�
	void simulaterCallCustomer(int time)
	{
		//�����ͨ�����Ƿ��п��е�
		for(int j=0;j<nbw.size();j++)
			{
				//���ڿ��л��߸ô��ڵ��û��պð���ҵ��
				if(nbw[j].isBusy&&this->IsServed(time,nbw[j].client)||!(nbw[j].isBusy))
				{
					//���ڵ��û��պð���ҵ�񣬸��û��뿪����
					if(nbw[j].isBusy&&this->IsServed(time,nbw[j].client))
					{
						nbw[j].client.getServed();
					}
					nbw[j].isBusy=false;
					nbw[j].client.id=-1;
					//����ͨ�û������Ŷӣ����и��û������д��ڰ���ҵ��
					if(!this->NormalUserQueue.empty()){
						NormalUser user=this->NormalUserQueue.front();
						this->NormalUserQueue.pop();
						this->callCustomer(user,nbw[j],time);
					}
				}
				//�������ڷ����û�
				else{
					nbw[j].HandleUser();
				}
			}
		//���VIP�����Ƿ��п��е�
		for(int j=0;j<vbw.size();j++)
		   {
			   //���ڿ��л��߸ô��ڵ��û��պð���ҵ��
				if(vbw[j].isBusy&&this->IsServed(time,vbw[j].client)||!(vbw[j].isBusy))
				{
					//���ڵ��û��պð���ҵ�񣬸��û��뿪����
					if(vbw[j].isBusy&&this->IsServed(time,vbw[j].client))
					{
						vbw[j].client.getServed();
					}
					vbw[j].isBusy=false;
					vbw[j].client.id=-1;
					//û��VIP�û������Ŷ�
					if(this->VIPUserQueue.empty()){
						//����ͨ�û������Ŷ�
						if(!this->NormalUserQueue.empty()){
							NormalUser user=this->NormalUserQueue.front();
							this->NormalUserQueue.pop();
							this->callCustomer(user,vbw[j],time);
						}
					}
					//��VIP�û������Ŷ�
					else{
						VIPUser user=this->VIPUserQueue.front();
						this->VIPUserQueue.pop();
						this->callCustomer(user,vbw[j],time);
					}
				}
				//�������ڷ����û�
				else{
					vbw[j].HandleUser();
				}
		   }
		//��鹫�ô����Ƿ��п��е�
		for(int j=0;j<obw.size();j++)
		   {
			    //���ڿ��л��߸ô��ڵ��û��պð���ҵ��
				if(obw[j].isBusy&&this->IsServed(time,obw[j].client)||!(obw[j].isBusy))
				{
					//���ڵ��û��պð���ҵ�񣬸��û��뿪����
					if(obw[j].isBusy&&this->IsServed(time,obw[j].client))
					{
						obw[j].client.getServed();
					}
					obw[j].isBusy=false;
					obw[j].client.id=-1;
					//û�й����û������Ŷ�
					if(this->OfficialUserQueue.empty())
					{
						//����ͨ�û������Ŷ�
						if(!this->NormalUserQueue.empty()){
							NormalUser user=this->NormalUserQueue.front();
							this->NormalUserQueue.pop();
							this->callCustomer(user,obw[j],time);
						}

					}
					//�й����û������Ŷ�
					else
					{
						OfficialUser user=this->OfficialUserQueue.front();
						this->OfficialUserQueue.pop();
						this->callCustomer(user,obw[j],time);
					}
				}
				//�������ڷ����û�
				else
				{
					obw[j].HandleUser();
				}
		   }
	}
	//��ʾ�����û�
	void callCustomer(User user,BankWindow &window,int time){
		if(window.isBusy)
			return;
		else{
			//��user������window����ҵ��
			window.isBusy=true;
			user.serveTime=time;
			user.isWait=time-user.arriveTime;
			window.client=user;
			cout<<"��"<<user.id<<"��"<<user.type<<"�ͻ���"<<window.type<<window.id<<"����ҵ��"<<endl;
		}
	}
	//��ʼ��
	void Initialize()
	{
		//��ʼ��������ͨ���ڣ�1��VIP���ڣ�1�����ô���
		NormalUser user(-1,0,0,0);
		NormalBankWindow nbw1(false,1,user);
		NormalBankWindow nbw2(false,2,user);
		NormalBankWindow nbw3(false,3,user);
		VIPBankWindow vbw1(false,4,user);
		OfficialBankWindow obw1(false,5,user);
		nbw.push_back(nbw1);
		nbw.push_back(nbw2);
		nbw.push_back(nbw3);
		vbw.push_back(vbw1);
		obw.push_back(obw1);
	}
	//ģ��������
	void simulate(){
		int id=1;
        this->Initialize();
		for(int i=0;i<=12;i+=1)
		{
			cout<<"      "<<"��ǰʱ��Ϊ"<<i<<"s��"<<endl<<endl;
			//��0s��2s��6sʱ�����¿ͻ��������У�ģ���û���������
			if(i==0)
			{
				for(int j=0;j<3;j++)
				{
					NormalUser nu(id++,0,i,0);
					this->simulaterCustomerEnter(nu);
				}
				VIPUser vu(id++,0,0,0);
				this->simulaterCustomerEnter(vu);
				OfficialUser ou(id++,0,0,0);
				this->simulaterCustomerEnter(ou);
			}
			if(i==2)
			{
				for(int j=0;j<5;j++)
				{
					NormalUser nu(id++,0,i,0);
					this->simulaterCustomerEnter(nu);
				}
			}
			if(i==6)
			{
				for(int j=0;j<5;j++)
				{
					NormalUser nu(id++,0,i,0);
					this->simulaterCustomerEnter(nu);
				}
				VIPUser vu(id++,0,i,0);
				this->simulaterCustomerEnter(vu);
			}
			//ģ��к�
			this->simulaterCallCustomer(i);
			//����Ƿ����û������Ŷ�
			if(NormalUserQueue.empty()&&VIPUserQueue.empty()&&OfficialUserQueue.empty())
			{
				cout<<"û���û������Ŷӣ�"<<endl;
			}
			else
			{
				cout<<"��"<<NormalUserQueue.size()+VIPUserQueue.size()+OfficialUserQueue.size()<<"���û������Ŷӣ�"<<endl;
			}
			//˯��2s
			Sleep(2000);
			system("cls");
		}
	}
};
int main()
{

	Simulater simulater;
	simulater.simulate();

	return 0;
}
