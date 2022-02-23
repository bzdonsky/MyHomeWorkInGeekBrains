#include <iostream>

//#1
template<typename T>
class Pair1 {
private:
    T val_1;
    T val_2;
public:
    Pair1(T value_1, T value_2) : val_1(value_1), val_2(value_2) {}
    ~Pair1() = default;

    T first() const {
        return val_1;
    }

    T second() const {
        return val_2;
    }

};
//#2
template<typename T,typename U>
class Pair2 {
private:
    T val_1;
    U val_2;
public:
    Pair2(T value_1, U value_2) : val_1(value_1), val_2(value_2) {}
    ~Pair2() = default;

    T first() const {
        return val_1;
    }

    U second() const {
        return val_2;
    }

};

//#3
template<typename T>
class Pair {
protected:
    std::string val_1;
    T val_2;
public:
    Pair(std::string value_1, T value_2) : val_1(value_1), val_2(value_2) {}


    std::string first() const {
        return val_1;
    }

    T second() const {
        return val_2;
    }

};
template<typename T>
class StringValuePair : public Pair<T>{
public:
    StringValuePair(std::string value1, T value2) : Pair<T>(value1,value2) {}


};

int main() {
    //#1
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    //#2
    Pair2<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair2<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
    //#3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;

    return 0;
}
