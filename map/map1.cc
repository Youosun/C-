#include <iostream>
#include <map>
#include <string>
using namespace std;

void test0()
{
	pair<int, string> t(600036, "招商银行");
	//std::map中存放的是std::pair<const typename T, typename I>
	//std::pair 中第一个类型是const 主键 不能更改
	cout << t.first << " --> " << t.second << endl;
	//t.first  返回键值对pair 的 key
	//t.second 返回键值对pair 的 value
}

void test1()
{
	pair<int, string> t(9, "Asia");
	
	//1.map中只能存放关键字不同的元素  
	//2.默认情况下，内部元素按照关键字以升序方式进行排列
	map<int, string> mapIntStr{
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "America"),
	};

	map<int, string>::iterator it;
	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}

	cout << mapIntStr[1] << endl; //读操作   根据关键字访问其值
	cout << mapIntStr[4] << endl;
	cout << mapIntStr[9] << endl;
	cout << mapIntStr[3] << endl; //访问不存在的关键字  返回空

	mapIntStr[4] = "America";//修改关键字所对应的值
							//重载了下标访问运算符  但并不是随机访问，时间复杂度仍然是log(n)
	mapIntStr[2] = "Austrilia";//数据即代码的风格
	mapIntStr[3] = "Antarctic";

	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}
}

void test2()
{
	map<int, string> mapIntStr{
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		pair<int, string>(4, "America"),
	};

	map<int, string>::const_iterator it;
	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}


	//第一次添加元素
	pair<int, string> t1(2, "Antarctic");
	pair<map<int, string>::iterator, bool> ret = mapIntStr.insert(t1);   //map.insert()的返回值 为 pair<map::iterator, bool> 类型的键值对   bool表示是否插入成功  无论插入成功与否iterator 都指向关键字相同的元素 
	//auto ret = mapIntStr.insert(t1);//使用auto关键字自动推导返回值类型
	if(ret.second)
	{
		cout << "insert success" << endl;
	}
	else{
		cout << "容器中已有相同关键字的元素，添加失败" << endl;
	}
	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}


	//第二次插入元素
	ret = mapIntStr.insert(std::make_pair(3, "Antarctic"));
	if(ret.second)
	{
		cout << "insertion success" << endl;
	}
	else{
		cout << "same key existed, insertion failed" << endl;
	}

	for(it = mapIntStr.begin(); it != mapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}
}

int main(void)
{
//	test0();
//	test1();
	test2();

	return 0;
}
