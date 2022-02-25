#include <iostream>
using namespace std;

template <typename T>
class MySharedPtr
{
public:
	
	MySharedPtr(T* ptr = nullptr)
	{
		m_Sptr = ptr;
		m_RefCount = new int();
		if (ptr)
		{
			(*m_RefCount)++;
		}
	}

	MySharedPtr(MySharedPtr<T>& sp)
	{
		m_Sptr = sp.m_Sptr;
		m_RefCount = sp.m_RefCount;
		(*m_RefCount)++;
	}

	unsigned int use_count()
	{
	return *m_RefCount;
	}

	T* get()
	{
		return m_Sptr;
	}

	T& operator*()
	{
		return *m_Sptr;
	}

	T* operator->()
	{
		return m_Sptr;
	}

	friend ostream& operator<<(ostream& os,
							MySharedPtr<T>& sp)
	{
		os << "Sptr Address : " << sp.get() << endl;
		os << "RefCount: " << *(sp.m_RefCount) << endl;
		return os;
	}
	
	~MySharedPtr()
	{
		(*m_RefCount)--;
		if (*m_RefCount == 0)
		{
			delete m_RefCount;
			delete m_Sptr;
		}
	}

private:
	int* m_RefCount;
	T* m_Sptr;
	
};

int main()
{
	MySharedPtr<int> ptr1(new int(1));
	cout << ptr1;
	cout << "------------------" << endl;
	MySharedPtr<int> ptr2 = ptr1;
    cout << ptr2;

	return 0;
}
