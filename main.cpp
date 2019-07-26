#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

template <typename T, unsigned N>
void print(const T (&p1)[N]){
    for (unsigned i = 0; i != N; ++i){
        cout << p1[i] << endl;
    }
}
//对于类，需要根据类的成员情况重载<<运算符以实现正确的打印

class TEST{
public:
        string s;
        int i;
    };

//重载输出运算符
ostream &operator<<(ostream &os, const TEST &t){
    os << "TEST s: " << t.s << "\n"
       << "TEST i: " << t.i << endl;
    return os;
}

template <typename T, size_t N>
T *begin_1(T (&arr)[N]){
    return arr;
}

template <typename T, size_t N>
T *end_1(T (&arr)[N]){
    return arr + N;
}

template <typename T, size_t N>
constexpr size_t size_1(T (&arr)[N]){
    return N;
}

int main() {
    long double ld[] = {3.14, 1.59, 2.6};
    print(ld);

    int ia[10] = {1, 2, 3, 4, 5, 6};
    print(ia);

    TEST iT[5] = {
            "a",1,
            "b",2,
            "c",3,
            "d",4,
    };
    print(iT);

    for (auto it_b = begin_1(iT), it_e = end_1(iT);it_b != it_e; ++it_b){
        cout << *it_b << endl;
    }

    constexpr size_t i = size_1(ld);
    cout << i << endl;
}