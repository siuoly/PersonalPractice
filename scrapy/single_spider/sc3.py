import scrapy
# ptt Tech_job版
# 使用 custom_settings 方法
# 使用複雜xpath 方法

class QuerySpider( scrapy.Spider ):
    name = 'query'
    start_urls = [
            'https://www.ptt.cc/bbs/Tech_Job/index.html']
            # 'https://docs.scrapy.org/en/latest/intro/overview.html' ]
    custom_settings = {
            'FEED_EXPORT_ENCODING':'utf-8',
    }
    def parse(self, response):
        for blocks in response.xpath("//div[@class='r-ent']"):
            yield { 'title' : blocks.xpath("div[@class='title']/a/text()").get() ,
                    'like' : blocks.xpath("div[@class='nrec']/span/text()").get('0') ,
                    'link' : blocks.xpath("div/a/@href").get() 
                }



