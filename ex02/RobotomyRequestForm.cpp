/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:04:15 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/02 14:04:16 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Creation Form", 72, 45), _target(target)
{
    std::cout << "Presidential Creation Form " << "created"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()), _target(src._target)
{
    std::cout << "Copy of Robotomy Creation Form " << "created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Creation Form " << "destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    std::cout << "Robotomy Creation Form " << "assigned to " << src.getName() << std::endl;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
    if (this->getSigne() == 0)
        throw AForm::FormNotSigned();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << std::endl << "----------------" << std::endl;
        std::cout << "*VRRRRRRRRRRRRRRRRRRRRRRR*" << std::endl;
        if (std::rand() % 2)
            std::cout << this->_target << " has been robotomized" << std::endl;
        else
            std::cout << "Robotomization failed" << std::endl;
        std::cout << "----------------" << std::endl << std::endl;
    }
}