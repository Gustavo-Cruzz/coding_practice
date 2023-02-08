with open("data/01_elf_calories.txt", "r") as f:
    file = f.readlines()

# Use lambda to filter the "\n" in the numbers from .readlines()
# And map to iterate over the array of strings
file = list(map(lambda x: "\n" if x == "\n" else int(x[:-1]), file))

# Variables for tracking calories with each elf
calories = []
total = 0
greater = 0

# If its the same elf, sum the values
for i in file:
    if i != "\n":
        total += i

    # Othewise, save the value and reset 'total'
    else:
        calories.append(total)
        if total > greater:
            greater = total
        total = 0

calories = sorted(calories)[-3:]
print(calories)
print(f"The elf carring most calories has: {greater} calories")
print(F"The top 3 elfs are carrying {sum(calories)} calories in total")