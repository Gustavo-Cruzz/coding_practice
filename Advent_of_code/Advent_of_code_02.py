total_score = 0
draw = 3
win = 6

scores =   {"X":1, # Rock
            "Y":2, # Paper
            "Z":3, # Scissors
            "A":1, # Rock
            "B":2, # Paper
            "C":3} # Scissors

def play(rival, me):
    """Function to play out all match combinations.
        Losing cases add no points, so they are not considered"""
    my_score = scores[me]
    rival_score = scores[rival]

    if my_score == rival_score:
        my_score += draw
    elif my_score < rival_score and rival_score - my_score == 2:
        my_score += win
    elif my_score > rival_score and my_score - rival_score != 2:
        my_score += win

    return my_score

with open("data/02_encryption.txt", "r") as f:
    file = f.readlines()

matches = [(x[0], x[2]) for x in file if x != "\n"]

for i in matches:
    total_score += play(i[0], i[1])

print(f" My scores against the elfs was: {total_score}")