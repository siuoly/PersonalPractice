" how to name the terminal tab 給terminal標籤命名
" delete a WORD in vim terminal 在terminal中,快速刪字
" toggle <F2> in terminal
" 在shell中,看有沒以抓到網頁,很麻煩,
"   1.fetch(url)  2.write file 3.vim file
" 如何加入模板?  自動加入
"    custom_settings = { 'FEED_EXPORT_ENCODING':'utf-8', }


let cmd = "scrapy runspider "
let out = " -O o.json \<CR>"
map <C-F> :call term_sendkeys(term_list()[0], cmd.expand('%').out )<CR>

map \d :vsp o.json<CR>

function! OpenTest()
  if bufwinnr("o.json")<0
    vsp o.json
  endif
endf


augroup vimrc
  autocmd!
  autocmd vimrc BufReadPost o.json setlocal autoread
  autocmd vimrc BufWritePost .vimrc :so .vimrc
augroup END


" map <C-F> :w<CR>:!scrapy runspider % -O o.json<CR>:if bufwinnr("o.json")<0<CR>vsp o.json<CR>endif<CR>
" map <C-F> :w<CR>:!scrapy runspider % -O o.json<CR>:call OpenTest()
" map <C-F> :w<CR>:!scrapy runspider % -O o.json<CR>
