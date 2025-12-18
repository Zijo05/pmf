#include <iostream>

template <typename T>
class DLList
{
    class DLLElement
    {
    public:
        T value;
        DLLElement *prev;
        DLLElement *next;

        DLLElement(T a_value) : value(a_value), prev(nullptr), next(nullptr) {}
    };

    class DLLIterator
    {
    public:
        DLLElement *ptr;
        DLLIterator(DLLElement *aptr) : ptr(aptr) {}

        bool operator==(const DLLIterator rhs) { return this->ptr == rhs.ptr; }
        bool operator!=(const DLLIterator rhs) { return !(*this == rhs.ptr); }

        DLLIterator &operator++()
        {
            if (ptr == nullptr) // ++it
                throw std::runtime_error("Invalid pointer!");
            ptr = ptr->next;
            return *this;
        }

        DLLIterator operator++(int) // it++
        {
            if (ptr == nullptr)
                throw std::runtime_error("Invalid pointer!");
            auto temp = *this;
            ptr = ptr->next;
            return temp;
        }

        T &operator*()
        {
            if (ptr == nullptr)
                throw std::runtime_error("Invalid pointer!");
            return ptr->value;
        }
    };

    DLLElement *head;
    DLLElement *tail;

public:
    DLList() : head(nullptr), tail(nullptr) {}
    ~DLList()
    {
        // TODO
    }

    friend std::ostream &operator<<(std::ostream &os, const DLList &dllist)
    {
        auto t = dllist.head;
        os << "[";
        while (t != nullptr)
        {
            os << t->value;
            t = t->next;
            if (t != nullptr)
                os << ", ";
        }
        os << "]";
        return os;
    }

    void push_front(T a_value)
    {
        auto tempElement = new DLLElement(a_value);
        if (head == nullptr)
            head = tail = tempElement;
        else
        {
            tempElement->next = head;
            head->prev = tempElement;
            head = tempElement;
        }
    }

    void push_back(T a_value)
    {
        auto tempElement = new DLLElement(a_value);
        if (head == nullptr)
            head = tail = tempElement;
        else
        {
            tempElement->prev = tail;
            tail->next = tempElement;
            tail = tempElement;
        }
    }

    DLLIterator begin() { return DLLIterator(head); }
    DLLIterator end() { return DLLIterator(nullptr); }
};

int main()
{
    DLList<int> l;
    l.push_back(30);
    l.push_back(40);
    l.push_front(20);
    l.push_front(10);

    std::cout << l << std::endl;

    for (auto x : l)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}