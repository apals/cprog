#include <stdio.h>
#include <vector>
#include <iostream>
template <typename T>
bool varannan(T begin1, size_t length1, T begin2, size_t length2){
    if(length1 != (2*length2+1))
        return false;

    begin1++;
    int i = 1;
    while(i < (length1 - 1)) {
        if(*begin1 != *begin2)
            return false;
        begin1++; begin1++;
        begin2++;
        i+=2;
    }
    return true;
}

int main(){
    std::vector<int> v1 = {1, 1, 1, 2, 1, 3, 1, 5, 1};
    std::vector<int> v2 = {1, 2, 3, 5};
    std::cout << varannan(v1.begin(), 9, v2.begin(), 4) << std::endl;
}

/*
 * D) Vad ställer din kod för krav på innehållet i respektive mängd?
 *
 * De ska kunna jämföras med != operatorn. Om det är olika typer måste det finnas funktionalitet för att jämföra dessa.
 */
