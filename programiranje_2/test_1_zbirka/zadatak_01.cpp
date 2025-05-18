#include <iostream>

unsigned int u_sekunde(unsigned int h, unsigned int m, unsigned int s)
{
    return h * 3600 + m * 60 + s;
}

void ispisi_sekunde_u_vrijeme(unsigned int s)
{
    std::cout << s / 3600 << "h " << (s / 60) % 60 << "min " << s % 60 << "s\n";
}

int main()
{
    // Prvi vremenski trenutak
    unsigned int h1, m1, s1;
    std::cout << "Unesi prvi vremenski trenutak (h m s): ";
    std::cin >> h1 >> m1 >> s1;

    // Drugi vremenski trenutak
    unsigned int h2, m2, s2;
    std::cout << "Unesi drugi vremenski trenutak (h m s): ";
    std::cin >> h2 >> m2 >> s2;

    // Razlika dva vremenska trenutka
    std::cout << "Izmedju dva vremenska trenutka proslo je ";
    ispisi_sekunde_u_vrijeme(u_sekunde(h2, m2, s2) - u_sekunde(h1, m1, s1));

    return 0;
}