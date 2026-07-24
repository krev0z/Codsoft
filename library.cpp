#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
    int borrowDays;
};

vector<Book> books;


// Add a new book
void addBook() {
    Book b;

    cin.ignore();

    cout << "\nEnter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    cout << "Enter ISBN: ";
    getline(cin, b.isbn);

    b.available = true;
    b.borrowDays = 0;

    books.push_back(b);

    cout << "Book added successfully!\n";
}


// Display all books
void displayBooks() {

    if (books.empty()) {
        cout << "\nNo books in library.\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (int i = 0; i < books.size(); i++) {

        cout << "\nBook ID: " << i + 1;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;
        cout << "\nISBN: " << books[i].isbn;

        if (books[i].available)
            cout << "\nStatus: Available\n";
        else
            cout << "\nStatus: Issued\n";
    }
}


// Search book
void searchBook() {

    string search;
    bool found = false;

    cin.ignore();

    cout << "\nEnter Title/Author/ISBN: ";
    getline(cin, search);


    for (int i = 0; i < books.size(); i++) {

        if (books[i].title == search ||
            books[i].author == search ||
            books[i].isbn == search) {

            cout << "\nBook Found";
            cout << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author;
            cout << "\nISBN: " << books[i].isbn;

            if (books[i].available)
                cout << "\nStatus: Available\n";
            else
                cout << "\nStatus: Issued\n";

            found = true;
        }
    }


    if (!found)
        cout << "Book not found!\n";
}


// Checkout book
void checkoutBook() {

    int id;

    displayBooks();

    cout << "\nEnter Book ID to issue: ";
    cin >> id;


    if (id >= 1 && id <= books.size()) {

        if (books[id - 1].available) {

            cout << "Enter number of borrowing days: ";
            cin >> books[id - 1].borrowDays;

            books[id - 1].available = false;

            cout << "Book issued successfully!\n";

        }
        else {
            cout << "Book already issued!\n";
        }

    }
    else {
        cout << "Invalid Book ID!\n";
    }
}


// Return book and calculate fine
void returnBook() {

    int id;
    int days;

    displayBooks();

    cout << "\nEnter Book ID to return: ";
    cin >> id;


    if (id >= 1 && id <= books.size()) {

        if (!books[id - 1].available) {

            cout << "Enter number of days book was kept: ";
            cin >> days;


            int fine = 0;


            if (days > books[id - 1].borrowDays) {

                fine = (days - books[id - 1].borrowDays) * 5;
            }


            books[id - 1].available = true;
            books[id - 1].borrowDays = 0;


            cout << "Book returned successfully!\n";
            cout << "Fine: Rs. " << fine << endl;

        }
        else {
            cout << "Book was not issued.\n";
        }

    }
    else {
        cout << "Invalid Book ID!\n";
    }
}



int main() {

    int choice;


    do {

        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                checkoutBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                cout << "Thank you for using Library System!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }


    } while(choice != 6);


    return 0;
}
