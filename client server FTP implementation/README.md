## NETWORK PROGRAMM  HW2

# Simple FTP implementation

Before executing.
1.In the directory , use "make" command , complie the "server.c" and "client.c" file.
2.Creat another directory , move "server" file into the new directory , and ensure the "client" file and "server" file in different directory.

Execute..
1.run server  (command "./client")
2.run client  (In another cmd , command "./server")
	I.In client cmd ,input "connect" + "IP address",   then input "port number" to get connection .  //IP預設輸入:127.0.0.1   port預設輸入:8080
	II. input "upload" + "filename" , upload file to server terminal.		  //filename 不可有空格
	III. input "exit" ,exit the process.


# Create File:
	filename.encode : the compressed file
	file.table : the huffman code imformation

作法：
	client 傳輸前 , 先用 variable length 壓縮檔案 傳輸
	兩邊建立socket , client 傳輸第一筆訊息是 檔案名稱, 告訴server 建立的檔案叫什麼
之後 傳輸兩筆檔案 , file.table(壓縮檔), file.table(編碼表) , server會在本地解碼,創立原檔案.
	client離開時,傳exit訊息給server,告訴server中斷連線

編碼表格式：有256筆項目,代表ascii 0~255 , 每個項目頻率愈高則編碼愈短, 反之則愈長.

編碼先建立MinHeapTree, 再建立 陣列[0~255]作為編碼表 , 做為查表



# PS:
	server & client 兩個檔案需要放在不同目錄下執行,否則 server decode檔案後 , 名稱會和 原始檔衝突 
