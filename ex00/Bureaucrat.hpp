/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:57:25 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/25 15:57:28 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        //constructors
        Bureaucrat(void);
        Bureaucrat(std::string const name);
        Bureaucrat(int grade);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const & src);
        //destructor
        ~Bureaucrat();
        //overloads
        Bureaucrat & operator=(Bureaucrat const &src);
        //getters
        std::string const getName()const;
        int getGrade()const;
        //methods
        void incrementGrade();
        void decrementGrade();
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

};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &a);