/*
** EPITECH PROJECT, 2023
** parser
** File description:
** parser
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <exception>
#include "../GRAPHICAL/graphical.hpp"

class MyException : public std::exception
{
    public:
        MyException(const std::string& message) : m_message(message) {}

        const char* what() const noexcept override
        {
            return m_message.c_str();
        }

    private:
        std::string m_message;
};


class Parser {
    private:
 
    public:

        Parser();
        ~Parser();
        void myParser(const std::string &request, Graphical *graphical);
        void interpretType(std::vector<std::string> parsedRequest);
        // void interpretSpecialType(const std::vector<std::string>& parsedRequest, int mult);

        void myBasicParser(const std::string &request, Graphical *graphical);

        void mszCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void bctCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void tnaCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pnwCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void ppoCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void plvCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pinCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pexCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pbcCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void picCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pieCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pfkCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pdrCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pgtCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void pdiCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void enwCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void eboCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void ediCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void sgtCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void sstCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void segCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void smgCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void sucCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void sbpCMD(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
        void execAllBasicCmd(std::vector<std::string> parsedRequest, Graphical *graphical, int opt);
};

