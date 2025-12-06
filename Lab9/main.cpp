#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author {
    string name;
    string nationality;
public:
    Author(string n="", string nat="") : name(n), nationality(nat) {}

    Author(const Author& other) : name(other.name), nationality(other.nationality) {}

    Author& operator=(const Author& other) {
        if(this != &other) {
            name = other.name;
            nationality = other.nationality;
        }
        return *this;
    }

    string getName() const { return name; }
    string getNationality() const { return nationality; }
};

class Book {
    string title;
    int publish_year;
    Author* author; // composition
public:
    Book(string t="", int y=0, string aname="", string anat="") : title(t), publish_year(y) {
        author = new Author(aname , anat);
    }

    Book(const Book& other) : title(other.title), publish_year(other.publish_year) {
        author = new Author(*other.author);
    }

    Book& operator=(const Book& other) {
        if(this != &other) {
            title = other.title;
            publish_year = other.publish_year;
            delete author;
            author = new Author(*other.author);
        }
        return *this;
    }

    ~Book() { delete author; }

    string getTitle() const { return title; }
    int getPubYear() const { return publish_year; }
    string getAuthorName() const { return author->getName(); }
    string getAuthorNationality() const { return author->getNationality(); }
};

class Library {
    vector<Book*> books; // aggregation
public:
    void addBook(Book* b) { books.push_back(b); }
    void listBooks() const {
        cout << "Library books:\n";
        for(auto bb : books) {
            cout << bb->getTitle() << " authored by " << bb->getAuthorName()
                 << " in " << bb->getPubYear() << endl;
        }
    }
};

class Member {
    string name;
    int id;
public:
    Member() = default;
    Member(string n,int i): name(n), id(i) {}
    void borrowBook(Book& b) { // take in ref
        cout << "Member: " << name << " borrowed " << b.getTitle() << endl;
    }
};

int main() {

    Book* b1 = new Book("1984", 1949, "George Orwell", "British");
    Book* b2 = new Book("Animal Farm", 1945, "George Orwell", "British");
    Book* b3 = new Book("Tales of Two Cities", 1859, "Charles Dickens", "British");

    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.listBooks();

    Member m1("Ahmed", 55);
    Member m2("ali", 66);

    m1.borrowBook(*b1); // send obj
    m2.borrowBook(*b2);

    delete b1;
    delete b2;
    delete b3;

    return 0;
}
