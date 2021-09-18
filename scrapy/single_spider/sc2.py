import scrapy
# ptt Tech_job版
# 使用 custom_settings 方法

class QuerySpider( scrapy.Spider ):
    name = 'query'
    start_urls = [
            'https://www.ptt.cc/bbs/Tech_Job/index.html']
            # 'https://docs.scrapy.org/en/latest/intro/overview.html' ]
    custom_settings = {
            'FEED_EXPORT_ENCODING':'utf-8',
    }
    def parse(self, response):
        for text in response.xpath("//div[@class='title']/a/text()").getall():
            yield {"標題":text }


