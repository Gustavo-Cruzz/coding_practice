"""For this task we will rearrange some boxes that look like this:

                    [L] [M]         [M]    
                [D] [R] [Z]         [C] [L]
                [C] [S] [T] [G]     [V] [M]
        [R]     [L] [Q] [B] [B]     [D] [F]
        [H] [B] [G] [D] [Q] [Z]     [T] [J]
        [M] [J] [H] [M] [P] [S] [V] [L] [N]
        [P] [C] [N] [T] [S] [F] [R] [G] [Q]
        [Z] [P] [S] [F] [F] [T] [N] [P] [W]

Into something else based on text inputs"""

import copy 
def load_data():
    with open("data/05_giant_cargo_crane.txt", "r") as f:
        return f.readlines()

def load_crates(txt):
    "Fills 9 arrays based on initial txt file"
    cargo = [[] for _ in range(9)]

    for text in txt[0:8]:
        for i in range(0, len(text), 4):
            if text[i] == '[':
                array_index = i // 4
                cargo[array_index].append(f"{text[i]}{text[i+1]}{text[i+2]}")

    return cargo

def extract_coordinates(text_input):
    """Extracts the coordinates from text input"""
    return [[int(i) for i in line.split() if i.isnumeric()] for line in text_input]

def rearrange_crates(crates, coordinates, reverse):
    """Rearrange the crates so that only one is moved at a time
        meaning that the crate on top will go to the bottom and vice versa"""

    start = 0
    for command in coordinates:
        amount, get_from, put_on = command[0]

        crates_to_move = crates[get_from-1][0:amount]

        if reverse:
            crates_to_move.reverse()

        for crate in crates_to_move[start:]:
            #Appends crates to their new array
            crates[put_on-1].insert(0, crate)

            #Removes crates from orginal array
            crates[get_from-1].pop(0)

    for i in crates:
        print(i)
    print()

file = load_data()
cargo = load_crates(file)
coordinates = extract_coordinates(file[10:])

crates = copy.deepcopy(cargo)
rearrange_crates(crates, coordinates, reverse = False)
rearrange_crates(cargo, coordinates, reverse = True)