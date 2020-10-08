"vim doc         http://vimcdoc.sourceforge.net/
"vim zh-tw       https://chienweichih.github.io/vimcdoc/doc/help.html
"vim zh-ch       https://yianwillis.github.io/vimcdoc/doc/help.html
"vim_faq         https://yianwillis.github.io/vimcfaq/doc/vim_faq.html
"noh : cancel highlight search
set nu
syntax on
set cursorline
set enc=utf-8
set tabstop=2
set ai
set hlsearch
set hls
set relativenumber
"set expandtab
set shiftwidth=2

" Uncomment the following to have Vim jump to the last position when                                                       
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$")
    \| exe "normal! g'\"" | endif
endif


imap ` <Esc>
map ` <Esc>
map <F4> : set rnu! nu!<BAR>set nornu? <CR>
map <F5> <Esc>:w<CR>:!g++ -g -Wall % && ./a.out <CR>
map <F6> :!gdb a.out<CR>


