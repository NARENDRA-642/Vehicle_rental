#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#include<iomanip>
using namespace std;
int age, hours;
void bookmyvehicle(void);

class Account
{
                    public:
                    char name[20],phno[10],gender,bankaccno[30];
                    string password,p2,dlno;
                    int flag=1;
                    void create()
                    {
                                        system("CLS");
                                        cout<<"Enter your details below :-"<<endl;
                                        cout<<"\nEnter your Name : "<<endl;
                                        cin>>name;
                                        cout<<"\nEnter your Phone Number : "<<endl;
                                        cin>>phno;
                                        if(strlen(phno)!=10) 
                                        {cout<<"\nEnter your Phone Number (10 digits) : "<<endl;
                                        cin>>phno;
                                        }
                                        cout<<"\nEnter your Bank Account Number"<<endl;
                                        cin>>bankaccno;
                                        cout<<"\nEnter your Gender : "<<endl;
                                        cout<<"Enter F for FEMALE AND M for MALE"<<endl;
                                        cin>>gender;
                                        cout<<"\nEnter your age"<<endl;
                                        cin>>age;
                                        do
                                        {
                                                            cout<<"ENTER YOUR DL NUMBER IN THE FOLLOWING FORMAT FIRST TWO CHARACTERS SHOULD REPRESENT THE STATE PINCODE"<<endl;
                                                            cout<<"THE REST 13 CHARACTERS ARE THE DIGIT"<<endl;
                                                            cin>>dlno;
                                                            if(dlno.length()!=15)
                                                            {
                                                                                flag=0;continue;
                                                            }
                                                            else if(isdigit(dlno[0])&&isdigit(dlno[1]))
                                                            {
                                                                                flag =0;continue;
                                                            }
                                                            else
                                                            flag=1;
                                        } while (flag=0);
                                        flag=0;
                                        do
                                        {
                                                            system("CLS");
                                                            cout<<"USER NAME : "<<name<<endl;
                                                            cout<<"YOUR PASSWORD SHOULD CONTAIN ATLEAST ONE SPECIAL CHARACTER,ONE DIGIT,ONE UPPERCASE AND ONE LOWER CASE CHARACTER"<<endl;
                                                            cout<<"YOUR PASSWORD SHOULD ATLEAST CONTAIN 8 CHARACTERS"<<endl;
                                                            cout<<"ENTER THE PASSWORD"<<endl;
                                                            cin>>password;
                                                            bool upper=false,lower=false,digit=false,splchar=false;
                                                            if(password.length()<8)
                                                            continue;
                                                            for(int i=0;i<password.length();i++)
                                                            {
                                                                                if(islower(password[i]))
                                                                                lower=true;
                                                                                else if(isupper(password[i]))
                                                                                upper=true;
                                                                                else if(isdigit(password[i]))
                                                                                digit=true;
                                                                                else
                                                                                splchar=true;
                                                            }
                                                            if(upper&&lower&&digit&&splchar)
                                                                                flag = 0;
                                                            
                                        }while(flag==1);
                                        flag=1;
                                        cout<<"STRONG PASSWORD"<<endl;
                                        do
                                        {
                                                           cout<<"RE-ENTER YOUR PASSWORD FOR CONFIRMATION"<<endl;
                                                           cin>>p2;
                                                           if(password==p2)
                                                           {
                                                            cout<<"LOG-IN SUCCESSFUL"<<endl;
                                                            cout<<"\n\nACCOUNT CRETAED SUCCESSFULLY......!!!"<<endl;
                                                            cin.get();
                                                            flag=0;
                                                           }
                                        } while (flag==1);
                                        ofstream f1;
                                        f1.open("createacc.txt",ios::app);
                                        f1<<name<<" :"<<"\n";
                                        f1<<password<<"\n";
                                        f1 << phno << "\n";
                                        f1<<bankaccno<<"\n";
                                        f1 << dlno << "\n";
                                        f1<<gender<<"\n";
                                        f1<<age<<"\n";
                                        f1<<"\n\nACCOUNT CRETAED SUCCESSFULLY......!!!"<<"\n";
                                        f1.close();
                                        ofstream outFile("Credentials.txt", ios::app);
                                        outFile << name << " " << password <<"  "<<dlno<< endl;
                                        outFile.close();
                    }
                    void login()
                    {
                                        char choice, check=0;

                                        string enteredpassword,enteredname,dl;
                                        cout<<"-------------------------------------------------------------------"<<endl;
                                        cout<<"                  WELCOME TO THE VEHICLE RENTAL SYSTEM              "<<endl;
                                        cout<<"-------------------------------------------------------------------"<<endl;
                                 
                                        cout<<"\n\nEnter your Name : "<<endl;
                                        cin>>enteredname;
                                      
                                        cout<<"\nENTER PASSWORD"<<endl;
                                        cin >> enteredpassword;
                                        cout<<"ENTER YOUR DL NUMBER"<<endl;
                                        cin>>dl;
                                        
                                        ifstream inFile("Credentials.txt");
                                        string line;
                                        while(getline(inFile,line))
                                        {
                                                           size_t pos = line.find(" ");
                                                           string fileusername = line.substr(0, pos);
                                                           size_t pos2=line.find("  ");
                                                           string filePassword = line.substr(pos + 1,pos2);
                                                           string filedlno=line.substr(pos2+1);
                                                           if(fileusername==enteredname && filePassword==enteredpassword&&filedlno==dl)
                                                           {
                                                            inFile.close();
                                                           
                                                            check = 1;
                                                            
                                                           }
                                        }
                                      
                                        if(check==1)
                                        {
                                            cout << "LOG-IN SUCCESSFULL" << endl;
                                            cout << "\n\nTO BOOK A VEHICLE, ENTER y/Y :" << endl;
                                            cin >> choice;

                                            if (choice == 'y' || choice == 'Y')
                                            {
                                                                bookmyvehicle();
                                            }
                                        }
                                        inFile.close();
                    }
                    void forgot_password()
                    {
                                        int option;
                                        system("cls");
                                        cout<<"HAVE YOU FORGOTTEN YOUR PASSWORD???\n";
                                        cout<<"NO WORRIES WE GOT YOU COVERED\n";
                                        cout<<"ENTER 1 TO KNOW YOUR PASSWORD BY ENTERING THE USER ID\n";
                                        cout<<"ENTER 2 TO RETURN BACK TO MAIN SCREEN\n";
                                        cin >> option;
                                        switch(option)
                                        {
                                          case 1:
                                                            {
                                                                                int check=0;
                                                                                string fuserId,fpass,fid,fdl;
                                                                                cout<<"ENTER THE USER ID \n";
                                                                                cin>>fuserId;
                                                                                cout<<"ENTER YOUR DLNO"<<endl;
                                                                                cin>>fdl;
                                                                                ifstream ff("Credentials.txt");
                                                                                 while(getline(inFile,line))
                                                                                {
                                                                                                    size_t pos = line.find(" ");
                                                                                                    string fileusername = line.substr(0, pos);
                                                                                                    size_t pos2=line.find("  ");
                                                                                                    string filePassword = line.substr(pos + 1,pos2);
                                                                                                    string filedlno=line.substr(pos2+1);
                                                                                                    if(fileusername==fuserId &&fdl==filedlno)
                                                                                                    {
                                                                                                                        inFile.close();
                                                                                                    
                                                                                                                        check = 1;
                                                                                                                        
                                                                                                    }
                                                                                }
                                                                                if(check==1)
                                                                                {
                                                                                                    cout<<"RETERIVAL SUCCESFFUL"<<endl;
                                                                                                    cout<<"YOUR PASSWORD IS : "<<filedlno<<endl;
                                                                                }
                                                                                else
                                                                                {
                                                                                                    inFile.close();
                                                                                                    cout<<"EITHER USER ID OR DL NUMBER IS INCORRECT OR THE USER HAVENT REGISTERED YET"<<endl;
                                                                                }
                                                            }
                                                                               
                                                            
                                          case 2:
                                                            {
                                                                                //main();
                                                                                break;
                                                            }
                                                            default:
                                                            {
                                                                                cout<<"WRONG CHOICE\nPLEASE TRY AGAIN\n";
                                                                                forgot_password();
                                                            }
                                        }
                                        
                    }
};

