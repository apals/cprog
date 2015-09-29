#include "Vector.hpp"

int main(){
	Vector<double> v(2);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(10);
	std::cout << v.size() << std::endl;
    return 0;
}
