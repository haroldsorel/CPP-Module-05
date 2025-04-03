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
#include "Intern.hpp"

int main()
{
    std::cout << "Intern creation" << std::endl;
    std::cout << "----------------" << std::endl;
    Intern  someRandomIntern;
    AForm   *createdForm;
    std::cout << std::endl;

    std::cout << "Intern creates forms" << std::endl;
    std::cout << "---------------------" << std::endl;
    createdForm = someRandomIntern.makeForm("robotomy request", "Bender");
    delete createdForm;
    std::cout << std::endl;
    createdForm = someRandomIntern.makeForm("shrubbery creation", "Bender");
    delete createdForm;
    std::cout << std::endl;
    createdForm = someRandomIntern.makeForm("presidential pardon", "Bender");
    delete createdForm;
    std::cout << std::endl;
    createdForm = someRandomIntern.makeForm("unknown form", "Bender");
    return (0);
}