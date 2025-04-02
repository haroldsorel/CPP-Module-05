/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:03:41 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/02 14:03:42 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    std::cout << "Bureaucrat Construction" << std::endl;
    std::cout << "------------" << std::endl;
    Bureaucrat Jim("Jim", 137);
    Bureaucrat John("John", 45);
    Bureaucrat Jack("Jack", 5);
    std::cout << std::endl;
    std::cout << "Forms Construction" << std::endl;
    std::cout << "------------" << std::endl;
    ShrubberyCreationForm Shrubbery("file");
    RobotomyRequestForm Robotomy("Frankenstein");
    PresidentialPardonForm Presidential("Michael Scofield");
    std::cout << std::endl;

    std::cout << "Forms Info" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << Shrubbery << std::endl;
    std::cout << Robotomy << std::endl;
    std::cout << Presidential << std::endl;
    std::cout << std::endl;

    std::cout << "Executing Documents Failure" << std::endl;
    std::cout << "-----------" << std::endl;
    Jim.executeForm(Shrubbery);
    Jim.executeForm(Robotomy);
    Jim.executeForm(Presidential);
    std::cout << std::endl;

    std::cout << "Signing Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    Jim.signForm(Shrubbery);
    Jim.signForm(Robotomy);
    Jim.signForm(Presidential);
    John.signForm(Shrubbery);
    John.signForm(Robotomy);
    John.signForm(Presidential);
    Jack.signForm(Shrubbery);
    Jack.signForm(Robotomy);
    Jack.signForm(Presidential);
    std::cout << std::endl;

    std::cout << "Executing Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    Jim.executeForm(Shrubbery);
    Jim.executeForm(Robotomy);
    Jim.executeForm(Presidential);
    John.executeForm(Shrubbery);
    John.executeForm(Robotomy);
    John.executeForm(Presidential);
    Jack.executeForm(Shrubbery);
    Jack.executeForm(Robotomy);
    Jack.executeForm(Presidential);
    std::cout << std::endl;

    std::cout << "Unsigning Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    Shrubbery.beUnsigned();
    Robotomy.beUnsigned();
    Presidential.beUnsigned();
    std::cout << std::endl;

    std::cout << "Executing Documents Failure" << std::endl;
    std::cout << "-----------" << std::endl;
    try {Shrubbery.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Shrubbery.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Shrubbery.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << "Signing Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    Jim.signForm(Shrubbery);
    Jim.signForm(Robotomy);
    Jim.signForm(Presidential);
    John.signForm(Shrubbery);
    John.signForm(Robotomy);
    John.signForm(Presidential);
    Jack.signForm(Shrubbery);
    Jack.signForm(Robotomy);
    Jack.signForm(Presidential);
    std::cout << std::endl;

    std::cout << "Executing Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    try {Shrubbery.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Shrubbery.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Shrubbery.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Robotomy.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(Jim);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Presidential.execute(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    std::cout << "Destruction" << std::endl;
    std::cout << "-----------" << std::endl;
    return (0);
}