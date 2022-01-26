#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;


void menu(); //main menu function prototype

class ManageMenu
{
private:
    string m_userName;

public:

    //virtual void menu(){}

    ManageMenu()
    {
        system("color 0A"); //change terminal color
        cout<<"=====================================\n"<<endl;
        cout << "Enter your name to continue as admin : ";
        cin >> m_userName;
        cout<<"\nBe patient";
        for(int i=0;i<4;i++){
            Sleep(1100);
            cout<<" .";
        }
        Sleep(1100);
        system("CLS");
        Sleep(1000);
        menu();
    }

    ~ManageMenu(){};
};

class Customers{
protected:
    string m_name,m_address;
    int m_mobileNo,m_CustomerId;
public:
        Customers():m_name("noName"),m_address("noAddress"),m_mobileNo(0),m_CustomerId(0){};

        void setDetails(){
        ofstream myFile("old_customers.txt",ios::app);

            cout<<"Enter Customer Id : "<<endl;
            cin>>m_CustomerId;
            cout<<"\nEnter Customer Name : "<<endl;
            cin>>m_name;
            cout<<"\nEnter Customer mobile number : "<<endl;
            cin>>m_mobileNo;
            cout<<"\nEnter Customer Address : "<<endl;
            cin>>m_address;


            myFile<<"\nCustomer id: "<<m_CustomerId<<endl;
            myFile<<"\nCustomer name: "<<m_name<<endl;
            myFile<<"\nCustomer address: "<<m_address<<endl;
            myFile<<"\nCustomer mobile number: "<<m_mobileNo<<endl;
            myFile<<"\n==================================\n";
            cout<<"\n--> Details Saved!\n";
            myFile.close();
        }

        void showDetails(){
            ifstream myFile("old_customers.txt");
            if(!myFile.is_open()){
                cout<<"\n--> Error!\n";
            }
            else {
                string lines;
                while(myFile.good()){
                getline(myFile,lines);
                cout<<lines<<endl;
        }
    }
}

}; // End of class Customers

class Cabs{
protected:
    int m_cabChoice,m_cabKiloMeters;
    double m_cabCost;
public:
    void cabDetails(){
    cout<<"============ WELCOME ============\n";
    cout<<"\n 1- Rent A standard cab - 0.5JD for 1KM.\n";
    cout<<"\n 2- Rent A luxary cab - 1.0JD for 1KM.\n";
    cout<<"\n To calculate the cost of your tour, Enter which kind of cab you need: \n";
    cin>>m_cabChoice;
    cout<<"/n Enter kilometers you have to travel: \n";
    cin>>m_cabKiloMeters;


    if(m_cabChoice==1) {
        m_cabCost=m_cabKiloMeters*.5;
        cout<<"\n your tour cost: "<<m_cabCost<<" JD for a standard cab with "<<m_cabKiloMeters<<" kilometers\n";
        cout<<"--> Press 1 to hire this cap.\n";
        cout<<"--> Press 2 to hire another cab.\n";
        cin>>m_cabChoice;

        system("CLS");

        if(m_cabChoice==1){
            cout<<"\n --> you have successfully hired a standard cab\n";
            cout<<"Go to menu and take receipt. \n";
            menu();
        }
        else if(m_cabChoice==2){
            cabDetails();
            menu();
        }
        else {
            cout<<"Invalid input! Redirecting to previous menu.\n";
            Sleep(1100);
            system("CLS");
            cabDetails();
        }
    }
    else if(m_cabChoice==2){
         m_cabCost=m_cabKiloMeters*1.0;
        cout<<"\n your tour cost: "<<m_cabCost<<" JD for a luxary cab with "<<m_cabKiloMeters<<" kilometers\n";
        cout<<"--> Press 1 to hire this cap.\n";
        cout<<"--> Press 2 to hire another cab.\n";
        cin>>m_cabChoice;

        system("CLS");

        if(m_cabChoice==1){
            cout<<"\n --> you have successfully hired a luxary cab\n";
            cout<<"Go to menu and take receipt. \n";
            menu();
        }
        else if(m_cabChoice==2){
            cabDetails();
        }
        else {
            cout<<"Invalid input! Redirecting to main menu.\n";
            Sleep(1100);
            system("CLS");
            cabDetails();
            menu();
        }
        int backMenu;
        cout<<"\nPress any key to redirect to main menu: \n";
        cin>>backMenu;
        system("CLS");
        if(backMenu){
            menu();
        }
    }
}
}; // End of class Cabs

class Booking {
protected:
    int m_choiceHotel,m_hotelPackage;
    double m_hotelCost;

public:

