#include "DataStruct_PrychantovskyiIvan.h"
using namespace std;
template <class data>
DataStruct_PrychantovskyiIvan<data>::DataStruct_PrychantovskyiIvan(vector<data> v) {
    n = v.size();
    a = new data[n];
    b = new data[4 * n];
    c = new data[4 * n];
    for (int i = 0; i < n; i++) { a[i] = v[i]; }
}
template <class data>
DataStruct_PrychantovskyiIvan<data>::~DataStruct_PrychantovskyiIvan() { // деструктор
    if (a != NULL) { delete[] a; delete[] b; delete[] c; }
}
template <class data>
DataStruct_PrychantovskyiIvan<data>::DataStruct_PrychantovskyiIvan(data* v, size_t n1) {
    n = n1;
    a = new data[n];
    b = new data[4 * n];
    c = new data[4 * n];
    for (int i = 0; i < n; i++) a[i] = v[i];
}
template <class data>
DataStruct_PrychantovskyiIvan<data>::DataStruct_PrychantovskyiIvan(size_t n1) { //ввод элементов
    n = n1;
    a = new data[n];
    b = new data[4 * n];
    c = new data[4 * n];
    for (int i = 0; i < n; i++) { data x; std::cout << "Input elements: "; std::cin >> x; a[i] = x; }
}
template <class data>
DataStruct_PrychantovskyiIvan<data>::DataStruct_PrychantovskyiIvan() {
    a = NULL;
    n = 0;
}
template <class data>
bool DataStruct_PrychantovskyiIvan<data>::append(data p) {
    data* a1 = new data[n + 1];
    data* b1 = new data[4 * n + 4];
    data* c1 = new data[4 * n + 4];
    for (int i = 0; i < n; i++) a1[i] = a[i];
    a1[n] = p;
    delete[] a;
    delete[] b;
    delete[] c;
    a = a1;
    b = b1;
    c = c1;
    n++;

    return true;
}
template <class data>
data DataStruct_PrychantovskyiIvan<data>::pop() {
    if (!DataStruct_PrychantovskyiIvan::is_empty()) {
        data* a1 = new data[n - 1];
        data* b1 = new data[4 * n - 4];
        data* c1 = new data[4 * n - 4];
        data p = a[n - 1];
        for (int i = 0; i < n - 1; i++) a1[i] = a[i];
        delete[] a;
        delete[] b;
        delete[] c;
        a = a1;
        b = b1;
        c = c1;
        n--;
        return p;
    }
    else throw "DataStruct is empty";
}
template <class data>
bool DataStruct_PrychantovskyiIvan<data>::is_empty() { //путой ои вектор?
    if (n == 0) return true;
    else return false;
}
template <class data>
bool DataStruct_PrychantovskyiIvan<data>::is_present(data p) {  //найти есть ли элемент который равен р
    for (int i = 0; i < n; i++) {
        if (a[i] == p) return true;
    }
    return false;
}
template <class data>
int DataStruct_PrychantovskyiIvan<data>::find(data p) { //найти какой из элементов равен р
    for (int i = 0; i < n; i++) {
        if (a[i] == p) return i;
    }
    return -1;
}
template <class data>
bool DataStruct_PrychantovskyiIvan<data>::delete_(data p) { //
    if (DataStruct_PrychantovskyiIvan::find(p) == -1) return false;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == p) k++;
    }
    int f = 0;
    data* a1 = new data[n - k];
    for (int i = 0; i < n; i++) {
        if (a[i] == p) { f++; }
        else a1[i - f] = a[i];
    }
    delete[] a;
    a = a1;
    n = n - k;
    return true;
}
template <class data>
vector<data> DataStruct_PrychantovskyiIvan<data>::find_all(data p1, data p2) { //
    vector<data> v;
    int k = 0;
    if (DataStruct_PrychantovskyiIvan::find(p1) != -1 and DataStruct_PrychantovskyiIvan::find(p2) != -1) { k = DataStruct_PrychantovskyiIvan::find(p1) - DataStruct_PrychantovskyiIvan::find(p2) + 1; }
    v.assign(k, a[0]);
    for (int i = DataStruct_PrychantovskyiIvan::find(p1); i <= DataStruct_PrychantovskyiIvan::find(p2); i++) {
        v[i - DataStruct_PrychantovskyiIvan::find(p1)] = a[i];
    }
    return v;
}
template <class data>
void DataStruct_PrychantovskyiIvan<data>::tree(int v, int tl, int tr) { //заполнить дерево
    if (tl == tr) {
        b[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        DataStruct_PrychantovskyiIvan::tree(v * 2, tl, tm);
        DataStruct_PrychantovskyiIvan::tree(v * 2 + 1, tm + 1, tr);
        b[v] = b[v * 2] + b[v * 2 + 1];
    }
}
template <class data>
void DataStruct_PrychantovskyiIvan<data>::kucha(int v, int tl, int tr) { //заполнить кучу без порядка (как дерево)
    if (tl == tr) {
        c[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        DataStruct_PrychantovskyiIvan::kucha(v * 2, tl, tm);
        DataStruct_PrychantovskyiIvan::kucha(v * 2 + 1, tm + 1, tr);
        c[v] = c[v * 2] + c[v * 2 + 1];
    }
}
template <class data>
void DataStruct_PrychantovskyiIvan<data>::show_b() {   //вывести дерево
    for (int i = 0; i < 4 * n; i++) std::cout << b[i] << '\n';
}
template <class data>
void DataStruct_PrychantovskyiIvan<data>::show_c() {   //отсортировать и вывести кучу
    for (int i = 4 * n; i >= 0; i--) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largestChild = i;
        int heapSize = 4 * n;

        if (leftChild < heapSize && leftChild > largestChild)
        {
            largestChild = leftChild;
        }

        if (rightChild < heapSize && rightChild > largestChild)
        {
            largestChild = rightChild;
        }

        if (largestChild == i)
        {
            break;
        }

        int temp = i;
        i = largestChild;
        largestChild = temp;
        i = largestChild;
        std::cout << c[i] << '\n';
    }
}