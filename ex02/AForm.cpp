/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:37:36 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/01 19:37:37 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeToSign, int gradeToExec) : _name(name), _signe(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Form " << "created" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src.getName()), _signe(src.getSigne()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
    std::cout << "Copy of Form " << " created" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form " << " destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << "Form " << _name << " assigned to " << src.getName() << std::endl;
    if (this != &src)
        _signe = src.getSigne();
    return (*this);
}

std::string const AForm::getName() const
{
    return (this->_name);
}

int AForm::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
    return (this->_gradeToExec);
}

int AForm::getSigne() const
{
    return (this->_signe);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signe = 1;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Form is not signed");
}

void AForm::beUnsigned()
{
    this->_signe = 0;
}

std::ostream	&operator<<(std::ostream &os, AForm const &a)
{
    os << "name : " << a.getName() << ", grade to sign : " << a.getGradeToSign() << ", grade to exec : " << a.getGradeToExec() << ", signed : " << a.getSigne();
    return (os);
}