#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T> void printVector(vector<T> vec, const string name);

int main() {
    vector<int> v1(10);              // Create a vector with a capacity of 10
    vector<int> v2 = {10, 20, 30};   // Initialize with an array initializer
    vector<int> v3;                  // Default initialization
    vector<int> v4 = {8, 3, 1, 5, 12, 13, 2, 7, 10};
    vector<int>::size_type vsize;    // size_type is an unsigned type that stores a size

    v1 = {1, 2, 3, 4};
    vsize = v1.size();
    cout << "Vector 1 size=" << vsize << "  ";
    cout << "capacity=" << v1.capacity() << endl;
    cout << "Vector 2 size=" << v2.size() << "  ";
    cout << "capacity=" << v2.capacity() << endl;
    cout << "Vector 3 size=" << v3.size() << "  ";
    cout << "capacity=" << v3.capacity() << endl;
    cout << "Vector 4 size=" << v4.size() << "  ";
    cout << "capacity=" << v4.capacity() << endl;

    cout << endl;
    cout << "Accessing the values in a vector: " << endl;
    // The following is UNSAFE
    cout << "   Array indexing: ";
    for (unsigned int ii=0; ii<v1.capacity()+5; ii++) {
        cout << v1[ii] << " ";
    }
    cout << endl;

    cout << "   at() (beyond size()): ";
    try {
        for (unsigned int ii=0; ii<v1.capacity()+5; ii++) {
            cout << v1.at(ii) << " ";
        }
    }
    catch (const out_of_range& excep) {
        cout << "Out of range exception!";
    }
    cout << endl;
     
    cout << "   at() (using size()): ";
    for (unsigned int ii=0; ii<v1.size(); ii++) {
        cout << v1.at(ii) << " ";
    }
    cout << endl;

    // The following is safer : use an iterator
    cout << "   Using an iterator:";
    for (vector<int>::iterator ii=v1.begin(); ii != v1.end(); ++ii) {
        cout << (*ii) << " ";
    }
    cout << endl;

    cout << "   Using a for-each: ";
    for (auto const &ii : v1) {
        cout << ii << " ";
    }
    cout << endl;

    // Modifying vector entry using array indexing
    v1[4] = 5;
    cout << endl << "v1[4]=5" << endl;
    cout << "Vector1 size = " << v1.size() << "  ";
    cout << "capacity = " << v1.capacity() << endl;
    cout << "Contents: " << endl;
    cout << "  for-each: ";
    for (auto const &ii : v1) {
        cout << ii << " ";
    }
    cout << "  array-indexing: ";
    for (unsigned int ii=0;ii<v1.capacity(); ii++) {
        cout << v1[ii] << " ";
    }
    cout << endl;

    // Modifying vector entry using push_back()
    v1.push_back(6);
    cout << endl << "push_back(6)" << endl;
    cout << "Vector1 size = " << v1.size() << "  ";
    cout << "capacity = " << v1.capacity() << endl;
    cout << "Contents: " << endl;
    cout << "  for-each: ";
    for (auto const &ii : v1) {
        cout << ii << " ";
    }
    cout << "  array-indexing: ";
    for (unsigned int ii=0;ii<v1.capacity(); ii++) {
        cout << v1[ii] << " ";
    }
    cout << endl;

    cout << endl << "Calling push_back when initialized with an array " << endl;
    v2.push_back(40);
    v2.push_back(50);
    v2.push_back(60);
    printVector(v2, "v2");

    cout << endl << "Calling push_back on uninitialized vector " << endl;
    v3.push_back(44);
    v3.push_back(55);
    v3.push_back(66);
    printVector(v3, "v3");


    cout << endl << "Calling push_back on a vector with a defined capacity " << endl;
    for (int ii=0;ii<10;ii++) {
        v1.push_back(ii+10);
    }
    printVector(v1, "v1");

    cout << endl << "Removing elements from v1" << endl;
    cout << "                          Before : ";
    printVector(v1, "v1");
    v1.erase(v1.begin());
    cout << "           Removed first element : ";
    printVector(v1, "v1");
    v1.erase(v1.begin()+3);
    cout << "          Removed fourth element : ";
    printVector(v1, "v1");
    v1.erase(v1.end()-1);
    cout << "            Removed last element : ";
    printVector(v1, "v1");
    v1.erase(v1.end()-3);
    cout << "   Removed third-to-last element : ";
    printVector(v1, "v1");
    v1.erase(v1.begin(), v1.begin() + v1.size()/2);
    cout << "  Removed 1st half of the vector : ";
    printVector(v1, "v1");
    v1.pop_back();
    cout << "          Removed using pop_back : ";
    printVector(v1, "v1");
    cout << endl;

    cout << "Print front & back v3:" << endl;
    printVector(v3, "v3");
    cout << "  v3 front: " << v3.front() << endl;
    cout << "  v3 back: " << v3.back() << endl;

    cout << endl << "Sorting a vector: " << endl; 
    cout << "  Before: ";
    printVector(v4, "v4");
    sort(v4.begin(), v4.end());
    cout << "  After: ";
    printVector(v4, "v4");

    cout << endl;
    return 0;
}

template<typename T> 
void printVector(vector<T> vec, const string name) {
    cout << "Vector " << name << " s=" << vec.size() 
         << " c=" << vec.capacity();
    cout << "  contents: [ ";
    for (auto const & ii : vec) {
        cout << ii << " ";
    }
    cout << "]" << endl;
}
