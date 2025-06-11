#include <iostream>
using namespace std;

class MyClass {
private:

    // Pointer to dynamically 
    // allocated memory
    int* data;

public:
    MyClass(int value) {
        data = new int;
        *data = value;
        cout << *data << endl;
    }

    // User-defined destructor: Free 
    // the dynamically allocated memory
    ~MyClass() {
        
        // Deallocate the dynamically 
        // allocated memory
        delete data;  
        cout << "Destructor: Memory deallocated";
    }
};

int main() {
    MyClass obj1(10);


    std::cout << "\n test \n";
    return 0;
}