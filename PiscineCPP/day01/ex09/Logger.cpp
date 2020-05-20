/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:43:59 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 01:44:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(void) {
    std::cout << "Constructor called!" << std::endl;
}

Logger::~Logger(void) {
    std::cout << "Destructor called!" << std::endl;
}

void Logger::log(std::string const & dest, std::string const & message) {
    void (Logger::*ptr[])(std::string const & str) =
    {
        &Logger::_logToConsole,
        &Logger::_logToFile
    };

    std::string commands[] = {
        "Console",
        "File",
    };

    for (int i = 0; i < 2; i++) {
        if (commands[i] == dest) {
            (this->*ptr[i])(this->makeLogEntry(message));
            break;
        }
    }
}

void Logger::_logToConsole(std::string const & str) {
    std::cout << str << std::endl;
}

void Logger::_logToFile(std::string const & str) {
    std::ofstream ofs;

    ofs.open("Logger", std::ios_base::app);
    ofs << str << std::endl;
    ofs.close();
}

std::string Logger::getCurrentDate(void) {
    time_t now = time(0);
    std::string currentTime = ctime(&now);
    std::string newString = currentTime.substr(0, currentTime.length() - 1);

    return ("[" + newString + "]");
}

std::string Logger::makeLogEntry(std::string message) {
    return (this->getCurrentDate() + ": " + message);
}
