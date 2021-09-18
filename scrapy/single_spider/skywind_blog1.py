import scrapy
# 基本抓 首頁 第一頁成功


class SkywindBlogSpider(scrapy.Spider):
    name = 'skywind_blog'
    allowed_domains = ['skywind3000.com']
    start_urls = ['http://skywind3000.com/']

    custom_settings = { 'FEED_EXPORT_ENCODING':'utf-8', }

    def parse(self, response):

        art_x =  "//h1[@class='post-title']/a" #article xpath string
        art_data = response.xpath( art_x )  #article data( url,title)

        for selector in art_data :
            title = selector.xpath("@title").get()
            url = selector.xpath("@href").get()
            yield dict( artcle = title, url=url )

