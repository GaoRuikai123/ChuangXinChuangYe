#include<iostream>
using namespace std;
const int MAX = 65535; 
//������ϣ��
void Creat_HashTable(int* arr, int num)
{
	int x = 0, key = 0; // x Ϊ��Ҫ�����ֵ�� key Ϊ��ֵ�±�
	//��ʼ����ϣ��ΪMAX
	for (int i = 0; i < num; i++)
	{
		arr[i] = MAX;
	}
	cout << "������" << num << "������������" << endl;
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
		//����
		arr[key] = x;
	}
}

//��ϣ��������ϣ���ң�
void Hash_Search(int* arr, int num, int target)
{
	int key = 0, count = 0;
	//���ݽ���ʱ���±��ҵ���ֵ
	key = target % num;
	//�����һ���Ҳ���
	while (arr[key] != target && ++count <= num)
	{
		key = (key + 1) % num;
	}
	if (count > num)
	{
		cout << "�Ҳ�����" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ����±�Ϊ" << key << "�ĵ�Ԫ��!" << endl;
	}
}

int main()
{
	int num = 0, target = 0;
	cout << "������Ҫ���������и�����" << endl;
	cin >> num;
	//��̬����һ����ϣ��
	int* arr = new int[num];
	Creat_HashTable(arr, num);
	cout << "��ϣ��Ϊ��" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	while (target != 65535)
	{
		cout << "������Ҫ���ҵļ�ֵ��" << endl;
		cin >> target;
		Hash_Search(arr, num, target);
	}

	system("pause");
	return 0;
}

