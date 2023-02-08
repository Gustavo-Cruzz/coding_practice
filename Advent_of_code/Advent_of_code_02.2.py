total_score = 0
scores =  {"X":0, # Lose
           "Y":3, # Draw
           "Z":6, # Win
           "A":1, # Rock
           "B":2, # Paper
           "C":3} # Scissors

def play(rival, me):
    """Function to play out all match combinations.
        Losing cases add no points, so they are not considered"""

    my_score = 0
    match_score = scores[me]
    their_score = scores[rival]

    if me == "X":
        my_score += their_score - 1
    elif me == "Y":
        my_score += their_score
    elif me == "Z":
        my_score += their_score + 1

    if my_score > 3:
        my_score = 1
    elif my_score < 1:
        my_score = 3

    return my_score + match_score

with open("data/02_encryption.txt", "r") as f:
    file = f.readlines()

matches = [(x[0], x[2]) for x in file if x != "\n"]
print(matches)

for i in matches:
    total_score += play(i[0], i[1])

print(total_score)