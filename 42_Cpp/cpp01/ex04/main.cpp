/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qraymaek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:25:29 by qraymaek          #+#    #+#             */
/*   Updated: 2024/05/22 15:25:33 by qraymaek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

std::string replace(std::string content, std::string to_replace, std::string replace_with)
{
    std::size_t pos = 0;
    while ((pos = content.find(to_replace, pos)) != std::string::npos)
    {
        content.erase(pos, to_replace.length());
        content.insert(pos, replace_with);
        pos += replace_with.length();
    }
    return (content);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error: Wrong Parameters" << std::endl;
        return (0);
    }

    // open the file
    std::ifstream   file;
    file.open(av[1]);

    // check if file is open
    if (!file.is_open())
    {
        std::cerr << "Error: Opening file: " << av[1] << std::endl;
        return (1);
    }
    
    // get the file content and close the file
    std::stringstream   content;
    content << file.rdbuf();
    file.close();

    // search and replace
    std::string new_content;
    new_content = replace(content.str(), av[2], av[3]);

    // open file again
    std::ofstream   output;
    output.open((std::string(av[1]) + ".replace").c_str());

    if (!output.is_open())
    {
        std::cerr << "Error: Creating replace file" << std::endl;
        return (1);
    }

    // put new content in
    output << new_content;

    output.close();
}
