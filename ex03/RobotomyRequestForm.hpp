/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:04:23 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/04/02 14:04:24 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const _target;
    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm & operator=(RobotomyRequestForm const &src);
        void execute(Bureaucrat const & executor)const;
};

