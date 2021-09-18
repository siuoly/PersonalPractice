import scrapy

class QuerySpider( scrapy.Spider ):
    name = 'query'
    start_urls = [
            'https://docs.scrapy.org/en/latest/intro/overview.html' ]

    def parse(self, response):
        for text in response.xpath("//h2/text()").getall():
            yield {"text":text}


