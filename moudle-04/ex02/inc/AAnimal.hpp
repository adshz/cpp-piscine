/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:57:47 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:57:49 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <string>

class AAnimal {
public:
  AAnimal(void);
  AAnimal(AAnimal const &src);
  virtual ~AAnimal(void);

  AAnimal &operator=(AAnimal const &src);

  virtual void makeSound(void) const;

protected:
  std::string _type;
};
