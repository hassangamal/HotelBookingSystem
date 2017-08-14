#include "def.h"
/* global object and variable */
    manager   manager_data;   // manager
    city      objcity;
    hotel     objhotel;
    booking   objbook;
    long long  choice;
/* end of global object and variable */
void music()
	{

		PlaySound("E:\\Project1\\Project1\\Midi Tone.wav", NULL, SND_LOOP | SND_ASYNC);

}
void loading()
{

	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<endl<<endl<<endl<<endl;;
cout<<"\t\t";
cout<<" #       ####    ##   #####  # #    #  ####  "<<endl;
cout<<"\t\t";
cout<<" #      #    #  #  #  #    # # ##   # #    # "<<endl;
cout<<"\t\t";
cout<<" #      #    # #    # #    # # # #  # #      "<<endl;
cout<<"\t\t";
cout<<" #      #    # ###### #    # # #  # # #  ### "<<endl;
cout<<"\t\t";
cout<<" #      #    # #    # #    # # #   ## #    # "<<endl;
cout<<"\t\t";
cout<<" ######  ####  #    # #####  # #    #  ####  "<<endl;
cout<<" ";
	for(int i=0;i<=40;i++)
	{
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout<<"==";
	Sleep(200);
}
	cout<<endl<<"\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"           Hotels Booking System                    ";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
	system("cls");
}
void startprogram()  /****** start to manager  or  client *********/
    {

        /**** take data from files ****/
        manager_data.manage_inf_file();   // take data from file account put it in manager vector
         objcity.take_city_inf();          // take  data  from file  city
         objhotel.take_hotel_inf();        // take data from file hotel
		/*** end of take data from files ***/

    		OUT_membership();
	int memberahip=1;
	Manue_mebership(memberahip);
	if(memberahip==1)
	{
		   long long  c=2;             // to try three times
            while(true)
             {
                    if(manager_data.take_manager_data())   // sign in go to process manager
                    {
                        /**** not take the data if he is client and speed the program ****/

                           disp_to_manger(); // display the choice /** city hotel exit ** /
                    }
                    else
                    {
                        if(c==0)
                        {
                            cout<<"\t\t\t the system can't open please try later.\n\n\n";  // if he enter three times false
                              return;
                        }
                        //Erorr();
                        validEmail();
                        c--;
						system("pause");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
						system("cls");
                    }
            }



    }


	else
	{
		objbook.take_booking_inf();
		disp_choices_booking();
	}
}
void  Bye()
{
    objbook.save_into_file_book();
    objcity.save_into_file_city();
    objhotel.save_into_file_hotel();
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"             Good bye team Hotels Booking System           ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
	 exit(0);
}
void invalid_name_City()/*when add city dipsaly massage can't add cit already exisit*/
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                City name already exists                   ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
}
void invalid_name_Hotel()/*when add city dipsaly massage can't add cit already exisit*/
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                Hotel name already exists                  ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
void undefined_name_Hotel()/*when search Hotel dipsaly massage can't search hotel Does not exist*/
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                Hotel name Does not Exist                  ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
void Enter_city_name(string &name)/*to enter city name in text when press add city */
{

	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" The Name of City is :                                     ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
	 gotoxy(37,7);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	 cin>>name;
}
void Enter_Hotel_name(string &name,int x,int y)/*to enter hotel name in text when press add hotel */
{

	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" The Name of Hotel is :                                    ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

	 gotoxy(x,y);
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	 cin>>name;
	 cout<<endl<<endl;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
void Enter_Hotel_price(long double &price,int x,int y)
{
		  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl;
	cout<<"           *   Price per night   :                                     *"<<endl;
	cout<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	 gotoxy(x,y);
	 cin>>price;
	 cout<<endl<<endl;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

}
void name_hotel_infile()
{
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                Hotel name already exists                  ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
void gotoxy( int column, int line )  // go to position
  {
	  COORD coord;
	  coord.X = column;
	  coord.Y = line;
	  SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
    );
  }
void Out_city() /*display chocies of cites */
{
	cout<<endl<<endl<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"          *"<<"*************************************************************"<<endl;
	cout<<"          *"<<"                                                            *"<<endl<<"          *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" <1> Add City                                               ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <2> Search City                                            *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <3> list all city                                          *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <4> Back to menu                                           *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<"*************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
system("pause");
}
void Manue_City(int &Process_City) /* manu to chose chosis of city*/
{

while(1){
	if(GetAsyncKeyState(VK_DOWN)&&Process_City==1)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_City++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_City==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 Process_City++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_City==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_City++;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_City==4)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_City--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_City==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_City--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_City==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<1> Add City"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search City"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all city"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_City--;

	}
		else if(GetAsyncKeyState(VK_F1))
{
	Beep(500,500);
	system("cls");
	break;
}

}
}
void OUT_MangerProcess() /* display_to_manger*/
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl;
	cout<<"            *"<<"*************************************************************"<<endl;
	cout<<"            *"<<"                    "<<"Choose your Operation"<<"                   "<<"*"<<endl;
	cout<<"            *"<<"                                                            "<<"*"<<endl<<"            *";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" <1> City                                                   ";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"            *"<<"                                                            "<<"*"<<endl;
	cout<<"            *"<<" <2> Hotel                                                  "<<"*"<<endl;
	cout<<"            *"<<"                                                            "<<"*"<<endl;
	cout<<"            *"<<" <3> Save and  Exit                                         "<<"*"<<endl;
	cout<<"            *"<<"                                                            "<<"*"<<endl;
	cout<<"            *"<<"                                                            "<<"*"<<endl;
	cout<<"            *"<<"                                                            "<<"*"<<endl<<"            *";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                     Hotels Booking System                  ";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);

	cout<<"*"<<endl<<"            *"<<"*************************************************************"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	system("Pause");


}
void Manue_toMangerProcess(int &Process) /* manue of display_tO_manger */
{
 while(1)
{
	if(GetAsyncKeyState(VK_DOWN)&&Process==0)
{
	Sleep(200);
gotoxy(14,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<1> City"<<endl;
gotoxy(13,8);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<" <2> Hotel"<<endl;
gotoxy(14,10);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> Save and  Exit"<<endl;
Process++;
}
	else if(GetAsyncKeyState(VK_DOWN)&&Process==1)
{
	Sleep(200);
gotoxy(14,6);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> City"<<endl;
gotoxy(13,8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<" <2> Hotel"<<endl;
gotoxy(14,10);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> Save and  Exit"<<endl;
Process++;

}
	else if(GetAsyncKeyState(VK_UP)&&Process==2)
{
	Sleep(200);
gotoxy(14,6);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<1> City"<<endl;
gotoxy(13,8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<" <2> Hotel"<<endl;
gotoxy(14,10);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> Save and  Exit"<<endl;
Process--;

}
	else if(GetAsyncKeyState(VK_UP)&&Process==3)
{
	Sleep(200);
gotoxy(14,6);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> City"<<endl;
gotoxy(13,8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<" <2> Hotel"<<endl;
gotoxy(14,10);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> Save and  Exit"<<endl;
Process--;

}
else if(GetAsyncKeyState(VK_DOWN)&&Process==2)
{
	Sleep(200);
gotoxy(14,6);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> City"<<endl;
gotoxy(13,8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<" <2> Hotel"<<endl;
gotoxy(14,10);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> Save and  Exit"<<endl;
Process++;

}
	else if(GetAsyncKeyState(VK_F1))
{
	Beep(500,500);
	system("cls");
	break;
}
}

}
void Out_Hotel()
{
	cout<<endl<<endl<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"          *"<<"*************************************************************"<<endl;
	cout<<"          *"<<"                                                            *"<<endl<<"          *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" <1> Add Hotel                                              ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <2> Search Hotel                                           *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <3> list all hotel                                         *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <4> Back to menu                                           *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<"*************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
system("pause");
}
void Manue_Hotel(int &Process_Hotel){

while(1){
	if(GetAsyncKeyState(VK_DOWN)&&Process_Hotel==1)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Hotel++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_Hotel==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 Process_Hotel++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_Hotel==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Hotel++;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Hotel==4)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Hotel--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Hotel==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Hotel--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Hotel==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<1> Add Hotel"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> Search Hotel"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> list all hotel"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Back to menu";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Hotel--;

	}
	else if(GetAsyncKeyState(VK_F1))
{
	Beep(500,500);
	system("cls");
	break;
}
}
}
void OUT_membership() /* display the meber of manger *** client */
{
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<endl<<endl<<endl<<endl;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"              *************************************************************"<<endl<<"              *";
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"               Choose your Membership                      ";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"*"<<endl<<"              *"<<"                                                           "<<"*"<<endl<<"              *";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"  <1> Manager                                              ";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"*"<<endl<<"              *"<<"  <2> Client                                               "<<"*"<<endl;
cout<<"              *"<<"                                                           "<<"*"<<endl;
cout<<"              *************************************************************"<<endl;
}
void Manue_mebership (int &membership) /*manue of manger and clinet */
{
	while(1)
{
	if(GetAsyncKeyState(VK_DOWN)&&membership==1)
{
	Sleep(200);
gotoxy(16,7);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<" <1> Manager"<<endl;
gotoxy(16,8);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<" <2> Client"<<endl;
membership--;
}
	else if(GetAsyncKeyState(VK_UP)&&membership==0)
{
	Sleep(200);
gotoxy(16,7);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<" <1> Manager"<<endl;
gotoxy(16,8);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<" <2> Client"<<endl;
membership++;

}
else if(GetAsyncKeyState(VK_F1))
{
	Beep(500,500);
	system("cls");
	break;
}
}
}
 void  disp_to_manger()    // display the choice to manager and take his choice to open city or hotel
{
        system("CLS");
        int  choice=1;
////************************************************************************************************************////
                               ///***************** second  list ******************///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   OUT_MangerProcess();
		Manue_toMangerProcess(choice);
       if(choice==1)
         disp_choices_city_to_manager();   // open city choices
       else if (choice==2)
          disp_choices_hotel_to_manager();  // open hotel choices
       else if (choice==3)
          {
             // fun exit
			   Bye();
          }

    }

void disp_choices_city_to_manager()  // open the class of  city to manager
{
        system("CLS");
   /*****  choices of city  *****/
     int choice=1;

      Out_city();
	  Manue_City(choice);
         if(choice==1)
               objcity.addcity(); // to add city
         else if (choice==2)
         {
               objcity.search_city();  // passing all city vector to function
         }
        else if (choice==3)
             display_city_inf();
         else if (choice==4)
               disp_to_manger();


         cout << "are  you want to choose again  (y/n) ? ";
         if (check())
          disp_choices_city_to_manager();   // repeat  same fun
         else
          {
              disp_to_manger();

          }

    }

    /******* this functions to hotel ******/
void disp_choices_hotel_to_manager()
{

        system("CLS");
        int  choice=1;
		Out_Hotel();
		Manue_Hotel(choice);
        if(choice==1)
            objhotel.addhotel();
        else if (choice==2)
        {
                objhotel.displayinhotel();
                objhotel.edit_hotel();
        }

        else if (choice==4)
            disp_to_manger();
        else if (choice==3)
        {
            objhotel.displayinhotel();   /**** tt3'yar ****/
        }
        else
           cout<<"\t\t!!!you enter invalid number try again";
           cout << "are  you want to choose in hotel list  again  (y/n) ? ";
        if (check())
          disp_choices_hotel_to_manager();
        else
        {
            disp_to_manger() ;

        }



 }

void  take_hotel_data(vector<string>&hotelname,vector<long long>& cityid_hotel,vector<long double>&  price_per_night,vector<long long>& hotelid,long long  &idof_city,long long  &idof_hotel) // put data into vector
{
    /***** m3ak kol m3lomat el vectors we a5er id fe el hotel******/
       system("CLS");
     // idof_city  is entered by user
    if(check_id_city(idof_city))   // if  city id  is valid in file  open
     {
         while(true)
            {
                                string name;
                                long double P_N=0;
								 Enter_Hotel_name(name,37,5);
                                 if (check_name_hotel(name)) // check  if  the name of hotel invalid return true
                                       {
                                             name_hotel_infile();
                              	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                                            cout<<endl<<endl<<"are you want to edit in this hotel (y/n) ? ";
                                            if(check())
											{
												cout<<endl<<endl;
                              	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                                                edit_hotel_p_p_N(name, P_N);
                              	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
											}
                                             else
                                                {
                                                    cout<<"are you want to add another  name of  hotel (y/n)";
                                                    if(check())
                                                      {
														  system("cls");
                                                            objhotel.addhotel();
                                                      }
                                                    else
                                                      {
                                                          disp_choices_hotel_to_manager();
                                                      }
                                                }
                                        }
                                  else
                                    {
                                       /****** btdeeef  el hotel *******/
								 Enter_Hotel_price(P_N,37,13);
                              	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
									  cout<< " confirm add (y/n) ";
									  if(check())
									  {
											  hotelname.push_back(name);
											  cityid_hotel.push_back(idof_city);
											  price_per_night.push_back(P_N);
											  idof_hotel++;
											  hotelid.push_back(idof_hotel);
											  objcity.no_hotel[idof_city-1000]++; // increase the number of hotel in this city
											  cout<<"are you want to add another hotel (Y/N) ";
														if(check())
															{
																objhotel.addhotel();
															}
														 else
															{
																disp_choices_hotel_to_manager();
															}
									  }
									  else
										  disp_choices_hotel_to_manager();

                                    }

                }
     }
    else   // if city id  not valid
    {
        cout<<"\t\t!!!the id  of city not  valid\n";
        long long  choice;
       cout<<"1-back to main menu\n2- view all city  ";
       cin >> choice;
       if (choice==1)
          disp_to_manger();
       else  if (choice==2)
         objcity.search_city();
    }

}
void display_city_inf()   // display all city information
    {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		cout<<"\t*****************************************************************"<<endl;
        for(long long  i=0;i<objcity.cityname.size();i++)
		{
			cout<<"\t* city id <"<<objcity.idcity[i]<<"> :   "<<"name : " << objcity.cityname[i];
		gotoxy(47,i+1);
		cout<<"  number of hotel    <"<<objcity.no_hotel[i]<<"> *"<<endl;
    }
		cout<<"\t*****************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
bool  check_id_city(long long  &id)    // return if  the id of  city in  file
{

    for(long long  i=0;i<objcity.idcity.size();i++)
    {
        if(id==objcity.idcity[i])
        return true;
    }
    return false;

}

bool check_name_hotel(string& name) // check if  name of hotel in file or not
{
   for(long long  i=0;i<objhotel.hotelname.size();i++)
   {
       if(objhotel.hotelname[i]==name)
        return true;   // if name of hotel in file ---> edit
   }
   return false; // not in file  ----->add this hotel
}
void edit_hotel_p_p_N(string name,long double  P_N)
{
	Enter_Hotel_price( P_N,40,26);
    for(long long  i=0;i<objhotel.hotelname.size();i++)
    {
        if(name==objhotel.hotelname[i])
        {
            objhotel.price_per_night[i]=P_N;
            cout<<"\n\t\t the new price per  night has been added ";
          disp_choices_hotel_to_manager();
        }
    }
}

bool check() // check yes or  no to continue
    {
          char  che;
          cin >> che;
           if(che=='y'||che=='Y')
            return true;
           else
            return false;
    }
/******* end functions to hotel ******/


/***** fun to booking *****/
void out_Booking()
{
	cout<<endl<<endl<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"          *"<<"*************************************************************"<<endl;
	cout<<"          *"<<"                                                            *"<<endl<<"          *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" <1> Add Booking                                            ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <2> list all booking                                       *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <3> delete booking request                                 *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<" <4> Exit                                                   *"<<endl;
	cout<<"          *"<<"                                                            *"<<endl;
	cout<<"          *"<<"*************************************************************"<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
system("pause");
}
void Manue_Booking(int &Process_Booking_process) /* manu to chose chosis of city*/
{

while(1){
	if(GetAsyncKeyState(VK_DOWN)&&Process_Booking_process==1)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Booking_process++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_Booking_process==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 Process_Booking_process++;
	}
	else if(GetAsyncKeyState(VK_DOWN)&&Process_Booking_process==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Booking_process++;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Booking_process==4)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Booking_process--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Booking_process==3)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Booking_process--;
	}
	else if(GetAsyncKeyState(VK_UP)&&Process_Booking_process==2)
	{
		Sleep(200);
gotoxy(12,6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"<1> Add Booking"<<endl;
gotoxy(12,8);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<2> list all booking"<<endl;
gotoxy(12,10);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<3> delete booking request"<<endl;
gotoxy(12,12);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"<4> Exit";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	Process_Booking_process--;

	}
		else if(GetAsyncKeyState(VK_F1))
{
	Beep(500,500);
	system("cls");
	break;
}

}
}
 void  disp_choices_booking()
{

        system("CLS");
        int  choose_Booking=1;
      out_Booking();
	  Manue_Booking(choose_Booking);
		if(choose_Booking==1)
			addbooking();
		else  if (choose_Booking==2)
		{
			list_booking_request();
			system("pause");
		}
		else if (choose_Booking==3)
			delete_booking();
		else
			Bye();
	     disp_choices_booking();


}
 void Enter_Id_booking(long long &name)/*to enter id booking to request */
{

	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"           *************************************************************"<<endl<<"           *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" Enter Id to request :                                     ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"           *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");
	 gotoxy(37,objhotel.cityid_hotel.size()+6);
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	 cin>>name;
}
 void Enter_rooms_numofN(long long rooms,long long nights)
 {
	 system("cls");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
cout<<"\t\t *"<<"**********************************************"<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<" <1> Num of Rooms :                           "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<" <2> Num of Nights :                          "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"                                              "<<"*"<<endl<<"\t\t *";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
cout<<"           Hotels Booking System              ";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
cout<<"*"<<endl<<"\t\t *"<<"                                              "<<"*"<<endl;
cout<<"\t\t *"<<"**********************************************"<<"*"<<endl;
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		
gotoxy(40,7);
cin>>rooms;
	Beep(500,500);
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
gotoxy(40,10);
cin>>nights;

 }
 void  addbooking()  // add booking request
{
	   system("cls");
    disp_hotel_tobook();   // to view all hotel and choose by  id
    long long  num=1;
	Enter_Id_booking(num);
	num-=100;
	if(num >= 0 && num<objhotel.cityid_hotel.size())
    {
		system("cls");
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"***************************************************************************"<<endl;
         cout <<"*\tthe hotel name :  "<< objhotel.hotelname[num]<<"\t price per night :  "<<objhotel.price_per_night[num]<<endl;// display hotel name  and price per  night which choosed
			gotoxy(74,1);
			cout<<"*"<<endl;
            cout<<"***************************************************************************"<<endl; \
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<" want to continue (y/n)";
            if(check())
            {
				Enter_rooms_numofN(objbook.room,objbook.night);
			 cout<<"\n\n\n\n\n\n";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                cout << "\t\t\tBooking Confirmation (y/n)";
                if(check()) // if  he  confirm add
                {
                           objbook.cost=objhotel.price_per_night[num] * objbook.room * objbook.night;
                           objbook.book++;   // the last id  of  booking
                           objbook.id_booking.push_back(objbook.book);
                           objbook.hotelname_booking.push_back(objhotel.hotelname[num]);
                           objbook.request_cost.push_back(objbook.cost);
                           objbook.no_room.push_back(objbook.room);
                           objbook.no_night.push_back(objbook.night);
                           system("CLS");
						   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t*************************************************************"<<endl;
	cout<<"\t*             the booking has been added successful         *"<<endl;
	cout<<"\t*                                                           *"<<endl;
	cout<<"\t*************************************************************"<<endl;
                        gotoxy(25,6);
						   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                           cout << "\ttotal cost : "<<objbook.cost;
						   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                             cout << " \n\n\n\n\n\n\t\t are you want to add another one (y/n) " ;
                             if(check())  // check if  he want to add another one
                                    addbooking();
                             else
                                     disp_choices_booking();
                }
                else
                {
                     disp_choices_booking();
                }

            }
            else
                 disp_choices_booking();
    }
    else
        {
            Erorr();
            disp_choices_booking();
        }
}
 void  list_booking_request()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"******************************************************************************"<<endl;
      cout<<"* request id\tname hotel\ttotal cost\tNum of rooms\tNum of night\n";
    for(int i=0 ;i < objbook.hotelname_booking.size() ; i++)
	{
		gotoxy(0,i+2);
        cout<<"* "<<objbook.id_booking[i];
		gotoxy(18,i+2);
		cout<<name_of_hotel(i+100)<<endl;
		gotoxy(35,i+2);
		cout<<objbook.request_cost[i]<<endl;
		gotoxy(52,i+2);
		cout<<objbook.no_room[i]<<endl;
		gotoxy(69,i+2);
		cout<<objbook.no_night[i]<<endl;
		gotoxy(77,i+1);
			cout<<"*";
	}
	cout<<"\n";
	cout<<"******************************************************************************"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
 void del_booking_Gui(long long &num )
 {
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	  cout<<"\t**************************************************"<<endl;
	  cout<<"\t*                                                *"<<endl;
	  cout<<"\t*                                                *"<<endl;
	  cout<<"\t*  enter  the request id :                       *"<<endl;
	  cout<<"\t**************************************************"<<endl;

	  /***************************/
	  gotoxy(15,3+objbook.hotelname_booking.size());
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	  cout<<"please enter the id of booking request";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(35,5+objbook.hotelname_booking.size());
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	 cin >> num;
	 num-=10;

 }
 void successful_delet_booking()
 {
	   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t *************************************************************"<<endl<<"\t *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"        the  request has been deleted  successful          ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"\t *************************************************************"<<endl;
	 cout<<"\t\t\t\t";
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	 system("pause");

 }
 void  delete_booking()
{
     list_booking_request();
     long long num=1;
	 del_booking_Gui(num);
	 if(num>=0&&num<objbook.hotelname_booking.size())
        {
			system("cls");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	 cout<<"\n\n\t\t**************************************************"<<endl;
	 cout << "\t\t* id : "<< objbook.id_booking[num]<<endl;
	 cout<< "\t\t* name hotel : " << objbook.hotelname_booking[num] <<endl;
	 cout<< "\t\t* total cost : "<<objbook.request_cost[num] <<endl;
	 cout<<"\t\t* Num of room : "<<objbook.no_room[num] <<endl;
	 cout<<"\t\t* Num of night  :"<<objbook.no_night[num]<<endl;
	 cout<<"\t\t**************************************************"<<endl;
	  for(int i=0;i<5;i++)
	  {
		  gotoxy(65,i+3);
		  cout<<"*"<<endl;;
	  }
	   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	 cout <<"\n\n\t\t confirm delete  (y/n)";
     if(check()) // delete the booking request
     {
         objbook.hotelname_booking.erase(objbook.hotelname_booking.begin()+num);
         objbook.no_night.erase(objbook.no_night.begin()+num);
         objbook.no_room.erase(objbook.no_room.begin()+num);
         objbook.request_cost.erase(objbook.request_cost.begin()+num);
         objbook.id_booking.erase(objbook.id_booking.begin()+num);
         for(int i=0;i<objbook.id_booking.size();i++) // to make a sequance of booking
            objbook.id_booking[i]=i+10;
            objbook.book=objbook.id_booking[objbook.id_booking.size()-1]; // to take the last id  of booking
		successful_delet_booking();
     }
	 else
		 disp_choices_booking();
        }
        else
           cout<< " you enter in valid id ";
			 disp_choices_booking();    // after the end of delete booking
}
 void  disp_hotel_tobook()  //  display hotel and id
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		 cout<<"\t\t***************************************************"<<endl;
	 for(int i=0; i < objhotel.hotelname.size();i++)
	 {
		 cout <<"\t\t* the id  : "<<i+100<< "\t\t  name :" <<  objhotel.hotelname[i];
		 gotoxy(66,i);
		 cout<<"*"<<endl;
		 }
		 cout<<"\t\t***************************************************"<<endl;
 }
