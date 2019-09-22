#include <cassert>

template <typename T>
class NodeADTLL {
    public:
        T data;
        NodeADTLL<T> *next;

        NodeADTLL():next(nullptr){}  // Empty contructor
        NodeADTLL(const T& item):data(item), next(nullptr){} // Initialize "data" member with contents of "item"
};

template <typename T>
class StackADTLL{
    private:
        NodeADTLL<T> *tos;
    public:
        StackADTLL():tos(nullptr){};
        ~StackADTLL(){
            NodeADTLL<T>* temp;
            while(tos!= nullptr){
                temp=tos;
                delete temp;
                tos=tos->next;
            }
        }

        StackADTLL(const StackADTLL<T>& actual){
            tos= nullptr;
            NodeADTLL<T>* temp=actual.tos;
            NodeADTLL<T>* bottom;
            while(temp!=nullptr){
                if(tos== nullptr){
                    tos=new NodeADTLL<T>(temp->data);
                    bottom=tos;
                }else{
                    bottom->next=new NodeADTLL<T>(temp->data);
                    bottom=bottom->next;
                }
                temp=temp->next;
            }
        }

        void Swap(StackADTLL<T>& rhs){
            NodeADTLL<T>* temp=tos;
            tos=rhs.tos;
            rhs.tos=temp;
        }

        StackADTLL<T>& operator=(StackADTLL<T> rhs){
            Swap(rhs);
            return *this;
        }

        void push(const T& item){
            NodeADTLL<T>* temp=new NodeADTLL<T>(item);
            temp->next=tos;
            tos=temp;
        }

        bool isEmpty(){return tos== nullptr;};
        T pop(){
            assert(!isEmpty());
            T result=tos->data;
            NodeADTLL<T>* temp=tos;
            tos=tos->next;
            delete temp;
            return result;
        }
};