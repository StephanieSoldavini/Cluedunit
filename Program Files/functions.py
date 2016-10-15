def openFile(file):
    lst = []
    with open("data/" + file + ".txt") as f:
        for line in f:
            line = line.strip()
            line = line.split(";")
            lst.append([l.strip() for l in line])
    return lst  
