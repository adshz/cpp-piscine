#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "Contact.class.hpp"

class PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        std::string trim(std::string str);
        bool        add(void);
        bool        search(void);
        void        display(void) const;

    private:
        struct ContactField {
            std::string prompt;
            bool (Contact::*setter)(const std::string);
        };
        Contact     _contacts[8];
        int         _index;
        bool        _stop;
        void        _incrementIndex(void);
        std::string	_getInput(std::string const input);
        bool        _displayOneContact(std::string const input ) const;
        void        _displayRow(int i) const;
        void        _displayCell(std::string str) const;
        bool        _setContactField(const ContactField& field);
};

#endif