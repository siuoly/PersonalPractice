## ZSH呼叫scrapy方法

```
vim sc{1,2,3}.py
\s   # 讀取 .vimrc 檔案
<C-F>  # 呼叫 scrapy runspider <file>
		  # 輸出寫入於 o.json 檔案
```

```
scrapy runspider {sc1.py | sc2.py | sc3.py |sc.py }
	# 呼叫使用
```

## 寫code方法

```
:tab terminal   #打開terminal
:<C-F>       	  #在terminal測試我的 <name>.py 程式
:vs o.json      #我的程式爬蟲結果在此
```

### 使用Shell方法

```
scrapy shell url  #開啟該網址的shell
load spy_sh_config.py     #初始設定
```

