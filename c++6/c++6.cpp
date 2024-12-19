#include <iostream>
#include <cstring>
#include <vector>

class String {
private:
    char* data;
    size_t size;

public:
    String(size_t length = 80) : size(length) {
        data = new char[size + 1];
        memset(data, 0, size + 1);
    }

    String(const char* str) : size(strlen(str)) {
        data = new char[size + 1];
        strcpy(data, str);
    }

    String(const String& other) : size(other.size) {
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~String() {
        delete[] data;
    }

    char& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int operator()(char c) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == c) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    operator int() const {
        return static_cast<int>(size);
    }

    void input() {
        std::cout << "Enter a string: ";
        std::cin.getline(data, size + 1);
        size = strlen(data);
    }

    void print() const {
        std::cout << data << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const String& str) {
        out << str.data;
        return out;
    }
};

int main() {
    String str("Hello, World!");
    str.print();

    try {
        std::cout << "Character at index 7: " << str[7] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    char searchChar = 'W';
    int index = str(searchChar);
    if (index != -1) {
        std::cout << "Character '" << searchChar << "' found at index: " << index << std::endl;
    }
    else {
        std::cout << "Character '" << searchChar << "' not found." << std::endl;
    }

    int length = str;
    std::cout << "Length of string: " << length << std::endl;

    return 0;
}
