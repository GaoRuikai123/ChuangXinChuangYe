#include<iostream>
using namespace std;
const int MAX = 65535; 
//建立哈希表
void Creat_HashTable(int* arr, int num)
{
	int x = 0, key = 0; // x 为将要输入的值， key 为键值下标
	//初始化哈希表为MAX
	for (int i = 0; i < num; i++)
	{
		arr[i] = MAX;
	}
	cout << "请输入" << num << "个非零整数：" << endl;
	for (int j = 0; j < num; j++)
	{
		cin >> x;
		if (x == MAX)
		{
			continue;
		}
		else
		{
			key = x % num;
		}
		while (arr[key] != MAX)
		{

			key = (key + 1) % num;
		}
		//存入
		arr[key] = x;
	}
}

//哈希函数（哈希查找）
void Hash_Search(int* arr, int num, int target)
{
	int key = 0, count = 0;
	//根据建表时的下标找到键值
	key = target % num;
	//如果第一次找不到
	while (arr[key] != target && ++count <= num)
	{
		key = (key + 1) % num;
	}
	if (count > num)
	{
		cout << "找不到！" << endl;
	}
	else
	{
		cout << "找到了！在下标为" << key << "的单元中!" << endl;
	}
}

int main()
{
	int num = 0, target = 0;
	cout << "请输入要建立的序列个数：" << endl;
	cin >> num;
	//动态创建一个哈希表
	int* arr = new int[num];
	Creat_HashTable(arr, num);
	cout << "哈希表为：" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	while (target != 65535)
	{
		cout << "请输入要查找的键值：" << endl;
		cin >> target;
		Hash_Search(arr, num, target);
	}

	system("pause");
	return 0;
}

