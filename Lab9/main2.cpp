#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author {
    string name;
    string nationality;
public:
    Author(string n="", string nat="") : name(n), nationality(nat) {}

    string getName() const { return name; }

    string getNationality() const { return nationality; }
};

class Book {
    string title;
    int publish_year;
    Author author; // composition
public:
    Book(string t="", int y=0, string aname="", string anat="") 
        : title(t), publish_year(y), author(aname, anat) {}

    string getTitle() const { return title; }
    int getPubYear() const { return publish_year; }
    string getAuthorName() const { return author.getName(); }
    string getAuthorNationality() const { return author.getNationality(); }
};

class Library {
    vector<Book> books; // aggregation
public:
    void addBook(const Book& b) { books.push_back(b); }
    void listBooks() {
        cout << "Library books:\n";
        for(auto& b : books) {
            cout << b.getTitle() << " authored by " << b.getAuthorName()
                 << " in " << b.getPubYear() << endl;
        }
    }
};

class Member {
    string name;
    int id;
public:
    Member() = default;
    Member(string n,int i): name(n), id(i) {}
    void borrowBook(Book& b) {
        cout << "Member: " << name << " borrowed " << b.getTitle() << endl;
    }
};

int main() {

    Book b1("1984", 1949, "George Orwell", "British");
    Book b2("Animal Farm", 1945, "George Orwell", "British");
    Book b3("Tales of Two Cities", 1859, "Charles Dickens", "British");

    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.listBooks();

    Member m1("Ahmed", 55);
    Member m2("ali", 66);

    m1.borrowBook(b1);
    m2.borrowBook(b2);

    return 0;
}
