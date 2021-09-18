scrapy shell --nolog <url>

scrapy shell --nolog
res = Request("url", ...)
fetch(res)
response.text

scrapy crawl --nolog <url>



==================xpath==================
x("/html")
x("/html/head")
x("body/div")
x("body/div[1]")


x("/html/body/div")
	a = x("/html/body")
	a.xpath("div")

x("//div")   所有div

x("//div//h1")   div仔元素 中 所有h1

x("//@href")     所有href屬性



