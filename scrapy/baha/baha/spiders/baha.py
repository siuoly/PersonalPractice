import scrapy

class BahaSpider(scrapy.Spider):
    name = "baha"
    start_urls=["https://forum.gamer.com.tw/B.php?bsn=60073"]

    def parse(self, response):
        announce = response.css( "a.b-list__main__title::text" ).getall()
        article  = response.css("p.b-list__main__title::text").getall()
        announce_links \
            = response.css( "a.b-list__main__title::attr(href)" ).getall()
        article_links \
            = response.css( "p.b-list__main__title::attr(href)" ).getall()  # 如何將其合併 漂亮?
        next_page = response.css( "div.b-pager a.next::attr(href)" ).get()
        for a,al in zip(announce,announce_links):
            yield{ a:al}
        for a,al in zip(article,article_links):
            yield { a:al}
            

        # 如何使用domain進入下一頁?

        # 紀錄得到的資料



        
        
        

