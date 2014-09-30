# --*- coding: utf-8 -*--

import urllib
import httplib
import re

data = {"DDDDD": "110210224", "upass": "056418", "0MKKey":"" }

data_encode = urllib.urlencode(data)

request_url = "http://172.16.3.200/"

header_data = {"Host": "172.16.3.200"}

connect = httplib.HTTPConnection("172.16.3.200")

connect.request(method="POST", url=request_url,body=data_encode, headers=header_data )

response = connect.getresponse()

res = response.read()

with open("login.html", 'w') as f:
	f.write(res)
f.close()

pattern = re.compile(r'You have successfully logged into our system.')

match = pattern.search(res)

if match:
	print match.group()
else:
	print "log error."
