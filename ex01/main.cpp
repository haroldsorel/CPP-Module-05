/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haroldsorel <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:57:33 by haroldsorel       #+#    #+#             */
/*   Updated: 2025/02/25 15:57:34 by haroldsorel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "Construction" << std::endl;
    std::cout << "------------" << std::endl;
    //burrocrats
    Bureaucrat John("John", 1);
    Bureaucrat Jack("Jack", 150);
    Bureaucrat Joe("Joe", 34);
    //invalid forms
    try {Form TooLow("TooLow", 151, 20);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Form TooLow("TooLow", 20, 151);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Form TooLow("TooLow", 151, 151);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Form TooHigh("TooHigh", 67, 0);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Form TooHigh("TooHigh", 0, 67);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {Form TooHigh("TooHigh", 0, 0);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    //valid forms
    Form mergeForm("Merge Form", 1, 1);
    Form climateForm("Climate Form", 36, 10);
    Form ToiletForm("Toilet Form", 150, 150);
    std::cout << std::endl;

    std::cout << "Forms Info" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << mergeForm << std::endl;
    std::cout << climateForm << std::endl;
    std::cout << ToiletForm << std::endl;
    std::cout << std::endl;

    std::cout << "Signing Documents" << std::endl;
    std::cout << "-----------" << std::endl;
    //burrocrats signing forms
    John.signForm(mergeForm);
    Jack.signForm(mergeForm);
    Joe.signForm(mergeForm);
    std::cout << mergeForm << std::endl;
    John.signForm(climateForm);;
    Jack.signForm(climateForm);
    Joe.signForm(climateForm);
    std::cout << climateForm << std::endl;
    John.signForm(ToiletForm);
    Jack.signForm(ToiletForm);
    Joe.signForm(ToiletForm);
    std::cout << ToiletForm << std::endl;
    //forms getting unsigned
    mergeForm.beUnsigned();
    climateForm.beUnsigned();
    ToiletForm.beUnsigned();
    //forms getting signed by burrocrats
    try {mergeForm.beSigned(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {mergeForm.beSigned(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {mergeForm.beSigned(Joe);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << mergeForm << std::endl;
    try {climateForm.beSigned(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {climateForm.beSigned(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {climateForm.beSigned(Joe);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << climateForm << std::endl;
    try {ToiletForm.beSigned(John);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {ToiletForm.beSigned(Jack);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try {ToiletForm.beSigned(Joe);} catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << ToiletForm << std::endl;
    std::cout << std::endl;

    std::cout << "Destroying" << std::endl;
    std::cout << "-----------" << std::endl;
    return (0);
}
