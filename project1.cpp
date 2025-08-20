#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> books;  // List of books

// Show all books
void show_books() {
    if (books.empty()) {
        cout << "No books available." << endl;
    } else {
        cout << "Book List:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". " << books[i] << endl;
        }
    }
}

// Add a new book
void add_book() {
    string book_name;
    cout << "Enter the name of the new book: ";
    cin.ignore();  // clear input buffer
    getline(cin, book_name);
    books.push_back(book_name);
    cout << "'" << book_name << "' has been added to the library." << endl;
}

// Remove a book
void remove_book() {
    show_books();
    if (!books.empty()) {
        int book_index;
        cout << "Enter the number of the book to remove: ";
        cin >> book_index;

        if (book_index > 0 && book_index <= books.size()) {
            string removed_book = books[book_index - 1];
            books.erase(books.begin() + (book_index - 1));
            cout << "'" << removed_book << "' has been removed from the library." << endl;
        } else {
            cout << "Please enter a valid number." << endl;
        }
    }
}

// Main program
int main() {
    while (true) {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Show all books" << endl;
        cout << "2. Add a new book" << endl;
        cout << "3. Remove a book" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                show_books();
                break;
            case 2:
                add_book();
                break;
            case 3:
                remove_book();
                break;
            case 4:
                cout << "Thank you! The Library System has been closed." << endl;
                return 0;
            default:
                cout << "Please select a valid option." << endl;
        }
    }
}
