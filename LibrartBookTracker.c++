#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX = 100;

struct Book {
    string title;
    string author;
    bool isBorrowed;
};

Book library[MAX];
int bookCount = 0;

void clearInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addBook() {
    if (bookCount >= MAX) {
        cout << "Library is Full!\n";
        return;
    }

    clearInput();

    cout << "Enter Book Title: ";
    getline(cin, library[bookCount].title);

    cout << "Enter Author Name: ";
    getline(cin, library[bookCount].author);

    library[bookCount].isBorrowed = false;
    bookCount++;

    cout << "Book Added Successfully!\n\n";
}

void showBooks() {
    if (bookCount == 0) {
        cout << "No Books in the Library.\n\n";
        return;
    }

    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << i + 1 << ". "
             << library[i].title << " by "
             << library[i].author;

        if (library[i].isBorrowed)
            cout << " (Borrowed)";
        else
            cout << " (Available)";

        cout << endl;
    }
    cout << endl;
}

void borrowBook() {
    if (bookCount == 0) {
        cout << "No Books to Borrow.\n\n";
        return;
    }

    showBooks();

    int choice;
    cout << "Enter Book Number to Borrow: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > bookCount) {
        cin.clear();
        clearInput();
        cout << "Invalid Choice.\n\n";
        return;
    }

    if (library[choice - 1].isBorrowed) {
        cout << "That Book is Already Borrowed!\n\n";
    } else {
        library[choice - 1].isBorrowed = true;
        cout << "You Borrowed the Book Successfully!\n\n";
    }
}

void returnBook() {
    if (bookCount == 0) {
        cout << "No Books to Return.\n\n";
        return;
    }

    showBooks();

    int choice;
    cout << "Enter Book Number to Return: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > bookCount) {
        cin.clear();
        clearInput();
        cout << "Invalid Choice.\n\n";
        return;
    }

    if (!library[choice - 1].isBorrowed) {
        cout << "That Book is Already Available.\n\n";
    } else {
        library[choice - 1].isBorrowed = false;
        cout << "Book Returned Successfully!\n\n";
    }
}

int main() {
    int option;

    do {
        cout << "==== LIBRARY BOOK TRACKER ====\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        if (cin.fail()) {
            cin.clear();
            clearInput();
            cout << "Invalid Option!\n\n";
            continue;
        }

        switch (option) {
            case 1:
                addBook();
                break;

            case 2:
                showBooks();
                break;

            case 3:
                borrowBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "INVALID OPTION!\n\n";
        }

    } while (option != 5);

    return 0;
}
