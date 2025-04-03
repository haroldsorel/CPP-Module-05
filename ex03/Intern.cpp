/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:17:48 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/03 15:17:49 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern " << "created" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "Copy of Intern " << "created" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern " << "destroyed" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern " << "assigned to another" << std::endl;
    return *this;
}

AForm *createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *(*formCreators[3])(std::string) =  {createRobotomy, createPresidential, createShrubbery};
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return (NULL)
    ;
}

