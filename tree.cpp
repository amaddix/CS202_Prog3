

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
#include "tree.h"


//-------------------------NODE--------------------------//

// constructor
node::node()
{
	base_food=NULL;
	left=NULL;
	right=NULL;

}

//coy constructor
node::node ( const node & source)
{
	if(source.base_food)
		base_food=source.base_food;	

	if (source.left)
		left=source.left;

	if(source.right)
		right=source.right;

}

//destructor
node::~node ()
{
	if(base_food)
		delete base_food;

	if(left)
		delete left;

	if(right)
		delete right;

}

//function to add a nodes information
int node:: add(gen_food * afood, char * temp_char)
{

	base_food=afood;

	base_food->add();
	strcpy(temp_char, base_food->get_name());

}

// function to display the nodes info
void node::display()
{
	base_food->display();
}

// funcion to return if a food item has dairy
bool node::get_dairy()
{
	if(base_food->get_dairy())
		return 1;
		
	return 0;
}

// funcion to return if a food item has meat
bool node:: get_meat()
{
	if (base_food->get_meat())
		return 1;

	return 0;

}

// funcion to return if a food item has nuts
bool node:: get_nuts()
{
	if (base_food->get_nuts())
		return 1;

	return 0;
}

// funcion to return if a food item has alcohol
bool node :: get_alcohol()
{
	if (base_food->get_alcohol())
		return 1;

	return 0;
}


//funcion to set the data of the node
int node::set_data(int temp)
{
//	data=temp;	
}

// function to set the left node
int node::set_left( node * temp)
{	
	left=temp;
}

// function to set the right node
int node::set_right( node * temp)
{
	right=temp;

}

// function to return the left node
node * & node::get_left()
{
	return left;

}

//function to return the right node
node * & node::get_right()
{
	return right;	
}

// function to return the base food
gen_food * & node::get_basefood()
{
	return base_food;
}

//function to compare if a node being added is < then the current one
bool node :: compare(char * adding)
{
	if(strcmp(adding, base_food->get_name()) < 0)
		return 1;

	return 0;

}

//function to compare if name == node.name
bool node:: get_match(char * temp)
{
	if (strcmp(base_food->get_name(), temp)==0)
		return 1;

	return 0;
}

		
// operator < with node and char* 
bool operator < (const node  & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)<0)
		return 1;

	return 0;

}

// operator < with char * and node
bool operator < (char * temp, const node  & adding) 
{
	if (strcmp(temp, adding.base_food->get_name())<0)
		return 1;

	return 0;

}

// operator < wih node and node
bool operator < (const node & adding, const node & added) 
{
	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())<0)
		return 1;
	
	return 0;

}

// operator <= with node and char *
bool operator <= (const node & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)<=0)
		return 1;

	return 0;


}
		 
// operator <= with char * and node
bool operator <= (char * temp, const node  & adding) 
{
	if (strcmp(temp, adding.base_food->get_name())<=0)
		return 1;

	return 0;


}
		 
// operator <= with node and node 
bool operator <= (const node  & adding, const node & added) 
{
	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())<=0)
		return 1;
	
	return 0;


}

		 
//  operator > with node and char 
bool operator > (const node  & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)>0)
		return 1;

	return 0;


}

//operator > with char and node	
bool operator > (char * temp, const node  & adding) 
{

	if (strcmp(temp, adding.base_food->get_name())>0)
		return 1;

	return 0;

}
		 
//operator > with node and node 
bool operator > (const node  & adding, const node & added) 
{
	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())>0)
		return 1;
	
	return 0;


}

// operator >= with node and char		  
bool operator >= (const node  & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)<=0)
		return 1;

	return 0;


}

// operator >= with char and node
 bool operator >= (char * temp, const node  & adding)
{

	if (strcmp(temp, adding.base_food->get_name())<=0)
		return 1;

	return 0;

}
		 
// operator >= with node and node 
bool operator >= (const node  & adding, const node & added)
{

	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())<=0)
		return 1;
	
	return 0;

}

		 
// operator != with node and char 
bool operator != (const node  & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)==0)
		return 1;

	return 0;


}
		 
