#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include<mmsystem.h>
using namespace std;
              /* definition of fun */
/************ function of GUI *********/
void loading();
void music();
void  Beganining();
void Bye();
void undefined_name_Hotel();
void gotoxy( int column, int line );
void invalid_name_City();
void invalid_name_Hotel();
void name_hotel_infile();
void Enter_city_name(string &name);
void Enter_Hotel_name(string &name,int x,int y);
void Enter_Hotel_price(long double &price,int x,int y);
void Out_Hotel();
void Manue_Hotel(int &Process_Hotel);
void Out_city();
void Manue_City(int &Process_City);
void OUT_MangerProcess();
void Manue_toMangerProcess(int &choice);
void OUT_membership();
void Manue_mebership (int &membership);
void  validEmail();
void  Erorr();
//void Enter_Hotel_name_price(string &name,long double &price,int x,int y);
/********* end fun  of GUI ********/
void  disp_to_manger() ;  // display the choices to manage
void  disp_choices_city_to_manager();  //display choices to  manager in city.
void  disp_choices_hotel_to_manager();  // hotel list open choices
void  startprogram();
void  take_hotel_data(vector<string>&hotelname,vector<long long>& cityid_hotel,vector<long double>&  price_per_night,vector<long long>& hotelid,long long& idof_city,long long & idof_hotel); // take data from manager about hotel and check about id user  in put
bool  check_id_city(long long  &id) ; //check if id  in  file or not
bool  check_name_hotel(string& name);  // when he  enter the name of hotel check if  it in  file or not
void edit_hotel_p_p_N(string name);
void display_city_inf(); // display all city information when add hotel
bool check();
void edit_hotel_p_p_N(string name,long double  P_N);
/**** booking ***/
void out_Booking();
void Manue_Booking(int &Process_Booking_process);
 void Enter_Id_booking(string &name);

void  disp_hotel_booking();  // display all hotel to choose which hotel will add booking
void  addbooking(); // to add booking request
void list_booking_request();
 void Enter_rooms_numofN();
void delete_booking();
void disp_choices_booking();
void disp_hotel_tobook();
string name_of_hotel(long long id); // take the id of hotel and return  name  hotel
//-------------------------------------------------------------------------------------------------------//

            /* end the definition of function */

class manager   //  email and password from manager to check it
{
public:
    string mail;
	string pass;
	vector<string> email;
	vector<string>    password;

	/* to take data from the file and put it in  vector*/
        void   manage_inf_file()
        {
             fstream outfile;
             outfile.open("account.txt");
             if(outfile.is_open())
             {
                while(!outfile.eof())
                    {
                    outfile >> mail >> pass;
                    email.push_back(mail);
                    password.push_back(pass);
                    }
             }
             else
            {
             cout<<"error can't take data from file try again "<<endl;
            }
            outfile.close();
        }
	/* end of take data from file */

	/*take email and password from manager */
    bool  take_manager_data()  // check if the manger enter valid email and pass
    {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
cout<<"\t\t *"<<"**********************************************"<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<" <1> Mail :                                   "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<" <2> Password :                               "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl<<"\t\t *";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"           Hotels Booking System              ";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"*"<<endl<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"**********************************************"<<"*"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		
gotoxy(30,7);
cin>>mail;
	Beep(500,500);
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
gotoxy(35,10);
cin>>pass;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
		 cout<<endl<<endl<<endl<<endl;
            for(long long  i=0;i<email.size();i++)
            {
                if(mail==email[i]&&pass==password[i])
                    return true;
            }
            return false;
    }

 /*the  end of  take data */
};
                     /********** end class manager ***********/
                     /*********** class city *********/
