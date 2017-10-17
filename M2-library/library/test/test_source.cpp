#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cstddef>
#include "book.hpp"
#include "customer.hpp"
#include "../src/library.hpp"

std::string generate_isbn(){
    srand(time(0));
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr1(100, 999); // define the range
    std::uniform_int_distribution<> distr2(100, 999); // define the range
    std::string s = "978-0-"+std::to_string(distr1(eng))+"-"+std::to_string(distr2(eng))+"-2";
    return s;
}

Date get_current_date(){
    Date d;
    std::time_t t = time(0);
    struct tm * now = localtime(&t);
    d.day=now->tm_mday;
    d.month=now->tm_mon+1;
    d.year=now->tm_year+1900;
    return d;
}

TEST(test_library, test_constructor) {
    auto l = Library("Test Library");
}

TEST(test_library, test_get_books) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto i2 = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);
    auto b4 = Book("Test book2", "Test author", i2);

    auto l = Library("Test Library");
    auto v = l.getBooks();
    v.push_back(b);
    v.push_back(b2);
    v.push_back(b3);
    v.push_back(b4);

    EXPECT_EQ(b.getName(), v[0].getName());
    EXPECT_EQ(b2.getName(), v[1].getName());
    EXPECT_EQ(b3.getName(), v[2].getName());
    EXPECT_EQ(b4.getName(), v[3].getName());
}

TEST(test_library, test_get_customers) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");
    auto l = Library("Test Library");
    auto v = l.getCustomers();
    v.push_back(c);
    v.push_back(c2);

    EXPECT_EQ(c.getName(), v[0].getName());
    EXPECT_EQ(c2.getName(), v[1].getName());
}

TEST(test_library2, test_find_book_by_name) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto i2 = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);
    auto b4 = Book("Test book2", "Test author", i2);

    auto l = Library("Test Library");
    std::vector<Book>& v = l.getBooks();
    v.push_back(b);
    v.push_back(b2);
    v.push_back(b3);
    v.push_back(b4);

    EXPECT_EQ(b2.getISBN(), l.findBookByName("C++ primer").getISBN());
    EXPECT_EQ(b3.getISBN(), l.findBookByName("Test book").getISBN());
}

TEST(test_library2, test_find_books_by_author) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto i2 = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);
    auto b4 = Book("Test book2", "Test author", i2);

    auto l = Library("Test Library");
    std::vector<Book>& v = l.getBooks();
    v.push_back(b);
    v.push_back(b2);
    v.push_back(b3);
    v.push_back(b4);

    EXPECT_EQ(b3.getISBN(), l.findBooksByAuthor("Test author")[0].getISBN());
    EXPECT_EQ(b4.getISBN(), l.findBooksByAuthor("Test author")[1].getISBN());
}

TEST(test_library2, test_find_all_loaned_books) {
    auto b = Book("The C++ programming language", "Stroustrup, Bjarne", "978-0-321-56384-2");
    auto b2 = Book("C++ primer", "Lippman, Stanley B.", "978-0-321-71411-4");
    auto i = generate_isbn();
    auto i2 = generate_isbn();
    auto b3 = Book("Test book", "Test author", i);
    auto b4 = Book("Test book2", "Test author", i2);

    b2.loan();
    b4.loan();

    auto l = Library("Test Library");
    std::vector<Book>& v = l.getBooks();
    v.push_back(b);
    v.push_back(b2);
    v.push_back(b3);
    v.push_back(b4);

    EXPECT_EQ(b2.getISBN(), l.findAllLoanedBooks()[0].getISBN());
    EXPECT_EQ(b4.getISBN(), l.findAllLoanedBooks()[1].getISBN());
}

TEST(test_library2, test_find_customer) {
    auto c = Customer("Pertti Kovanen", "45647658657");
    auto c2 = Customer("Satu Kivinen", "95871034857");
    auto l = Library("Test Library");
    std::vector<Customer>& v = l.getCustomers();
    v.push_back(c);
    v.push_back(c2);

    EXPECT_EQ(c.getName(), l.findCustomer("45647658657").getName());
}
