#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#define RESET   "\033[0m"      // Reset to default text color
#define RED     "\033[31m"     // Red text color
#define GREEN   "\033[32m"     // Green text color
#define YELLOW  "\033[33m"     // Yellow text color
#define BLUE    "\033[34m"     // Blue text color
#define MAGENTA "\033[35m"     // Magenta text color
#define CYAN    "\033[36m"     // Cyan text color
#define WHITE   "\033[37m"     // White text color
#define GRAY    "\033[90m"     // Gray text color
#define LIGHT_RED     "\033[91m"     // Light Red text color
#define LIGHT_GREEN   "\033[92m"     // Light Green text color
#define LIGHT_YELLOW  "\033[93m"     // Light Yellow text color
#define LIGHT_BLUE    "\033[94m"     // Light Blue text color
#define LIGHT_MAGENTA "\033[95m"     // Light Magenta text color
#define LIGHT_CYAN    "\033[96m"     // Light Cyan text color
using namespace std;

class TicketBookingException : public exception {
public:
    const char* what() const throw()
     {
        return "Error: You are asking for more tickets than available!";
    }
};

class Seats {
public:
    int seatid;
    string seattype;
    int totalseats;
    int no_of_bookedseats;
    int availableseats;

    Seats(int id, string type, int n, int no_ofb,int as)
     {
        seatid = id;
        seattype = type;
        totalseats = n;
        no_of_bookedseats = no_ofb;
        availableseats = totalseats - no_of_bookedseats;
    }

    void displayAvailableSeats()
     {

        cout <<YELLOW <<"SEATS DETAILS:" << endl;
        cout <<MAGENTA<< "Seat Type: " << seattype << endl;
        cout << MAGENTA<<"Total Seats: " << totalseats << endl;
        cout << MAGENTA<<"Booked seats: " << no_of_bookedseats << endl;
        cout << MAGENTA<<"Seats Available: " << availableseats << endl;
    }
};

class Hall {
public:
    int hall_id;
    string hallname;
    Seats seats;

    Hall(int hall_id, string name, int seat_id, string seat_type, int total_seats, int booked_seats)
        : hall_id(hall_id), hallname(name), seats(seat_id, seat_type, total_seats, booked_seats, 0) // The last parameter "as" is set to 0 as it is not provided in the constructor of Seats.
    {
    }

    void displaydetails()
    {
        cout << "hall ID: " << hall_id << endl;
        cout << "hall Name: " << hallname << endl;
        cout << "Seat Type: " << seats.seattype << endl;
        cout << "Total Seats: " << seats.totalseats << endl;
        cout<<"Available seats in the hall: "<<seats.availableseats<<endl;

    }

};


class Movie {
public:
    int movieid;
    string moviename;
    string genre;
    string duration;
   Hall *h;

    Movie(int a, string name, string genre, string duration)
     {
        movieid = a;
        moviename = name;
        this->genre = genre;
        this->duration = duration;
    }

    void displayMovieDetails()
     {
        cout <<YELLOW <<"MOVIE DETAILS:" << endl;
        cout << MAGENTA<<"Movie id: " << movieid << endl;
        cout << MAGENTA<<"Movie Name: " << moviename << endl;
        cout << MAGENTA<<"Genre: " << genre << endl;
        cout << MAGENTA<<"Duration: " << duration << " minutes" << endl;
    }
};

class Employee {
public:
    int employeeid;
    string employeename;
    string designation;
    float salary;

    Employee(int id, string name, string des, float s)
    {
        employeeid = id;
        employeename = name;
        designation = des;
        salary = s;
    }

    virtual void displaydetails()
     {
        cout << BLUE<<"Employee ID: " << employeeid << endl;
        cout <<BLUE<< "Employee name: " << employeename << endl;
        cout <<BLUE<< "Employee designation: " << designation << endl;
        cout <<BLUE<< "Salary: " << salary << endl;
    }
};

class Operatorroom {
public:
   string msg;
    Hall* h;
    Employee *emp;
    Operatorroom( string m,Hall *h)
    {
       msg=m;
       this->h=h;
    }

    void control()
    {
        // Code to control screen, movies, and sound systems

        cout <<YELLOW <<"HALL"<<h->hall_id<<"-"<<msg << endl;
    }
};


class technicalstaff : public Employee {
public:
    technicalstaff(int employeeid, string employeename, string designation, float salary) :
        Employee(employeeid, employeename, designation, salary) {}