class city
{
public:
      long long  id_counter,h;   // id_counter have the last id of city
      string name;
      vector<string> cityname;    // to put all city name in this vector
      vector<long long > idcity;          // to put all city id in this vector
      vector<long long >no_hotel;         // to put all no-hotel  in this vector
      /*   to take city information from file */
void take_city_inf()  // take data from file
{
        fstream  outfile;
       outfile.open("city.txt");
      if(outfile.is_open())
        {
          while(!outfile.eof())
            {
               if(outfile.eof())
                break;
               outfile>> id_counter >> name >> h;
               idcity.push_back(id_counter);
               cityname.push_back(name);
               no_hotel.push_back(h);

           }
             idcity.erase(idcity.begin()+idcity.size()-1);
             cityname.erase(cityname.begin()+cityname.size()-1);
             no_hotel.erase(no_hotel.begin()+no_hotel.size()-1);

        }
        else
            cout<<"can't take data from city file "<<endl;
     outfile.close();

}
    /* end of  take information from file */
void    addcity()        // to add city
{
	system("cls");
       
        long long   valid=0;
		gotoxy(6,2);
		Enter_city_name(name);
          for(long long i=0;i<cityname.size();i++)  // check if city name in  file or not
            {
              if(name==cityname[i])
                  {
                   valid++;
                   break ;
                  }
            }
            if(valid==0)  //
                {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);  //edit 
                    cout<<"\n\n\t\t are you sure to add this city (y/n)";

                          if(check())  // check if  he want to add this city
                          {
                                 cityname.push_back(name); // put  name in vector
                                 id_counter++;                   // to increment  id  of  city
                                 idcity.push_back(id_counter);
                                 no_hotel.push_back(0);
								system("cls");
								cout<<endl<<endl<<endl;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"       **********************************************************************"<<endl;
	cout<<"       *                                                                    *"<<endl;
	cout<<"       *                                                                    *"<<endl;
	cout<<"       *                                                                    *"<<endl;
	cout<<"       **********************************************************************"<<endl;
	                        gotoxy(6,4);
                                 cout<<" * id : ";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
								 cout<<id_counter ;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	                        gotoxy(6,5);
								 cout<<" * name : ";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
								 cout<<name;
	                        gotoxy(6,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
							cout<<" *";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                            cout<<"\t\t\tNew city has been added";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                          }
                          else
                            disp_choices_city_to_manager();

                }
                else
                {
                  invalid_name_City();
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                }
			cout<<endl<<endl<<endl;
         cout<<"\n are you want to add city again (y/n) :";
         if(check())
             addcity();
         else
         {
             disp_choices_city_to_manager();
         }

    }
void display_all_ids() // display all id  to show information about id
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	  cout<<"\t****************************************************************"<<endl;
         for(long long  i=0;i<idcity.size();i++)
         {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
             cout<<"\t* city "<<i+1<<" : ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				 cout<<cityname[i]<<endl; // 3lashan y3red el modon  we howa y5tae elmdena ely y3rf 3nha el inf
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				
		 }
		 
         for(long long  i=0;i<idcity.size()+1;i++)
		 {
		  gotoxy(71,i);
			 cout<<"*";
		 }
		 cout<<endl;
		 
	 cout<<"\t****************************************************************"<<endl;

 }
void search_city()
{
    display_all_ids(); // to show all id's of city
         long long choice;
         long long  valid=0;
		  cout<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
         cout <<"please enter number  of city to see all information about it \n";
         cout<<" Number : " ;
         cin>>choice;
         choice--; // to control by index
		 system("cls");
         for(long long  i=0;i<cityname.size();i++)
            {
              if(i==choice)
                 {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	 cout<<"\t****************************************************************"<<endl;
	 cout<<"\t*";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout<< " Number:"<<idcity[i]<<",  city name : "<<cityname[i] << ",   number of hotel  : " << no_hotel[i];
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				gotoxy(71,1);
				cout<<"*"<<endl ;
	 cout<<"\t****************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                 valid++;
                 }
            }
            if(valid==0)
                {
                    /**** we can display all city here *******/
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	 cout<<"\t****************************************************************"<<endl<<"\t*";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
     cout<<"                 you enter invalid  id                        ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	 cout<<"*"<<endl<<"\t****************************************************************"<<endl;
                 }
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
              cout<<"\n are you want to search again (y/n) :";
         if(check())
		 {
			 system("cls");
             search_city();
		 }
         else
          {
                disp_choices_city_to_manager();
          }

    }
void save_into_file_city()    // when exit
 {
       fstream  inputfile;
       inputfile.open("city.txt");
       if(inputfile.is_open())
       {
           //inputfile << "id\t\tname\t\tno-hotel\n";
           for(long long  i=0;i<cityname.size();i++)
           {
               inputfile <<idcity[i]<<"\t\t" << cityname[i]<<"\t\t"<< no_hotel[i]<<endl;
           }
       }
       inputfile.close();

   }

};
                    /************ end class of  city *************/
