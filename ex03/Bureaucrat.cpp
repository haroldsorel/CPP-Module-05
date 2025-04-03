/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucart.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:57:20 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/25 15:57:21 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
    std::cout << "Bureaucrat " << "Default" << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name): _name(name), _grade(150)
{
    std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Default"), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << "Default" << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName()), _grade(src.getGrade())
{
    std::cout << "Copy of Bureaucrat " << src.getName() << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
} 

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    std::cout << "Bureaucrat " << _name << " assigned to " << src.getName() << std::endl;
    if (this != &src)
        _grade = src.getGrade();
    return *this;
}

std::string const Bureaucrat::getName()const
{
    return (this->_name);
}

int Bureaucrat::getGrade()const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << this->_name << " was promoted!" << std::endl;
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->_name << " was demoted!" << std::endl;
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    if (this->_grade > form.getGradeToSign())
        std::cout << this->_name << " couldn't sign " << form.getName() << " because his grade is too low" << std::endl;
    else
    {
        std::cout << this->_name << " signed " << form.getName() << std::endl;
        form.beSigned(*this);
    }
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getSigne() == 0)
        std::cout << this->_name << " couldn't execute " << form.getName() << " because the form is not signed" << std::endl;
    else if (this->_grade > form.getGradeToExec())
        std::cout << this->_name << " couldn't execute " << form.getName() << " because his grade is too low" << std::endl;
    else
    {
        std::cout << this->_name << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &a)
{
	os << a.getName() << ", bureaucrat grade " << a.getGrade();
	return (os);    
}