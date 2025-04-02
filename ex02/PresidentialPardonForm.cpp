/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:04:06 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/02 14:04:08 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Creation Form", 25, 5), _target(target)
{
    std::cout << "Presidential Creation Form " << "created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), _target(src._target)
{
    std::cout << "Copy of Presidential Creation Form " << "created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Creation Form " << "destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    std::cout << "Presidential Creation Form " << "assigned to " << src.getName() << std::endl;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    if (this->getSigne() == 0)
        throw AForm::FormNotSigned();
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    std::cout << std::endl << "----------------" << std::endl;
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    std::cout << "----------------" << std::endl << std::endl;
}