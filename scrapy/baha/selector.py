# coding: utf-8
import scrapy.selector as sel
fetch("https://docs.scrapy.org/en/latest/topics/selectors.html#scrapy.selector.SelectorList")
r = response
r = sel.Selector(r)


r.xpath('//div/a/img').extract()
r.xpath('//div[@id="images"]/a/img[@src="image1_thumb.jpg"]').extract()
r.xpath('//div[@id="images"]/a/img')[1].attrib['src']


 r.xpath('//base/@href')
