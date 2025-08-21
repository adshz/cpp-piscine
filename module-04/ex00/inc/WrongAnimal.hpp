/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:54:06 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:54:07 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(WrongAnimal const &src);
  WrongAnimal(std::string const &type);
  virtual ~WrongAnimal(void);

  WrongAnimal &operator=(WrongAnimal const &src);

  std::string const &getType(void) const;
  void makeSound(void) const;

protected:
  std::string _type;
};
