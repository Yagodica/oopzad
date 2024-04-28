#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Book {
public:
    Book(const std::string& title, const std::vector<std::string>& authors, unsigned int year,
         const std::string& publisher, unsigned int pages)
            : title(title), authors(authors), year(year), publisher(publisher), pages(pages) {}

    std::string getTitle() const { return title; }
    std::vector<std::string> getAuthors() const { return authors; }
    unsigned int getYear() const { return year; }
    std::string getPublisher() const { return publisher; }
    unsigned int getPages() const { return pages; }

private:
    std::string title;
    std::vector<std::string> authors;
    unsigned int year;
    std::string publisher;
    unsigned int pages;
};

struct Reader {
    std::string name;
    unsigned int date; // in YYYYMMDD format
};

class CatalogBook : public Book {
public:
    CatalogBook(const std::string& title, const std::vector<std::string>& authors, unsigned int year,
                const std::string& publisher, unsigned int pages, unsigned int id, unsigned int quantity)
            : Book(title, authors, year, publisher, pages), id(id), quantity(quantity), instances(quantity), readers() {}

    unsigned int getID() const { return id; }
    unsigned int getQuantity() const { return quantity; }
    unsigned int getInstances() const { return instances; }
    std::vector<Reader> getReaders() const { return readers; }

    void addReader(const std::string& name) {
        time_t now = time(0);
        char dateStr[9];
        strftime(dateStr, sizeof(dateStr), "%Y%m%d", gmtime(&now));
        unsigned int date = std::stoi(dateStr);
        readers.push_back({name, date});
        --instances;
    }

    void returnBook(const std::string& name) {
        for (size_t i = 0; i < readers.size(); ++i) {
            if (readers[i].name == name) {
                readers.erase(readers.begin() + i);
                ++instances;
                break;
            }
        }
    }

private:
    unsigned int id;
    unsigned int quantity;
    unsigned int instances;
    std::vector<Reader> readers;
};

int main() {
    std::vector<CatalogBook> catalog;

    while (true) {
        std::cout << "1. Create/delete book\n2. Add/remove book to/from catalog\n3. Show book info\n4. Search book\n5. Borrow book\n6. Return book\n7. Show overdue readers\n0. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        // Implement the corresponding functionality for each menu option
    }

    return 0;
}
