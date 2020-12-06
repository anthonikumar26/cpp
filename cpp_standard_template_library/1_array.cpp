
#include <algorithm> 
#include <array> 
#include <iostream> 
#include <iterator> 
#include <string> 

using namespace std; 

template <class T>
bool my_compare_function (T i, T j) { 
    return (i > j);
}

template <class T, size_t size>
void display(array<T, size> arr){
    //range based for loop
    for (auto i : arr) {
        cout << i << "  ";
    }
    //for (auto &i : arr) {
    //  cout << i << "  ";
    //}
    cout << "\n" << endl;
}


int main() { 

    // construction-1
    array<int, 5> arr1 = {4, 2, 3, 1, 5};
    cout << "construction-1 : " << endl;
    cout << "size of arr1 = " << arr1.size() << endl;
    display(arr1);


    // construction-2	 
    array<float, 5> arr2{{3.3, 4.4, 5.5, 1.1, 2.2}};
    cout << "construction-2 : " << endl;
    cout << "size of arr2 = " << arr2.size() << endl;
    display(arr2);

    // construction-3	 
    array<char, 5> arr3 = {{'d', 'b', 'c', 'a', 'e'}};
    cout << "construction-3 : " << endl;
    cout << "size of arr3 = " << arr3.size() << endl;
    display(arr3);

    // construction-4
    array<string, 2> arr4{{string("a"), "b"}}; 
    cout << "construction-4 : " << endl;
    cout << "size of arr4 = " << arr4.size() << endl;
    display(arr4);
  
    //  default sort function
    //	template <class T>
    //  void sort (T first, T last);
    cout << "default sort function :" << endl;
    sort(arr1.begin(), arr1.end()); 
    sort(arr2.begin(), arr2.end()); 
    sort(arr3.begin(), arr3.end()); 

    cout << "default sort arr1 = ";
    display(arr1);
    cout << "default sort arr2 = ";
    display(arr2);
    cout << "default sort arr3 = ";
    display(arr3);
    cout << "default sort arr4 = ";
    display(arr4);

    //  custom sort function
    //	template <class T, class C>
    //  void sort (T first, T last, C comp);
    cout << "custom sort function :" << endl;
    sort(arr1.begin(), arr1.end(), my_compare_function<int>); 
    sort(arr2.begin(), arr2.end(), my_compare_function<int>); 
    sort(arr3.begin(), arr3.end(), my_compare_function<int>);
    sort(arr4.begin(), arr4.end(), my_compare_function<string>);

    cout << "custom sort arr1 = ";
    display(arr1);
    cout << "custom sort arr2 = ";
    display(arr2);
    cout << "custom sort arr3 = ";
    display(arr3);
    cout << "custom sort arr4 = ";
    display(arr4);

    cout << "\n"; 
    return 0; 
}  



/*---output---

construction-1 : 
size of arr1 = 5
4  2  3  1  5  

construction-2 : 
size of arr2 = 5
3.3  4.4  5.5  1.1  2.2  

construction-3 : 
size of arr3 = 5
d  b  c  a  e  

construction-4 : 
size of arr4 = 2
a  b  

default sort function :
default sort arr1 = 1  2  3  4  5  

default sort arr2 = 1.1  2.2  3.3  4.4  5.5  

default sort arr3 = a  b  c  d  e  

default sort arr4 = a  b  

custom sort function :
custom sort arr1 = 5  4  3  2  1  

custom sort arr2 = 5.5  4.4  3.3  2.2  1.1  

custom sort arr3 = e  d  c  b  a  

custom sort arr4 = b  a

*/
