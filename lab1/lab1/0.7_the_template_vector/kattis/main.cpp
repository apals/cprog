#include "Vector.hpp"

int main(){
	Vector<int> v(2); // size = 2 , cap = 5;
	v.erase(0);
	v.erase(0);
	v.erase(0);
	std::cout << v.size() << std::endl;
    return 0;
}
