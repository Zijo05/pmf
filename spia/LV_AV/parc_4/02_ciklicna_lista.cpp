#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class CList
{
private:
    class CLElement
    {
    public:
        T value;
        CLElement *next;
        CLElement *prev;
        CLElement(T v) : value(v), next(nullptr), prev(nullptr) {}
        ~CLElement()
        {
            // cout << "Destroying element with value " << value << endl;
        }
    };

    CLElement *head;
    CLElement *tail;

public:
    class CLIterator
    {
    public:
        CLElement *ptr;
        CLElement *start; // pokazivač na početak liste koji koristimo da prepoznamo kraj

        // konstruktor: ptr je trenutni element, start označava glavu liste
        CLIterator(CLElement *p = nullptr, CLElement *s = nullptr) : ptr(p), start(s) {}

        inline bool operator==(const CLIterator &rhs) const
        {
            return this->ptr == rhs.ptr;
        }

        inline bool operator!=(const CLIterator &rhs) const
        {
            return !(*this == rhs);
        }

        // prefix ++
        CLIterator &operator++()
        {
            if (ptr == nullptr)
            {
                throw runtime_error("Iterator out of bounds.");
            }
            // ako će sljedeći element biti start, postavimo na end (nullptr)
            if (ptr->next == start)
            {
                ptr = nullptr;
            }
            else
            {
                ptr = ptr->next;
            }
            return *this;
        }

        // postfix ++
        CLIterator operator++(int)
        {
            auto temp = *this;
            if (ptr == nullptr)
            {
                throw runtime_error("Iterator out of bounds.");
            }
            if (ptr->next == start)
            {
                ptr = nullptr;
            }
            else
            {
                ptr = ptr->next;
            }
            return temp;
        }

        T &operator*()
        {
            if (ptr == nullptr)
            {
                throw runtime_error("Iterator out of bounds.");
            }
            return this->ptr->value;
        }
    };

    CList() : head(nullptr), tail(nullptr) {}
    ~CList()
    {
        // destruktor za kružnu listu
        if (head == nullptr)
            return;

        CLElement *cur = head->next;
        while (cur != nullptr && cur != head)
        {
            CLElement *next = cur->next;
            delete cur;
            cur = next;
        }
        // obriši i glavu (ako postoji)
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    void PushFront(T v)
    {
        auto nova = new CLElement(v);
        if (head == nullptr)
        {
            head = nova;
            tail = nova;
            nova->next = nova;
            nova->prev = nova;
        }
        else
        {
            nova->next = head;
            nova->prev = tail;
            tail->next = nova;
            head->prev = nova;
            head = nova;
        }
    }

    void PushBack(T v)
    {
        auto nova = new CLElement(v);
        if (tail == nullptr)
        {
            head = nova;
            tail = nova;
            nova->next = nova;
            nova->prev = nova;
        }
        else
        {
            nova->next = head;
            nova->prev = tail;
            tail->next = nova;
            head->prev = nova;
            tail = nova;
        }
    }

    void Test()
    {
        if (head == nullptr)
        {
            cout << endl;
            return;
        }
        auto t = head;
        do
        {
            cout << t->value << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }

    // begin i end za range-based for
    CLIterator begin()
    {
        // begin pokazuje na head; start= head (kako bismo znali kada završiti)
        return CLIterator(head, head);
    }

    CLIterator end()
    {
        // end reprezentiramo kao iterator sa ptr == nullptr i start == head
        return CLIterator(nullptr, head);
    }

    CLIterator begin() const
    {
        return CLIterator(head, head);
    }
    CLIterator end() const
    {
        return CLIterator(nullptr, head);
    }

    CLIterator remove(CLIterator it)
    {
        CLElement *node = it.ptr;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node == head && node == tail)
        {
            head == tail = nullptr;
            delete node;
            return CLIterator(nullptr);
        }
        if (head == node)
        {
            head = node->next;
        }
        if (tail == node)
        {
            tail = node->prev;
        }

        auto ret = CLIterator(node->next);

        delete node;

        return ret;
    }
};

int main()
{
    CList<int> lista;
    for (size_t i = 0; i < 41; i++)
    {
        lista.PushBack(i + 1);
    }
    auto it = lista.begin();
    // dodati size i dovrsiti...

    return 0;
}

/*
Za vježbu:
Dijeljenje liste na do iteratora i od iteratora
Na postojeću listu nadodati novu listu
Obrtanje liste (inplace - bez pravljenja novih objekata); najbolje algoritam koji prepliće elemente
Ubacivanje u listu, ali da je lista sortirana
Dodati remove od-do za uklanjanje
*/
