//本阶段主要针对c++泛型编程和STL技术做详解
//c++提供两种模板机智 函数模板和类模板
//函数模板作用 建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表
//语法
//template<typename T>
// template  声明创建模板
//typename  表明其后面的符号是一种数据类型 可以用class代替
//函数声明或定义
//#include<iostream>
//using namespace std;
//template<typename T>
//void myswap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//void test()
//{
//	int a = 10;
//	int b = 20;
//	//自行类型推导
//	myswap(a, b);
//	cout << "a=" << a << "b=" << b << endl;
//	double c = 2.5;
//	double d = 1.5;
//	//显示指定类型
//	myswap<double>(c, d);
//	cout << "a=" << c <<endl<< "b=" << d << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//template<typename T>
//void myswap(T& a, T& b)
//{
//	T temp=a;
//	a = b;
//	b = temp;
//	
//}
//template<typename T>
//void mySort(T arr[], int len)
//{
//	int i = 0;
//	int max;
//	for (i = 0; i < len; i++)
//	{
//		max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[j] > arr[max])
//			{
//				if (max != j)
//				{
//					myswap(arr[j], arr[max]);
//				}
//			}
//		}
//	}
//}
//template<typename T>
//void myprint(T arr[],int n)
//{
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cout << arr[i];
//	}
//	cout << endl;
//}
//void test()
//{
//	char arr[] = "efcda";
//	int num = sizeof(arr) / sizeof(arr[0]);
//	mySort(arr,num);
//	myprint(arr, num);
//	int arr2[] = { 7,4,7,5,1 };
//	int s = sizeof(arr2) / sizeof(arr2[0]);
//	mySort(arr2, s);
//	myprint(arr2, s);
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//普通函数调用可以发生隐式类型转换
//函数模板 用自动类型推导，不可以发生隐式类型转换
//函数模板 用显示指定类型，可以发生隐式类型转换
 
//如果函数模板和普通函数都可以实现，优先调用普通函数
//可以通过 空模板参数列表 来强制调用模板函数
//myPrint<>(a,b)
//函数模板也可以重载
//如果函数模板可以产生更好的匹配有限调用函数模板

//函数模板的局限性
//利用具体化Person的版本实现代码，具体化优先调用
//template<>	bool mycompare(Person& p1, Person& p2)
//{
//	if (p1.name == p2.name && p1.age == p2.age)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//利用具体化的模板，可以解决自定义类型的通用化

//类模板没有自动类型推导的使用方式
//类模板在模板参数列表中可以有默认参数
//template<class Nametype,class agetype=int>
//
//类模板的成员函数在调用时才会创建
//
//类模板对象做函数参数
//类模板实例化出的对象，向函数传参的方式
//1、指定传入的类型  直接显示对象的数据类型
//2、参数模板化      将对象中的参数变为模板进行传递
//3、整个类模板化    将这个对象类型 模板化进行传递

//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class Person
//{
//public:
//	T1 m_name;
//	T2 m_age;
//	Person(T1 name, T2 age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//	void showname()
//	{
//		cout << "姓名：" << m_name << endl << "年龄:" << m_age << endl;
//	}
//};
////1、指定传入的类型
//void myprint(Person<string,int> &p)
//{
//	p.showname();
//}
//void test1()
//{
//	Person<string, int> p1("小桀", 31);
//	myprint(p1);
//}
////2、参数模板化
//template<class T1,class T2>
//void myprint1(Person<T1, T2> &p)
//{
//	p.showname();
//	cout << "T1类型" << typeid(T1).name() << endl;
//	cout << "T1类型" << typeid(T2).name()<< endl;
//}
//void test2()
//{
//	Person<string, int> p2("老桀", 32);
//	myprint1(p2);
//}
////3、整个类模板化
//template<class T>
//void myprint2(T &p)
//{
//	p.showname();
//	cout << "T1类型" << typeid(T).name() << endl;
//}
//void test3()
//{
//	Person<string, int> p3("小武", 24);
//	myprint2(p3);
//}
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}

//当子类继承的父类是一个类模板时，子类在声明的时候，需要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的类型，子类也需变为类模板
//template<class T1,class T2>
//class Son:Person<T1>
//{
//	T2 name;
//};

//类模板分文件编写
//类模板中成员函数创建时机是在调用阶段，导致分文件编写时连接不到
//解决方式1 直接包含cpp文件
//解决方式2 将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制

//全局函数类外实现
//加空模板参数列表  并且需要让编译器提前知道这个函数 的存在


//类模板案例
//可以对内置数据类型以及自定义数据类型的数据进行存储
//将数组中的数据存储到堆区
//构造函数中可以传入数组的容量
//提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//提供尾插法和尾删法对数组中的数据进行增加和删除
//可以通过下标的方式访问数组中的元素
//可以获取数组中当前元素个数和数组的容量


#include"myarray.hpp"
using namespace std;
void myprint(Myarray<int>& m)
{
	for (int i = 0; i < m.getsize(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
}
void test1()
{
	Myarray<int> m(20);
	for (int i = 0; i < 4; i++)
	{
		m.PushBack(i);
		
	}
	myprint(m);
	cout << "容量是:" << m.getcapacity() << endl;
	cout << "大小是:" << m.getsize() << endl;
	m.PopBack();
	myprint(m);
	cout << "容量是:" << m.getcapacity() << endl;
	cout << "大小是:" << m.getsize() << endl;

}
class Person
{
public:
	Person() {}
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string m_name;
	int m_age;
};
void printPerson(Myarray<Person>& m)
{
	for (int i = 0; i < m.getsize(); i++)
	{
		cout << m[i].m_name << " ";
		cout << m[i].m_age << " ";
	}
	cout << endl;
}
void test2()
{
	Myarray<Person> m(5);
	Person p1("小桀", 21);
	Person p2("中桀", 22);
	Person p3("老桀", 23);
	Person p4("老桀", 23);
	Person p5("老桀", 23);
	m.PushBack(p1);
	m.PushBack(p2);
	m.PushBack(p3);
	m.PushBack(p4);
	m.PushBack(p5);
	printPerson(m);
	cout << "容量是:" << m.getcapacity() << endl;
	cout << "大小是:" << m.getsize() << endl;

}
int main()
{
	test1();
	test2();
	return 0;
}
