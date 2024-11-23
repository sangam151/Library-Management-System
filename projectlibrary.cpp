#include<iostream>
#include<string>
using namespace std;
class Librarian;
class book
{
    private:
    string title;
    string author;
    int price;
    static int bookcount;
    public:
    //default constructor
    book():title("unknown"),author("unknown"),price(0)
    {
        bookcount++;
    }
    //parametrized constructor
    book(string t,string a,int p=100):title(t),author(a),price(p)
    {
        bookcount++;
    }
    //copy constructor
    book(const book &b)
    {
        title=b.title;
        author=b.author;
        price=b.price;
        bookcount++;
    }
    //static method to get the count of book
    static int getbookcount()
    {
        return bookcount;
    }
    //friend function to display the book details
    friend void displaybook(const book &b);
    //friend class to update book details
    friend class Librarian;
    //nesting member function
    void updateprice(int newprice)
    
    {
        setprice(newprice);
    }
    private:
    //private member function to set price
    void setprice(int newprice)
    {
        price=newprice;
    }
};
//static data member initialization
int book::bookcount=0;
//function to display book details(friend function)
void displaybook(const book &b)
{
    cout<<"Title:"<<b.title<<", Author:"<<b.author<<", Price"<<b.price<<endl;
}
class  Librarian
{
    public:
    void updatebooktitle(book &b,const string &newtitle)
    {
        b.title=newtitle;
    }
     void updatebookauthor(book &b,const string &newauthor)
    {
        b.author=newauthor;
    }
};
//main function
int main(){
    //dynamic initialization using parameterized constructor
    book b1("C++ programming","Bjarne Stroustrup",500);
    //Default constructor
    book b2;
    //copy constructor
    book b3=b1;
    //Arrays of book
    book library[2]={b1,b2};
    //displaying book
    cout<<"initial books:"<<endl;
    for(int i=0;i<2;i++)
    {
        displaybook(library[i]);
    }
    //update bookdetails using friendclass
    Librarian librarian;
    librarian.updatebooktitle(library[1],"python programming");
    librarian.updatebookauthor(library[1],"Guido van Rossum");
    cout<<"books after update"<<endl;
    for(int i=0;i<2;i++)
    {
        displaybook(library[i]);
    }
    //using static method
    cout<<"total book:"<<book::getbookcount()<<endl;
    return 0;
}