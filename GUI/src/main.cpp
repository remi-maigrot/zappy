/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** main.cpp for zappy gui core
*/

#include "../include/Core.hpp"

int main(int ac, char **av)
{
    Zappy::Core core;

    if (ac <= 2 || std::string(av[1]) == "-help") {
        std::cout << "USAGE: ./zappy_ai -p port -h machine" << std::endl;
        std::cout << "\tport\tis the port number" << std::endl;
        std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
        return 0;
    }
    core.init(ac, av);
    core.run();
    return 0;
}
