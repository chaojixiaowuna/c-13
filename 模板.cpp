//���׶���Ҫ���c++���ͱ�̺�STL���������
//c++�ṩ����ģ����� ����ģ�����ģ��
//����ģ������ ����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
//�﷨
//template<typename T>
// template  ��������ģ��
//typename  ���������ķ�����һ���������� ������class����
//������������
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
//	//���������Ƶ�
//	myswap(a, b);
//	cout << "a=" << a << "b=" << b << endl;
//	double c = 2.5;
//	double d = 1.5;
//	//��ʾָ������
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

//��ͨ�������ÿ��Է�����ʽ����ת��
//����ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
//����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��
 
//�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//����ͨ�� ��ģ������б� ��ǿ�Ƶ���ģ�庯��
//myPrint<>(a,b)
//����ģ��Ҳ��������
//�������ģ����Բ������õ�ƥ�����޵��ú���ģ��

//����ģ��ľ�����
//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
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
//���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�

//��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//��ģ����ģ������б��п�����Ĭ�ϲ���
//template<class Nametype,class agetype=int>
//
//��ģ��ĳ�Ա�����ڵ���ʱ�Żᴴ��
//
//��ģ���������������
//��ģ��ʵ�������Ķ����������εķ�ʽ
//1��ָ�����������  ֱ����ʾ�������������
//2������ģ�廯      �������еĲ�����Ϊģ����д���
//3��������ģ�廯    ������������� ģ�廯���д���

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
//		cout << "������" << m_name << endl << "����:" << m_age << endl;
//	}
//};
////1��ָ�����������
//void myprint(Person<string,int> &p)
//{
//	p.showname();
//}
//void test1()
//{
//	Person<string, int> p1("С��", 31);
//	myprint(p1);
//}
////2������ģ�廯
//template<class T1,class T2>
//void myprint1(Person<T1, T2> &p)
//{
//	p.showname();
//	cout << "T1����" << typeid(T1).name() << endl;
//	cout << "T1����" << typeid(T2).name()<< endl;
//}
//void test2()
//{
//	Person<string, int> p2("����", 32);
//	myprint1(p2);
//}
////3��������ģ�廯
//template<class T>
//void myprint2(T &p)
//{
//	p.showname();
//	cout << "T1����" << typeid(T).name() << endl;
//}
//void test3()
//{
//	Person<string, int> p3("С��", 24);
//	myprint2(p3);
//}
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}

//������̳еĸ�����һ����ģ��ʱ��������������ʱ����Ҫָ����������T������
//�����ָ�����������޷�����������ڴ�
//��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
//template<class T1,class T2>
//class Son:Person<T1>
//{
//	T2 name;
//};

//��ģ����ļ���д
//��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
//�����ʽ1 ֱ�Ӱ���cpp�ļ�
//�����ʽ2 ��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��

//ȫ�ֺ�������ʵ��
//�ӿ�ģ������б�  ������Ҫ�ñ�������ǰ֪��������� �Ĵ���


//��ģ�尸��
//���Զ��������������Լ��Զ����������͵����ݽ��д洢
//�������е����ݴ洢������
//���캯���п��Դ������������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//����ͨ���±�ķ�ʽ���������е�Ԫ��
//���Ի�ȡ�����е�ǰԪ�ظ��������������


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
	cout << "������:" << m.getcapacity() << endl;
	cout << "��С��:" << m.getsize() << endl;
	m.PopBack();
	myprint(m);
	cout << "������:" << m.getcapacity() << endl;
	cout << "��С��:" << m.getsize() << endl;

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
	Person p1("С��", 21);
	Person p2("����", 22);
	Person p3("����", 23);
	Person p4("����", 23);
	Person p5("����", 23);
	m.PushBack(p1);
	m.PushBack(p2);
	m.PushBack(p3);
	m.PushBack(p4);
	m.PushBack(p5);
	printPerson(m);
	cout << "������:" << m.getcapacity() << endl;
	cout << "��С��:" << m.getsize() << endl;

}
int main()
{
	test1();
	test2();
	return 0;
}
