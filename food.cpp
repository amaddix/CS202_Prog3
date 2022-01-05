

// Ashley Maddix
// CS202, FQ18, prog 3

//  main
//	menu

//**food**
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

#include "tree.h"


//-------------------------GEN_FOOD--------------------------//

// constructor
gen_food::gen_food(): calorie(0), dairy(0)
{
	type=NULL;
	name=NULL;
	veggie=NULL;
	fruit=NULL;

}
//copy constructor
gen_food::gen_food(const gen_food & source)
{

	calorie=source.calorie;
	dairy=source.dairy;


	if(source.type)
	{
		type=source.type;
	}

	if(source.name)
	{
		name= new char[strlen(source.name)+1];
		strcpy(name, source.name);
	}
	

	if (source.veggie)
	{
		veggie= new char[strlen(source.veggie)+1];
		strcpy(veggie, source.veggie);
	}

	if(source.fruit)
	{
		fruit= new char[strlen(source.fruit)+1];
		strcpy(fruit, source.fruit);
	}

}

// destructor
gen_food::~gen_food()
{
	if(type)
		delete type;
	
	if(name)
		delete [] name;

	if(veggie)
		delete[] veggie;

	if (fruit)
		delete [] fruit;

	calorie=0;
	dairy=0;

}

// function to add
int gen_food:: add()
{
	char temp[100];
	char tempchar;

	cout<<"1.	What is the name of the food you're adding?"<<endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	name= new char[strlen(temp)+1];
	strcpy(name, temp);

	cout<<"2.	How many calories does this thing have?"<<endl;
	cin>>calorie;
	cin.ignore(100,'\n');

	cout<<"3.	Is there any dairy (Y/N)"<<endl;
	cin>>tempchar;
	cin.ignore(100,'\n');
	tempchar=toupper(tempchar);

	if (tempchar == 'Y')
		dairy=1;
	else
		dairy=0;

	cout<<"4.	If there is there any vegtables in this, that is it?   If not, type 0"<<endl;
	cin.get(temp, 100, '\n');
	cin.ignore (100, '\n');
	if (strcmp(temp, "0") ==0)
		veggie=NULL;
	else
	{
		veggie=new char[strlen(temp)+1];
		strcpy(veggie, temp);
	}


	cout<<"5.	If there is a fruit in this, that is it?   If not, type 0"<<endl<<endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');
	if (strcmp(temp, "0")==0)
		fruit=NULL;

	else
	{
		fruit=new char [strlen(temp)+1];

		strcpy(fruit, temp);
	}

}

// function to display
void gen_food:: display() const
{
	cout<<"  Food  :   "<<name<<endl;
	cout<<"  Calories  :  "<<calorie<<endl;

	if(dairy)
		cout<<"  item contains dairy"<<endl;	

	if (veggie)
		cout<<"  item contains the veggie :  "<<veggie<<endl;

	if (fruit)
		cout<<"  item contains the fruit  :  "<<fruit<<endl;


}

// function to return name
char * gen_food::get_name()
{
	return name;
}

// functio to return dairy
bool gen_food::get_dairy()
{
	return dairy;
}

// operator =
gen_food & gen_food:: operator = (const gen_food & adding)
{

	if(adding.name)
	{	
		if(name)
			delete [] name;

		name = new char[strlen(adding.name) +1];
		strcpy(name, adding.name);
	}
	else
		name=NULL;


	calorie=adding.calorie;

	dairy=adding.dairy;	

	if(adding.veggie)
	{
		if(veggie)
			delete [] veggie;

		veggie= new char[strlen(adding.veggie) +1];
		strcpy(veggie, adding.veggie);
	}
	else
		veggie=NULL;

	if(adding.fruit)
	{
		if(fruit)
			delete [] fruit;

		fruit= new char[strlen(adding.fruit) +1];
		strcpy(fruit, adding.fruit);
	}
	else
		fruit=NULL;
} 


// operator functions that were commented out

