/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:37:43 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/01 19:37:44 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
        const std::string   _name;
        int                 _signe;
        const int                 _gradeToSign;
        const int                 _gradeToExec;
    public:
        //constructors
        AForm(std::string const name, int gradeToSign, int gradeToExec);
        AForm(AForm const & src);
        //destructor
        virtual ~AForm();
        //overloads
        AForm & operator=(AForm const &src);
        //getters
        std::string const getName()const;
        int getGradeToSign()const;
        int getGradeToExec()const;
        int getSigne()const;
        //methods
        void beSigned(Bureaucrat &bureaucrat);
        void beUnsigned();
        virtual void execute(Bureaucrat const & executor)const = 0;
        //exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &os, AForm const &a);
