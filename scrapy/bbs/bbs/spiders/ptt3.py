
""" 3st version  抓網頁 抓圖片 """

import scrapy
from bbs.spiders import func


class PttSpider(scrapy.Spider):
    # name = 'bbs'  # 註解 避免誤用
    allowed_domains = ['ptt.cc']

    # 下面沒用到 因為需另設cookies 之故 使用 start_requests()
    start_urls = ['https://www.ptt.cc/bbs/Gamesale/index.html'] 

    # set paser string 
    p_blocks = "div.r-ent"
    p_author = "div.author::text"
    p_title  = "div.title a::text"
    p_src    = "div.title a::attr(href)"
    p_like   = "div.nrec span::text"
    p_date   = "div.date::text"

    def start_requests(self): # 設cookie 所以用此函數
        url =  'https://www.ptt.cc/bbs/Beauty/index'
        pages = 1  # 預設是抓1頁 就好
        # start at 'https://www.ptt.cc/bbs/Beauty/index3637.html'
        urls = [ url + str(3637-i) +".html" 
                for i in range(pages) ]
        for url in urls:
            yield scrapy.Request(url=url, 
                    cookies={"over18":"1"} , callback=self.parse)

    def parse(self, response):
        blocks = response.css( self.p_blocks )

        for block in blocks:
            author = block.css( self.p_author ).get()
            title  = block.css( self.p_title ).get()
            src    = block.css( self.p_src ).get()
            like   = block.css( self.p_like ).get()
            date   = block.css( self.p_date ).get()
            if title is None :
                continue
            if like is None:
                like = 0
            # 產生針對該 src 的follow parse , 作為下載之用
            yield response.follow(src, 
                    cookies= {"over18":"1"}, 
                    callback = self.parse_article ,
                    cb_kwargs = {"like":like}
            )  # 注意 follow 會和 Domain搭配 ppt.cc + bbs/cxxczc/zxczcxc

            yield { "author" : author ,
                    "title"  : title ,
                    "src"    : src   ,
                    "like"   : like  ,
                    "date"   : date }

    def parse_article(self,response , like):
        # 擷取 作者 標題 日期 讚數 連結
        author = response.css("span.article-meta-value::text")[0].get() 
        title = response.css("span.article-meta-value::text")[2].get() 
        date = response.css("span.article-meta-value::text")[3].get() 
        links = response.css("a::attr(href)").getall()
        links = [ i for i in links if i.find("jpg") != -1 ] 
        # 開新資料夾 由文章,讚數設定
        dirname = func.mkdir( like, title,date)
        # 下載圖片, 使用src ,title , like ,date作為input
        i = 1
        for link in links:
            func.downloadURL(link, dirname+'/'+str(i)+".jpg")
            i+=1
        # 資料夾內做紀錄
        with open(dirname+'/links',"w") as f:
            f.write( "author:"+author + "\ndate:" + date + '\n' )
            f.write( str(links) )
        pass

        
# 注 : response.body <-- byte
# 注 : response.body.decode("utf-8") <-- str
# 注 : response.body_as_unicode() <-- str
# 注 : response.text <-- str

""" 再次處理
response.follow( src , callback = xxx )
作者,看板名,標題,時間 = .css("span.article-meta-value::text").get()  [0,1,2,3]

取得所有 頁面中的 link
links = r2.css("div.main-content a::attr(href)").getall()

取得 過濾後的網址
link = [ i for i in t if i.find("jpg") != -1 ] 
"""
