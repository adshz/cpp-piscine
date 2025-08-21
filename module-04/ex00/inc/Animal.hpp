/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:53:19 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:53:21 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <string>

class Animal {
public:
  Animal(void);
  Animal(Animal const &src);
  Animal(std::string const &type);
  virtual ~Animal(void);

  Animal &operator=(Animal const &src);

  std::string const &getType(void) const;
  virtual void makeSound(void) const;

protected:
  std::string _type;
};
