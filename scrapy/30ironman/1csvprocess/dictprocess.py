#!/bin/python3.8
import csv

with open('mock_data.csv', 'a', newline='') as csvfile:

    fieldnames = ['id', 'first_name', 'last_name' ,'email', 'gender', 'ip_address']
    writer = csv.DictWriter(csvfile, fieldnames, delimiter=',', quotechar='"')
    writer.writerow({
        'id': 4,
        'first_name': 'Salvatore',
        'last_name': 'Gaitskill',
        'email': 'abc@ggmail.com',
        'gender': 'Male',
        'ip_address': '123.456.789.1'
    })

with open('MOCK_DATA.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile, delimiter=',', quotechar='"')
    for row in reader:
        print(row['first_name'], row['last_name'],row['email'], row['gender'], row['ip_address'])


