" " add new mapping

augroup MAP
  au!
augroup END

" <C-C> refresh
se autoread
nnoremap <C-c> :!<cr><cr>

" <F3> quickfix read
nnoremap <expr><F3> &bt=="" ? "<C-W>j<C-\><C-N>z100<CR>H" :"z8<CR><C-w>k"



