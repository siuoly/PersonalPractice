#!/bin/python3.8
import csv
# read


# write
with open('MOCK_DATA.csv', 'a', newline='') as csvfile:
    writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    writer.writerow([3, 'Corri', 'Campling', 'Female', 'Sweden'])

with open('MOCK_DATA.csv', newline='') as csvfile:
    reader = csv.reader(csvfile )# , delimiter=',', quotechar='"')
    for row in reader:
        print( ', '.join(row))
