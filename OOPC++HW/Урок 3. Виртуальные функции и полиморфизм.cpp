#include <iostream>

#include <cmath>

// 1.
class Figure {
public:
    Figure() = default;

    virtual int area() = 0;
};

class Parallelogram : public Figure {
protected:
    int a; // основание
    int h; // высота
public:
    Parallelogram(int _a, int _h) : a(_a), h(_h) {}

    Parallelogram(int _a) : a(_a) {}

    virtual int area() override {
        return a * h; // основание умноженое на высоту
    }
};

class Circle : public Figure {
private:
    int r; // радиус
    const float Pi = 3.14;
public:
    Circle(int _r) : r(_r) {}

    virtual int area() override { // как переопределить виртуальную функцию в родительском классе так чтобы все
        return Pi * pow(r, 2);  // функции использовали тип int , а эта тип float?
    }
};

class Rectangle : public Parallelogram {
//S = a × b
public:
    Rectangle(int _a, int _b) : Parallelogram(_a, _b) {}
};

class Square : public Parallelogram {
public:
    Square(int _a) : Parallelogram(_a) {}

    virtual int area() override {
        return pow((a * a), 2); // S = a × a = a2
    }
};

class Rhombus : public Parallelogram {
private:
public:
    Rhombus(int _a, int _h) : Parallelogram(_a, _h) {}

    virtual int area() override {
        return a * h; // сторона * высоту
    }
};

// 2.
class Car {
protected:
    std::string company;
    std::string model;
public:
    Car() = default;

    ~Car() = default;
};

class PassengerCar : public virtual Car {
public:
    PassengerCar() {
        company = "One";
        model = "1";
        std::cout << company << " " << model << std::endl;
    }

    void print() {}

    ~PassengerCar() = default;

};

class Bus : public virtual Car {
public:
    Bus() {
        company = "two";
        model = "2";
        std::cout << company << " " << model << std::endl;
    }

    ~Bus() = default;

};

class Miniven : public PassengerCar, public Bus {
public:
    Miniven() {
        PassengerCar::company = "One";
        Bus::model = "2";
        std::cout << PassengerCar::company << " " << Bus::model << std::endl;
    }

    ~Miniven() = default;

};


// 3.
class Fraction {
private:
    int numerator;
    int denominator;

    int HOD(int a, int b) {
        while (a != 0 and b != 0) {
            if (a > b) { a = a % b; } else { b = b % a; }
        }
        return a + b;
    }

    int HOK(const int a,const int b) {
        return (a * b) / HOD(a, b);
    }

    bool zero(const int a) {
        if (denominator == 0 || a == 0) { return true; } else { return false; }
    }

     int operation(int a,int b,const char simbol,int _a,int _b) {
        int c;
        switch (simbol) {
            case '+':
                a = a * _b;
                _a = _a * b;
                c = a + _a;
                break;
            case '-':
                a = a * _b;
                _a = _a * b;
                c = a - _a;
                break;
            case '*':
                c = a * _a;
                break;
            case '/':
                c = a * _b;
                break;

        }
        return c;
    }

public:
     Fraction(float _num, float _den) : numerator(_num), denominator(_den) {}

    const int getNum() {
        return numerator;
    }

    const int getDen() {
        return denominator;
    }

    Fraction &operator+(Fraction &_num) {

        if (zero(_num.denominator)) { return *this; }
        else {
            int temp;
            temp = HOK(denominator, _num.denominator);
            numerator = operation(numerator, denominator, '+', _num.numerator, _num.denominator);

            if (numerator % HOD(numerator,temp) == 0 and temp % HOD(numerator,temp) == 0) {
                denominator = temp / HOD(numerator, temp) ;
                numerator = numerator / HOD(numerator,temp);

                return *this;
            } else {
                denominator = temp;
                return *this;
            }

        }

    }

    const Fraction &operator-(const Fraction &_num) {
        if (zero(_num.denominator)) { return *this; }
        else {
            int temp;
            temp = HOK(denominator, _num.denominator);
            numerator = operation(numerator, denominator, '-', _num.numerator, _num.denominator);
            denominator = temp;
            return *this;
        }

    };

   const Fraction &operator*(const Fraction &_num) {
        if (zero(_num.denominator)) { return *this; }
        else {
            numerator = operation(numerator, denominator, '*', _num.numerator, _num.denominator);
            if (denominator == _num.denominator) {
                return *this;
            } else {
                denominator = denominator * _num.denominator;
                return *this;
            }


        }
    }

    const Fraction &operator/(const Fraction &_num) {
        if (zero(_num.denominator)) { return *this; }
        else {
            numerator = operation(numerator, denominator, '/', _num.numerator, _num.denominator);
            denominator = denominator * _num.numerator;
            int temp1;
            int temp2;
            temp1 = HOK(numerator, denominator);
            temp2 = temp1 / numerator;
            numerator = temp1 / denominator;
            denominator = temp2;
        }
        return *this;
    }



    void print() {
        std::cout << numerator << '/' << denominator << std::endl << HOD(numerator,denominator) << std::endl;

    }
};

int main() {
    Fraction a(2, 9);
    Fraction b(2, 3);

    a-b;
    a.print();
    return 0;
}