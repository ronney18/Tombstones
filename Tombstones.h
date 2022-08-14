#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_
#include <iostream>
using namespace std;

void Dangling_Error()
{
	cout << "There is a dangling pointer!" << endl;
}

void Memory_Leak()
{
	cout << "Memory leak detected!" << endl;
}

template <class T> class Pointer;
template <class T> class Tombstones;

template <class T>
class Tombstones
{
	public:
		int count;
		T* value;
		bool isDeleted;

		Tombstones<T>()
		{
			count = 0;
			value = NULL;
			isDeleted = false;
		}
};

template <class T>
class Pointer 
{
	public:
 		Pointer<T>()
		{
			ptr = new Tombstones<T>();
			ptr->isDeleted = true;
		}
		
		Pointer(Pointer<T>& obj)
		{
			if(obj.ptr->isDeleted)
			{
				Dangling_Error();
			}
			ptr = obj.ptr;
			if(ptr->count != 0)
			{
				ptr->count++;
			}
		}	
 		
		Pointer(T* obj)
		{
			ptr = new Tombstones<T>();
			ptr->value = obj;
			ptr->isDeleted = false;
			if(obj != NULL)
			{
				ptr->count = 1;
			}
			else
			{
				ptr->count = 0;
			}
		}
 		
 		~Pointer()
		{
			ptr->count--;
			if(ptr->count == 0 && !(ptr->isDeleted))
			{
				Memory_Leak();
			}
			ptr = NULL;
		}

 		T& operator*() const
		{
			if(ptr->count == 0)
			{
				Memory_Leak();
			}
			else if(ptr->isDeleted == true)
			{
				Dangling_Error();
			}
			return *(ptr->value);
		}

 		T* operator->() const
		{
			if(ptr->count == 0)
			{
				Memory_Leak();
			}
			else if(ptr->isDeleted == true)
			{
				Dangling_Error();
			}
			return ptr->value;
		}

 		Pointer<T>& operator=(const Pointer<T>& obj)
                {
                      
                     ptr->count--;
		     if(ptr->count == 0)
		     {
			Memory_Leak();
		     }
		     ptr = obj.ptr;
		     ptr->count++;
		     if(ptr->isDeleted)
		     {
			     Dangling_Error();
		     }
		     return *this;
                }
 
 		friend void free(Pointer<T>& obj) 
                {
			if(obj.ptr->isDeleted)
			{
				Dangling_Error();
			}
			else
			{
                    		delete(obj.ptr->value);
				obj.ptr->isDeleted = true;
			}
                }
 	
 		bool operator==(const Pointer<T>& obj) const
		{
			if(ptr->isDeleted || (obj.ptr->isDeleted))
			{
				Dangling_Error();
			}
			return ptr->value == (obj.ptr->value);
		}
 		bool operator!=(const Pointer<T>& obj) const
		{
                        if(ptr->isDeleted || (obj.ptr->isDeleted))
                        {
				Dangling_Error();
                        }
                        return ptr->value != (obj.ptr->value);
                }
 		bool operator==(const int num) const
		{
			return ptr->value == NULL && num == 0;
		}
 		bool operator!=(const int num) const
		{
			return !(ptr->value == NULL && num == 0);
		}
 		
	private:
		Tombstones<T> *ptr;
     
};

template <class T>
bool operator==(const int num, const Pointer<T>& obj)
{
	return obj == num;
}

template <class T>
bool operator!=(const int num, const Pointer<T>& obj)
{
        return obj != num;
}
#endif
