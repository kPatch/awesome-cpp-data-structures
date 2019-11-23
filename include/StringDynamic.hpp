// Spring 2017
// https://www.kent.edu/sites/default/files/file/Prel-DS-April2017.pdf
// 
// Problem 2  
// In  C++,  implement  a  String  abstract  data  type  (ADT)  using  a  dynamically  allocated  array.
// The array of char should be NULL terminating.  
// This dynamic version of the String will only allocate exactly the amount of memory necessary to store the characters. 
// That is, the length will always be the same as the capacity.  
// However, the size of the dynamic array needs to have an extra char for the NULL terminator. 
//
// You must implement the following methods: 
// •Default constructor that sets the object to the empty string. 
// •Constructor that takes a const char array and converts it into a string. 
// •Copy constructor 
// •Destructor 
// •Swap – swaps two strings in constant time regardless of the size of the array. 
// •Assignment operator using standard copy semantics 
// •Concatenation (String operator+(const String&) const;) that concatenates any two strings and returns a new string with the proper amount of allocated memory.

#include <iostream>

class String {
    private:
        char* str;
        int length;
    
    public:
        String() {
            str = new char[1];
            str[0] = '\0';
            length = 0;
        }

        String(const char* temp) {
            int temp_length = 0;
            while(temp[temp_length] != '\0') {
                temp_length++;
            }

            length = temp_length;
            str = new char [length + 1];

            for(int i = 0; i < length; i++) {
                str[i] = temp[i];
            }
            str[length] = '\0';
        }

        String (const String& actual) {
            length = actual.length;
            str = new char[length + 1];

            for(int i = 0; i < length; i++) {
                str[i] = actual.str[i];
            }
            str[length] = '\0';
        }

        ~String() {
            length = 0;
            delete[] str;
        }

        void Swap(String& rhs) {
            int temp_length = length;
            length = rhs.length;
            rhs.length = temp_length;

            char* temp_str = str;
            str = rhs.str;
            rhs.str = temp_str;
        }

        String& operator=(String rhs) {
            Swap(rhs);
            return *this;
        }

        String operator+(const String& rhs) const {
            int total_length = length + rhs.length;
            char* res_str = new char[total_length + 1];

            for(int i = 0; i < length; i++) {
                res_str[i] = str[i];
            }

            for(int j = length; j < total_length; j++) {
                res_str[j] = rhs.str[j - length];
            }
            res_str[total_length] = '\0';
            String result(res_str);
            return result;
        }
}