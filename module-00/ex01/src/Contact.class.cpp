
#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void): _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _secret("") {
    return ;
}

Contact::~Contact(void) {
    return ;
}
/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/



// bool    Contact::setLastName(std::string str) {
//     if (str.empty())
//         return (false);
//     else if (!_onlyAlpha(str)) {
//         std::cout << "Error: Names can only contains alphabetical letters, spaces and hyphens" << std::endl;
//         return (false);
//     }
//     for (std::string::iterator iter = str.begin(); iter != str.end(); iter++) {
//         *it = std::toupper(*it);
//     }
//     return (true); 
// }

bool    Contact::isEmpty(void) const{
    if (this->_firstName.empty()|| 
        this->_lastName.empty() || 
        this->_nickname.empty() || 
        this->_phoneNumber.empty() || 
        this->_secret.empty())
        return (true);
    return (false);
}

bool    Contact::displayDetails(void) const {
    if (this->isEmpty())
        return (false);
    std::cout	<< "+ First name\t: "	<< this->getFirstName()	<< std::endl
				<< "+ Last name\t: "	<< this->getLastName()	<< std::endl
				<< "+ Nickname\t: "		<< this->getNickname()	<< std::endl
				<< "+ Phone number\t: "	<< this->getPhoneNumber() 	<< std::endl
				<< "+ Darkest secret: "	<< this->getSecret()	<< std::endl;
    return (true);
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
bool Contact::setFirstName(std::string str) {
        return _setName(str, this->_firstName); 
}

bool Contact::setLastName(std::string str) {
        return _setName(str, this->_lastName); 
}

bool Contact::setNickname(std::string str) {
        return _setName(str, this->_nickname); 
}

bool Contact::setPhoneNumber(std::string nbr) {
      if (nbr.empty())
        return (false);
    else if (!(this->_onlyDigits(nbr))) {
        std::cout << "Error: Only digits (0-9), spaces and hyphens." << std::endl;
        return (false);
    }
    this->_phoneNumber = nbr;
    return (true);
}

bool	Contact::setSecret(std::string const str) {
	if (str.empty()) {
		return (false);
	}
	this->_secret = str;
	return (true);
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

std::string const   Contact::getFirstName(void) const {
    return (this->_firstName);
}

std::string const   Contact::getLastName(void) const {
    return (this->_lastName);
}

std::string const   Contact::getNickname(void) const {
    return (this->_nickname);
}

std::string const   Contact::getPhoneNumber(void) const {
    return (this->_phoneNumber);
}

std::string const	Contact::getSecret(void) const {
	return (this->_secret);
}


/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/


bool    Contact::_setName(std::string str, std::string &target) {
    if (str.empty())
        return (false);
    else if (!_onlyAlpha(str)) {
        std::cout << "Error: Names can only contains alphabetical letters, spaces and hyphens" << std::endl;
        return (false);
    }
    str[0] = std::toupper(str[0]);
    target = str;
    return (true);
}

bool    Contact::_onlyAlpha(std::string const str) {
    for (std::string::const_iterator iter = str.begin(); iter != str.end(); iter++) {
        if (!std::isalpha(*iter) && *iter != ' ' && *iter != '-')
            return (false);
    }
    return (true);
}

bool    Contact::_onlyDigits(std::string const nbr) {
    for (std::string::const_iterator iter = nbr.begin(); iter != nbr.end(); iter++) {
        if (!std::isdigit(*iter) && *iter != ' ' && *iter != '-')
            return (false);
    }
    return (true);
}