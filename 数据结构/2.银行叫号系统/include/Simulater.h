#ifndef SIMULATER_H
#define SIMULATER_H

#include<iostream>
#include <queue>//����
#include<vector>
#include<windows.h>
#include"NormalUser.h"
#include"User.h"
#include"VIPUser.h"
#include"OfficialUser.h"
#include"NormalBankWindow.h"
#include"VIPBankWindow.h"
#include"OfficialBankWindow.h"
using namespace std;
static int serveTime=4;//ÿ���û��ķ���ʱ��
static int timeInterval=2;//ʱ����
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
						nbw[j].isBusy=false;
					    nbw[j].client.id=-1;
					}
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
							cout<<"111111"<<NormalUserQueue.size()<<endl;
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
			cout<<"��"<<user.id<<"��"<<user.type<<"��"<<window.type<<window.id<<"����ҵ��"<<endl;
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
		for(int i=0;i<=12;i++)
		{
			cout<<endl<<endl<<"��ǰʱ��Ϊ"<<i<<"s��"<<endl<<endl;
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
			//system("cls");
		}
	}

    protected:
    private:
};

#endif // SIMULATER_H
