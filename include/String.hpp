// Spring 2016
// https://www.kent.edu/sites/default/files/file/Prel-DS-April2016.pdf
//
// Problem 2  
// In C++, implement a string abstract data type (ADT) using a dynamically allocated array.  
// The array of char should be null terminating.  
// You must implement the following methods: 
// •Default constructor (allocates 128 characters as capacity) and sets the string to empty 
// •Constructor  that  takes  an  integer  value  as  the  capacity  to  allocate  and  sets  the  string  to empty 
// •Length 
// •Capacity  
// •Copy constructor 
// •Destructor 
// •Swap – swaps two strings in constant time regardless of the size of the array. 
// •Assignment operator using standard copy semantics 
// •Concatenation (overload the + operator) that returns a string that is the concatenation of any two strings regardless of the resulting size

#include <iostream>

class String {
    const int MAX_CAPACITY = 128;
    private:
        char* str;
        int length;
        int capacity;
    
    public:
        String() {
            str = new char[MAX_CAPACITY + 1];
            str[0] = '\0';
            length = 0;
            capacity = MAX_CAPACITY;
        }

        String(const int cap) {
            length = 0;
            capacity = cap;
            str = new char[capacity + 1];
            str[0] = '\0';
        }

        String(const char* str_char) {
            int i = 0;
            while(str_char[i] != '\0') {
                i++;
            }
            length = i;
            str = new char[length + 1];
            capacity = length;

            for(int j = 0; j < length; j++) {
                str[j] = str_char[j];
            }
            str[length] = '\0';
        }

        String(const String& actual) {
            length = actual.length;
            capacity = actual.capacity;
            str = new char[capacity + 1];

            for(int i = 0; i < length; i++) {
                str[i] = actual.str[i];
            }
            str[length] = '\0';
        }

        ~String() {
            length = 0;
            capacity = 0;
            delete[] str;
        }

        int Length() {
            return length;
        }

        int Capacity() {
            return capacity;
        }

        void Swap(String& rhs) {
            int temp_length = length;
            length = rhs.length;
            rhs.length = temp_length;

            int temp_capacity = capacity;
            capacity = rhs.capacity;
            rhs.capacity = temp_capacity;

            char* temp_str = str;
            str = rhs.str;
            rhs.str = temp_str;
        }

        String& operator=(String rhs) {
            Swap(rhs);
            return *this;
        }

        String operator+(const String& rhs) const {
            int res_length = length + rhs.length;
            String result(res_length);

            // char* res_str = new char[res_length + 1];

            for(int i = 0; i < length; i++) {
                result.str[i] = str[i];
            }

            for(int j = length; j < res_length; j++) {
                result.str[j] = rhs.str[j - length];
            }
            result.str[res_length] = '\0';
            result.length = res_length;

            return result;
        }
};

