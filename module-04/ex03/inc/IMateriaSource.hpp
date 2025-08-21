/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:01:12 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:01:13 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
  virtual ~IMateriaSource(void) {}

  virtual void learnMateria(AMateria *newMateria) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};
