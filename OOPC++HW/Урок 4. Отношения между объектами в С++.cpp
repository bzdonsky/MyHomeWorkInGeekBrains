#include <iostream>

#define INIT 4u
class vector {
private:
    size_t m_size;
    size_t m_copacity;
    int *m_data;
    bool empty(){
        return  m_size!=0u;
    }
public:
vector() : m_size(0), m_data(nullptr) {}
vector(int copacity) : m_copacity(copacity){
        if(copacity >0){
            m_data = new int[copacity];
        } else {
            m_data = nullptr;
        }
    }

size_t size () const {
    return m_size;
}
size_t copacity()const{
    return m_copacity;
}

void push_back(int value){
    if(m_data){
        if(m_size +1u > m_copacity){
            int* temp_data = new int [m_copacity = m_copacity * 2u];
            std::copy(m_data, m_data + m_size, temp_data);
            delete[] m_data;
            m_data = temp_data;

        }
    } else {
        m_data = new int [INIT];
        m_copacity = INIT;

    }
    m_data[m_size++] = value;
}
void pop_back(){
    if(empty()){
        --m_size;
    }
}
void sort(){
    int temp;
    if(empty()){
        for(int index_i = 0u; index_i < m_size; index_i++){
            for(int index_j = 0u; index_j < m_size - index_i - 1u; index_j++){
                if(m_data[index_j] > m_data[index_j+1u]){
                    temp = m_data[index_j];
                    m_data[index_j] = m_data[index_j + 1u];
                    m_data[index_j +1u] = temp;
                }
            }
        }
    }
}
void push_front(int value){
    if(m_data){
        if(m_size +1u > m_copacity){
            int* temp_data = new int [m_copacity = m_copacity * 2u];
            std::copy(m_data, m_data + m_size, temp_data);
            delete[] m_data;
            m_data = temp_data;

        }
    } else {
        m_data = new int [INIT];
        m_copacity = INIT;
    }
    for(int index_i = m_size; index_i >= 0u; index_i--){
        m_data[index_i + 1u] = m_data[index_i];
    }
    m_data[0] = value;
    m_size++;
}
void pop_front(){
    if(empty()){
        for(int index_i = 0u; index_i < m_size; index_i++){
            m_data[index_i] = m_data[index_i +1u];

        }
        --m_size;
    }
}
void printdata(){
    if(empty()){
        for(int index_i= 0u; index_i < m_size; index_i++){
            std::cout << m_data[index_i] << std::endl;
        }
    }
}
void number(){
    sort();
    int number = 0u;
    for(int i = 0u; i < m_size; i++){
        if(m_data[i] != m_data[i+1]){
            ++number;
        }
    }
    std::cout << number << std::endl;
}

    ~vector() {
    delete[] m_data;
}
};


int main() {



    return 0;
}
