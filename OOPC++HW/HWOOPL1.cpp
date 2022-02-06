#include <iostream>
#include <cstdint>
//1.
class Power {
public:
    Power() = default;
    Power(const int _numOne,const int _numTwo) : numOne(_numOne), numTwo(_numTwo) {}

    void SetNum(const int _numOne, const int _numTwo) {
        numOne = _numOne;
        numTwo = _numTwo;
    }

    void calculate() {
        int x = numOne;
        if (numTwo == 0u) {
            std::cout << "result 0" << std::endl;
        }
        if (numTwo == 1u) {
            std::cout << "result " << numOne << std::endl;
        }
        if (numTwo > 1u) {
            for (int i = 1u; i < numTwo; ++i) {
                x = x * numOne;
            }
            std::cout << "result " << x << std::endl;
        }
    };


private:
    int numOne;
    int numTwo;
};

// 2.
class RGBA {
private:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
public:

RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}
void PrintRGBA(){
    std::cout << "value red " << +m_red << std::endl << "value green " << +m_green << std::endl << "value blue " << +m_blue << std::endl << "value alpha " << +m_alpha << std::endl;
}
};

// 3.

class Stack {
private:
    int arrayStack[10u]{0u};
    int lengthStack = -1;
public:
    void reset(){
           if(lengthStack < -1u){
            for(int i = lengthStack; i > 0u; --i) {
                arrayStack[i] = 0u;
            }
            lengthStack = -1;
        } else {
               std::cout << "stack is empty" << std::endl;

           }
    }
    bool push(const int num){
        if(lengthStack < 10){
            arrayStack[++lengthStack] = num;
            return true;
        } else {
            return false;
        }

    }
    void pop(){
        if(lengthStack >= 0u){
            arrayStack[lengthStack--] = 0u;
        }
    }
    void printStack(){
        std::cout << '(';
        if(lengthStack > -1){
            for(int i = 0u; i < lengthStack +1u; ++i){
                std::cout << arrayStack[i];
            }
        }
        std::cout << ')'<< std::endl;
    }

};

int main() {
   // 1.
    Power Data;
    Data.SetNum(3u, 4u);
    Data.calculate();
    Data.SetNum(1u, 0u);
    Data.calculate();
    Data.SetNum(3u, 1u);
    Data.calculate();
    // 2.
    RGBA DataRGBA;
    DataRGBA.PrintRGBA();
    // 3.
    Stack stack;
    stack.reset();
    stack.printStack();
    stack.push(3u);
    stack.push(7u);
    stack.push(5u);
    stack.printStack();
    stack.pop();
    stack.printStack();
    stack.pop();
    stack.pop();
    stack.printStack();
    stack.reset();



    return 0;
}
