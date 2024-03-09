#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector( char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector( char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    int setX(int a)
    {
        x=a;
    }

    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    ~Vector()
    {
        delete []name;
    }

    Vector(const Vector &v)
{
    name=new char[strlen(v.name)+1];
    strcpy(name,v.name);
    x=v.x;
    y=v.y;
    z=v.z;
}

    friend ostream &operator<<(ostream &output, Vector &v);
    friend Vector operator*(int i,Vector v);
//    friend istream &operator>>(istream &input, Vector &v);

    Vector operator^(Vector v)
    {
        Vector tmp("tmp");

        tmp.x=y*v.z-z*v.y;
        tmp.y=z*v.x-v.z*x;
        tmp.z=x*v.y-v.x*y;

        return tmp;
    }

    Vector& operator=(const Vector &v)
    {
        x=v.x;
        y=v.y;
        z=v.z;


    return *this;

    }

    int operator==(Vector v)
    {
        if(v.x!=x || v.y !=y || v.z!=z)
            return 0;
        else
            return 1;
    }

    Vector operator*(int i)
    {
        Vector tmp("tmp");

        tmp.x=x*i;
        tmp.y=y*i;
        tmp.z=z*i;



        return tmp;
    }

    Vector operator*(Vector v)
    {
        Vector tmp("tmp");

        tmp.x=x*v.x;
        tmp.y=y*v.y;
        tmp.z=z*v.z;

        return tmp;
    }




};

ostream &operator<<(ostream &output, Vector &v)
{
    output << v.getName() << ": " << v.x << "x";
    if(v.y >=0)
        output <<"+" <<  v.y << "y";
    else
        output << v.y << "y";

     if(v.z >=0)
        output <<"+" <<  v.z << "z" << endl;
    else
        output << v.z << "z" << endl;


    return output;


}

Vector operator*(int i,Vector v)
{
    Vector tmp("tmp");

    tmp.x=v.x*i;
    tmp.y=v.y*i;
    tmp.z=v.z*i;

    return tmp;
}

int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    cout << v1;     //Print the components of vector v1
    cout << v2;     //Print the components of vector v2

    v3=v1^v2;       //Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1=v1*2;       //Multiply each component of vector v1 with the given value
    cout << v1;     //Print the modified components of vector v1

    v2=2*v2;        //Multiply each component of vector v2 with the given value
    cout << v2;     //Print the modified components of vector v2

    v3=v1*v2;       //Multiply each component of vector v1 with the corresponding component of vector v2
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}

/* Output:
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
Vectors are equal
v1: 2x+4y+6z
v2: 8x+10y-12z
Result1: 16x+40y-72z
Vectors are not equal
*/


