## Questions from my practice/no-help coding

### question 1 - Are `const` in return type with different positions same regardlessly?
```cpp
std::string const& getName(void) const;
```

and 
```cpp
const std::string& getName(void) const;
```

### question 2 - Please give me feedback on my understanding and answer my
confusion

It is interesting to see the old code I wrote months ago (Maybe I was
copying from someone else), the return type of `int getGrade(void) const`
doesn't have `const` whereas the return type of `const std::string&
Bureaucrat::GetName(void) const { return (this->_name);}` had one but I
changed(well you can read /home/szhong/code/cpp/cpp-learn/cpp05/ex01/sources/Bureaucrat.cpp:66)

My reason to use just `std::string getName(void) const;` is because 
```cpp
std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}
```
if we return the reference without `const` this means we return an alias of `this->_name`
a reference is not a variable because it doesn't have its own memory address as
pointer. So we can say a variable `theName` from 

```cpp
Bureaucrat b();
const std::string theName =  b.getname();
```

`theName` is actually accessing the private member variable of the class
Bureaucrat. Even if, as of writing this question led me to a more clear thought
that as long as you write `const std::string& Bureaucrat::getName(void) const`
will work fine because we need to use `const` to qualifier a variable like we
did in `const std::string theName = b.getName();` but a quick question if we
have `std::string noConstName = b.getName();` would the compiler compalin?

`const std::string theName = b.getName(); ` where `const std::string&
Bureaucrat::getName(void) const;` works fine as explained previously, it defeats
the purpose of design a class to have private scopes and public scopes. At least
that is what I think. 


### question 3: Please provide a better explanation than mine one.

Initially I didn't get the point that we have `void signForm(AForm& form) const;` from `ex02`

/home/szhong/code/cpp-piscine/module-05/ex02/
```cpp
void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< RED 
					<< this->_name 
					<< " couldn't sign " << form.getName()
					<< " because " 
					<< e.what() 
					<< RESET
					<< std::endl;
	}
}

``` as compared to /home/szhong/code/cpp-piscine/module-05/ex01 
```cpp
void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout	<< GREEN 
					<< *this 
					<< " signed " 
					<< form 
					<< RESET 
					<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout	<< RED 
					<< *this 
					<< " couldn't sign " 
					<< form 
					<< " because: " 
					<< e.what()
					<< RESET
					<< std::endl;
	}
}
```
Functionally they are almost identical except the `Form` class became an
abstract class in `ex02/` ; I guess the Cpp piscine at 42 tried to help us
understand the difference between a normal class and an abstract class. However,
I mostly certainly lost the context and forgot about the big picture.

I think the ex02/ mainly introduced the feature of C++98 Polymophrism. 
You are wellcome to draw the ascii art for how AForm is related to other derived
classes.

### question 4 -  How can I encode these two concepts?

How does this implementation relate to what I know?
I saw in the class declaration header file

```cpp
Class GradeTooHighException: public std::exception {
public:
    virtual const char* what(void) const throw();
};
```

I was confused to see this connection between
using `virtual` and pure `virtual`

as of writing down my thought process. I suddenly know the difference
when you write a virtual function is it means this allowed to be overwritten.

but I wanted to know more about throw()
How does this work?

#### question 5 - Does this mean `std::exception` is
a base class ?  I wanted to read the source code where?


### question 6 - I saw int const _grade then I know it is the same as const int _grade but I have question Does it mean you cant change the type but you can reassign?  or both you can reassign and change the return type?


### question 7 - Are they the same `std::string const &` and `const std::string &`? 

### question 8 - Ok, what is `protected` keyword and why do we need it?

### question 9  
initially I was confused about seeing no pure virtual function until protected:

### question 10 

I have a question about
why we only make destructor
as a virtual but not
constructor?
I guess it was because
of the compiler as it mostly
would complain about that
but I wanted to know why


### question 11

I got that
`ShrubberyCreationForm`
isn't an abstract class
so it doesn't need `virtual`

but the declaration

`void executeAction(void) const;`

almost identical though ,so I lost the purpose of doing this so?
maybe again I lost the context and didn't understand why we do what we do with 
`void executeAction(void) const;`

### question 12 - How could I know/solve unsolved problems?

The Context:
Now I can see the picture between
Bureaucrat and Form
they interact with each
other via
- signForm
- executeForm

because I saw the solution now. however, my question how
could I build this solution from the subject/brief that is usually vague and
abstract?

because right now I know
it because I looked at
the solution and then
Aha moment. I would discount that. I was wondering about where
I was blocked and how could I unblock?

I understand I may just restrict myself and being hard on myself.
so from now on I would take this as one of case study and commit them to my long
term memory. so I can take this out when I need it. but I would like to hear
from you.

### question 13 - can we  modify the private member variable
when the function is called and return type is a reference

ok I use this example

```cpp

