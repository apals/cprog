#include <iostream>
struct Data {
    int x, y, z;
};  

Data ** foo(Data ** v, int x) {
    for (int i = 0; i < x; i++)
        //if (v[i] != 0)
            v[i] = new Data;
    }
    return v;
}

int main () {
    const int size = 5;
    Data ** v = new Data * [size];
    Data ** p = foo(v, size);
    std::cout << p << std::endl;
    std::cout << v << std::endl;
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(v) << std::endl;
    for(int i = 0; i < size; i++){
        delete p[i];
    }
    delete [] v;
}
