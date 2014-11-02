newSpace = input("Space to go to: ")
fields = newSpace.split(",")
newSpaceTuple = (int(fields[0].strip()), int(fields[1].strip()))
print(newSpaceTuple)
