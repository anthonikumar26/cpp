#include <iostream>

using namespace std;

template <class T>
class MyUniquePtr
{

public:
    MyUniquePtr() : m_Uptr(nullptr)
    {
        cout << "default constructor " << m_Uptr << endl;
    }
	
    MyUniquePtr(T * m_Uptr) : m_Uptr(m_Uptr)
    { 
        cout << "parameterized constructor" << endl;
    }

    MyUniquePtr(const MyUniquePtr & obj) = delete;
    MyUniquePtr& operator=(const MyUniquePtr & obj) = delete;

    MyUniquePtr(MyUniquePtr && dyingObj)
    {
        cout << "move constructor " << m_Uptr << endl;
        this->m_Uptr = dyingObj.m_Uptr;
        dyingObj.m_Uptr = nullptr; 
    }

    void operator=(MyUniquePtr && dyingObj)
    {
        cout << "move assignment constructor " << m_Uptr << endl;
        this->m_Uptr = dyingObj.m_Uptr;
        dyingObj.m_Uptr = nullptr;
    }

    T* operator->()
    {
        cout << "pointer access " << m_Uptr << endl;
        return this->m_Uptr;
    }

    T& operator*()
	{
        cout << "pointer dereference " << m_Uptr << endl;
        return *(this->m_Uptr);
    }
	
    T* get()
    {
        return m_Uptr;
    }
	
    friend ostream& operator<<(ostream& os, MyUniquePtr<T>& sp)
    {
        os << "Address: " << sp.get() << endl;
        return os;
    }

    ~MyUniquePtr()
    {
        cout << "default destructor " << m_Uptr << endl;
        if (m_Uptr != nullptr)
            delete m_Uptr;
    }

private:
    T * m_Uptr = nullptr;
	
};

int main() {
    {
        MyUniquePtr<int> ptr;
        cout << ptr;
    }
    cout << "----------------" << endl;
    MyUniquePtr<int> ptr1(new int(1));
    cout << ptr1;
    {
        MyUniquePtr<int> ptr2 = move(ptr1);
        cout << ptr2;
    }
    
    return 0;
}