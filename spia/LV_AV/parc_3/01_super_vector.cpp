#include <iostream>
#include <initializer_list>

template <typename T>
class sv_iterator
{
    super_vector<T> *vektor;
    size_t indeks;

public:
    sv_iterator(super_vector<T> &v, size_t idx) : vektor(v), indeks(idx) {}

    friend bool operator==(const sv_iterator<T> &lhs, const sv_iterator<T> &rhs) { return lhs.vektor == rhs.vektor && lhs.indeks == rhs.indeks; }
    friend bool operator!=(const sv_iterator<T> &lhs, const sv_iterator<T> &rhs) { return !(lhs == rhs); }

    // sv_iterator<>
};

template <typename T>
class super_vector
{
    T *vektor;
    size_t kapacitet;
    size_t velicina;

public:
    super_vector() : kapacitet(2), velicina(0)
    {
        vektor = new T[kapacitet];
    }
    super_vector(std::initializer_list<T> init) : kapacitet(init.size()), velicina(init.size())
    {
        vektor = new T[kapacitet];
        size_t i = 0;
        for (const auto &el : init)
        {
            vektor[i++] = el;
        }
    }
    ~super_vector()
    {
        delete[] vektor;
    }
    void push_back(const T &el)
    {
        if (velicina == kapacitet)
        {
            kapacitet *= 2;
            T *novi_vektor = new T[kapacitet];
            for (size_t i = 0; i < velicina; i++)
            {
                novi_vektor[i] = vektor[i];
            }
            delete[] vektor;
            vektor = novi_vektor;
        }
        vektor[velicina++] = el;
    }
    void push_front(const T &el)
    {
        if (velicina == kapacitet)
        {
            kapacitet *= 2;
            T *novi_vektor = new T[kapacitet];
            for (size_t i = 0; i < velicina; i++)
            {
                novi_vektor[i + 1] = vektor[i];
            }
            delete[] vektor;
            vektor = novi_vektor;
        }
        else
        {
            for (size_t i = velicina; i > 0; i--)
            {
                vektor[i] = vektor[i - 1];
            }
        }
        vektor[0] = el;
        velicina++;
    }
    size_t size() const
    {
        return velicina;
    }
    T &operator[](size_t index)
    {
        if (index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        else if (index >= velicina)
        {
            if (index >= kapacitet)
            {
                T *novi_vektor = new T[index + 1];
                for (size_t i = 0; i < velicina; i++)
                {
                    novi_vektor[i] = vektor[i];
                }
                delete[] vektor;
                vektor = novi_vektor;
                for (size_t i = velicina; i < index + 1; i++)
                {
                    vektor[i] = T();
                }
                kapacitet = index + 1;
                velicina = index + 1;
            }
            else if (index < kapacitet)
            {
                velicina = kapacitet;
                vektor[index] = T();
            }
        }
        return vektor[index];
    }
    void primijeni(T (*funkcija)(T))
    {
        for (size_t i = 0; i < velicina; i++)
        {
            vektor[i] = funkcija(vektor[i]);
        }
    }

    sv_iterator<T> begin() { return sv_iterator(this, 0); }
    sv_iterator<T> end() { return sv_iterator(this, size); }
};

int main()
{
    super_vector<int> sv{1, 2, 3, 4, 5};
    sv.push_front(6);
    sv.primijeni([](int x)
                 { return x * x; });
    for (size_t i = 0; i < sv.size(); i++)
    {
        std::cout << sv[i] << " ";
    }
    return 0;
}