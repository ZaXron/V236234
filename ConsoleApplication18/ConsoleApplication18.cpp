#include <iostream>
using namespace std;
class Book {
    char* authour;
    char* text;
    int pages;
    int year;
public:
    Book() = default;
    Book(const char* _authour, const char* _text, int _pg, int _y)
    {
        authour = new char[strlen(_authour) + 1];
        strcpy_s(authour, strlen(_authour) + 1, _authour);
        text = new char[strlen(_text) + 1];
        strcpy_s(text, strlen(_text) + 1, _text);
        pages = _pg;
        year = _y;
    }
    Book& operator=(const Book& obj) = delete;
    Book(Book& obj) = delete;
    Book& operator=(Book&& obj)
    {
        authour = obj.authour;
        text = obj.text;
        pages = obj.pages;
        year = obj.year;
        obj.authour = nullptr;
        obj.text = nullptr;
        obj.pages = 0;
        obj.year = 0;
        return*this;
    }
    Book(Book&& obj)
    {
        authour = obj.authour;
        text = obj.text;
        pages = obj.pages;
        year = obj.year;
        obj.authour = nullptr;
        obj.text = nullptr;
        obj.pages = 0;
        obj.year = 0;
    }

    void Print() {
        cout << authour << endl << text << endl << pages << endl << year << endl;
    }
};
int main()
{
    Book a("hello", "page", 1, 2);

    Book d = move(a);
    d.Print();

}