    void displaydetails()
    {
        cout << YELLOW<<"TECHNICAL STAFF DETAILS------" << endl;
        Employee::displaydetails(); // Call base class displaydetails
    }
};

class support_staff : public Employee {
public:
    support_staff(int employeeid, string employeename, string designation, float salary) :
        Employee(employeeid, employeename, designation, salary) {}

    void displaydetails()
    {
        cout << YELLOW<<"SUPPORT STAFF DETAILS---------" << endl;
        Employee::displaydetails(); // Call base class displaydetails
    }
};

class parking {
public:
    int totalslots;
    int slots_occupied;
    int aslots;
   Employee *e;

    parking(int n, int so,int av)
    {
        totalslots = n;
        slots_occupied = so;
        aslots=av;
    }

    void park()
    {
        // Code to park a vehicle
        cout << "Vehicle parked successfully!" << endl;
    }

    void pay()
     {
        // Code to pay parking fees
        cout << "Parking fees paid successfully!" << endl;
    }
};
class Ticket_c {
public:
    int ticketid;
    int ticketprice;
    Employee *e;

    Ticket_c(int id, int price)
     {
        ticketid = id;
        ticketprice = price;
    }

    void ShowTickets()
    {
        //cout << "Tickets available for " << mo->moviename << " in Hall " << ha->hall_id << ":" << endl;
        cout << "- Price per ticket: " << ticketprice << " INR" << endl;
        //cout << "- Available tickets: " << s->totalseats - s->no_of_bookedseats << endl;
    }
};



class customer {
public:
    int customerid;
    string customername;
    int customerage;

    parking *park;
    Ticket_c *tick;
    customer(string name)
     {
        //customerid = id;
        customername = name;
        //customerage = age;
    }

    void displaydetails()
    {
        cout << "Customer Name: " << customername << endl;
    }
};




class shops {
public:
    int shopid;
    int employeeid;
    string shopname;
    string itemlist[25];
    customer* cu;

    shops(int id, int eid, string name,customer *cu)
    {
        shopid = id;
        employeeid = eid;
        shopname = name;
        this->cu=cu;
    }

    void shopDetails() {
        cout << YELLOW<<"Shop Details:" << endl;
        cout << "Shop Name: " << shopname << endl;
        cout << "Employee ID: " << employeeid << endl;
        cout<<endl;
        cout<<"Name of the customer purchasing items: "<<cu->customername<<endl;
    }

    void itemDetails() {
        cout << BLUE<<"Items in Shop:" << endl;
        for (int i = 0; i < 5; i++) {
            cout  << itemlist[i] << endl;
        }
    }

    void buy() {
        // Code to buy items from the shop
        cout << "Item purchased successfully!" << endl;
    }
};

class Theatremanagement {
    private:
    static Theatremanagement* instance; // Private static member variable to hold the single instance
    Theatremanagement(string name, string city, int no_of_screens)
    {
        this->theatrename = name;
        this->city = city;
        this->no_of_screens = no_of_screens;
        // You can initialize other members here if needed.
    }
public:
    string theatrename;
    string city;
    int no_of_screens;
    string movielist[10];
    Hall *H;
    Operatorroom *OR;
    Ticket_c *Tc;
    parking *P;

     static Theatremanagement* getInstance(string name, string city, int no_of_screens) {
        if (!instance) {
            instance = new Theatremanagement(name, city, no_of_screens);
        }
        return instance;
    }


    void displaytheatre()
     {
        cout << MAGENTA<<"Theatrename: " <<theatrename<< endl;
        cout << MAGENTA<<"city: " <<city<< endl;
        cout<<MAGENTA<<"Number of screens: "<< no_of_screens << endl;
    }

    void displayMovies()
     {
        cout << YELLOW<<"MOVIE LIST:" << endl;
        for (int i = 0; i < no_of_screens; i++)
            {
            cout << MAGENTA<<"- " << movielist[i] << endl;
        }
    }
};
Theatremanagement* Theatremanagement::instance = nullptr;


