// FIFO

#include <iostream>

template <typename T>
class Queue
{
    class QueueElement
    {
    public:
        T m_value;
        QueueElement *m_next;
        QueueElement(T value) : m_value(value), m_next(nullptr) {}
    };
    QueueElement *m_head; // Pointer to head of queue
    QueueElement *m_tail; // Pointer to tail of queue
    size_t m_size;        // Size of queue

public:
    Queue() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    Queue(const QueueElement &q) : m_head(nullptr), m_tail(nullptr), m_size(0)
    {
        auto to_add = q.m_head;
        while (to_add != nullptr)
        {
            push(to_add->m_value);
            to_add = to_add->m_next;
        }
    }

    ~Queue()
    {
        auto t = m_head;
        while (t != nullptr)
        {
            auto to_delete = t;
            t = t->m_next;
            std::cout << "Unistavam QueueElement.\n";
            delete to_delete;
        }

        // while (m_head != nullptr)
        //     pop();
    }

    Queue &operator=(const Queue &q)
    {
        if (this == &q)
            return *this;

        while (!empty())
            pop(); // this->pop();

        auto to_add = q.m_head;
        while (to_add != nullptr)
        {
            push(to_add->m_value);
            to_add = to_add->m_next;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Queue &q)
    {
        auto t = q.m_head;
        os << "[";
        while (t != nullptr)
        {
            os << t->m_value;
            t = t->m_next;
            if (t != nullptr)
                os << ", ";
        }
        os << "]";
        return os;
    }

    bool empty() { return m_head == nullptr; }

    std::size_t size() { return m_size; }

    void push(T value)
    {
        auto ptr = new QueueElement(value);
        if (m_head == nullptr)
        {
            m_head = ptr;
            m_tail = ptr;
        }
        else
        {
            m_tail->m_next = ptr;
            m_tail = ptr;
        }
        m_size++;
    }

    T &front()
    {
        if (m_head == nullptr)
            throw std::runtime_error("Queue is empty!");
        return m_head->m_value;
    }

    T &back()
    {
        if (m_head == nullptr) // ili (m_tail == nullptr)
            throw std::runtime_error("Queue is empty!");
        return m_tail->m_value;
    }

    void pop()
    {
        if (m_head == nullptr)
            throw std::runtime_error("Queue is empty!");
        auto to_pop = m_head;
        m_head = m_head->m_next;
        if (m_head == nullptr)
            m_tail = nullptr;

        delete to_pop;
        m_size--;
    }
};

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    Queue<int> q1(q);

    std::cout << "Front = " << q.front() << std::endl;

    std::cout << q;

    q.pop();

    std::cout << q;

    std::cout << q1;

    return 0;
}