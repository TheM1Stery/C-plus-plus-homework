#include <iostream>
#include <string.h>

struct Book
{
    char* title;
    char* author;
    char* publisher;
    char* genre;
    ~Book()
    {
        delete[] title;
        delete[] author;
        delete[] publisher;
        delete[] genre;
    }
};

void initiliaze_obj(Book** library, const size_t size)
{
    for (int i = 0; i < size;i++)
    {
        library[i] = new Book();
    }
}

void delete_obj(Book** library, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        delete library[i];
    }
}

void create_book(Book* book, const char* title, const char* author, const char* publisher,const char* genre, const size_t buffer_size = 100)
{
    book->title = new char[buffer_size];
    strcpy_s(book->title, buffer_size, title);
    book->author = new char[buffer_size];
    strcpy_s(book->author, buffer_size, author);
    book->publisher = new char[buffer_size];
    strcpy_s(book->publisher, buffer_size, publisher);
    book->genre = new char[buffer_size];
    strcpy_s(book->genre, buffer_size, genre);
}



// void edit_book_contents(Book* book, const char* )
// {

// }

std::ostream& operator << (std::ostream& stream, Book* book)
{
    stream << "Book:\n";
    stream << "\tTitle: " << book->title << "\n";
    stream << "\tAuthor: " << book->author << "\n";
    stream << "\tPublisher: " << book->publisher << "\n";
    stream << "\tGenre: " << book->genre << "\n";
    return stream;
}

void print_lib(Book**& library, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << library[i];
    }
}

void push_back(Book**& books,Book* book,  size_t& size)
{
    Book** new_books = new Book*[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_books[i] = books[i];
    }
    new_books[size] = book;
    delete[] books;
    books = new_books;
    size++;
} 

Book** search_author(Book** library, const char* author, const size_t size, size_t& srch_res)
{
    size_t srch_size = 0;
    Book** new_lib = new Book*[srch_size];
    char* temp;
    for (int i = 0; i < size; i++)
    {
        temp = strstr(library[i]->author, author);
        if (temp != nullptr)
        {
            push_back(new_lib, library[i], srch_size);

        }
    }
    srch_res = srch_size;
    return new_lib;

}

Book** search_name(Book** library, const char* title, const size_t size, size_t& srch_res)
{
    size_t srch_size = 0;
    Book** new_lib = new Book*[srch_size];
    char* temp;
    for (int i = 0; i < size; i++)
    {
        temp = strstr(library[i]->title, title);
        if (temp != nullptr)
        {
            push_back(new_lib, library[i], srch_size);
        }
    }
    srch_res = srch_size;
    return new_lib;
}

void sort_by_name(Book** library, const size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            // if (library[j]->title < library[temp]->title)
            // {
            //     temp = j;
            // }
            if (strcmp(library[j]->title, library[temp]->title) == -1)
            {
                temp = j;
            }
        }
        std::swap(library[temp], library[i]);
    }
}


void sort_by_author(Book** library, const size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(library[j]->author, library[temp]->author) == -1)
            {
                temp = j;
            }
        }
        std::swap(library[temp], library[i]);
    }
}


void sort_by_publisher(Book** library, const size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(library[j]->publisher, library[temp]->publisher) == -1 )
            {
                temp = j;
            }
        }
        std::swap(library[temp], library[i]);
    }
}




int main()
{
    size_t size = 10;
    Book** library = new Book*[size];
    initiliaze_obj(library, size);
    // char temp[1];
    create_book(library[0], "Book1", "Author1", "Publisher1", "Genre1");
    create_book(library[1], "Book2", "Author2", "Publisher2", "Genre2");
    create_book(library[2], "Book3", "Author3", "Publisher3", "Genre3");
    create_book(library[3], "Book4", "Author4", "Publisher4", "Genre4");
    create_book(library[4], "Book5", "Author5", "Publisher5", "Genre5");
    create_book(library[5], "Book6", "Author6", "Publisher6", "Genre6");
    create_book(library[6], "Book7", "Author7", "Publisher7", "Genre7");
    create_book(library[7], "Book8", "Author8", "Publisher8", "Genre8");
    create_book(library[8], "Book9", "Author9", "Publisher9", "Genre9");
    create_book(library[9], "Book10", "Author10", "Publisher10", "Genre10");
    size_t srch_size = 0;
    // Book** srch_res = search_author(library, "Author1", size, srch_size);
    // print_lib(srch_res, srch_size);
    // delete[] srch_res;
    delete_obj(library, size);
    delete[] library;
}