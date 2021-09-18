
""" 4st version  自動開download資料夾 避免重複下載"""

import scrapy
from bbs.spiders import func
from bbs.settings import DOWNLOAD_PAGE ,START_URL ,DEBUG
from bbs import settings


class PttSpider(scrapy.Spider):
    name = 'bbs'  # 註解 避免誤用
    allowed_domains = ['ptt.cc']
    page = 1

    # 下面沒用到 因為需另設cookies 之故 使用 start_requests()
    start_urls = ['https://www.ptt.cc/bbs/Gamesale/index.html'] 

    # set paser string 
    p_blocks = "div.r-ent"
    p_author = "div.author::text"
    p_title  = "div.title a::text"
    p_url    = "div.title a::attr(href)"
    p_like   = "div.nrec span::text"
    p_date   = "div.date::text"

    def start_requests(self): # 設cookie 所以用此函數
        url = START_URL
        yield scrapy.Request(url=url, 
                    cookies={"over18":"1"} , callback=self.parse)


    def parse(self, response):
        # 一則文章 一個block
        blocks = response.css( self.p_blocks )

        for block in blocks:
            author = block.css( self.p_author ).get()
            title  = block.css( self.p_title ).get()
            url    = block.css( self.p_url ).get()
            like   = block.css( self.p_like ).get()
            date   = block.css( self.p_date ).get()
            if title is None :
                continue
            if like is None:
                like = 0
            # 產生針對該 url 的follow parse , 作為下載之用
            if not DEBUG or block == blocks[0]:
                self.log("=====================================================================")
                yield response.follow(url, 
                    cookies= {"over18":"1"}, 
                    callback = self.parse_article ,
                    cb_kwargs = {"like":like}
                )  # 注意 follow 會和 Domain搭配 ppt.cc + bbs/cxxczc/zxczcxc
            yield { "author" : author ,
                    "title"  : title ,
                    "url"    : url   ,
                    "like"   : like  ,
                    "date"   : date }
        # 往下一頁爬蟲
        n_page = response.css("a.btn::attr(href)").getall()[3]
        if self.page < DOWNLOAD_PAGE :
            self.page += 1
            yield response.follow( n_page, cookies={"over18":"1"} , callback=self.parse)


    def parse_article(self,response , like):
        # 擷取 作者 標題 日期 讚數 連結
        author = response.css("span.article-meta-value::text")[0].get() 
        title = response.css("span.article-meta-value::text")[2].get() 
        date = response.css("span.article-meta-value::text")[3].get() 
        links = response.css("a::text").getall()
        links = [ l for l in links if l.find("imgur.com")!=-1 ]
        # 假如url不存在則跳出
        if links == []:
            self.log( f"{title} 沒有圖片")
            pass

        # 進入下載目錄,下載圖片, 使用url,title, like 作為input
        func.enterdir(settings.DIRNAME)

        # 開新資料夾 由文章,讚數設定
        dirname = func.mkdir( like, title,date)
        i = 1
        for link in links:
            #debug
            if not DEBUG or link == links[0] :
                func.downloadURL(link, dirname )
            i+=1
        # 資料夾內做紀錄
        with open(dirname+'/links',"w") as f:
            f.write( "author:" + author + "\ndate:" + date + '\n' )
            f.write( str(links) )
        pass

        
# 注 : response.body <-- byte
# 注 : response.body.decode("utf-8") <-- str
# 注 : response.body_as_unicode() <-- str
# 注 : response.text <-- str

""" 再次處理
links = r2.css("div.main-content a::attr(href)").getall()

取得 過濾後的網址
link = [ i for i in t if i.find("jpg") != -1 ] 
"""
