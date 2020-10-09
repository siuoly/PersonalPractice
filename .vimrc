"vim doc         http://vimcdoc.sourceforge.net/
"vim zh-tw       https://chienweichih.github.io/vimcdoc/doc/help.html
"vim zh-ch       https://yianwillis.github.io/vimcdoc/doc/help.html
"vim_faq         https://yianwillis.github.io/vimcfaq/doc/vim_faq.html
"noh : cancel highlight search
set nu
set relativenumber
set cursorline
set enc=utf-8
set tabstop=2
set ai
set hls
set ignorecase
set incsearch
"set expandtab
set shiftwidth=2
syntax on

" Uncomment the following to have Vim jump to the last position when                                                       
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$")
    \| exe "normal! g'\"" | endif
endif

" make 使用
map q :w<CR>
map Q :make<CR>
map W :make clean<CR>

"   ` 取代 <ESC> 
imap ` <Esc>
map ` <Esc>

" 快速測試 編譯
map <F3> :w<CR>:!./%<CR> 
map <F4> : set rnu! nu!<BAR>set nornu? <CR>
map <F5> <Esc>:w<CR>:!g++ -g -Wall % && ./a.out <CR>
map <F6> :!gdb a.out<CR>


