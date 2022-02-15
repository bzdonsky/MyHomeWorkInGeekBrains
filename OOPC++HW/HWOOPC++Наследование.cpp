#include <iostream>
#include <cstdint>

// 1.
class Person {
protected:
    std::string Name;
    std::uint8_t Age;
    std::string Gender;
    std::uint8_t Weight;
public:
    Person(std::string _Name, std::uint8_t _Age, std::string _Gender, std::uint8_t _Weight) :
            Name(_Name), Age(_Age), Gender(_Gender), Weight(_Weight) {}

    ~Person() {}
};

class Student : public Person {
private:
    std::uint16_t Year_of_study;
public:
    Student(std::string _Name, std::uint8_t _Age, std::string _Gender, std::uint8_t _Weight,
            std::uint16_t _Years_of_study) :
            Person(_Name, _Age, _Gender, _Weight), Year_of_study(_Years_of_study) {

        Student::m_square++;
    }

    ~Student() {}

    static std::uint8_t m_square;

    void Print() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Age: " << +Age << std::endl;
        std::cout << "Gender: " << Gender << std::endl;
        std::cout << "Weight: " << +Weight << std::endl;
        std::cout << "Year of study: " << +Year_of_study << std::endl;
        std::cout << std::endl;
    }

    void setName(std::string _Name){
        Name = _Name;
    }
    void setAge(std::uint8_t _Age){
        Age = _Age;
    }
    void setGender(std::string _Gender){
        Gender = _Gender;
    }
    void setWeight(std::uint8_t _Weight){
        Weight = _Weight;
    }
    void setYear_of_study(std::uint16_t _Year_of_study){
        Year_of_study = _Year_of_study;
    }
    void setStudent(std::string _Name, std::uint8_t _Age, std::string _Gender, std::uint8_t _Weight,
                    std::uint16_t _Years_of_study) {
        Name = _Name;
        Age = _Age;
        Gender = _Gender;
        Weight = _Weight;
        Year_of_study = _Years_of_study;
    }


};

uint8_t Student::m_square = 0; // счетчик студентов
void PrintNumStu() {
    std::cout << "Number of Students: " << +Student::m_square << std::endl;
    std::cout << std::endl;
}

// 2.
class Fruit {
protected:
    std::string Name;
    std::string Color;
public:
    Fruit() = default;

    ~Fruit() {}

    std::string getName() {
        return Name;
    }

    std::string getColor() {
        return Color;
    }
};

class Apple : public Fruit {
public:
    Apple(std::string _color) {
        Color = _color;
        Name = "Apple";
    }

    Apple();

    ~Apple() {}
};

class Banana : public Fruit {
public:
    Banana() {
        Name = "Banana";
        Color = "yellow";
    }

    ~Banana() {}

};

class GrannySmith : public Apple {
private:
    std::string lastName;


public:
    GrannySmith() : Apple(Name) {
        lastName = "Granny Smith ";
    }

    ~GrannySmith() {}

    std::string getName() {
        return lastName + Name;
    }

};

int main() {
    // 1.
    Student One("Gleb", 20, "Male", 80, 2022);
    Student Two("Ren", 40, "Male", 50, 2020);
    Student Three("Dima", 25, "Male", 70, 2021);
    Three.setStudent("Uliya", 28, "Female", 50, 2021);
    One.Print();
    Two.Print();
    Three.Print();
    PrintNumStu();
// 2.
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


    return 0;
}