        void Hotels(){
        string hotels[] = {"Hilton", "Geneva", "kempiniski"};
        for(int i = 0; i < 3; i++)
        {
            cout << (i+1)<<"- " << hotels[i]<<" Hotel.\n" << endl;
        }


        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> m_choiceHotel;

        system("CLS");

        if(m_choiceHotel == 1){
                        cout << "===== WELCOME TO Hilton Hotel =====\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant\n";

            cout << "Packages Offered by ChoiceYou:\n\n" << endl;

            cout << "1- Family Package: 80JD for a day.\n";
            cout << "2- Couple Package: 50JD for a day\n" << endl;
            cout << "3- Single Package: 40JD for a day\n" << endl;

            cout << "\n\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> m_hotelPackage;

            if (m_hotelPackage == 1){
                    int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Family Pack at Hilton" << endl;
                cout << "Go to Menu and take the receipt" << endl;
                menu();
            }
            else if (m_hotelPackage == 2){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Couple Pack at Hilton" << endl;
                cout << "Goto Menu and take the receipt" << endl;
                menu();
            }
            else if (m_hotelPackage == 3){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Single Pack at Hilton" << endl;
                cout << "Goto Menu and take the receipt" << endl;
                menu();
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                Hotels();
            }

            int goToMenu;
            cout << "\nPress any key to redirect main menu: ";
            cin >> goToMenu;
            system("CLS");
            if(goToMenu){
                menu();
            }
            else{
                menu();
            }

        }
        else if(m_choiceHotel == 2){
            cout << "===== WELCOME TO Geneva Hotel =====\n" << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant\n";

            cout << "\nPackages Offered by Geneva:\n" << endl;

            cout << "\n1- Family Package: 80JD for a day.\n";
            cout << "\n2- Couple Package: 50JD for a day\n" << endl;
            cout << "\n3- Single Package: 40JD for a day\n" << endl;

            cout << "\n\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> m_hotelPackage;

            if (m_hotelPackage == 1){
                    int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Family Pack at Geneva.\n" << endl;
                cout << "Go to Menu and take the receipt.\n" << endl;
                menu();
            }
            else if (m_hotelPackage == 2){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Couple Pack at Geneva.\n" << endl;
                cout << "Goto Menu and take the receipt.\n" << endl;
                menu();
            }
            else if (m_hotelPackage == 3){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Single Pack at Geneva.\n" << endl;
                cout << "Go to Menu and take the receipt.\n" << endl;
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                Hotels();
            }

            int goToMenu;
            cout << "\nPress an key to redirect main menu: ";
            cin >> goToMenu;
            system("CLS");
            if(goToMenu){
                menu();
            }
            else {
                menu();
            }

        }
               else if(m_choiceHotel == 3){
            cout << "===== WELCOME TO kimpiniski Hotel =====\n" << endl;

            cout << "\nSwimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant\n";

            cout << "\nPackages Offered by ChoiceYou:\n" << endl;

            cout << "\n 1- Family Package: 80JD for a day.\n";
            cout << "\n 2- Couple Package: 50JD for a day\n" << endl;
            cout << "\n 3- Single Package: 40JD for a day\n" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> m_hotelPackage;

            if (m_hotelPackage == 1){
                    int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Family Pack at kimpiniski.\n" << endl;
                cout << "Goto Menu and take the receipt." << endl;
                menu();
            }
            else if (m_hotelPackage == 2){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Couple Pack at kimpiniski.\n" << endl;
                cout << "Go to Menu and take the receipt." << endl;
                menu();
            }
            else if (m_hotelPackage == 3){
                int howManyDays;
                cout<<"Enter number of days: ";
                cin>>howManyDays;
                m_hotelCost = 80*howManyDays;
                cout << "You have successfully booked Single Pack at kimpiniski.\n" << endl;
                cout << "Goto Menu and take the receipt." << endl;
                menu();
            }
            else{
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                Hotels();

            }

            int goToMenu;
            cout << "\nPress an key to redirect main menu: ";
            cin >> goToMenu;
            system("CLS");
            if(goToMenu){
                menu();
            }
            else {
                menu();
            }
    } // End of hotel function

        }
}; // End of class Booking



class Charges : public Booking, Cabs, Customers {
private:
public:
    void printBill()
    {
        ofstream myFile("receipt.txt");
        {
             myFile<< "====== Travel Agency ======" << endl;
             myFile<< "======    Receipt    ======" << endl;
             myFile<< "_________________________________" << endl;
             myFile << "Customer ID: " << Customers::m_CustomerId <<endl;
             myFile<< "Description\t\t Total" << endl;
             myFile<< "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::m_hotelCost<< endl;
             myFile << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::m_cabCost << endl;
             myFile << "_________________________________" << endl;
             myFile << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::m_hotelCost+Cabs::m_cabCost<< endl;
             myFile<< "_________________________________" << endl;
             myFile << "========== THANK YOU ==========" << endl;
        }
        myFile.close();

    }

    void showBill()
    {
        ifstream myFile("receipt.txt");
        {
            if(!myFile.is_open())
            {
                cout << "\nError!\n" << endl;
            }
            while(myFile.good())
            {
                string lines;
                getline(myFile, lines);
                cout << lines << endl;
            }
        }
        myFile.close();
    }
}; // End of class Booking

// main menu start

void menu() //menu function contain main menu
{
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "============== Main Menu ==============\n" << endl;
    cout << "1- Customer management.\n" << endl;
    cout << "2- Cabs management.\n" << endl;
    cout << "3- Bookings management.\n" << endl;
    cout << "4- Charges & bill.\n" << endl;
    cout << "5- Exit.\n" << endl;
    cout << "\nPick A choice: ";
    cin >> mainChoice;
    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1){
        cout << "======== Customers ========\n" << endl;
        cout << "1- Enter new customer"<< endl;
        cout << "2- Show old customers"<< endl;

        cout << "\nPick A choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.setDetails();
        }
    else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if(gotoMenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }

    else if(mainChoice == 3){
        cout << "--> Book a Luxury Hotel using the System <--\n" << endl;
        a4.Hotels();
    }

    else if(mainChoice == 4){
        cout << "-->Get your receipt<--\n" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display the your receipt in the screen\n Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if(gotoMenu == 1){
            system("CLS");
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if(gotoMenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout << "\nGOOD BYE!" << endl;
        Sleep(1100);
        system("CLS");
        ManageMenu();
    }
    else{
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

// main menu end

int main()
{
    ManageMenu startObj;
    return 0;
}

