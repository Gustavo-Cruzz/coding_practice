import time
 
# record start time
start = time.time()
 
with open("data/03_rucksacks.txt", "r") as f:
    file = f.readlines()

# Clear the "\n" commom to all strings
file = list(map(lambda x: x[:-1], file[:-1]))
key = "N"
sum_of_scores = 0

for i in file:
    breaking = False
    length = int(len(i)/2)

    # Splitting each word in half, in order to compare their characters
    first  = i[:length]
    second = i[length:]

    for j in first:
        for k in second:
            if j == k: # If the characters match, break
                key = k
                breaking = True
                break

        if breaking: break

    # Converting a char to ASCII code
    score = ord(key)

    # Regulating the value to fit the challenge's criterion
    if score > 91:
        score = score -96
    elif score < 91:
        score = score -38

    sum_of_scores += score

print(sum_of_scores)
print(time.time() - start)

