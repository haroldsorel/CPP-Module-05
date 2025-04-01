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

#include "Form.hpp"

Form::Form(std::string const name, int gradeToSign, int gradeToExec) : _name(name), _signe(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << name << " created" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _signe(src.getSigne()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
    std::cout << "Copy of Form " << src.getName() << " created" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &src)
{
    std::cout << "Form " << _name << " assigned to " << src.getName() << std::endl;
    if (this != &src)
    {
        _signe = src.getSigne();
        _gradeToSign = src.getGradeToSign();
        _gradeToExec = src.getGradeToExec();
    }
    return (*this);
}

std::string const Form::getName() const
{
    return (this->_name);
}

int Form::getGradeToSign() const
{
    return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
    return (this->_gradeToExec);
}

int Form::getSigne() const
{
    return (this->_signe);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signe = 1;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Form::beUnsigned()
{
    this->_signe = 0;
}

std::ostream	&operator<<(std::ostream &os, Form const &a)
{
    os << "name : " << a.getName() << ", grade to sign : " << a.getGradeToSign() << ", grade to exec : " << a.getGradeToExec() << ", signed : " << a.getSigne();
    return (os);
}