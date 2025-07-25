/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:55:05 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:55:08 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

void testWrong(void) {
  std::cout << "============= Wrong Animal/Cat tests ============="
            << std::endl;
  {
    std::cout << "============= WrongAnimal =============" << std::endl;
    const WrongAnimal *animal = new WrongAnimal();
    std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
    animal->makeSound();
    delete animal;
    std::cout << std::endl;
  }
  {
    std::cout << "============= WrongCat by WrongCat class ============="
              << std::endl;
    const WrongCat *cat = new WrongCat();
    std::cout << "WrongCat type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
  }
  {
    std::cout << "============= WrongCat by WrongAnimal parent class"
              << std::endl;
    const WrongAnimal *cat = new WrongCat();
    std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
  }
  //   {
  //     const WrongCat *cat = new WrongAnimal();
  //     cat->makeSound();
  //     delete cat;
  //   }
}

void testCorrect(void) {
  std::cout << "============= Correct Animal Cat Dog tests ============="
            << std::endl;
  {
    std::cout << "============= Animal =============" << std::endl;
    const Animal *animal = new Animal();
    std::cout << "Animal type: " << animal->getType() << std::endl;
    animal->makeSound();
    delete animal;
    std::cout << std::endl;
  }
  {
    std::cout << "============= Cat by cat class =============" << std::endl;
    const Cat *cat = new Cat();
    std::cout << "Cat type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
  }
  {
    std::cout << "============= Cat by animal parent class ============="
              << std::endl;
    const Animal *cat = new Cat();
    std::cout << "Animal type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << std::endl;
  }
  {
    std::cout << "============= Dog by dog class =============" << std::endl;
    const Dog *dog = new Dog();
    std::cout << "Dog type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;
    std::cout << std::endl;
  }
  {
    std::cout << "============= Dog by animal parent class ============="
              << std::endl;
    const Animal *dog = new Dog();
    std::cout << "Animal type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;
    std::cout << std::endl;
  }
}

void testSubject(void) {
  std::cout << "--- Subject tests" << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();
  delete j;
  delete i;
  delete meta;
  std::cout << std::endl;
}

int main(void) {
  testWrong();
  testCorrect();
  testSubject();
  return (0);
}