/*
   gen_food  gen_food:: operator + (const gen_food & adding) const
   {
   gen_food sum;

   sum.name= new char [strlen( name)+ strlen(adding.name)+1];
   strcpy(sum.name, name);
   strcat(sum.name, adding.name);

   sum.calorie=calorie+adding.calorie;

   if (dairy || adding.dairy)
   sum.dairy=1;

   if (veggie && adding.veggie)
   {
   sum.veggie=new char[strlen(veggie) + strlen(adding.veggie)+1];
   strcpy(sum.veggie, veggie);
   strcat(sum.veggie, adding.veggie);
   }

   else if(!veggie)
   {
   sum.veggie=new char[strlen(adding.veggie) +1];
   strcpy(sum.veggie, adding.veggie);
   }

   else if(!adding.veggie)
   {
   sum.veggie=new char[strlen(veggie) +1];
   strcpy(sum.veggie, veggie);
   }

   if (fruit && adding.fruit)
   {
   sum.fruit=new char[strlen(fruit) + strlen(adding.fruit) +1];
   strcpy(sum.fruit, fruit);
   strcat(sum.fruit, adding.fruit);
   }

   else if(!fruit)
   {
   sum.fruit=new char[strlen(adding.fruit)+1];
   strcpy(sum.fruit, adding.fruit);
   }
   else if(!adding.fruit)
   {

   sum.fruit=new char[strlen(fruit)+1];
   strcpy(sum.fruit, fruit);
   }

   return sum;	

   }

   gen_food& gen_food:: operator += (const gen_food adding)
   {
   char temp[100];

   strcpy(temp, name);
   delete [] name;
   name = new char[strlen(temp)+strlen(adding.name)+1];
   strcpy(name, temp);
   strcat(name, adding.name);

   calorie+=adding.calorie;

   if (dairy || adding.dairy)
   dairy=1;

if (veggie && adding.veggie)
{
	strcpy(temp, veggie);
	delete [] veggie;
	veggie = new char[strlen(temp)+strlen(adding.veggie) +1];
	strcpy(veggie, temp);
	strcat(veggie, adding.veggie);
}

else if(!veggie)
{
	veggie=new char[strlen(adding.veggie) +1];
	strcpy(veggie, adding.veggie);
}


if (fruit && adding.fruit)
{
	strcpy(temp, fruit);
	delete [] fruit;
	fruit = new char[strlen(temp)+strlen(adding.fruit) +1];
	strcpy(fruit, temp);
	strcat(fruit, adding.fruit);

}

else if(!fruit)
{
	fruit=new char[strlen(adding.fruit)+1];
	strcpy(fruit, adding.fruit);
}


}

bool gen_food:: operator == (const gen_food & adding) const
{	 
	bool match=1;

	if (strcmp(name, adding.name)!=0 && calorie!=adding.calorie && dairy!=adding.dairy)
		match =0;

	if (veggie && adding.veggie && strcmp(veggie, adding.veggie)!=0);
	match =0;

	if (veggie && !adding.veggie || !veggie && adding.veggie)
		match=0;

	if (fruit && adding.fruit && strcmp(fruit, adding.fruit)!=0);
	match =0;

	if (fruit && !adding.fruit || !veggie && adding.fruit)
		match=0;

	return match;

}

bool gen_food::operator == ( const char * tempname) const
{
	if(strcmp(name, tempname)==0)
		return 1;

	return 0;

}

bool gen_food::operator == ( const int tempcalorie) const
{
	if (calorie == tempcalorie)
		return 1;

	return 0;

}
bool gen_food::operator == ( const bool tempdairy) const
{
	if (dairy == tempdairy)
		return 1;

	return 0;

}

/////////////////////////
bool operator == ( const char * tempveggie) const
{
	if (veggie && tempveggie && strcmp(veggie, tempveggie)==0)
		return 1;

	if (!veggie && !tempveggie)
		return 1;

	return 0;
}

bool operator == ( const char * tempfruit) const
{
	if (fruit && tempfruit && strcmp(fruit, tempfruit)==0)
		return 1;

	if (!fruit && !tempfruit)
		return 1;

	return 0;

} /////////////////////////////////////////////

bool gen_food::  operator != (const gen_food & adding) const
{
	bool match=0;

	if (strcmp(name, adding.name)==0 && calorie==adding.calorie && dairy==adding.dairy)
		match =1;

	if (veggie && adding.veggie && strcmp(veggie, adding.veggie)==0);
	match =1;

	if (!veggie && !adding.veggie)
		match=1;

	if (fruit && adding.fruit && strcmp(fruit, adding.fruit)==0);
	match =1;

	if (!fruit && !adding.fruit)
		match=1;

	return match;

}
	*/


