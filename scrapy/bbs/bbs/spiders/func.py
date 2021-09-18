# import requests as req
# a = req.get("https://i.imgur.com/rLqOHFU.jpg")
# with open("f.jpg","wb") as f:
#     f.write(a.content)
import os
import requests as req

def mkdir( like, title ,date ):
    dirname = str(like) + '_' + title.replace(' ', '_')
    if not os.path.exists( dirname):
        os.mkdir( dirname )
    return dirname

def downloadURL( url , dirname):
    #圖片網址格式修正
    if url.split(".")[-1] != "jpg":
        url += ".jpg"
    image = req.get( url, stream=True )
    #圖片下載不成功注意
    if image.url == "https://i.imgur.com/removed.png":
        print( dirname + url + "download failure" )
        pass
    name = dirname + "/" + url.split("/")[-1]
    #假如已下載則跳出
    if( os.path.exists(name)): pass
    with open( name , "wb") as f:
        f.write( image.content )
    print("success download" + name)


# coding: utf-8
# 如果目前不在dir,則創立dir,進入dir
def enterdir( dirname):
    cwd = os.getcwd().split('/')[-1]
    if  cwd != dirname:
        os.makedirs( dirname ,exist_ok = True )
        os.chdir( dirname )
