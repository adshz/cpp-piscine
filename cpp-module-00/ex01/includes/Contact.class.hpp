#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>

class Contact {
    public:
        Contact(void);
        ~Contact(void);

        bool            setFirstName(std::string str);
        bool            setLastName(std::string str);
        bool            setNickname(std::string str);
        bool            setPhoneNumber(std::string const str);
        bool            setSecret(std::string const str);
        bool            displayDetails(void) const;
        bool            isEmpty(void) const;
        std::string const       getFirstName(void) const ;
        std::string const       getLastName(void) const ;
        std::string const       getNickname(void) const ;
        std::string const       getPhoneNumber(void) const ;
        std::string const       getSecret(void) const;
    
    private:
        std::string     _firstName;
        std::string     _lastName;
        std::string     _nickname;
        std::string     _phoneNumber;
        std::string     _secret;
        bool            _onlyAlpha(std::string const str);
        bool            _onlyDigits(std::string const nbr);
        bool            _setName(std::string str, std::string &target);
};

#endif