/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:56:10 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:56:12 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include <string>

class Brain {
public:
  Brain(void);
  Brain(Brain const &src);
  ~Brain(void);

  Brain &operator=(Brain const &src);

  std::string const &getIdea(int index) const;
  void setIdea(int index, std::string const &idea);

  static int const nb_ideas = 100;

private:
  std::string _ideas[nb_ideas];
};
