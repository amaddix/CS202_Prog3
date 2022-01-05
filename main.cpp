
// Ashley Maddix
// CS202, FQ18, prog 3

// ** main **
//	menu

//food
//	gen_food
//		add
//		display
//		get name
//		get meat
//		get nuts
//		get dairy
//		get alcohol
//		=
//		<<
//		>>

//	main_course
//		add
//		display
//		get meat
//		get nuts
//		=
//		<<
//		>>

//	dessert
//		add
//		display 
//		get nuts
//		=
//		<<
//		>>

//	drink
//		add
//		display
//		get alcohol
//		==
//		<<
//		>>


//tree
//	node
//		add
//		display
//		get dairy
//		get meat
//		get nuts
//		get alcohol
//		set data
//		set left
//		set right
//		get left
//		get right
//		get basefood
//		compare
//		get match
//		<, <=, >, >=, !=, ==
//		=, +, +=
//	tree
//		add
//		display
//		nondairy
//		non meat
//		non alcohol
//		no nuts
//		find name



#include "tree.h"


int main ()
{
	gen_food * afood; 
	char temp_char[100]; 
	node * temp;
	tree newtree;

	int choice=1;
	int read=0;

	do
	{	

		if (choice == 1)	
		{
			cout<<"  what type of food is it?"<<endl
				<<"  1.  main course  "<<endl
				<<"  2.  dessert   "<<endl
				<<"  3.  drink  "<<endl<<endl;

			cin>>read;
			cin.ignore(100, '\n');

			if (read == 1)
				afood= new main_course;

			if (read == 2)
				afood= new dessert;

			if (read == 3)
				afood= new drink;

			temp= new node;
			temp->add(afood, temp_char);


			newtree.add(temp, temp_char);
		}



		if (choice ==2)
			newtree.display();
	
		if (choice == 3)
			newtree.find_name();
		
		if(choice ==4)
			newtree.find_nondairy();
	
		if (choice == 5)
			newtree.find_nomeat();
	
		if(choice == 6)
			newtree.find_nonuts();
		
		if (choice == 7)
			newtree.find_nonalcohol();

		choice=menu();

	}while (choice <= 10);
	return 0;
}

// function to display the menu of options
int menu()
{

	int choice=0;

	cout<<"  Choose an action  :  "<<endl
		<<"  1.    add a food item "<<endl
		<<"  2.    display all food items"<<endl
		<<"  3.    find specific item"<<endl
		<<"  4.    display all dairy free"<<endl
		<<"  5.    display all vegatarian"<<endl
		<<"  6.    display all nut free"<<endl
		<<"  7.    display all non alchoholc beverages "<<endl
		<<"  8.    find total calories, sugar, and salt in items ate"<<endl
		<<"  9.   end program"<<endl<<endl;

	cin>>choice;
	cin.ignore(100, '\n');

	return choice;


}
