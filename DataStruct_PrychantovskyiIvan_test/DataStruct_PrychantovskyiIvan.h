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
	data* b; //массив для дерева
	data* c; //массив для кучи
	DataStruct_PrychantovskyiIvan(vector<data>);
	DataStruct_PrychantovskyiIvan(data*, size_t); // <=> array<data, n>
	DataStruct_PrychantovskyiIvan(size_t);
	DataStruct_PrychantovskyiIvan();
	~DataStruct_PrychantovskyiIvan(); //деструктор
	bool append(data);
	data pop();
	bool is_empty();
	bool is_present(data);
	int find(data);
	bool delete_(data);
	vector<data> find_all(data, data); // вектор чисел между [р1,з2]
	void tree(int, int, int); //заполнить дерево
	void kucha(int, int, int); //заполнить кучу
	void show_b(); //вывести дерево
	void show_c(); //вывести кучу
};


