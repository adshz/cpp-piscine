/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:58:19 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:58:20 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
  Dog(void);
  Dog(Dog const &src);
  ~Dog(void);

  Dog &operator=(Dog const &src);

  Brain *getBrain(void) const;
  void makeSound(void) const;

private:
  Brain *_brain;
};
