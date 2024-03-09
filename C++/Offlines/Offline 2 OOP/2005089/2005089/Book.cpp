/************Topics of Practice*************************/
/* => Dynamic Allocation of objects         		   */
/* => Constructor overloading		        		   */
/* => Copy constructor				        		   */
/* => Passing and returning objects from functions     */
/*******************************************************/

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Book{
	int isbn;
	char* title;
	double price;
	public:
		//Constructor functions
		Book(){//default constructor
//		    cout<<"In the default constructor of Book"<<endl;
			//Write your code here
            isbn=-1;
            price=0;
            title=(char*) malloc ((strlen("No Title")+1)*(sizeof(char)));
            strcpy(title,"No Title");
		}

		Book(int isbn, char* title, int price){//constructor with arguments

			//Write your code here
			this->isbn=isbn;
			this->price=price;
			this->title=(char*) malloc ((strlen(title)+1)*(sizeof(char)));
			strcpy(this->title,title);

//			cout<<"In the parameterized constructor of Book "<<isbn<<endl;

		}
		Book(const Book& book){//Copy constructor

			//Write your code here

			isbn=book.isbn;
			price=book.price;
			title=(char*) malloc ((strlen(book.title)+1)*(sizeof(char)));
			strcpy(title,book.title);

//            cout<<"In the copy constructor of Book "<<isbn<<endl;


		}

		//Destructor function
		~Book(){
//		    cout<<"In the destructor of Book "<<isbn<<endl;
			//Write your code here
			free(title);
		}

		//Write the setter functions here

		void set_price(int p)
		{
		    price=p;
		}

		void set_isbn(int i)
		{
		    isbn=i;
		}

		void set_title(char *t)
		{
		    free(title);
		    title=(char*) malloc ((strlen(t)+1)*(sizeof(char)));
		    strcpy(title,t);
		}


		//Write the getter functions here

		int get_price()
		{
		    return price;
		}

		int get_isbn()
		{
		    return isbn;
		}

		char* get_title()
		{
		    return title;
		}

		//Service functions
		void print(){
			//Write your code here

			cout << "ISBN : " << isbn << ", Title : " << title << ", price : " << price << endl;


		}

		int isTheSameBook(Book b){
			//Write your code here



            if(isbn==b.isbn)
                return 1;
            else
                return 0;
		}

		Book generateNewEdition(int isbn, int price){
			//Write your code here
            Book tmp;

            tmp.price=price;
            tmp.isbn=isbn;
            tmp.title= title=(char*) malloc ((strlen(title)+1)*(sizeof(char)));
            strcpy(tmp.title,title);

            return tmp;

		}
};

//int main(){
//	//To do: Create a book object named b1 with the default constructor
//    Book b1;
//	//To do: Set the properties of b1 as follows: isbn=101, title="Teach yourself C++", price=230
//    b1.set_isbn(101);
//    b1.set_title("Teach yourself C++");
//    b1.set_price(230);
//	//To do: Print the details of b1
//    b1.print();
//	//To do: Create a book object named b2 with values initialized as- isbn=102, title="Teach Yourself Java", price=235
//    Book b2(102,"Teach Yourself Java",235);
//	//To do: Crate a book object b3 and initialize with b2
//    Book b3(b2);
//	//To do: Check if b2 and b3 represent the same book. Print "Yes" or "No" based on the check result.
//    if(b2.isTheSameBook(b3) ==1)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//	//To do: Change the title of b3 to "Teach Yourself Java in Thirty Days"
//    b3.set_title("Teach Yourself Java in Thirty Days");
//	//To do: Change the isbn of b3 to 103
//    b3.set_isbn(103);
//	//To do: Print the details of book b2 and b3
//    b2.print();
//    b3.print();
//	//To do: Create a book b4 as a new edition of b3. Set the isbn and price of the new edition to 104 and 600, respectively
//    Book b4=b3.generateNewEdition(104,600);
//	//To do: Print the details of b4
//    b4.print();
//	//To do: Create a Book pointer named bp1
//    Book *bp1;
//	//To do: Allocate a Book object to bp1 initialized as- isbn=104, title="C++ For Dummies", price=400
//    bp1= new Book(104,"C++ For Dummies",400);
//	//To do: Print the details of the book pointed by bp1
//    bp1->print();
//	//To do: Free the memory allocated to bp1
//    delete bp1;
//	//To do: Create a Book pointer named bl1 and allocate three book objects to it without any initialization
//    Book *bl1=new Book[3];
//	//To do: Set the properties of the three book objects pointed to by bl1 as follows:
//	// <isbn=201, title=Compilers, price=340>,
//	// <isbn=202, title=Operating Systems, price=450>,
//	// <isbn=203, title=Data Communications, price=600>
//    bl1[0].set_isbn(201);
//    bl1[0].set_title("Compilers");
//    bl1[0].set_price(340);
//
//
//
//    bl1[1].set_isbn(202);
//    bl1[1].set_title("Operating Systems");
//    bl1[1].set_price(450);
//
//
//    bl1[2].set_isbn(203);
//    bl1[2].set_title("Data Communications");
//    bl1[2].set_price(600);
//
//
//
//
//
//
////To do: Print the details of all the three books pointed to by bl1
//
//	for(int i=0;i<3;i++)
//        bl1[i].print();
//
//	//To do: Free the memory allocated to bl1
//
//	delete [] bl1;
//}