int main() {

    Theatremanagement* T1 = Theatremanagement::getInstance("CINEPOLIS", "HUBLI", 3);
    T1->movielist[0] = "MOVIE1";
    T1->movielist[1] = "MOVIE2";
     T1->movielist[2] = "MOVIE3";
    Movie M1(111,"OPPENHIEMER","BIOLOGICAL THRILLER","3:15 hrs");
     Movie M2(121,"BARBIE","FANTASY COMEDY","2:30 hrs");
     Movie M3(131, "HOSTEL HUDUGARU BEKAGIDDARE", "COMEDY", "2:45 hrs");
     Ticket_c ticket1(101,350);
     Ticket_c ticket2(102,350); // Assuming the ticket price is 200 INR
     Ticket_c ticket3(103, 200);
      Hall h1(01, "Hall A", 1, "Regular", 100, 78);
      Hall h2(02, "Hall B", 2, "Regular", 100, 63);
      Hall h3(03, "Hall C", 3, "Regular", 100, 80);

      Seats s1(1,"REGULAR",100,78,22);
      Seats s2(2,"REGULAR",100,63,37);
      Seats s3(3, "REGULAR", 100, 80, 20);
      parking p1(50,35,15);
      parking p2(65,42,23);
      parking p3(60, 40, 20);
      Operatorroom o1("OPERATOR ROOM UNDER CONTROL",&h1);
      Operatorroom o2("OPERATOR ROOM UNDER CONTROL",&h2);
      Operatorroom o3("OPERATOR ROOM UNDER CONTROL",&h3);
      customer c1("SUSHMA");
      customer c2("APREMEYA");
      customer c3("PRASANNA");
       Hall h[3]={h1,h2,h3};
       T1->H=h;
       Operatorroom o[3]={o1,o2,o3};
       T1->OR=o;
       Ticket_c tick[3]={ticket1,ticket2,ticket3};
       T1->Tc=tick;
       parking p[3]={p1,p2,p3};
       T1->P=p;
    Employee *e[4];
    e[0]=new technicalstaff(301,"RISHI","TECHINAL HEAD",35000);
     e[1]=new technicalstaff(302,"VIKRAM","SOUND ENGINEER",30000);
    e[2]=new support_staff(502,"ARJUN","PARKING ATTENDANT",10000);
    e[3]=new support_staff(503,"SATISH","TICKET CHECKER",7500);
   cout<<endl;
   int choice,c;
   string code;
   while(1)
   {
       cout<<"-------------------------------------------------------"<<endl;
       cout<<YELLOW<<"--------WELCOME TO THEATRE MANAGEMENT SYSTEM----------"<<endl;
       cout<<"1.Customer"<<endl;
       cout<<"2.Employee"<<endl;
       cout<<"3.exit(0)"<<endl;
       cout<<RESET<<"Enter your choice:--"<<endl;
       cin>>choice;
       switch(choice){
   case 1:

       cout<<endl;
       T1->displaytheatre();
       cout<<endl;
       T1->displayMovies();
       cout<<endl;
        cout<<YELLOW<<"Select a movie: "<<endl;

        for(int i=0;i<T1->no_of_screens;i++)
        {
            cout<<MAGENTA<<i+1<<"."<<T1->movielist[i]<<endl;
        }

        cin>>c;
        if(c>=1 && c<=T1->no_of_screens)
        {
            cout<<YELLOW<<"You selected: "<<T1->movielist[c-1]<<endl;
        }
        switch(c)
        {
        case 1:
            cout<<endl;
            M1.displayMovieDetails();
             cout<<endl;

             ticket1.ShowTickets();
             h1.displaydetails();

              cout<<endl;

             s1.displayAvailableSeats();
              cout<<endl;
                 int numTickets;
             cout << RESET<<"Enter the number of tickets you want to book: "<<endl;

            cin >> numTickets;
            try {
                    if (c == 1 && numTickets > s1.availableseats)
                        {
                        throw TicketBookingException();
                       }
                    else {
                            s1.availableseats=s1.availableseats-numTickets;
                            p1.park();
                            cout<<endl;
                            p1.pay();
                            cout<<endl;
                        cout <<YELLOW<< "Ticket issued successfully! " << endl;
                        shops sh1(1,1,"SHOP1",&c1);
                      sh1.itemlist[0]="CANDY";
                            sh1.itemlist[1]="ICECREAM";
                           sh1.itemlist[2]="SODA/SOFT-DRINKS";
                             sh1.itemlist[3]="FRUIT JUICES";
                               sh1.itemlist[4]="BOTTLED WATER";
                           shops sh2(2,2,"SHOP2",&c1);
                          sh2.itemlist[0]="HOT DOGS";
                           sh2.itemlist[1]="NAHCOS";
                          sh2.itemlist[2]="SAMOSAS";
                          sh2.itemlist[3]="PIZZA SLICES";
                          sh2.itemlist[4]="FRIES";
                          shops sh3(3,3,"SHOP3",&c1);
                          sh3.itemlist[0]="POPCORN";
                          sh3.itemlist[1]="LAYZ";
                          sh3.itemlist[2]="CHOCOLATES";
                          sh3.itemlist[3]="PUFFS";
                          sh3.itemlist[4]="CAKES";
                        cout<<YELLOW<<"----SNACK----"<<endl;
                        sh1.shopDetails();
                        sh1.itemDetails();
                        cout<<endl;

                        sh2.shopDetails();
                        sh2.itemDetails();
                        cout<<endl;

                        sh3.shopDetails();
                        sh3.itemDetails();
                        int numitems;
                        int selectitem;
                        cout<<RESET<<"Enter the number of food items you want to buy: "<<endl;
                        cin>>numitems;
                        if(numitems<=0)
                        {
                            cout<<YELLOW<<"OKAY!!! ENJOY THE MOVIE---"<<endl;
                        }
                        else
                        {
                           for (int i = 0; i < numitems; i++) {
                                        cout << RESET<<"Select the item by entering the corresponding number(s):" << endl;
                                        cin >> selectitem;
                                        if (selectitem >= 1 && selectitem <= 15) {
                                            sh1.buy();
                                        } else {
                                            cout << YELLOW<<"SORRY! INVALID CHOICE" << endl;
                                            cout << YELLOW<<"THANK YOU!" << endl << endl;
                                        }
                                    }
                                    cout << YELLOW<<"ENJOY THE MOVIE!!!" << endl << endl;
                        }

                    }
                } catch (TicketBookingException& e) {
                    cout << RED<<e.what() << endl;
                }
            break;
        case 2:
            M2.displayMovieDetails();
             cout<<endl;

             ticket2.ShowTickets();
             h2.displaydetails();
             cout<<endl;

             s2.displayAvailableSeats();
              cout<<endl;
                 int numtickets;
            cout << RESET<<"Enter the number of tickets you want to book: "<<endl;

            cin >> numtickets;
            try {
                    if (c == 2 && numtickets > s2.availableseats)
                        {
                        throw TicketBookingException();
                        }
                    else {
                            s2.availableseats=s2.availableseats-numtickets;
                            p2.park();
                            cout<<endl;
                            p2.pay();
                            cout<<endl;
                        cout << YELLOW<<"Ticket issued successfully! " << endl;
                        shops sh1(1,1,"SHOP1",&c2);
                          sh1.itemlist[0]="CANDY";
                          sh1.itemlist[1]="ICECREAM";
                          sh1.itemlist[2]="SODA/SOFT-DRINKS";
                          sh1.itemlist[3]="FRUIT JUICES";
                          sh1.itemlist[4]="BOTTLED WATER";
                          shops sh2(2,2,"SHOP2",&c2);
                          sh2.itemlist[0]="HOT DOGS";
                          sh2.itemlist[1]="NAHCOS";
                          sh2.itemlist[2]="SAMOSAS";
                          sh2.itemlist[3]="PIZZA SLICES";
                          sh2.itemlist[4]="FRIES";
                          shops sh3(3,3,"SHOP3",&c2);
                          sh3.itemlist[0]="POPCORN";
                          sh3.itemlist[1]="LAYZ";
                          sh3.itemlist[2]="CHOCOLATES";
                          sh3.itemlist[3]="PUFFS";
                          sh3.itemlist[4]="CAKES";
                        cout<<YELLOW<<"----SNCAK----"<<endl;
                        sh1.shopDetails();
                        sh1.itemDetails();
                        cout<<endl;

                        sh2.shopDetails();
                        sh2.itemDetails();
                        cout<<endl;

                        sh3.shopDetails();
                        sh3.itemDetails();
                        int numitems;
                        int selectitem;
                        cout<<RESET<<"Enter the number of food items you want to buy: "<<endl;
                        cin>>numitems;
                        if(numitems<=0)
                        {
                            cout<<YELLOW<<"OKAY!!! ENJOY THE MOVIE---"<<endl;
                        }
                        else
                        {
                           for (int i = 0; i < numitems; i++) {
                                        cout <<RESET <<"Select the item by entering the corresponding number(s):" << endl;
                                        cin >> selectitem;
                                        if (selectitem >= 1 && selectitem <= 15) {
                                            sh1.buy();
                                        } else {
                                            cout <<YELLOW<< "SORRY! INVALID CHOICE" << endl;
                                            cout << YELLOW<<"THANK YOU!" << endl << endl;
                                        }
                                    }
                                    cout << YELLOW<<"ENJOY THE MOVIE!!!" << endl << endl;
                        }

                    }
                }
                 catch (TicketBookingException& e)
                 {
                    cout << RED<<e.what() << endl;
                }

            break;
        case 3:
                                    cout << endl;
                        M3.displayMovieDetails();
                        cout << endl;
                        ticket3.ShowTickets();
                        h3.displaydetails();
                        cout << endl;
                        s3.displayAvailableSeats();
                        cout << endl;
                        int NumTickets;
                        cout <<RESET<<"Enter the number of tickets you want to book: " << endl;
                        cin >> NumTickets;
                        try {
                            if (c == 3 && NumTickets > s3.availableseats) {
                                throw TicketBookingException();
                            } else {
                                s3.availableseats = s3.availableseats - NumTickets;
                                p3.park();
                                cout << endl;
                                p3.pay();
                                cout << endl;
                                cout <<YELLOW <<"Ticket issued successfully! " << endl;
                                shops sh1(1,1,"SHOP1",&c3);
                                  sh1.itemlist[0]="CANDY";
                                  sh1.itemlist[1]="ICECREAM";
                                  sh1.itemlist[2]="SODA/SOFT-DRINKS";
                                  sh1.itemlist[3]="FRUIT JUICES";
                                  sh1.itemlist[4]="BOTTLED WATER";
                                  shops sh2(2,2,"SHOP2",&c3);
                                  sh2.itemlist[0]="HOT DOGS";
                                  sh2.itemlist[1]="NAHCOS";
                                  sh2.itemlist[2]="SAMOSAS";
                                  sh2.itemlist[3]="PIZZA SLICES";
                                  sh2.itemlist[4]="FRIES";
                                  shops sh3(3,3,"SHOP3",&c3);
                                  sh3.itemlist[0]="POPCORN";
                                  sh3.itemlist[1]="LAYZ";
                                  sh3.itemlist[2]="CHOCOLATES";
                                  sh3.itemlist[3]="PUFFS";
                                  sh3.itemlist[4]="CAKES";
                                cout << YELLOW<<"----SNACK----" << endl;
                                sh1.shopDetails();
                                sh1.itemDetails();
                                cout << endl;
                                sh2.shopDetails();
                                sh2.itemDetails();
                                cout << endl;
                                sh3.shopDetails();
                                sh3.itemDetails();
                                int numitems;
                                int selectitem;
                                cout <<RESET <<"Enter the number of food items you want to buy: " << endl;
                                cin >> numitems;
                                if (numitems <= 0) {
                                    cout << YELLOW<<"OKAY!!! ENJOY THE MOVIE---" << endl;
                                } else {

                                    for (int i = 0; i < numitems; i++) {
                                        cout << "Select the item by entering the corresponding number(s):" << endl;
                                        cin >> selectitem;
                                        if (selectitem >= 1 && selectitem <= 15) {
                                            sh1.buy();
                                        } else {
                                            cout << YELLOW<<"SORRY! INVALID CHOICE" << endl;
                                            cout << YELLOW<<"THANK YOU!" << endl << endl;
                                        }
                                    }
                                    cout << YELLOW<<"ENJOY THE MOVIE!!!" << endl << endl;
                                }
                            }
                        } catch (TicketBookingException& e) {
                            cout <<RED<< e.what() << endl;
                        }
            break;
        case 4:
            cout<<RED<<"Invalid choice"<<endl;
            exit(0);
        }

    break;
   case 2:cout<<RESET<<"Enter the code:--"<<endl;
          cin>>code;
         try{ if(code=="ts0121")
          {
              cout<<endl;
              e[0]->displaydetails();
              cout<<endl;
              e[1]->displaydetails();
              cout<<endl;
              o1.control();
              o2.control();
              o3.control();
          }
          else if(code=="ss012131")
          {
              cout<<endl;
              e[2]->displaydetails();
              cout<<endl;
              e[3]->displaydetails();
              cout<<endl;
               o1.control();
              o2.control();
              o3.control();
          }
          else
          {
              throw "INVALID CODE";
          }
         }
         catch(const char *e)
         {
             cout<<RED<<"ERROR: "<<e<<endl;
         }

    break;
   case 3:
     exit(0);
     break;
   default:
    cout<<RED<<"INVALID CHOICE"<<endl;
    break;

    }
   }

    return 0;
}


