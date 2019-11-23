#ifndef ALL_DLL_H
#define ALL_DLL_H

#include <iostream>

template<typename T>

class Node{
    public:
        T data;
        Node<T> *prev,*next;  // Doubly LinkeList has a prev and next node

        Node():data(), prev(nullptr), next(nullptr){ };
        Node(const T& item):data(item), prev(nullptr), next(nullptr){ };
};

template<typename T>
class Itr {
    private:
        Node<T> *current;

    public:
        Itr():current(nullptr){ };
        Itr(Node<T>* ptr):current(ptr){ }; // not const

        // pre-increment
        Itr<T>& operator++() {
            if(current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        // post-increment
        Itr<T> operator++(int){
            Itr<T> result(current);
            current = current->next;
            return result;

            // Itr<T> result = *this;
            // ++*this;
            // return result;
        }

        // return reference
        // Node<T>& operator*() const {
        //     return *current;
        // }

        // // return pointer
        // Node<T>* operator->() const {
        //     return current;
        // }

        // *& First is a reference to a pointer, 
        // **&second is a reference to a pointer to a pointer.

        Node<T>* operator->(){
            return current;
        }

        const Node<T>* operator->() const{
            return current;
        }

        bool operator ==(const Node<T>* ptr){
            return current == ptr;
        }

        bool operator !=(const Node<T>* ptr){
            return current != ptr;
        }
};

template<typename T>
class List{
    private:
        Node<T> * beginning, *ending;

    public:
        /**
         * Default constructor
         */
        List():beginning(nullptr), ending(nullptr){};

        /**
         * Copy constructor
         */
        List(const List<T>& actual){
            Node<T>* temp = actual.beginning;
            beginning = nullptr;

            while(temp != nullptr) {
                if(beginning == nullptr) {
                    beginning = new Node<T>(temp->data);
                    ending = beginning;
                } else {
                    ending->next = new Node<T>(temp->data);
                    ending->next->prev = ending;
                    ending = ending->next;
                }
                temp = temp->next;
            }
        }

        /**
         * Destructor
         */
        ~List(){
            Node<T> *temp = beginning;
            while(beginning != nullptr){
                beginning = beginning->next;
                delete temp;
                temp = beginning;
            }
        }

        /**
         * Insert value after a given iterator node
         * There are 3 possible scenarios
         * (1) List is empty
         * (2) The iterator/pointer is at the tail
         * (3) Insert in between
         */
        void insertAfter(const T& item,Itr<T> ptr) {
            if(beginning == nullptr) {              // 1. Check if we are adding to an empty list
                beginning = new Node<T>(item);
                ending = beginning;                 // 2. Set the ending and beginning to point to the same node
            } else {
                if(ptr == ending) {                     // 1. Check if we are adding to the end
                    ending->next = new Node<T>(item);   // 2. Create a new node. Point it to ending pointer's "next node" pointer
                    ending->next->prev = ending;        // 3. Refer the new ending node's previous pointer to the "old ending" pointer
                    ending = ending->next;              // 4. Officially point the ending to the new node
                } else {
                    Node<T>* temp = new Node<T>(item);
                    temp->next = ptr->next;
                    temp->prev = ptr.operator->();
                    ptr->next->prev = temp;
                    ptr->next = temp;
                }
            }
        }

        void insertBefore(const T& item, Itr<T> ptr) {
            if(beginning == nullptr) {
                beginning = new Node<T>(item);
                ending = beginning;
            } else {
                if(ptr == beginning) {
                    beginning->prev = new Node<T>(item); // used to point to nullptr
                    beginning->prev->next = beginning;
                    beginning = beginning->next;
                } else {
                    Node<T>* temp = new Node<T>(item);
                    temp->prev = ptr->prev;
                    temp->next = ptr.operator->();
                    ptr->prev->next = temp;
                    ptr->prev = temp;
                }
            }
        }

        void remove(Itr<T> ptr) {
            if(ptr == beginning) {
                beginning = beginning->next;
                beginning->prev = nullptr;
            } else if(ptr == ending) {
                ending = ending->prev;
                ending->next = nullptr;
            } else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr-> prev;
            }

            delete ptr.operator->();
        }

        Itr<T> begin() {
            return Itr<T>(beginning);
        }

        const Itr<T> begin()const {
            return Itr<T>(beginning);
        }

        Itr<T> end() {
            return Itr<T>(ending);
        }
        const Itr<T> end()const {
            return Itr<T>(ending);
        }

    /////for test//////////
        void PrintList(){
            Node<T>* temp=beginning;
            while(temp!= nullptr){
                std::cout<<temp->data<<" ";
                temp=temp->next;
            }
            std::cout<<std::endl;
        }
    //////SOME OTHER FUNCTION////


        List<T>& operator=(List<T> rhs){
            swap(rhs);
            return *this;
        }

        void swap(List<T>& rhs){
            Node<T>* temp=beginning;
            beginning=rhs.beginning;
            rhs.beginning=temp;

            temp=ending;
            ending=rhs.ending;
            rhs.ending=temp;
        }

        Itr<T> find(const T& key){
            Itr<T> pos(beginning);
            while(pos->data!=key)
                ++pos;
            return pos;
        }
};





#endif //ALL_DLL_H
