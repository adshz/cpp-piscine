#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void): _index(-1), _stop(false) {
    return ;
}

PhoneBook::~PhoneBook(void) {
    return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

std::string    PhoneBook::trim(std::string str) {
    std::string blank = " \t\n\r\v\f";
    size_t      start;
    size_t      end;

    start = str.find_first_not_of(blank);
    end = str.find_last_not_of(blank);
    if (start == end)
        return (str);
    return (str.substr(start, end - start + 1));
}

bool    PhoneBook::add(void) {
    std::string input;

    _incrementIndex();
    std::cout << std::endl << "------------ Adding a New Contact (Enter Details Below) -------------" << std::endl << std::endl;
    ContactField fields[] = {
        {"a first name", &Contact::setFirstName},
        {"a last name", &Contact::setLastName},
        {"a nickname", &Contact::setNickname},
        {"a phone number", &Contact::setPhoneNumber},
        {"a darkest secret", &Contact::setSecret}
    };
    
    for (size_t i = 0 ; i < 5 ; i++) {
        if (!_setContactField(fields[i])) {
            _stop = false;
            return (false);
        }
    }
    std::cout << std::endl << "------------------------------------------------------" << std::endl;
    std::cout << "\033[0;92m""Contact saved successfully." "\033[0;39m" << std::endl << std::endl << std::endl;
    return (true);
}

bool    PhoneBook::search(void) {
    std::string input;

    if (_index == -1) {
		std::cout << "No contacts in record. Please add a contact first." << std::endl << std::endl << std::endl;
		return (true);
	}
    std::cout << std::endl << "------------ Search Contacts (Enter Index to View) -------------" << std::endl << std::endl;
    this->display();
    input = _getInput("Please enter index of the contact list");
    if (input.empty())
        return (false);
    this->_displayOneContact((std::string const)input);
    return (true);
}



/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void    PhoneBook::_incrementIndex(void) {
    _index++;
    if (_index > 7) {
        _index = 0;
    }
}

std::string PhoneBook::_getInput(std::string const prompt) {
    std::string input;

    std::cout << "\nPlease enter " << prompt << ": " << std::endl << "> ";
    if (!std::getline(std::cin, input) || std::cin.eof()) {
        _stop = true;
        std::cout << std::endl;
        return (std::string());
    }
    input = trim(input);
    return (input);
}

bool    PhoneBook::_displayOneContact(std::string const input ) const {
    int index;

    if (input.length() == 1 && std::isdigit(input[0])) {
        index = input[0] - '0';
        if (index >= 0 && index < 8) {
            if (this->_contacts[index].displayDetails())
                return (true);
            else {
                std::cout << "Error: No record at index " << index << "Please ADD a contact and try again" << std::endl;
                return (false);
            }
        }
    }
    std::cout << "Error: \'" << input <<"' is not a valid index (range from 0 to 7). Please try again." << std::endl;
    return (false);
}

void    PhoneBook::display(void ) const {
    std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		_displayRow(i);
	}
	std::cout << std::endl;
	return ;
}

void    PhoneBook::_displayRow(int i) const {
    if (this->_contacts[i].isEmpty())
		return ;
    std::cout << "|" << std::setw(10) << i << "|";
    _displayCell(this->_contacts[i].getFirstName());
	_displayCell(this->_contacts[i].getLastName());
	_displayCell(this->_contacts[i].getNickname());
	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	return ;
}

void    PhoneBook::_displayCell(std::string str) const {
    if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

bool    PhoneBook::_setContactField(const ContactField& field) {
    std::string input;

    while (!_stop) {
        input = _getInput(field.prompt);
        if (_stop || (this->_contacts[_index].*(field.setter))(input))
            break ;
    }
    return !_stop;
}
