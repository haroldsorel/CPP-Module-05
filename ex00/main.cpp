/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:57:33 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/25 15:57:34 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Construction" << std::endl;
    std::cout << "------------" << std::endl;
    Bureaucrat Default;
    Bureaucrat Jim("Jim");
    Bureaucrat John("John", 1);
    Bureaucrat Jack("Jack", 34);
    Bureaucrat Jack_copy(Jack);
    try {Bureaucrat("Bob", 0);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Bureaucrat("Bobette", 151);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << "Grades Before Increment" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << Default << std::endl;
    std::cout << Jim << std::endl;
    std::cout << John << std::endl;
    std::cout << Jack << std::endl;
    std::cout << Jack_copy << std::endl;
    std::cout << std::endl;

    std::cout << "Increment grade" << std::endl;
    std::cout << "---------------" << std::endl;
    try {Default.incrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {John.incrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Jack.incrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Jack_copy.incrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << "Grades After Increment" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << Default << std::endl;
    std::cout << Jim << std::endl;
    std::cout << John << std::endl;
    std::cout << Jack << std::endl;
    std::cout << Jack_copy << std::endl;
    std::cout << std::endl;

    std::cout << "Grades Before Decrement" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << Default << std::endl;
    std::cout << Jim << std::endl;
    std::cout << John << std::endl;
    std::cout << Jack << std::endl;
    std::cout << Jack_copy << std::endl;
    std::cout << std::endl;

    std::cout << "Decrement grade" << std::endl;
    std::cout << "---------------" << std::endl;
    try {Default.decrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Jim.decrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {John.decrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Jack.decrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Jack_copy.decrementGrade();} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << "Grades After Decrement" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << Default << std::endl;
    std::cout << Jim << std::endl;
    std::cout << John << std::endl;
    std::cout << Jack << std::endl;
    std::cout << Jack_copy << std::endl;
    std::cout << std::endl;

    std::cout << "Destroying" << std::endl;
    std::cout << "-----------" << std::endl;
    return (0);
}
