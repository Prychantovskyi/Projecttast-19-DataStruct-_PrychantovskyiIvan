#include "DataStruct_PrychantovskyiIvan.h"
#include "DataStruct_PrychantovskyiIvan.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    DataStruct_PrychantovskyiIvan <int> t(10); //вводимо 10 елементів
    t.append(1);
    t.is_present(11);
    t.find(1);
    t.pop();
    t.delete_(5);
    t.is_empty();
    t.tree(0, 0, t.n);
    t.kucha(0, 0, t.n);
    cout << "derevo:";
    t.show_b();
    cout << "kucha:";
    t.show_c();
    return 0;
}