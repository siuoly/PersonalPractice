""" 1st version  基本能抓網頁 """

import scrapy


class PttSpider(scrapy.Spider):
    # name = 'bbs'  # 這裡註解撞名 衝突
    allowed_domains = ['ptt.cc/']
    start_urls = ['https://www.ptt.cc/bbs/Gamesale/index.html']

    # set paser string 這裡沒用到
    p_block = "div.r-ent"                 
    p_author = "div.author::text"          
    p_title = "div.title a::text"         
    p_src = "div.title a::attr(href)"
    p_like = "div.nrec span::text"       
    p_date = "div.date::text"            

    def start_requests(self):
        urls = [ 'https://www.ptt.cc/bbs/Gamesale/index.html']
        for url in urls:
            yield scrapy.Request(url=url, cookies={"over18":"1"} , callback=self.parse)


    def parse(self, response):
        self.log( """
=================start scrapy================================ 
"""     )
        with open("f.html","wb") as f:
            f.write( response.body )
        self.log( f"save file {f.name} ")

    def parse_brower_page(self,response):
        pass
        
