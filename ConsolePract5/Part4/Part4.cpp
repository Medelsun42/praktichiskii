#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    int publicationYear;
    bool isAvailable;

public:
    Book(std::string isbn, std::string title, std::string author, int year)
        : isbn(isbn), title(title), author(author), publicationYear(year), isAvailable(true) {
    }

    // Getters
    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    bool getAvailability() const { return isAvailable; }

    // Setters
    void setAvailability(bool available) { isAvailable = available; }
};

class User {
private:
    std::string id;
    std::string name;
    std::string email;

public:
    User(std::string id, std::string name, std::string email)
        : id(id), name(name), email(email) {
    }

    // Getters
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

class Loan {
private:
    Book* book;
    User* user;
    time_t loanDate;
    time_t dueDate;
    bool isReturned;

public:
    Loan(Book* book, User* user, time_t loanDate, time_t dueDate)
        : book(book), user(user), loanDate(loanDate), dueDate(dueDate), isReturned(false) {
        book->setAvailability(false);
    }

    void returnBook() {
        isReturned = true;
        book->setAvailability(true);
    }

    // Getters
    Book* getBook() const { return book; }
    User* getUser() const { return user; }
    time_t getDueDate() const { return dueDate; }
    bool getReturnStatus() const { return isReturned; }
};

class Reservation {
private:
    Book* book;
    User* user;
    time_t reservationDate;

public:
    Reservation(Book* book, User* user, time_t date)
        : book(book), user(user), reservationDate(date) {
    }

    // Getters
    Book* getBook() const { return book; }
    User* getUser() const { return user; }
    time_t getReservationDate() const { return reservationDate; }
};

class Fine {
private:
    User* user;
    double amount;
    std::string reason;
    bool isPaid;

public:
    Fine(User* user, double amount, std::string reason)
        : user(user), amount(amount), reason(reason), isPaid(false) {
    }

    void payFine() { isPaid = true; }

    // Getters
    User* getUser() const { return user; }
    double getAmount() const { return amount; }
    std::string getReason() const { return reason; }
    bool getPaymentStatus() const { return isPaid; }
};

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;
    std::vector<Loan> loans;
    std::vector<Reservation> reservations;
    std::vector<Fine> fines;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addUser(const User& user) {
        users.push_back(user);
    }

    bool loanBook(Book* book, User* user, int loanDays = 14) {
        if (!book->getAvailability()) return false;

        time_t now = time(0);
        time_t dueDate = now + loanDays * 24 * 60 * 60;
        loans.emplace_back(book, user, now, dueDate);
        return true;
    }

    bool returnBook(Book* book) {
        auto it = std::find_if(loans.begin(), loans.end(),
            [book](const Loan& loan) {
                return loan.getBook() == book && !loan.getReturnStatus();
            });

        if (it != loans.end()) {
            it->returnBook();

            // Check for overdue and apply fine if needed
            time_t now = time(0);
            if (now > it->getDueDate()) {
                double daysOverdue = difftime(now, it->getDueDate()) / (24 * 60 * 60);
                double fineAmount = daysOverdue * 0.5; // $0.5 per day
                fines.emplace_back(it->getUser(), fineAmount, "Overdue book return");
            }
            return true;
        }
        return false;
    }

    bool reserveBook(Book* book, User* user) {
        if (book->getAvailability()) return false;

        time_t now = time(0);
        reservations.emplace_back(book, user, now);
        return true;
    }

    // Search functions
    std::vector<Book*> searchByTitle(const std::string& title) {
        std::vector<Book*> results;
        for (auto& book : books) {
            if (book.getTitle().find(title) != std::string::npos) {
                results.push_back(&book);
            }
        }
        return results;
    }

    std::vector<Book*> searchByAuthor(const std::string& author) {
        std::vector<Book*> results;
        for (auto& book : books) {
            if (book.getAuthor().find(author) != std::string::npos) {
                results.push_back(&book);
            }
        }
        return results;
    }

    // Other management functions
    void displayAllBooks() const {
        for (const auto& book : books) {
            std::cout << book.getTitle() << " by " << book.getAuthor()
                << " (" << book.getISBN() << ") - "
                << (book.getAvailability() ? "Available" : "Not Available") << "\n";
        }
    }

    // ... additional methods for user management, fine tracking, etc.
};

int main() {
    Library library;

    // Add sample books
    library.addBook(Book("978-3-16-148410-0", "The C++ Programming Language", "Bjarne Stroustrup", 2013));
    library.addBook(Book("978-0-13-235088-4", "Clean Code", "Robert C. Martin", 2008));

    // Add sample users
    library.addUser(User("001", "John Doe", "john@example.com"));
    library.addUser(User("002", "Jane Smith", "jane@example.com"));

    // Display all books
    library.displayAllBooks();

    // Search and loan a book
    auto results = library.searchByTitle("C++");
    if (!results.empty()) {
        Book* cppBook = results[0];
        User* john = john;

        if (library.loanBook(cppBook, john)) {
            std::cout << "Book loaned successfully!\n";
        }
    }

    return 0;
}