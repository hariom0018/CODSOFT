#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;
};

vector<Book> library;

void addBook(int id, string title, string author) {
    library.push_back({id, title, author, false});
    cout << "Book added successfully!\n";
}

void viewBooks() {
    cout << "\nLibrary Books:\n";
    for (auto &book : library) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Author: " << book.author
             << " | Status: " << (book.isBorrowed ? "Borrowed" : "Available") << endl;
    }
}

void borrowBook(int id) {
    for (auto &book : library) {
        if (book.id == id && !book.isBorrowed) {
            book.isBorrowed = true;
            cout << "You borrowed: " << book.title << endl;
            return;
        }
    }
    cout << "Book is not available!\n";
}

void returnBook(int id) {
    for (auto &book : library) {
        if (book.id == id && book.isBorrowed) {
            book.isBorrowed = false;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "book id is invalid or book was not borrowed!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. View Books\n3. Borrow Book\n4. Return Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            addBook(id, title, author);
        } 
        else if (choice == 2) {
            viewBooks();
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            borrowBook(id);
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            returnBook(id);
        } 
        else if (choice == 5) {
            cout << "Exiting Library System...\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}