// operator <<
ostream& operator << (ostream& out, const gen_food* & item)
{
	item->display();

	return out;


}
// operaor >>
istream& operator >> (istream& in, gen_food* & item)
{
	item->add();

} 

//-------------------------MAIN_COURSE--------------------------//

// constructor
main_course::main_course(): gen_food(), nuts(0), salt(0)
{
	meat=NULL;

}

// copy construcot
main_course::main_course(const main_course & source): gen_food(source)
{
	nuts=source.nuts;
	salt=source.salt;

	if (meat)
	{
		meat=new char[strlen(source.meat)+1];
		strcpy(meat, source.meat);
	}

}
// deructor
main_course::~main_course()
{
	nuts=0;
	salt=0;

	if (meat)
	{
		delete [] meat;
		meat=NULL;	
	}

}
// add function
int main_course:: add()
{
	//	main_course temp_item;
	char temp;
	char tempvar[100];

	gen_food::add();

	cout<<"  1.  is there any nuts in this meal? (Y/N)"<<endl;

	cin>>temp;
	cin.ignore(100, '\n');
	temp=toupper(temp);

	if (temp == 'Y')
		nuts=1;
	else
		nuts=0;

	cout<<"  2.  How much salt is in this meal?(1-10)"<<endl;
	cin>>salt;
	cin.ignore (100, '\n');

  cout<<"  3.  If there is any meat in this meal, what is it? Otherwise type 0"<<endl<<endl;
	cin.get(tempvar, 100, '\n');
	cin.ignore(100, '\n');

	if (strcmp ( tempvar, "0") == 0)
		meat=NULL;

	else
	{
		meat= new char[strlen(tempvar)+1];
		strcpy(meat, tempvar);
	}



}
// display funcion
void main_course:: display() const 
{
	gen_food::display();

	if (nuts)
		cout<<"  Meal conains nuts  "<<endl;

	cout<<" Amount of salt in meal  :  "<<salt<<endl;

	if (meat)
		cout<<"  This meal contains :  "<<meat<<endl;	
}
// return meat
bool main_course::get_meat()
{
	if (meat)
		return 1;

	return 0;
}

// return nuts
bool main_course::get_nuts()
{
	return nuts;
}

// operator =
main_course & main_course ::operator = (const main_course & adding)
{
	gen_food::operator =(adding);

	if (meat)
		delete [] meat;

	meat= new char[strlen(adding.meat) +1];
	strcmp(meat, adding.meat);

	nuts=adding.nuts;

	salt= adding.salt;



}

// operator functions commented out
/*
   main_course main_course ::operator + (const main_course & adding) const
   {
   gen_food::operator + (adding);

   main_course sum;


   if(meat && adding.meat)
   {
   sum.meat= new char[strlen(meat) + strlen(adding.meat) +1];
   strcpy(sum.meat, meat);
   strcat(sum.meat, adding.meat);
   }

   if (nuts || adding.nuts)
   sum.nuts =1;
   else
   sum.nuts=0;

   sum.salt= salt+adding.salt;	

   return sum;

   }

   main_course & main_course :: operator += (const main_course & adding)
   {
   gen_food::operator +=(adding);

   char temp[100];

   if (meat)
   {
   strcpy(temp, meat);
   delete [] meat;
   meat=new char[strlen(temp) +strlen(adding.meat) +1];
   strcpy(meat, temp);
   strcat(meat, adding.meat);
   }	
   else
   {
   meat= new char[strlen(adding.meat) +1];
   strcpy(meat, temp);
   }


   if (nuts || adding.nuts)
   nuts =1;
   else
   nuts=0;

   salt+=adding.salt;


   }

 */