string name_of_hotel(long long id) // take the id of hotel and return  name  hotel
{
	return objbook.hotelname_booking[id-100];
}
/****** fun end of booking *****/


/***** fun to GUI****/
void Beganining()
{
    cout<<'\a';
	cout<<endl<<endl<<endl<<endl;
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"          *"<<"*************************************************************"<<endl;
	cout<<"          *"<<"                        "<<"Welcome"<<"                             "<<"*"<<endl;
	cout<<"          *"<<"                                                            "<<"*"<<endl;
	cout<<"          *"<<" <1> ABdelrahamn HASSAN MOHAMED  Ali           (Dev&leader) "<<"*"<<endl;
	cout<<"          *"<<" <2> Abdelrahamn Mohamed Esmail Abdelmaqusod      (UI)      "<<"*"<<endl;
	cout<<"          *"<<" <3> Abdelfatah El-Saaid  Mostafa Abass           (UI)      "<<"*"<<endl;
	cout<<"          *"<<" <4> Hassn Gamal Abdelaal Kamal                  ( Dev )    "<<"*"<<endl;
	cout<<"          *"<<" <5> Abdelrahamn Mohamed Ashraf Mohamed          ( Dev )    "<<"*"<<endl;
	cout<<"          *"<<"                                                            "<<"*"<<endl<<"          *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<" Note : press movemnt to select & F1 to choose .            ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          *"<<"                                                            "<<"*"<<endl<<"          *";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"                  Hotels Booking System                     ";
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          *"<<"*************************************************************"<<endl;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
	system("pause");
	system("cls");
}
void validEmail()
{
	cout<<endl<<endl<<endl;
    cout<<'\a';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"          ****************************************************************"<<endl<<"          *";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"             Password or Email not valid ,try again later     ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"          ****************************************************************"<<endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);

}
void Erorr()  // cout if there is  error
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<endl<<endl<<endl<<endl;
	cout<<"             ***************************************************************"<<endl<<"             *";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"               You Enter wrong Operation try again later     ";
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"*"<<endl<<"             ***************************************************************"<<endl;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	system("pause");
}




/****** end  fun  of  GUI ****/

