#!/bin/python3.8
import json

# read
with open('MOCK_DATA.json', newline='' ) as jsonfile:
    data = json.load(jsonfile)
# print(data)

# with open('MOCK_DATA.json', 'w', newline='' ) as jsonfile:
#     data.append({ \
#             'id':5,\
#             'first_name':'Vin',\
#             'last_name': 'Sturdgess',\
#             'gender': 'Male', \
#             'country': 'Greece' \
#         })
#     # json.dump(data , jsonfile)   # 寫入

# print(json.dumps(data )) # 寫入

