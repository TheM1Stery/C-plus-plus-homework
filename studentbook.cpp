#include <iostream>
#include <string.h>
struct Student_Book
{
    char* name;
    bool grade1 : 1; 
    bool grade2 : 1;
    bool grade3 : 1;
    bool grade4 : 1;
    bool grade5 : 1;
    bool grade6 : 1;
    bool grade7 : 1;
    bool grade8 : 1;
    bool grade9 : 1;
    bool grade10 : 1;
};


union data_structure
{
    unsigned long var;
    long var;
};

void obj_init(Student_Book* student_book, const char* name, size_t buffer_size = 100)
{
    student_book->name = new char[buffer_size];
    strcpy_s(student_book->name, buffer_size, name);
    
}

void init_arr(Student_Book** arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = new Student_Book;
    }

}



double get_average_grade(Student_Book* student_book)
{
    double count = 0;
    char* object = (char*) student_book;
    object += sizeof(char*);
    for (int i = 0 ; i < 10; i++)
    {
        if (*(bool*) object == true)
        {
            count++;
        }
        object++;
    }
    return (count / 10) * 100;
}
 


std::ostream& operator << (std::ostream& stream, Student_Book* student_book)
{
    stream << "Student name: " << student_book->name << "\n";
    char* object = (char*) student_book;
    object += sizeof(char*);
    for (int i = 0; i < 10; i++)
    {
        stream << "Grade " << i + 1 << ": ";
        stream << *(bool*)object << '\n';
        object++;
    }
    stream << "Average grade: " << get_average_grade(student_book) << "%";
    return stream;
}


void push_back(Student_Book**& student_book, Student_Book* student, size_t& size)
{
    Student_Book** new_student_book = new Student_Book*[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_student_book[i] = student_book[i];
    }
    new_student_book[size] = student;
    delete[] student_book;
    student_book = new_student_book;
    size++;
}

void give_grades(Student_Book* student_book, bool* grades)
{
    char* object = (char*)student_book;
    object += sizeof(char*);
    for (int i = 0; i < 10; i++)
    {
        *(bool*)object = grades[i];
        object++;
    }
}

void print_students(Student_Book** student_book, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << student_book[i]->name << "\n";
    }
    std::cout << "\n";
}

void print_student(Student_Book** book, char* target, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(book[i]->name, target) == 0)
        {
            std::cout << book[i];
            break;
        }
    }
    std::cout << "There is no such student" << std::endl;
}

// void print_debt(Student_Book** book, const size_t size)
// {
//     for (int i = 0; i < size; i++)
//     {

//     }
// }

enum class TYPE
{
    ULONG,
    LONG
};










int main()
{
    // Student_Book* student_book = new Student_Book;
    // init(student_book, "Seymur");
    // std::cout << student_book << "\n";
    // size_t size = 0;
    // Student_Book** student_book = new Student_Book*[size];
    
    
}