# coding: utf-8
r = response
# %load write.py
open("a.html", "wb").write( response.body)
def xp(s):
    return r.xpath( s ).getall()
    
def cs(s):
    return r.css( s).getall()
    
def x(s):
    return r.xpath( s )
    
def c(s):
    return r.css( s )
    
a= "//a//text()"
a= "//img/@src"
a= '//p[@class="b-list__main__title"]//text()'
s4 = "//a[@class='next']/@href"
s5 = "//td[@class='b-list__main']/a/div[@class='b-list__img skeleton lazyload']/@data-thumbnail"
      # 限定此類class	子類a/    限定class				取該class 的data-thumbnail元素
s6 = "//div[contains(@class,'lazy')]/@data-thumbnail"
	    #div標籤中 clas 名稱中有'lazy'的class 取其 data-thumbail的value


