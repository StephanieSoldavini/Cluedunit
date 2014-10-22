def openFile(file):
	lst = []
	with open("data/" + file + ".txt", encoding = "utf-8") as f:

		for line in f:
			line = line.strip()
			line = line.split(";")
			lst.append([l.strip() for l in line])

	return lst  