// operator != with temo and node 
bool operator != (char * temp, const node  & adding) 
{
	if (strcmp(temp, adding.base_food->get_name())==0)
		return 1;

	return 0;


}
		 
// operator != with node and node 
bool operator != (const node  & adding, const node & added) 
{
	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())==0)
		return 1;
	
	return 0;


}
	
		
// operator == with node and char 
bool operator == (const node  & adding, char * temp) 
{
	if (strcmp(adding.base_food->get_name(), temp)!=0)
		return 1;

	return 0;


}
		 
// operator == with char and noce 
bool operator == (char * temp, const node  & adding)
{
	if (strcmp(temp, adding.base_food->get_name())!=0)
		return 1;

	return 0;


}
		 
// operator == with node and node 
bool operator == (const node  & adding, const node & added) 
{
	if (strcmp(adding.base_food->get_name(), added.base_food->get_name())!=0)
		return 1;
	
	return 0;


}

// operaor =
node & node::operator = (const node & adding)
{
	base_food=adding.base_food;		

} 

// operator +
node node ::operator + (const node &) const
{

}

// operator +=
node & node::operator += (const node)
{

}


//-------------------------TREE--------------------------//

// tree constructor
tree::tree()
{
	root=NULL;

}

// copy constructo
tree::tree(const tree & source)
{
	if (source.root)
		root=source.root;
}

// destrucotr
tree::~tree()
{
	if (root)
		delete root;

}

//wrapper to add
int tree::add(node * temp, char * temp_char)
{

	add(root, temp, temp_char);

}

// recursiono add
int tree::add(node * & root, node * temp, char * temp_char)
{
	if (!root)
	{
		root= new node;
		//root->set_data(temp);
		root = temp;
		root->set_left(NULL);
		//root -=NULL;
		root->set_right(NULL);
		//root +=NULL;
		return 0;
	}



//	if( temp < root)
	if (root->compare(temp_char))
		add(root->get_left(), temp, temp_char);		


	else
		add(root->get_right(), temp, temp_char);



}

// wrapper to display
void tree::display() const
{
	display(root);

}

// recursion to display
void tree::display(node * root) const
{	
	if (!root)
		return ;

	display(root->get_left());	


	root->display();

	display(root->get_right());

}

//wrapper to find no dairy
int tree::find_nondairy()
{
	find_nondairy(root);
}
// recursion to find no dairy
int tree::find_nondairy(node * root)
{
	if (!root)
		return 0;

	find_nondairy(root->get_left());

	if(!root->get_dairy())
		root->display();
	
	find_nondairy(root->get_right());


}
// wrapper to find no meat
int tree::find_nomeat()
{
	find_nomeat(root);
}

// recursion to find no meat
int tree::find_nomeat(node * root)
{
	if (!root)
		return 0;

	find_nondairy(root->get_left());

	if(!root->get_meat())
		root->display();
	
	find_nondairy(root->get_right());

}

// wrapper to find no nuts
int tree::find_nonuts()
{
	find_nonuts(root);
}

// recursion to find no nuts
int tree::find_nonuts(node * root)
{
	if (!root)
		return 0;

	find_nondairy(root->get_left());

	if(!root->get_nuts())
		root->display();
	
	find_nondairy(root->get_right());

}

// wrapper to find no alcohol
int tree::find_nonalcohol()
{
	find_nonalcohol(root);
}

// recursion to find no alcohol
int tree::find_nonalcohol(node * root)
{
	if (!root)
		return 0;

	find_nondairy(root->get_left());

	if(!root->get_nuts())
		root->display();
	
	find_nondairy(root->get_right());

}

// wrapper to find name
int tree::find_name()
{
	char temp[100];


	cout<<"what is the name of the food item you're looking for?"<<endl;
	cin.get(temp, 100, '\n');
	cin.ignore(100, '\n');

	find_name(root, temp);
}

// recursion to find name
int tree::find_name(node * root, char * temp)
{
	if (!root)
		return 0;
	
	if(root->get_match(temp))
	{
		root->display();
		return 1;
	}

	if(root->compare(temp))
		find_nondairy(root->get_left());

	else	
		find_nondairy(root->get_right());
}

