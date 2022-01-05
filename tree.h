

// Ashley Maddix
// CS202, FQ18, prog 3

//  main
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


//**tree**
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
#include "food.h"


class node
{

	public:
		node(); // construcotr
		node ( const node & source); // copy cnstructor
		~node (); // destructor
		
		int add(gen_food * afood, char *); // function to create a new node
		void display(); // function to display node
		bool get_dairy(); // function to return dairy
		bool get_meat(); // function to return meat
		bool get_nuts(); // function to return nuts
		bool get_alcohol(); // function to return alcohol
	

		int set_data(int ); // function to set the data (= operator)
		int set_left( node *); // function to set left node
		int set_right(node *); // function to set the right node
		node * & get_left(); // function to return left node
		node * & get_right(); // function to return the right node
		gen_food * & get_basefood(); // function to return base food
				
		bool  compare(char * adding); // function that works how the < operator func. should
		bool  get_match(char * temp); // function that should work how the == function works

		// operators to compare	
		 friend bool operator < (const node  &, char *);
		 friend bool operator < (char *, const node  &);
		 friend bool operator < (const node  &, const node &) ;

		 friend bool operator <= (const node  &, char *) ;
		 friend bool operator <= (char *, const node  &) ;
		 friend bool operator <= (const node  &, const node &) ;

		 friend bool operator > (const node  &, char *) ;
		 friend bool operator > (char *, const node  &) ;
		 friend bool operator > (const node  &, const node &) ;

		 friend bool operator >= (const node  &, char *) ;
		 friend bool operator >= (char *, const node  &) ;
		 friend bool operator >= (const node  &, const node &) ;

		 friend bool operator != (const node  &, char *) ;
		 friend bool operator != (char *, const node &) ;
		 friend bool operator != (const node  &, const node &) ;
	
		 friend bool operator == (const node  &, char *) ;
		 friend bool operator == (char *, const node &) ;
		 friend bool operator == (const node &, const node &) ;

		//operators to change values
		 node & operator = (const node &);
		 node operator + (const node &) const;
	  	 node & operator += (const node);

		
		
		
	
	protected:
		gen_food * base_food;
	
		node * left;		
		node * right;

};


class tree
{

	public:
		tree(); //construtor
		tree(const tree & source);
		~tree(); // destructor

		int add(node*, char *); //wrapper to add
		int add(node * &, node *, char *); // recursion to add
		void display() const; // wrapper to display
		void display(node *) const; // recursion to display
		int find_nondairy(); // wrapper to find non dairys
		int find_nondairy(node *); // recursion to find non dairies
		int find_nomeat(); // wrapper to find no meat
		int find_nomeat(node *); // recursion to find no meat
		int find_nonuts(); // wrapper to find no nuts
		int find_nonuts(node *); // recusion to find no nuts
		int find_nonalcohol(); // wrapper to find no alchohol
		int find_nonalcohol(node *); // recursion to find no alcohol
		int find_name(); // wrapper to find name
		int find_name(node *, char *); //recursion to find name
		

	protected:
		node * root; // root
		
} ;
