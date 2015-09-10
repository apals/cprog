#ifndef UINTVECTOR
#define UINTVECTOR

class UIntVector {

    private:
        size_t vector_size;
    public:
        UIntVector();
        UIntVector(size_t);
        UIntVector(std::initializer_list<unsigned int>);
        void reset();
        std::size_t size();
};

#endif
