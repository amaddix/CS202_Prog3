

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

#include <iostream>
#include <cstring>

using namespace std;

int menu();

class gen_food
{
	public:
		gen_food();
		gen_food(const gen_food & source);

		virtual ~gen_food();


		virtual int add();
		virtual void display() const;
		char * get_name();
		virtual bool get_meat(){};
		virtual bool get_nuts(){};
		bool get_dairy();
		virtual bool get_alcohol(){};


		virtual gen_food& operator = (const gen_food &);
		/*
		   virtual gen_food operator + (const gen_food &) const;
		   virtual gen_food & operator += (const gen_food);


		   virtual  bool operator == (const gen_food &) const;
		   virtual bool operator == ( const char * tempname) const;
		   virtual bool operator == ( const int tempcalorie) const;
		   virtual bool operator == ( const bool tempdairy) const;
		//	virtual bool operator == ( const char * tempveggie) const;
		//	virtual bool operator == ( const char * tempfruit) const;

		virtual  bool operator != (const gen_food &) const;
		 */
		friend ostream & operator << (ostream&, const gen_food * &);
		friend istream & operator >> (istream&,  gen_food * &);  



	protected:
		gen_food * type;
		char * name;
		int calorie;
		bool dairy;
		char * veggie;
		char * fruit;

};

class main_course: public gen_food
{
	public:
		main_course();
		main_course(const main_course & source);
		~main_course();

		int add();
		void display() const ;

		// char * get_name(){}
		bool get_meat();
		bool get_nuts();
		//	 bool get_dairy();
		bool get_alcohol(){}

		main_course & operator = (const main_course &);
		/*
		   main_course   operator + (const main_course &) const;
		   main_course  & operator += (const main_course &); */


	protected:
		char * meat;
		bool nuts;
		int salt;

};

class dessert: public gen_food
{
	public:
		dessert();

		int add();
		void display() const;

		//char * get_name(){}
		bool get_meat(){}
		bool get_nuts();
		//	 bool get_dairy();
		bool get_alcohol(){}

		dessert  & operator = (const dessert &); 
		/*
		   dessert   operator + (const dessert &) const;
		   dessert  & operator += (const dessert &); */

	protected:
		int sugar;
		bool nuts;
};

class drink: public gen_food
{
	public:
		drink();

		int add();
		void display() const;

		//	 char * get_name(){}
		bool get_meat(){}
		bool get_nuts(){}
		//	 bool get_dairy();
		bool get_alcohol();

		drink  & operator = (const drink &); 
		/*
		   drink   operator + (const drink &) const;
		   drink  & operator += (const drink &); */

	protected:
		int sugar;
		bool alcohol;
		bool carbonation;

};
