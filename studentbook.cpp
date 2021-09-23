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
    ~Student_Book()
    {
        delete[] name;
    }
};


union data_structure
{
    unsigned long ulong;
    long longg;
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
    char* object = (char*)student_book;
    object += sizeof(char*);
    for (int i = 0; i < 10; i++)
    {
        if (*(bool*)object == true)
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
    char* object = (char*)student_book;
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
    Student_Book** new_student_book = new Student_Book * [size + 1];
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
    std::cout << "List of students: \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". " << student_book[i]->name << "\n";
    }
    std::cout << "\n";
}

void print_student(Student_Book** book, const char* target, const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(book[i]->name, target) == 0)
        {
            std::cout << book[i];
            return;
        }
    }
   
    std::cout << "There is no such student" << std::endl;
}

void print_debt(Student_Book** book, const size_t size)
{
    std::cout << "List of students that have debt: " << "\n";
    for (int i = 0; i < size; i++)
    {
        char* temp = (char*)book[i];
        temp += sizeof(char*);
        int count = 0;
        for (int j = 0; j < 10; j++)
        {
            if (*(bool*)temp == 0)
            {
                count++;
            }
            temp++;
        }
        if (count >= 5)
        {
            std::cout << book[i]->name << "\n";
        }
    }
    std::cout << std::endl;
}











int main()
{
    //Student_Book* student_book = new Student_Book;
    //obj_init(student_book, "Seymur");
   // std::cout << student_book << "\n";
    // size_t size = 0;
    // Student_Book** student_book = new Student_Book * [size];
    // Student_Book* student = new Student_Book;
    // obj_init(student, "xz");
    // bool grades[10] = { 0,1,1,0,0,0,0,0,0,1 };
    // give_grades(student, grades);
    // push_back(student_book, student, size);
    // print_students(student_book, size);
    // print_student(student_book, "xz", size);
    // std::cout << "\n";
    // print_debt(student_book, size);
    // delete[] student_book;

    
    // data_structure data;
    // data.ulong = 32;
    // std::cout << typeid(data.ulong).name() << "\n";
    // data.longg = 32;
    // std::cout << typeid(data.longg).name();
}