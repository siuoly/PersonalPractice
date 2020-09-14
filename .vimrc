set nu
syntax on
set cursorline
set enc=utf-8
set tabstop=2
set ai
set hlsearch
set hls
set relativenumber
set expandtab
set shiftwidth=2

map <F4> : set rnu! nu!<BAR>set nornu? <CR>
map <F5> <Esc>:w<CR>:!g++ -g % && ./a.out <CR>
map <F6> :!gdb a.out<CR>
