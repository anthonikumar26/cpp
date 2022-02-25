template <class T>
class my_unique_ptr<T[]>
{
private:
    T * ptr = nullptr;

public:
    MyUniquePtrArray() : ptr(nullptr){}

    MyUniquePtrArray(T * ptr) : ptr(ptr){}

    MyUniquePtrArray(const MyUniquePtrArray & obj) = delete; 
    MyUniquePtrArray& operator=(const MyUniquePtrArray & obj) = delete;

    MyUniquePtrArray(MyUniquePtrArray && dyingObj)
    {
        cleanup(); 
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(MyUniquePtrArray && dyingObj)
    {
        cleanup();
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T* operator->() 
    {
        return this->ptr;
    }

    T& operator*()
    {
        return *(this->ptr);
    }

    T& operator[](int index)
    {
        return this->ptr[index];
    }

    ~MyUniquePtrArray()
    {
        cleanup();
    }

private:
    void cleanup()
    {
        if (ptr != nullptr)
            delete[] ptr;
    }
};