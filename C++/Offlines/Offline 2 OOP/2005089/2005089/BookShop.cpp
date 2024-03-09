/*******************************Offline 2****************************************/
/* Implement the functions of the class BookShop below as per the instructions  */
/* given inline the class definition. Make sure the output of the code in the   */
/* main function matches the given sample output. You may add/delete codes in   */
/* the main function during your testing. But before submission remove all your */
/* modifications from the main function and submit it as provided initially.    */
/********************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class BookShop
{
    char* name;
    Book* books; //List of books in the shop
    int size;  //maximum number of books the shop can keep
    int count; //tracks currently how many numbers in the shop
public:
    void setName(char* name)
    {
        free(this->name);
        /*Set the name of the bookshop to the given name*/
        this->name=(char*) malloc ((sizeof(name)+1)*sizeof(char));
        strcpy(this->name,name);
    }

    BookShop() //Default constructor
    {
        /*Initialize with size 5 and name to empty string ""*/
        size=5;
        count=0;
        books=(Book*) malloc (sizeof(Book)*size);


        name=(char*) malloc ((sizeof("")+1)*sizeof(char));
        strcpy(name,"");
    }

    BookShop(char* name, int size) //Parameterized constructor
    {
        /*Initialize with the given name and size*/
        this->name=(char*) malloc ((sizeof(name)+1)*sizeof(char));
        strcpy(this->name,name);

        this->size=size;

        this->count=0;

        this->books=(Book*) malloc (sizeof(Book)*size);



    }

    BookShop(const BookShop& bs) //Copy constructor
    {
        /*Write necessary code for the copy constructor*/

        name=(char*) malloc ((sizeof(bs.name)+1)*sizeof(char));
        strcpy(name,bs.name);

        size=bs.size;

        count=bs.count;

        books=(Book*) malloc (sizeof(Book)*size);

        for (int i=0; i<count; i++)
        {

            books[i]=bs.books[i];
        }

    }

    ~BookShop() //Destructor
    {
        /*Free memory as applicable*/
        free(name);
        free(books);
    }

    void addBook(Book b)
    {
        /*Add book b to the end of the list*/

        books[count] = b;
        count++;

    }

    void addBook(Book* ba, int count)
    {
        /*Add the given array of books ba to the end of the list*/

       for(int i=0;i<count;i++)
        addBook(ba[i]);
    }

    Book getBookInfo(char* title)
    {
        /*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/

        for(int i=0; i<count; i++)
        {
            if(strcmp(books[i].get_title(),title)== 0)
                return books[i];
        }


    }

    void updateBookPrice(int isbn, int price)
    {
        /*Update the price of the book with given isbn to the given price*/


        for(int i=0; i<count; i++)
        {
            if(isbn ==  books[i].get_isbn())
            {

                books[i].set_price(price);
                break;
            }


        }
    }

    void removeBook(int isbn)
    {
        /*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/

        for(int i=0; i<count; i++)
        {
            if(isbn == books[i].get_isbn())
            {
                for(int j=i; j<count-1; j++)
                {
                    books[j]=books[j+1];
                }
            }

        }
        books[count-1].set_isbn(-1);

        books[count-1].set_price(0);

        books[count-1].set_title("No Title");

        count--;

    }

    int totalPrice()
    {
        /*Return the sum of the prices of all the books in the list*/
        int sum=0;

        for(int i=0; i<count; i++)
        {
            sum=sum+books[i].get_price();
        }
        return sum;
    }

    void print()
    {
        /*Print the bookshop's name followed by information of all the books in the bookshop*/

        cout << "Bookshop Name : " << name << endl;

        for(int i=0; i<count; i++)
            books[i].print();
    }

    BookShop mergeShop(BookShop b)
    {
        /* Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/ 			/* Use the title **MergedShop** of the new bookshop*/

        int tmp_size;
        tmp_size=size+b.size;

        BookShop tmp_b("MergedShop",tmp_size);
        for(int i=0; i<count; i++)
        {

            tmp_b.addBook(books[i]);
        }

         for(int i=0; i<b.count; i++)
        {

            tmp_b.addBook(b.books[i]);
        }

        return tmp_b;



    }
};

int main()
{

    BookShop bs1;
    bs1.setName("Boimela");
    Book b1(101,"Teach Yourself C++",100);
    Book b2(102,"Teach Yourself C",200);
    Book b3(103,"Java For Dummies",300);
    bs1.addBook(b1);
    bs1.addBook(b2);
    bs1.addBook(b3);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
    cout<<endl;
    cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/

    cout<<endl;
    bs1.removeBook(102);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    bs1.updateBookPrice(101,500);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    Book jfd=bs1.getBookInfo("Java For Dummies");
    jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    Book ba[3]= {Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
    BookShop bs2("Puthighor",5);
    bs2.addBook(ba,3);
    bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Price: 1000
					 ISBN: 202, Title: Compilers, Price: 2000
					 ISBN: 203, Title: Computer Networks, Price: 1500
				 */

    cout<<endl;
    BookShop bs3=bs1.mergeShop(bs2);
    bs3.setName("Mullick Brothers");
    bs3.print();
    /*Output:
    				Bookshop Name: Mullick Brothers
    				ISBN: 101, Title: Teach Yourself C++, Price: 500
    				ISBN: 103, Title: Java For Dummies, Price: 300
    				ISBN: 201, Title: Operating Systems, Price: 1000
    				ISBN: 202, Title: Compilers, Price: 2000
    				ISBN: 203, Title: Computer Networks, Price: 1500
    			 */




}