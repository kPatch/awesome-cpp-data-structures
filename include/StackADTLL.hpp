#ifndef ADT_STACK_LL
#define ADT_STACK_LL
#include <cassert>

template <typename T>
class NodeADTLL {
    public:
        T data;
        NodeADTLL<T> *next;

        NodeADTLL():data(), next(nullptr){}  // Empty contructor
        NodeADTLL(const T& item):data(item), next(nullptr){} // Initialize "data" member with contents of "item"
};

template <typename T>
class StackADTLL {
    private:
        NodeADTLL<T> *tos;  // Top of stack
    public:
        StackADTLL():tos(nullptr){};

        StackADTLL(const StackADTLL<T>& actual){
            tos = nullptr;
            NodeADTLL<T>* temp = actual.tos; // Iterator - used to iterator throught 'actual'
            NodeADTLL<T>* bottom;           // Last node copied
            while(temp != nullptr) {
                if(tos == nullptr) {
                    tos = new NodeADTLL<T>(temp->data);
                    bottom = tos;
                } else {
                    bottom->next = new NodeADTLL<T>(temp->data);
                    bottom = bottom->next;
                }
                temp = temp->next;
            }
        }

        ~StackADTLL(){
            // NodeADTLL<T>* temp;
            // while(tos != nullptr){
            //     temp = tos;
            //     delete temp;
            //     tos = tos->next;
            // }

            NodeADTLL<T>* temp = tos;
            while(tos != nullptr){
                tos = tos->next;
                delete temp;
                temp = tos;
            }
        }

        void Swap(StackADTLL<T>& rhs) {
            NodeADTLL<T>* temp = tos;
            tos = rhs.tos;
            rhs.tos = temp;
        }

        StackADTLL<T>& operator=(StackADTLL<T> rhs){
            Swap(rhs);
            return *this;
        }

        bool isEmpty() {
            return tos == nullptr;
        }

        void push(const T& item) {
            NodeADTLL<T>* temp = new NodeADTLL<T>(item);    // Create new node
            temp->next = tos;                               // Point 'next' pointer to curren 'tos'
            tos = temp;                                     // Set new node as 'tos'
        }

        T pop() {
            assert(!isEmpty());
            T result = tos->data;
            NodeADTLL<T>* temp = tos;
            tos = tos->next;
            delete temp;
            return result;
        }
};

#endif //ADT_STACK_LL