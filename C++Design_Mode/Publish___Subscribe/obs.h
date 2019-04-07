#ifndef   _OBS_H
#define   _OBS_H
#include<string>
#include<list>
#include<iostream>
using namespace std;
class NEWS;//因Observe中有NEWS对象，所以要先声明。
class Observe//声明一个抽象观察者类；
{
public:
	string name;//定义观察者名单，声明为公用的是因为在主题NEWS中输出了观察者名单。
	NEWS* news;//定义了主题对象
public:
	Observe();//默认构造函数
	~Observe();//析构函数
	Observe(string n_name, NEWS*n_news):name(n_name), news(n_news)//见注1。
	{
	}
	virtual void update() = 0;//声明纯虚函数。见注2。
};
Observe::Observe() {}//默认构造函数
Observe::~Observe() {}//析构函数
class obsA :public Observe//定义具体观察者obsA
{
public:
	obsA();
	~obsA();
	obsA(string name, NEWS*news) :Observe(name, news)
	{
 
	}
	void update();//观察者obsA收到消息更新自己的动作。
};
class obsB :public Observe
{
public:
	obsB();
	~obsB();
	obsB(string name, NEWS*news) :Observe(name, news)
	{
 
	}
	void update();//观察者obsB收到消息更新自己的动作。
};
class obsC :public Observe
{
public:
	obsC();
	~obsC();
	obsC(string name, NEWS*news) :Observe(name, news)
	{
 
	}
	void update();//观察者obsC收到消息更新自己的动作。
};
class NEWS//定义抽象基类新闻类
{
protected:
	list<Observe*>Obs;//观察者模式的核心--在一个对象中存在另一个对象的链表
public:
	string act;
	virtual void add(Observe*) = 0;
	virtual void Delete(Observe*) = 0;
	virtual void notify() = 0;
	virtual void Show() = 0;
};
class newsA :public NEWS//抽象新闻类实例化
{
public:
	void add(Observe*obs)//添加订阅者
	{
		Obs.push_back(obs);
	}
	void Delete(Observe*obs)//删除订阅者
	{
		list<Observe*>::iterator it;
		for (it = Obs.begin(); it != Obs.end(); )//见注3。
		{
			if ((*it) == obs)
            {    
                it=Obs.erase(it);
            }
            else
            {
                it++;
            }
				
		}
	}
	void Show()
	{
		list<Observe*>::iterator it;
		cout << "当前订阅人员名单:" << endl;
		for (it = Obs.begin(); it != Obs.end(); it++)//注意begin和end后面的括号不要忘记了
		{
			cout <<(*it)->name << endl;//公有化观察者对象成员name。
		}
	}
	void notify()
	{
		list<Observe*>::iterator it;
		for (it = Obs.begin(); it != Obs.end(); it++)
		{
			(*it)->update();//观察者模式的另一个核心--通知所有观察者对象的函数
		}
	}
 
};
obsA::obsA(){}
obsA::~obsA() {}
void obsA::update()
{
	cout << name << " 收到消息：" << news->act << endl;
	cout << "我不想看，扔掉" << endl;
}
obsB::obsB() {}
obsB::~obsB() {}
void obsB::update()
{
	cout << name << " 收到消息：" << news->act << endl;
	cout << "放在桌子上，一会去看" << endl;
 
}
obsC::obsC() {}
obsC::~obsC() {}
void obsC::update()
{
	cout << name << " 收到消息：" << news->act << endl;
	cout << "不想看China Daily的报纸了，打电话告诉出版社取消订阅" << endl;
 
}
#endif