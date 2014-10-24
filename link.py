# --*- coding: utf-8 -*--

import urllib.request
import re

which = re.compile(r'<li><a href="(.+?) target=">(.+?)</a>(.+?)</li>')

def get_html(url):
	response = urllib.request.urlopen(url)
	return response.read().decode('utf-8')

def find_data(url):
	html = get_html(url)
	content = []
	for x in which.findall(html):
		values = dict(url = x[0], title = x[1], info = x[2])
		content.append(values)
	return content

def file_write(uri, url):
	content = find_data(url)
	html = "<!DOCTYPE html> \
			<html lang='en'> \
			<head> \
				<meta charset=\"UTF-8\"> \
				<title>Document</title> \
			</head> \
			<body>"

	f = open(uri + ".html", "w")
	f.write(html)
	for x in content:
		f.write("<a href=\"" + x['url'] + "\">" + x['title'] + "</a>" + x['info'] + "<br>")

	html = "</body> \
			</html>"
	f.write(html)
	f.close

if __name__ == '__main__':
	file_write("c://users/lenovo/desktop/get", "http://blog.jobbole.com/78901/")
	print("write down")


#print(find_data("http://blog.jobbole.com/78901/"))
#find_data("http://blog.jobbole.com/78901/")

