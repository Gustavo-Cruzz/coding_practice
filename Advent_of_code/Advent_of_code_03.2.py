with open("data/03_rucksacks.txt", "r") as f:
    file = f.readlines()

# Clear the "\n" commom to all strings
file = tuple(map(lambda x: x[:-1], file[:-1]))
key = "N"
sum_of_scores = 0

total_items = len(file) # 300

for i in range(0,total_items,3):
    breaking = False

    # getting words in sets of 3, in order to compare their characters
    first  = file[i]
    second = file[i+1]
    third = file[i+2]

    for j in first:
        for k in second:
            if j == k and k in third: # If the characters match, break
                key = k
                breaking = True
                break

        if breaking: break

    # Converting a char to ASCII code
    score = ord(key)

    # Regulating the value to fit the challenge's criterion
    if score > 91:
        score = score -96
    else:
        score = score -38

    sum_of_scores += score

print(sum_of_scores)
