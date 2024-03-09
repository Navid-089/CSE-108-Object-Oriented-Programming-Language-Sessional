#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Student
{
    int id;
    char *name;
    float credit;
    float cgpa;

public:
    Student(const char *name1,int id1, float credit1, float cgpa1); //constructor
    ~Student(); // destructor
    void showInfo();
    void change(const char *name1);
    void change(int id1)
    {
        id=id1;
    }
    void addTermResult(float credit_add, float cgpa_add)
    {
        cgpa=(cgpa*credit+cgpa_add*credit_add)/(credit+credit_add);
        credit=credit+credit_add;
    }
};

Student :: Student(const char *name1,int id1, float credit1, float cgpa1)
{
    name=(char*) malloc ((strlen(name1))+1);  // memory allocating for name
    if(name==0)
    {
        cout << "There was an error while allocating memory...";
        exit(1);
    }

    strcpy(name,name1);
    id=id1;
    credit=credit1;
    cgpa=cgpa1;
}

Student ::~Student()
{
    free(name);
}

void Student :: showInfo()
{
    cout << "Name : " << name << ", ID : " << id << ", Credit Completed: " << credit << ", Cgpa : " << cgpa << endl; // printing info

}

void Student :: change(const char *name1)
{
    free(name);     // free-ing the name
    name=(char*) malloc (strlen(name1)+1);      // memory allocating for the new name inserted
    if(name==0)
    {
        cout << "There was an error while allocating memory...";
        exit(1);
    }
    strcpy(name,name1);
}

class Batch
{
    Student *list;
    int idx;
public:
    Batch();        // constructor
    ~Batch()
    {
        free(list);
    }

    void addStudent(Student &stu)
    {
        list[idx++]=stu;
    }
    void showAllStudents()
    {
        for(int i=0; i<idx; i++)
            list[i].showInfo();
    }
};

Batch :: Batch()
{
    list=(Student*) malloc(1200*sizeof(Student));
    if(list==0)
    {
        cout << "There was an error while allocating memory...";
        exit(1);
    }
    idx=0;
}

int main()
{
// Part 1
    /*A student class holds the information of the
    student name, id, credit earned so far, and
    cumulative gpa (cgpa)*/
    /*The name of a student is stored using malloc,
    which will be freed during destruction*/
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();
    cout<<"Changing the name of s1"<<endl;
    /*During changing the name, you should reallocate
    memory of the new name and free the previously
    allocated memory*/
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();
    cout<<"Changing the id of s2"<<endl;
    s2.change(1905149);
    s2.showInfo();
    cout<<"Adding a term result of s1"<<endl;
    /*The first argument of addTermResult is the credit
    earned in a term and second one is the gpa obtained
    in that term*/
    s1.addTermResult(19, 3.85);
    s1.showInfo();
//  Part 2
// Batch contains a list of students
    /*During construction, a Batch object allocates dynamic
    memory for 1200 students using malloc. The memory will
    be freed during destruction*/
    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);
    cout<<"Printing the list of students of the batch b"<<endl;
    b.showAllStudents();
}
