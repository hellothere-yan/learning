# list用法

1、list<type>l1(n,val)，声明一个有n个元素的列表，每个元素都是val。l1(n),声明n个元素的列表。

2、begin(),end(),用于得到list容器的指向第一个元素的itertor和末端的下一个位置。

3、push_front(),push_back(),用于在list中头部和尾部插入元素。

4、empty（），用于判断是否为空。

5、resize(n),使list长度变为n，多余的将会被删除。resize(n,val),将n个val插入到list尾端。

6、front(),back(),返回list的头部元素和尾部元素。使用前要判断是否为空。

7、pop_back()，pop_front()，返回尾部和首部的第一个元素，并且删除。使用前要判断是否为空。

8、assign（），L1.assign（L2.begin(),L2.end()），将L2中的元素赋给L1。

9、L1.swap（L2），交换链表。

10、merge（），合并两个链表使之默认升序。L1.merge(L2,great<int>());**调用结束之后L2变为空。**

11、insert（），

​					l1.insert(l1.begin(),100); 在l1的开始位置插入100。

​					l1.insert(l1.begin(),2,200); 在l1的开始位置插入2个100。

​					l1.insert(l1.begin(),l2.begin(),l2.end());在l1的开始位置插入l2的从开始到结束的所有位置的元素。