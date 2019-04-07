#include "obs.h"
#include <stdlib.h>
 
int main()
{
	NEWS *ChinaDaily = new newsA();//见注4。
	Observe *xiaoming = new obsA("xiaoming", ChinaDaily);
	Observe *xiaowang = new obsB("xiaowang", ChinaDaily);
	Observe *xiaozhang = new obsC("xiaozhang", ChinaDaily);
	ChinaDaily->add(xiaoming);//添加订阅者名单
	ChinaDaily->add(xiaowang);
	ChinaDaily->add(xiaozhang);
	ChinaDaily->Show();//输出订阅者名单
	cout << endl;
	ChinaDaily->act = "ChinaDaily有新报纸派送啦";//报社做出反应
	ChinaDaily->notify();//通知订阅者
	cout << endl;
	ChinaDaily->Delete(xiaozhang);
	ChinaDaily->Show();
	cout << endl;
	return 0;
}