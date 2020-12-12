
#include <iostream>
#include <unordered_set>

using namespace std;

void displayArray(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[5]={5,3,6,6,3};
    int n;
    
    n = sizeof(a)/sizeof(int);

    cout << "Original array is: ";
    displayArray(a,n);

    //Method-1
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; )
        {
            if(a[j] == a[i])
            {
                for(int k = j; k < n-1; k++)
                {
                    a[k] = a[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    cout << "Method-1 New array is: ";
    displayArray(a,n);

    //Method-2
    unordered_set<int> s(begin(a), end(a));
    cout << "Method-2 New array is: ";
    for(auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


/*---output---

Original array is: 5 3 6 6 3 
Method-1 New array is: 5 3 6 
Method-2 New array is: 6 3 5

*/