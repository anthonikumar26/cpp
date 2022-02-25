template <class T>
class my_unique_ptr<T[]>
{
private:
    T * ptr = nullptr;

public:
    my_unique_ptr() : ptr(nullptr){}

    my_unique_ptr(T * ptr) : ptr(ptr){}

    my_unique_ptr(const my_unique_ptr & obj) = delete; 
    my_unique_ptr& operator=(const my_unique_ptr & obj) = delete;

    my_unique_ptr(my_unique_ptr && dyingObj)
    {
        cleanup(); 
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(my_unique_ptr && dyingObj)
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

    ~my_unique_ptr()
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