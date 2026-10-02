#!/usr/bin/env python3

##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## parser
##

from sys import exit

def parse_vision(vision: str) -> list:
    '''Parse the vision string and return a list dict containing information for each tile'''

    vision = vision.split(',')

    vision = [item.replace('\n', '') for item in vision]
    vision = [item.replace('[', '').replace(']', '') for item in vision]

    result = []

    for element in vision:
        parsed_dict = {}
        for item in element.split(" "):
            if item == "":
                continue
            if item in parsed_dict:
                parsed_dict[item] += 1
            else:
                parsed_dict[item] = 1
        result.append(parsed_dict)

    return result

def parse_inventory(inventory_str: str) -> dict:
    '''Parse the inventory string and return a list dict containing information for each tile'''
    inventory = inventory_str.split(',')

    inventory = [item.replace('\n', '') for item in inventory]
    inventory = [item.replace('[', '').replace(']', '') for item in inventory]

    temp_dict = {item.split()[0]: int(item.split()[1]) for item in inventory}

    return temp_dict
