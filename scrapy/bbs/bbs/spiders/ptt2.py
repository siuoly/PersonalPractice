
""" 1st version  基本能抓網頁 """

import scrapy


class PttSpider(scrapy.Spider):
    # name = 'bbs'  # 註解 避免誤用
    allowed_domains = ['ptt.cc/']
    # 下面沒用到 因為需另設cookies 之故 使用 start_requests()
    start_urls = ['https://www.ptt.cc/bbs/Gamesale/index.html'] 

    # set paser string 
    p_blocks = "div.r-ent"
    p_author = "div.author::text"
    p_title  = "div.title a::text"
    p_src    = "div.title a::attr(href)"
    p_like   = "div.nrec span::text"
    p_date   = "div.date::text"

    def start_requests(self):
        urls = [ 'https://www.ptt.cc/bbs/Gamesale/index.html']
        for url in urls:
            yield scrapy.Request(url=url, cookies={"over18":"1"} , callback=self.parse)


    def parse(self, response):
        print(type(response))
        self.log( """
=================start scrapy================================ 
"""     )
        blocks = response.css( self.p_blocks )
        for block in blocks:
            author = block.css( self.p_author ).get()
            title  = block.css( self.p_title ).get()
            if title is None :
                title = block.css("div.title::text").get()
            src    = block.css( self.p_src ).get()
            like   = block.css( self.p_like ).get()
            date   = block.css( self.p_date ).get()
            yield { "author" : author ,
                    "title"  : title  ,
                    "title"  : title ,
                    "src"    : src   ,
                    "like"   : like  ,
                    "date"   : date }
        with open("f.html","w") as f:
            f.write( response.text )
        self.log( f"save file {f.name} ")

    def parse_brower_page(self,response):
        pass
        
# 注 : response.body <-- byte
# 注 : response.body.decode("utf-8") <-- str
# 注 : response.body_as_unicode() <-- str
# 注 : response.text <-- str
