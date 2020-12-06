#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <class data>
class DataStruct_PrychantovskyiIvan
{
public:
	data* a;
	int n;
	data* b; //������ ��� ������
	data* c; //������ ��� ����
	DataStruct_PrychantovskyiIvan(vector<data>);
	DataStruct_PrychantovskyiIvan(data*, size_t); // <=> array<data, n>
	DataStruct_PrychantovskyiIvan(size_t);
	DataStruct_PrychantovskyiIvan();
	~DataStruct_PrychantovskyiIvan(); //����������
	bool append(data);
	data pop();
	bool is_empty();
	bool is_present(data);
	int find(data);
	bool delete_(data);
	vector<data> find_all(data, data); // ������ ����� ����� [�1,�2]
	void tree(int, int, int); //��������� ������
	void kucha(int, int, int); //��������� ����
	void show_b(); //������� ������
	void show_c(); //������� ����
};