std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}
```

my confusion is that because function call is completed when 
it reaches `}` the function `b.getName()` disappears from the function call
stack ( I don't know if "function call stack" is a right term, please correct me)

because return statement would perform copy by value, so the reference is
actually not the private member but the copy of a private member variable?

#### irrelevant note to this question 13
to be honest, I wanted to know about this above, I realised I didn't consider `const` + `&`
I believe question 2 somehow lurked in the back of my mind; I figureed out I
missed either `const` or `&` until I tried to apply `const std::string theName =
b.getName();` because you have `const` to restrict the variable, so even it is
directly accessing the private member variable, it is cool. 

### question 14 is overloading functions as one of features different between C
and C++98

I think the code in
ex01/Bureaucrat.cpp
Maybe I did it wrong
back in days. But I can't recognise the reasons for these two function
definition
why they should exist?
void Bureaucrat::incrementGrade(void)
void Bureaucrat::incrementGrade(int i)

my explanation is that c++ compiler can recognise what functions I am using

```cpp

// Bureaucrat.cpp
void Bureaucrat::incrementGrade(void)
void Bureaucrat::incrementGrade(int i)

// main.cpp
Buraucrat b();
Buraucrat c();

b.incrementGrade();
c.incrementGrade(10);
```

it would automatically call respective function, however in C you cannot do so?

### question 15 - what headers do we need to when use
try { }
catch { }

### question 16 - Initialization list or function body, which should occur first?

considering the following code,
```cpp

//Parameterised constructor
Bureaucrat::Bureaucrat ( const std::string & name, int grade) 
    : _name(name)
    ,_grade(Bureaucrat::lowestGrade)

{
if (grade < Bureaucrat::highestGrade)
    throw (Bureaucrat::GradeTooHighException());
else if (grade > Bureaucrat::lowestGrade)
    throw (Bureaucrat::GradeTooLowException())
}
```

Because from my previous knowledge I know if
the initialization list would be the first to be done by the compiler
but what if the grade we passed in are not satisfy the condition check via if -
else statement. and we did throw the error 

does mean those variables would be clean out?


### question 17 - 

I was wondering about how we could use `e.what()` and why `e.what()` could use
the messsage I overwrite? 

the first thing I know is that from the header file we have this definition

see 
```cpp

Class GradeTooHighException : public std::exception {
public:
    virtual const char* what(void) const throw()
};
```
I believe this is quite basic but I wanted to know how to use e.what() basic

### question 18 - two ways of using throw? any other features like this in
C++98?


You can throw like this
if (this->_grade + i > Bureaucrat::lowestGrade)
    return ( throw (Bureaucrat::GradeTooLowException()))

You can also do the same
if (gradeToSign > 150) || gradeToExecute > 150)
    throw Form::GradeTooLowException

### question 19 - why do we need to use try/catch and when do we use them?

I discovered the reason why we are using `try/catch` because 
interaction between the two classes (objects) are easier to lead to unexpected errors?
but I am not sure about why and how and when.

I wanted to cultivate an ability

like parking a car,

you know when you need to park your car in a parallel way or reverse way.

### question 20 - 

I checked the answer
from cpp/cpp-learn/cpp05/sources/Bureaucrat.cpp

```cpp
Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat name/grade constructor called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}
```

why do we need `else this->_grade=grade;`

or would that be an issue for removing else?

```cpp

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat name/grade constructor called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade = grade;
	return ;
}
```

my logic is simple, if we can pass if and else if
then we can just safely to do the next step

but in the past I have some trauma about removing else in a situation similiar
to this and it led to a bug. 


### question 21 - initialisation list

```cpp
Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "Bureaucrat name/grade constructor called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}
```

so we have `_grade(Bureaucrat::lowestGrade)`

then we also have this `this->_grade = grade`
but why should we use `_grade(Bureaucrat::lowestGrade)`

is it the compiler would initialise some garabge values to the private member
variable?

#### irrelevant note

To be honest, as of writing this document to this point, I realised I learned a
new thing.

I was confused about `grade` and `_grade`, because I did not think of them in
terms of scope.

`_grade` is belonging to the class, `grade` is what users passed through.

they are not the same but I did think this is quite muddy in C++98,
so I would need you to help me reconstruct a better mental model
because I suspected i was still unskillful about this.

### question 22 - so now I think I can build a memory palace for the final
exercise to make this cpp05 as one of my go to recall

my plan is to chunk these concepts together, then I can build a memory palace
based on school. place them one by one. 

1 days
3 days
5 days etc

but i don't know if this seems extreme or silly but I think it is good for me to
consolidate what I learned etc. 