//-------------------------DESSERT--------------------------//

//constructor
dessert::dessert(): gen_food(), sugar(0), nuts(0)
{

}

// add function
int dessert:: add()
{
	char temp;
	gen_food::add();

	cout<<"  1.   How much sugar is in his dessert?(in grams)"<<endl;
	cin>>sugar;
	cin.ignore(100, '\n');

	cout<<"  2.  Is there any nuts in this dessert? (Y/N)"<<endl;

	cin>>temp;
	cin.ignore(100, '\n');
	temp=toupper(temp);

	if (temp == 'Y')
		nuts=1;
	else
		nuts=0;

}

// fiplay function
void dessert::display() const
{
	gen_food::display();

	cout<<"  Amount of sugar:  "<<sugar<<endl;
	if (nuts)
		cout<<"This dessert contains nuts"<<endl;


}

// return nuts
bool dessert::get_nuts()
{
	return nuts;
}

// operator =
dessert & dessert  :: operator = (const dessert & adding)
{
	gen_food::operator =(adding);

	sugar=adding.sugar;

	nuts=adding.nuts;	

} 

// operator functions commented out
/*	
	dessert dessert  :: operator + (const dessert & adding) const
	{
	dessert sum;

	gen_food::operator +(adding);

	sum.sugar= sugar+ adding.sugar;

	if (nuts || adding.nuts)
	sum.nuts=1;
	else 
	sum.nuts=0;	

	return sum;	

	}

	dessert & dessert :: operator += (const dessert & adding)
	{
	gen_food::operator +=(adding);

	sugar+= adding.sugar;

	if (nuts || adding.nuts)
	nuts=1;
	else 
	nuts=0;	

	} */





//-------------------------DRINK--------------------------//


// construcotr
drink::drink(): gen_food(), sugar(0), alcohol(0), carbonation(0)
{

}

// add function
int drink::add()
{	char temp;
	gen_food::add();

	cout<<"  1. amount of sugar"<<endl;
	cin>>sugar;
	cin.ignore(100, '\n');

	cout<<"  2. alchohol (Y/N)"<<endl;
	cin>>temp;
	cin.ignore(100, '\n');
	temp=toupper(temp);
	if (temp == 'Y')
		alcohol=1;
	else
		alcohol=0;

	cout<<"  3. carbonation (Y/N)"<<endl;
	cin>>temp;
	cin.ignore(100, '\n');
	temp=toupper(temp);
	if (temp == 'Y')
		carbonation=1;
	else
		carbonation=0;
}

// display functin
void drink::display() const
{
	gen_food::display();

	cout<<"Amount of sugar  :   "<<sugar<<endl;

	if (alcohol)
		cout<<"alcholic beverage"<<endl;

	if (carbonation)
		cout<<"carbinated"<<endl;

}

// return alcohol
bool drink::get_alcohol()
{
	return alcohol;
}

//operator =
drink & drink  :: operator = (const drink & adding)
{
	gen_food::operator =(adding);

	sugar=adding.sugar;

	alcohol=adding.alcohol;

	carbonation= adding.carbonation;

}

// operator functions comented out

/*	
	drink drink  :: operator + (const drink & adding) const
	{	
	drink sum;

	gen_food::operator +(adding);

	sum.sugar=sugar+adding.sugar;

	if(alcohol || adding.alcohol)
	sum.alcohol=1;
	else
	sum.alcohol=0;


	if(carbonation || adding.carbonation)
	sum.carbonation=1;
	else
	sum.carbonation=0;


	return sum;	

	}

	drink & drink :: operator += (const drink & adding)
	{
	gen_food::operator += (adding);

	sugar += adding.sugar;

	if (alcohol | adding.alcohol)
	alcohol=1;	
	else 
	alcohol =0;

	if(carbonation | adding.carbonation)
	carbonation =1;
	else
	carbonation=0;

	} */
