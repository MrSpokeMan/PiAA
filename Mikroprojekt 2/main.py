import csv

with open('projekt2_dane.csv') as csvfile:
    csvreader = csv.reader(csvfile)
    next(csvreader)  # pomijamy pierwszy wiersz z nagłówkiem kolumn

    rankings = []
    for row in csvreader:
        tytul, nr_w_rankingu = row[1], row[2]
        rankings.append((tytul, nr_w_rankingu))

# teraz możesz użyć listy rankings w swoim programie
for r in rankings:
    print(r[0], r[1])
