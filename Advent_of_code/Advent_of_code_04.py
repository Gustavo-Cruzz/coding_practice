def fully_contains(data):
    """Checks how many pairs are contained within another"""
    counter = 0

    for i in data:
        if int(i[0][0]) < int(i[1][0]):
            if int(i[0][1]) >= int(i[1][1]):
                counter+= 1

        elif int(i[1][0]) < int(i[0][0]):
            if int(i[1][1]) >= int(i[0][1]):
                counter += 1

        elif int(i[1][0]) == int(i[0][0]) or int(i[0][1]) == int(i[1][1]):
                counter += 1

    print(f"{counter} pairs fully contain the other")

def overlaps(data):
    """Counts how many pairs have overlaps on their ranges"""
    counter = 0

    for i in data:
        if int(i[0][0]) == int(i[1][0]) or int(i[0][1]) == int(i[1][1]):
            counter += 1

        elif int(i[0][0]) < int(i[1][0]):
            if int(i[0][1]) >= int(i[1][0]):
                counter+= 1

        elif int(i[1][0]) < int(i[0][0]):
            if int(i[1][1]) >= int(i[0][0]):
                counter += 1

    print(f"{counter} pairs overlap")

with open("data/04_id_cleaning.txt", "r") as f:
    file = f.readlines()

# The original data comes in this format: 18-20,19-21
data = [(j[0].split("-"), j[1].split("-")) for j in [i.strip("\n").split(",") for i in file if i != "\n"]]

#After preprocessing, i has the becomes the following: (['18', '20'], ['19', '21']))
fully_contains(data)
overlaps(data)