int main()
{
                    int ch;
                    Account a;
                    bool b=true;
                    system("CLS");
                    cout<<"-------------------------------------------------------------------"<<endl;
                    cout<<"                  WELCOME TO THE VEHICLE RENTAL SYSTEM              "<<endl;
                    cout<<"-------------------------------------------------------------------"<<endl;
                    while(b)
                    {                   system("CLS");
                                        cout<<"-------------------------------------------------------------------"<<endl;
                                        cout<<"                  WELCOME TO THE VEHICLE RENTAL SYSTEM              "<<endl;
                                        cout<<"-------------------------------------------------------------------"<<endl;
                                        cout<<"\nDon't have an account??  Enter 1 to Create your account here"<<endl;
                                        cout<<"\nAlready have an account??  Login here to enjoy our services, Enter 2 to login "<<endl;
                                        cout<<"\nHappy Journey !! Press any key to EXIT  "<<endl;
                                        cin>>ch;
                                        if(ch==1)
                                                            a.create();
                                        else if(ch==2)
                                                            a.login();
                                        else 
                                                            b=false;
                                        
                    }

                    return 0;                   
}
void bookmyvehicle()

{
                    int total_cost = 0, tax = 100, cost = 0;
                    

                    if (age >= 18)
                    {
                                        int ch, fee;
                                        float change;
                                        int model;
                                        cout << "DO YOU WANNA BOOK A CAR OR A BIKE???\n IF YOU ARE LOOOKING FOR A CAR, ENTER 1 \n IF YOU ARE LOOKING FOR A BIKE, ENTER 2" << endl;
                                        cin >> ch;
                                        cout<<"\n\nWe offer Rental services on the basis of total number of hours.\n User has to pay fee for fixed number of hours\n If he/she takes the vehicle more than given time,\n he/she will be charged according for each hour........"
                                        if (ch == 1)
                                        {
                                                            cout << "\t\tWelcome to Our Car Rental Showroom, We have a list of cars available here at afforadable prices. Book it now";
                                                            cout << " \n\nEnter 1 for TOYOTA INNOVA CRYSTA - 7 SEATER - Rs.1500 for 8 hours" << endl;
                                                            cout << " Enter 2 for RENAULT DUSTER TURBO - 5 SEATER - Rs.1400 for 8 hours" << endl;
                                                            cout << " Enter 3 for TATA NEXON SUV OR EV - 5 SEATER - Rs.1200 for 8 hours" << endl;
                                                            cout << " Enter 4 for RENAULT DUSTER DACIA - 7 SEATER - Rs.1399 for 8 hours" << endl;
                                                            cout << " Enter 5 for HYUNDAI CRETA SUV    - 5 SEATER - Rs.1199 for 8 hours" << endl;
                                                            cin >> model;
                                                            if (model == 1)
                                                            {
                                                            system("CLS");

                                                            cout << "You have chosen TOYOTA INNOVA CRYSTA - 7 SEATER" << endl;
                                                            cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                                                cost = 150 * (hours - 8) + 1500;
                                                                              
                                                            }
                                                            else{
                                                                                cost = 1500;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 2)
                                        {
                                                            system("CLS");
                                                            cout << "You have chosen RENAULT DUSTER TURBO - 5 SEATER" << endl;
                                                           cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                                                cost = 150 * (hours - 8) + 1400;
                                                                              
                                                            }
                                                            else{
                                                                                cost = 1400;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 3)
                                        {
                                                            system("CLS");
                                                            cout << "You have chosen TATA NEXON SUV OR EV - 5 SEATER" << endl;
                                                            cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                                                cost = 150 * (hours - 8) + 1200;
                                                                              
                                                            }
                                                            else{
                                                                                cost = 1200;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 4)
                                        {
                                                            system("CLS");
                                                            cout << "You have chosen RENAULT DUSTER DACIA - 7 SEATER" << endl;
                                                            cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                                                cost = 150 * (hours - 8) + 1399;
                                                                              
                                                            }
                                                            else{
                                                                                cost = 1399;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 5)
                                        {
                                                            system("CLS");
                                                            cout << "You have chosen HYUNDAI CRETA SUV    - 5 SEATER" << endl;
                                                            cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                                                cost = 150 * (hours - 8) + 1199;
                                                                              
                                                            }
                                                            else{
                                                                                cost =1199;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else
                                        {
                                                            cout << "Entered Car Model is currently unavailable.We try to fix this issue soon. Please try again! Sorry for Convenience..." << endl;
                                        }
                                        cin.get();
                    }
                    else if (ch == 2)
                    {
                                        cout << "\t\tWelcome to Our Bike Rental Showroom, We have a list of scooters and motorbikes available here at afforadable prices. Book it now" << endl;
                                        cout << " \n\nEnter 1 for TVS APACHE RTR - Rs.1099 " << endl;
                                        cout << " Enter 2 for YAMAHA R15 V4  - Rs.1099 " << endl;
                                        cout << " Enter 3 for HONDA ACTIVA 6g- Rs.999  " << endl;
                                        cout << " Enter 4 for YAMAHA FASCINO - Rs.980  " << endl;
                                        cout << " Enter 5 for ROYAL ENFIELD  - Rs.1299 " << endl;
                                        cin >> model;
                                          if (model == 1)
                                        {
                                          system("CLS");

                                          cout << "You have chosen TVS APACHE RTR - Rs.1099  " << endl;
                                          cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                            cost = 150 * (hours - 8) + 1099;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 2)
                                        {
                                          system("CLS");
                                          cout << "You have chosen YAMAHA R15 V4  - Rs.1099" << endl;
                                          cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                            cost = 150 * (hours - 8) + 1099;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 3)
                                        {
                                          system("CLS");
                                          cout << "You have chosen HONDA ACTIVA 6g- Rs.999  " << endl;
                                          cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                            cost = 150 * (hours - 8) + 999;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 4)
                                        {
                                          system("CLS");
                                          cout << "You have chosen YAMAHA FASCINO - Rs.980" << endl;
                                         cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                            cost = 150 * (hours - 8) + 980;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else if (model == 5)
                                        {
                                          system("CLS");
                                          cout << "You have chosen ROYAL ENFIELD  - Rs.1299" << endl;
                                          cout << "\nEnter the total numbere of hours required : " << endl;
                                                            cin >> hours;
                                                            if(hours>8)
                                                            {
                                                            cost = 150 * (hours - 8) + 1199;
                                                            }
                                                            total_cost = cost + 100;
                                                            cout << "\n\n Thank you for using our services\n\nCharges : Rs."<<cost<<"/-\nCGST/SGST : Rs."<<tax<<"/-\nTotal Charges : Rs. "<<total_cost<<"/-" << endl;

                                                            cout << "\n\nEnter the fee here : ";
                                                            cin >> fee;
                                                            if(fee == total_cost)
                                                            cout << "\n\n--------PAYMENT SUCCESSFULL-------------    " << endl;
                                                            else
                                                            cout << "\nKindly pay the exact amount......" << endl;
                                                            cin.get();
                                        }
                                        else
                                        {
                                          cout << "Entered Bike Model is currently unavailable. We try to fix this issue soon. Please try again! Sorry for Convenience..." << endl;
                                        }
                                        cin.get();
                    }
        }    
  }
