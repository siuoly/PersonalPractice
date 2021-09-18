#!/bin/python3.8
dic = {'a': 1, 'b': 2, 'c': 3, '0':12}
js = json.dumps(dic)
print(js)

js = json.dumps(dic, indent=4)
print(js)

js = json.dumps(dic, indent=4, sort_keys=True, separators=(',','++') )
print(js)