class hotel
{
public:
    vector<string> hotelname;
    string name ;
    vector<long long>  cityid_hotel; // id  of  city
    long long idof_city;
    vector<long double>  price_per_night;
    long double P_P_N;  // price per night
    vector<long long>  hotelid;
    long long  idof_hotel; // constant can't change take the  last id of hotel
void take_hotel_inf()      // open file and take data from file hotel
{
        fstream outfile;
        outfile.open("hotel.txt");
       if(outfile.is_open())
        {
          while(!outfile.eof())
           {
              outfile >> idof_hotel >> name >> P_P_N >> idof_city;
              hotelname.push_back(name);
              cityid_hotel.push_back(idof_city);
              hotelid.push_back(idof_hotel);
              price_per_night.push_back(P_P_N);
           }
		        hotelname.erase(hotelname.begin()+hotelname.size()-1);
                cityid_hotel.erase(cityid_hotel.begin()+cityid_hotel.size()-1);
                hotelid.erase(hotelid.begin()+hotelid.size()-1);
              price_per_night.erase(price_per_night.begin()+price_per_night.size()-1);
           
        }
        outfile.close();

    }
void addhotel()
{
	system("cls");
      display_city_inf();
      cout<<" enter number   of city you will add hotel in it\ncity number : ";
      cin>>idof_city;  // id of city will use to add any thing in vectors
      take_hotel_data(hotelname,cityid_hotel,price_per_night,hotelid,idof_city,idof_hotel);  // got to this function to check data and put data

 }
void displayinhotel()  // display data in hotel file
{
	cout<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"***************************************************************************"<<endl;
       cout<<"* id of hotel      "<< " name of hotel     " << "price per night     " << "    id of city"<<endl;
       for(long long  i=0;i<hotelname.size();i++)
	   {
         cout<<"* "<<hotelid[i]<<"   \t\t"<<hotelname[i]<<"    \t      "<<price_per_night[i]<<" \t \t "<< cityid_hotel[i]<<endl;
}
	cout<<"**************************************************************************"<<endl;
       for(long long  i=0;i<hotelname.size()+2;i++)
	   {
	gotoxy(74,i+3);
		 cout<<"*";
}
	   cout<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //to remove press any key to continue
}
void edit_hotel() // search about hotel to edit in price per  night
{
    string name;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    long double newprice;
    char  check;
	Enter_Hotel_name(name,30+hotelname.size(),10+hotelname.size());
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    for(long long  i=0;i<hotelid.size();i++)
    {
        if(name==hotelname[i])
         {
			 system("cls");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"***************************************************************************"<<endl;
            cout<< "*\tname of hotel :" <<hotelname[i]<< "    old price per night :" <<price_per_night[i]<<endl;
			gotoxy(74,1);
			cout<<"*"<<endl;
            cout<<"***************************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout<<"continue edit in this hotel (y/n)  : ";
             cin>>check;
             if(check=='y'||check=='Y')
             {
				 Enter_Hotel_price(newprice,40,9);
                 price_per_night[i]=newprice;
				 disp_choices_hotel_to_manager();
				 break ; 
             }
             else
             {
                 disp_choices_hotel_to_manager();
				  break ; 
             }


          }	
		
    }
             undefined_name_Hotel();
			system("pause");
			disp_choices_hotel_to_manager();
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void save_into_file_hotel()    // when exit
 {
       fstream  inputfile;
       inputfile.open("hotel.txt");
       if(inputfile.is_open())
       {
           //inputfile << "id\t\tname\t\tno-hotel\n";
           for(long long  i=0;i<hotelid.size();i++)
           {
               inputfile <<hotelid[i] <<"\t\t" << hotelname[i]<<"\t\t"<< price_per_night[i]<<"\t\t"<<cityid_hotel[i]<<endl;
           }
       }
       inputfile.close();

   }
};

class booking
{
public:
    vector<long long > id_booking;
    long long book;
    vector<string> hotelname_booking;
    string name;
    vector<long double> request_cost;
    long double cost;
    vector<long long > no_room;
    long long room;
    vector<long long > no_night;
    long long night ;
void take_booking_inf()      // open file and take data from file hotel
{
        fstream outfile;
        outfile.open("booking.txt");
       if(outfile.is_open())
        {
          while(!outfile.eof())
           {
              outfile >> book >> name >> cost >> room >> night ;
              id_booking.push_back(book);
              hotelname_booking.push_back(name);
              request_cost.push_back(cost);
              no_room.push_back(room);
              no_night.push_back(night);
           }
		        hotelname_booking.erase(hotelname_booking.begin()+hotelname_booking.size()-1);
                no_night.erase(no_night.begin()+hotelname_booking.size()-1);
                no_room.erase(no_room.begin()+hotelname_booking.size()-1);
                request_cost.erase(request_cost.begin()+hotelname_booking.size()-1);
                id_booking.erase(id_booking.begin()+hotelname_booking.size()-1);
         
        }
    outfile.close();

}
void save_into_file_book()    // when exit
 {
       fstream  inputfile;
       inputfile.open("booking.txt");
       if(inputfile.is_open())
       {
           //inputfile << "id\t\tname\t\tno-hotel\n";
           for(long long  i=0;i<id_booking.size();i++)
           {
               inputfile << id_booking[i] <<"\t\t" << hotelname_booking[i]<<"\t\t"<< request_cost[i]<<"\t\t"<<no_room[i]<<"\t\t"<<no_night[i]<<endl;
           }
       }
       inputfile.close();

   }

};

