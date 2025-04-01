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

class Form 
{
    private:
        const std::string   _name;
        int                 _signe;
        int                 _gradeToSign;
        int                 _gradeToExec;
    public:
        //constructors
        Form(std::string const name, int gradeToSign, int gradeToExec);
        Form(Form const & src);
        //destructor
        ~Form();
        //overloads
        Form & operator=(Form const &src);
        //getters
        std::string const getName()const;
        int getGradeToSign()const;
        int getGradeToExec()const;
        int getSigne()const;
        //methods
        void beSigned(Bureaucrat &bureaucrat);
        void beUnsigned();
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
        class FormAlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &os, Form const &a);
