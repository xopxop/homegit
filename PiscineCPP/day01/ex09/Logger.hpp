/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:44:09 by dthan             #+#    #+#             */
/*   Updated: 2020/05/11 01:44:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_CLASS_HPP
# define LOGGER_CLASS_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
# include <sstream>

class Logger {
    public:
        Logger(void);
        ~Logger(void);
        std::string fileName;
        std::string getCurrentDate(void);
        void log(std::string const & dest, std::string const & message);

    private:
        void        _logToConsole(std::string const & str);
        void        _logToFile(std::string const & str);
        std::string makeLogEntry(std::string message);
};

#endif
