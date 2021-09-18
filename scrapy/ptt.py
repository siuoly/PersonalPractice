import pysnooper as ps  
"""
scrap ptt index basic usage
"""
import requests as req

with ps.snoop('log.txt'):
    h = dict (cookie= 'over18=1;' )
    res = req.get("https://www.ptt.cc/bbs/Gamesale/index4030.html" ,headers = h )

    res.raise_for_status()

    # with open("t.html" ,"wb") as f:
    print( res.content.decode("utf-8") )
        # f.write( res.content)



"""
使用scrapy 開啟 "https://www.ptt.cc/bbs/Gamesale/index.html" 步驟:

$: scrapy shell
from scrapy import Request
url = "https://www.ptt.cc/bbs/Gamesale/index.html"
req=Request(url, cookies={'over18':'1'} )
fetch(req)
r = response

"""
#接下來 可對r進行一系列操作
"""
對response操作:
x = r.css("div.title")
x2 = x.css("a::text")                             # 取資料
r.css("div.title a::text").getall()              # 等同於上述兩步驟
r.css("div.r-ent div.title a::text").getall()    # 同上

r.css("div.r-ent  div.nrec span::text").getall() # 點讚數 有空字串問題

block = r.css("div.r-ent")                    # 文章塊
block.css("div.title a::attr(href)").getall() # 網址
                # ex: /bbs/Gamesale/M.1619246527.A.AB8.html  --> add leading manually "https://www.ptt.cc"

a.css("div.author::text").get()

"""
# 先對取各文章項目, 對各項取 標題,作者,讚數,網址,日期

"""
設定字串::
1. 取文章項目:
blocks = r.css("div.r-ent")
2. for  bolck in blocks ..抓各項目
3. 抓block作者
author=block.css("div.author::text").get()
4. 抓bolck標題 , 網址
title = block.css( "div.title a::text").get()
url = block.css( "div.title a::attr(href)" ).get()
5. 抓block讚數
like = block.css( "div.nrec span::text").get()
6. 抓 block日期
date = block.css("div.date::text").get()
"""
